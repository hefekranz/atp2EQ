#include <math.h>
#include "FilterProcessor.h"

FilterProcessor::FilterProcessor()
: sampleRate(0)
{}

void FilterProcessor::initialize(float sampleRate){
	this->sampleRate = sampleRate;
	lowBand.initialize(sampleRate, MINFREQ_low, MAXFREQ_low, MIDFREQ_low);
	midBand1.initialize(sampleRate,MINFREQ_mid1, MAXFREQ_mid1, MIDFREQ_mid1);
	midBand2.initialize(sampleRate,MINFREQ_mid2, MAXFREQ_mid2, MIDFREQ_mid2);
    midBand3.initialize(sampleRate,MINFREQ_mid3, MAXFREQ_mid2, MIDFREQ_mid3);
    midBand4.initialize(sampleRate,MINFREQ_mid4, MAXFREQ_mid2, MIDFREQ_mid4);
	highBand.initialize(sampleRate, MINFREQ_high, MAXFREQ_high, MIDFREQ_high);
}

void FilterProcessor::process(float* input, float * output, int numSamples){
	for(int i = 0; i < numSamples; i++){
		output[i] = lowBand.processOneSample(input[i]);
		output[i] = midBand1.processOneSample(output[i]);
		output[i] = midBand2.processOneSample(output[i]);
        output[i] = midBand3.processOneSample(output[i]);
        output[i] = midBand4.processOneSample(output[i]);
		output[i] = highBand.processOneSample(output[i]);
	}
}
