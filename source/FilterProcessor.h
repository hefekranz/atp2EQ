#ifndef __FILTERPROCESSOR_H
#define __FILTERPROCESSOR_H
#include "FilterBand.h"

/* --- init values for each band -- */
//LOW
const double MINFREQ_low = 31.5;
const double MAXFREQ_low = 250;
const double MIDFREQ_low = 125;
//MID_1
const double MINFREQ_mid1 = 125;
const double MAXFREQ_mid1 = 1000;
const double MIDFREQ_mid1 = 500;
//MID_2
const double MINFREQ_mid2 = 500;
const double MAXFREQ_mid2 = 2000;
const double MIDFREQ_mid2 = 1000;
//MID_3
const double MINFREQ_mid3 = 1000;
const double MAXFREQ_mid3 = 4000;
const double MIDFREQ_mid3 = 2000;
//MID_4
const double MINFREQ_mid4 = 2000;
const double MAXFREQ_mid4 = 8000;
const double MIDFREQ_mid4 = 4000;
//HIGH
const double MINFREQ_high = 4000;
const double MAXFREQ_high = 16000;
const double MIDFREQ_high = 8000;
//same for all bands
const double MAXQ = 18;
const double MAXGAIN = 24;


class FilterProcessor{
public:
	FilterProcessor();
	void initialize(float sampleRate);
	void process(float* input, float* output, int numSamples);
	FilterBand lowBand;
	FilterBand midBand1;
	FilterBand midBand2;
    FilterBand midBand3;
    FilterBand midBand4;
	FilterBand highBand;
private:
	float sampleRate;
};

#endif