#include <math.h>
#include "FilterBand.h"

const double pi = 3.1415926535897932384626433832795;
FilterBand::FilterBand()
	: a(0), b(0), c(0), d(0), e(0), x1(0), x2(0), y1(0), y2(0)
	, sampleRate (0)
	, frequency(0)
	, gain (0)
	, q(1)
	, type(PEAK)
	, bypass(0)
{}


void FilterBand::initialize(double setSampleRate, float MINFREQ, float MAXFREQ, float MIDFREQ){
	sampleRate = setSampleRate;
	this->MINFREQ = MINFREQ;
	this->MAXFREQ = MAXFREQ;
	this->MIDFREQ = MIDFREQ;
	frequency = MIDFREQ;
	q = 1;
	gain = 0;

	set(type, frequency, q, gain);
}

/* --- Setting up Stuff on parameter change --- */
void FilterBand::setFrequency(float frequency){
	this->frequency = frequency;
	set(type, frequency, q, gain);
}

void FilterBand::setType(FilterType type){
	this->type = type;
	set(type, frequency, q, gain);
}

void FilterBand::setGain(float gain){
	this->gain = gain;
	set(type, frequency, q, gain);
}

void FilterBand::setQ(float q){
	this->q = q;
	set(type, frequency, q, gain);
}

void FilterBand::setBypass(int bypass){
	this->bypass = bypass;
}


void FilterBand::set(FilterType type, float frequency, float q, float gain){

	
	// begrenzt Frequenzbereich auf Werte in MIN/MAXFREQ
	if (frequency < MINFREQ) {
		frequency = MINFREQ;
	}

	if (frequency > MAXFREQ){
		frequency = MAXFREQ;
	}

	double amp = pow(10.0, gain / 40.0);
	double w = 2.0 * pi * (frequency / sampleRate);
	double sinw = sin(w);
	double cosw = cos(w);
	double alpha = sinw / (2.0 * q);
	double beta = sqrt(amp) / q;
	double fkap = (float) exp(-w);

	double a0, a1, a2, b0, b1, b2;

	if (type == PEAK){
		b0 = 1.0 + (alpha * amp);
		b1 = -2.0 * cosw;
		b2 = 1.0 - (alpha * amp);
		a0 = 1.0 + (alpha / amp);
		a1 = 2.0 * cosw;
		a2 = -1.0 + (alpha / amp);
	}
	else if (type == LOWPASS){
		b0 = (1.0 - cosw) * 0.5;
		b1 = 1.0 - cosw;
		b2 = (1.0 - cosw) * 0.5;
		a0 = 1.0 + alpha;
		a1 = 2.0 * cosw;
		a2 = alpha - 1.0;
	}
	else if (type == HIGHPASS){
		b0 = (1.0 + cosw) * 0.5;
		b1 = -(cosw + 1.0);
		b2 = (1.0 + cosw) * 0.5;
		a0 = 1.0 + alpha;
		a1 = 2.0 * cosw;
		a2 = alpha - 1.0;
	}
	else if (type == LOW_SHELF){
		b0 = amp * ((amp+1.0) - ((amp-1.0)*cosw) + (beta*sinw));
		b1 = 2.0 * amp * ((amp-1.0) - ((amp+1.0)*cosw));
		b2 = amp * ((amp+1.0) - ((amp-1.0)*cosw) - (beta*sinw));
		a0 = (amp+1.0) + ((amp-1.0)*cosw) + (beta*sinw);
		a1 = 2.0F * ((amp-1.0) + ((amp+1.0)*cosw));
		a2 = -((amp+1.0) + ((amp-1.0)*cosw) - (beta*sinw));
	}
	else if (type == HIGH_SHELF){
		b0 = amp * ((amp+1.0F) + ((amp-1.0)*cosw) + (beta*sinw));
		b1 = -2.0 * amp * ((amp-1.0) + ((amp+1.0)*cosw));
		b2 = amp * ((amp+1.0) + ((amp-1.0)*cosw) - (beta*sinw));
		a0 = (amp+1.0) - ((amp-1.F)*cosw) + (beta*sinw);
		a1 = -2.0 * ((amp-1.0) - ((amp+1.0)*cosw));
		a2 = -((amp+1.0) - ((amp-1.0)*cosw) - (beta*sinw));
	}

	set(a0, a1, a2, b0, b1, b2);
}

void FilterBand::set(double a0, double a1, double a2, double b0, double b1, double b2){
	a = b0/a0;
	b = b1/a0;
	c = b2/a0;
	d = a1/a0;
	e = a2/a0;
}

float FilterBand::processOneSample(float input){

	double output;

	if(bypass == 0){

		output = (a*input) + (b*x1) + (c*x2) + (d*y1) + (e*y2);
		x2 = x1;
		x1 = input;
		y2 = y1;
		y1 = output;
	}

	else{
		output = input;
	}
	return (float) output;
}
