#ifndef __FilterBand_H
#define __FilterBand_H
#include <string>

enum FilterType{
	PEAK,
	LOWPASS,
	HIGHPASS,
	LOW_SHELF,
	HIGH_SHELF,
	NUMTYPES
};


class FilterBand{
public:

	FilterBand();
	void initialize(double sampleRate, float MINFREQ, float MAXFREQ, float MIDFREQ);
	void set(FilterType type, float frequency, float Q, float gain); 
	void set(double a0, double a1, double a2, double b0, double b1, double b2);
	void setFrequency(float frequency);
	void setType(FilterType type);
	void setQ(float q);
	void setGain(float gain);
	void setBypass(int bypass);

	float processOneSample(float input);

private:
	float MINFREQ;
	float MAXFREQ;
	float MIDFREQ;
	float frequency;
	FilterType type;
	float gain;
	float q;
	double sampleRate;
	double a, b, c, d, e;
	double x1, x2, y1, y2;
	int bypass;
};
#endif