#include "plugin.h"
#include "pluginterfaces/base/ustring.h"

#include <stdio.h>

namespace Steinberg {
	namespace Vst {


		//-----------------------------------------------------------------------------
		// member function of PluginController!
		// define parameter definitions here...
		void PluginController::setupParameters(){

			/*------------------Low Band Parameters----------------------------*/

			// Filter Type
			StringListParameter* stringListParameter = new StringListParameter(STR16("Typ_low"), kFilterTypeLowId);
			stringListParameter->appendString(USTRING("Peak"));
			stringListParameter->appendString(USTRING("Lowpass"));
			stringListParameter->appendString(USTRING("Highpass"));
			stringListParameter->appendString(USTRING("Low Shelf"));
			stringListParameter->appendString(USTRING("High Shelf"));
			parameters.addParameter(stringListParameter);

			// low Frequenz: 20...200 Hz
			parameters.addParameter(new RangeParameter(STR16("Frequency_low"), kFrequencyLowId, STR16("Hz"), MINFREQ_low, MAXFREQ_low, 1));

			// low Q: 0,1 ... 18
			parameters.addParameter(new RangeParameter(STR16("Q_low"), kQLowId, STR16("Hz"), 0.1, MAXQ));

			// low Gain: -24 dB ... +24 dB
			parameters.addParameter(new RangeParameter(STR16("Gain_low"), kGainLowId, STR16("dB"), -MAXGAIN, MAXGAIN, 0));

			// low Bypass 
	
			parameters.addParameter(new RangeParameter(STR16("Bypass_low"), kBypassLowId, STR16(""), false, true, 1));

			/*------------------Mid Band 1 Parameters ------------------------*/

			StringListParameter* stringListParameter_mid1 = new StringListParameter(STR16("Typ_mid1"), kFilterTypeMid1Id);
			stringListParameter_mid1->appendString(USTRING("Peak"));
			stringListParameter_mid1->appendString(USTRING("Lowpass"));
			stringListParameter_mid1->appendString(USTRING("Highpass"));
			stringListParameter_mid1->appendString(USTRING("Low Shelf"));
			stringListParameter_mid1->appendString(USTRING("High Shelf"));
			parameters.addParameter(stringListParameter_mid1);

			// mid1 Frequenz:
			parameters.addParameter(new RangeParameter(STR16("Frequency_mid1"), kFrequencyMid1Id, STR16("Hz"), MINFREQ_mid1, MAXFREQ_mid1));

			// mid1 Q: 0,1 ... 18
			parameters.addParameter(new RangeParameter(STR16("Q_mid1"), kQMid1Id, STR16("Hz"), 0.1, MAXQ));

			// mid1 Gain: -24 dB ... +24 dB
			parameters.addParameter(new RangeParameter(STR16("Gain_mid1"), kGainMid1Id, STR16("dB"), -MAXGAIN, MAXGAIN, 0));
            
            //bypass
            parameters.addParameter(new RangeParameter(STR16("Bypass_mid1"), kBypassMid1Id, STR16(""), false, true, 1));

			/*------------------Mid Band 2 Parameters ------------------------*/

			StringListParameter* stringListParameter_mid2 = new StringListParameter(STR16("Typ_mid2"), kFilterTypeMid2Id);
			stringListParameter_mid2->appendString(USTRING("Peak"));
			stringListParameter_mid2->appendString(USTRING("Lowpass"));
			stringListParameter_mid2->appendString(USTRING("Highpass"));
			stringListParameter_mid2->appendString(USTRING("Low Shelf"));
			stringListParameter_mid2->appendString(USTRING("High Shelf"));
			parameters.addParameter(stringListParameter_mid2);

			// mid2 Frequenz:
			parameters.addParameter(new RangeParameter(STR16("Frequency_mid2"), kFrequencyMid2Id, STR16("Hz"), MINFREQ_mid2, MAXFREQ_mid2, (MINFREQ_mid2 + MAXFREQ_mid2)/2));

			// mid2 Q: 0,1 ... 18
			parameters.addParameter(new RangeParameter(STR16("Q_mid2"), kQMid2Id, STR16("Hz"), 0.1, MAXQ));

			// mid2 Gain: -24 dB ... +24 dB
			parameters.addParameter(new RangeParameter(STR16("Gain_mid2"), kGainMid2Id, STR16("dB"), -MAXGAIN, MAXGAIN, 0));
            
            //bypass
            parameters.addParameter(new RangeParameter(STR16("Bypass_mid2"), kBypassMid2Id, STR16(""), false, true, 1));
            
            /*------------------Mid Band 3 Parameters ------------------------*/
            
			StringListParameter* stringListParameter_mid3 = new StringListParameter(STR16("Typ_mid3"), kFilterTypeMid3Id);
			stringListParameter_mid3->appendString(USTRING("Peak"));
			stringListParameter_mid3->appendString(USTRING("Lowpass"));
			stringListParameter_mid3->appendString(USTRING("Highpass"));
			stringListParameter_mid3->appendString(USTRING("Low Shelf"));
			stringListParameter_mid3->appendString(USTRING("High Shelf"));
			parameters.addParameter(stringListParameter_mid3);
            
			// mid3 Frequenz:
			parameters.addParameter(new RangeParameter(STR16("Frequency_mid3"), kFrequencyMid3Id, STR16("Hz"), MINFREQ_mid3, MAXFREQ_mid3, (MINFREQ_mid3 + MAXFREQ_mid3)/2));
            
			// mid3 Q: 0,1 ... 18
			parameters.addParameter(new RangeParameter(STR16("Q_mid3"), kQMid3Id, STR16("Hz"), 0.1, MAXQ));
            
			// mid3 Gain: -24 dB ... +24 dB
			parameters.addParameter(new RangeParameter(STR16("Gain_mid3"), kGainMid3Id, STR16("dB"), -MAXGAIN, MAXGAIN, 0));
            
            //bypass
            parameters.addParameter(new RangeParameter(STR16("Bypass_mid3"), kBypassMid3Id, STR16(""), false, true, 1));
            
            /*------------------Mid Band 4 Parameters ------------------------*/
            
			StringListParameter* stringListParameter_mid4 = new StringListParameter(STR16("Typ_mid4"), kFilterTypeMid4Id);
			stringListParameter_mid4->appendString(USTRING("Peak"));
			stringListParameter_mid4->appendString(USTRING("Lowpass"));
			stringListParameter_mid4->appendString(USTRING("Highpass"));
			stringListParameter_mid4->appendString(USTRING("Low Shelf"));
			stringListParameter_mid4->appendString(USTRING("High Shelf"));
			parameters.addParameter(stringListParameter_mid4);
            
			// mid4 Frequenz:
			parameters.addParameter(new RangeParameter(STR16("Frequency_mid4"), kFrequencyMid4Id, STR16("Hz"), MINFREQ_mid4, MAXFREQ_mid4, (MINFREQ_mid4 + MAXFREQ_mid4)/2));
            
			// mid4 Q: 0,1 ... 18
			parameters.addParameter(new RangeParameter(STR16("Q_mid4"), kQMid4Id, STR16("Hz"), 0.1, MAXQ));
            
			// mid4 Gain: -24 dB ... +24 dB
			parameters.addParameter(new RangeParameter(STR16("Gain_mid4"), kGainMid4Id, STR16("dB"), -MAXGAIN, MAXGAIN, 0));
            
            //bypass
            parameters.addParameter(new RangeParameter(STR16("Bypass_mid4"), kBypassMid4Id, STR16(""), false, true, 1));

			/*------------------ High Band Parameters-------------------------*/

			// Filter Type
			StringListParameter* stringListParameter_high = new StringListParameter(STR16("Typ_high"), kFilterTypeHighId);
			stringListParameter_high->appendString(USTRING("Peak"));
			stringListParameter_high->appendString(USTRING("Lowpass"));
			stringListParameter_high->appendString(USTRING("Highpass"));
			stringListParameter_high->appendString(USTRING("Low Shelf"));
			stringListParameter_high->appendString(USTRING("High Shelf"));

			parameters.addParameter(stringListParameter_high);

			// high Frequenz: 2500...18000 Hz
			parameters.addParameter(new RangeParameter(STR16("Frequency_high"), kFrequencyHighId, STR16("Hz"), MINFREQ_high, MAXFREQ_high));

			// high Q: 0,1 ... 18
			parameters.addParameter(new RangeParameter(STR16("Q_high"), kQHighId, STR16("Hz"), 0.1, MAXQ));

			// high Gain: -24 dB ... +24 dB
			parameters.addParameter(new RangeParameter(STR16("Gain_high"), kGainHighId, STR16("dB"), -MAXGAIN, MAXGAIN, 0));
            
            //bypass
            parameters.addParameter(new RangeParameter(STR16("Bypass_high"), kBypassHighId, STR16(""), false, true, 1));
		}


		//-----------------------------------------------------------------------------
		Plugin::Plugin ()
			: numChannels(0)
			, sampleRate(0)
		{
			setControllerClass (PluginControllerUID);
		}
		//-----------------------------------------------------------------------------
		void Plugin::startProcessing(int numChannels, SampleRate sampleRate){
			this->numChannels = numChannels;
			this->sampleRate = sampleRate;
			leftProcessor.initialize(sampleRate);
			rightProcessor.initialize(sampleRate);

		}
		tresult PLUGIN_API Plugin::process (ProcessData& data)
		{

			/* --- Low Band Changes --- */

			if (hasInputParameterChanged(data, kFilterTypeLowId)){
				float value = getInputParameterChange(data, kFilterTypeLowId);
				FilterType filterType = (FilterType) std::min<int8> ((int8)(NUMTYPES * value), NUMTYPES - 1);
				leftProcessor.lowBand.setType(filterType);
				rightProcessor.lowBand.setType(filterType);
			}
			if (hasInputParameterChanged(data, kFrequencyLowId)){
				float param = getInputParameterChange(data, kFrequencyLowId);
				float frequency = MINFREQ_low + param * (MAXFREQ_low - MINFREQ_low);
				leftProcessor.lowBand.setFrequency(frequency);
				rightProcessor.lowBand.setFrequency(frequency);
			}
			if (hasInputParameterChanged(data, kGainLowId)){
				float param = getInputParameterChange(data, kGainLowId);
				float gain = -MAXGAIN + (param * 2 * MAXGAIN);
				leftProcessor.lowBand.setGain(gain);
				rightProcessor.lowBand.setGain(gain);
			}
			if (hasInputParameterChanged(data, kQLowId)){
				float param = getInputParameterChange(data, kQLowId);		
				float Q = 1 + (MAXQ - 1) * param;
				leftProcessor.lowBand.setQ(Q);
				rightProcessor.lowBand.setQ(Q);	
			}
			if (hasInputParameterChanged(data, kBypassLowId)){
				bool param = getInputParameterChange(data, kBypassLowId);		
				leftProcessor.lowBand.setBypass(param);
				rightProcessor.lowBand.setBypass(param);	
			}

			/* --- Mid Band 1 Changes --- */

			if (hasInputParameterChanged(data, kFilterTypeMid1Id)){
				float value = getInputParameterChange(data, kFilterTypeMid1Id);
				FilterType filterType = (FilterType) std::min<int8> ((int8)(NUMTYPES * value), NUMTYPES - 1);
				leftProcessor.midBand1.setType(filterType);
				rightProcessor.midBand1.setType(filterType);
			}
			if (hasInputParameterChanged(data, kFrequencyMid1Id)){
				float param = getInputParameterChange(data, kFrequencyMid1Id);
				float frequency = MINFREQ_mid1 + param * (MAXFREQ_mid1 - MINFREQ_mid1);
				leftProcessor.midBand1.setFrequency(frequency);
				rightProcessor.midBand1.setFrequency(frequency);
			}
			if (hasInputParameterChanged(data, kGainMid1Id)){
				float param = getInputParameterChange(data, kGainMid1Id);
				float gain = -MAXGAIN + (param * 2 * MAXGAIN);
				leftProcessor.midBand1.setGain(gain);
				rightProcessor.midBand1.setGain(gain);
			}
			if (hasInputParameterChanged(data, kQMid1Id)){
				float param = getInputParameterChange(data, kQMid1Id);		
				float Q = 1 + (MAXQ - 1) * param;
				leftProcessor.midBand1.setQ(Q);
				rightProcessor.midBand1.setQ(Q);
			}
            if (hasInputParameterChanged(data, kBypassMid1Id)){
				bool param = getInputParameterChange(data, kBypassMid1Id);
				leftProcessor.midBand1.setBypass(param);
				rightProcessor.midBand1.setBypass(param);
			}

			/* --- Mid Band 2 Changes --- */

			if (hasInputParameterChanged(data, kFilterTypeMid2Id)){
				float value = getInputParameterChange(data, kFilterTypeMid2Id);
				FilterType filterType = (FilterType) std::min<int8> ((int8)(NUMTYPES * value), NUMTYPES - 1);
				leftProcessor.midBand2.setType(filterType);
				rightProcessor.midBand2.setType(filterType);
			}
			if (hasInputParameterChanged(data, kFrequencyMid2Id)){
				float param = getInputParameterChange(data, kFrequencyMid2Id);
				float frequency = MINFREQ_mid2 + param * (MAXFREQ_mid2 - MINFREQ_mid2);
				leftProcessor.midBand2.setFrequency(frequency);
				rightProcessor.midBand2.setFrequency(frequency);
			}
			if (hasInputParameterChanged(data, kGainMid2Id)){
				float param = getInputParameterChange(data, kGainMid2Id);
				float gain = -MAXGAIN + (param * 2 * MAXGAIN);
				leftProcessor.midBand2.setGain(gain);
				rightProcessor.midBand2.setGain(gain);
			}
			if (hasInputParameterChanged(data, kQMid2Id)){
				float param = getInputParameterChange(data, kQMid2Id);		
				float Q = 1 + (MAXQ - 1) * param;
				leftProcessor.midBand2.setQ(Q);
				rightProcessor.midBand2.setQ(Q);
			}
            if (hasInputParameterChanged(data, kBypassMid2Id)){
				bool param = getInputParameterChange(data, kBypassMid2Id);
				leftProcessor.midBand2.setBypass(param);
				rightProcessor.midBand2.setBypass(param);
			}
            
            /* --- Mid Band 3 Changes --- */
            
			if (hasInputParameterChanged(data, kFilterTypeMid3Id)){
				float value = getInputParameterChange(data, kFilterTypeMid3Id);
				FilterType filterType = (FilterType) std::min<int8> ((int8)(NUMTYPES * value), NUMTYPES - 1);
				leftProcessor.midBand3.setType(filterType);
				rightProcessor.midBand3.setType(filterType);
			}
			if (hasInputParameterChanged(data, kFrequencyMid3Id)){
				float param = getInputParameterChange(data, kFrequencyMid3Id);
				float frequency = MINFREQ_mid3 + param * (MAXFREQ_mid3 - MINFREQ_mid3);
				leftProcessor.midBand3.setFrequency(frequency);
				rightProcessor.midBand3.setFrequency(frequency);
			}
			if (hasInputParameterChanged(data, kGainMid3Id)){
				float param = getInputParameterChange(data, kGainMid3Id);
				float gain = -MAXGAIN + (param * 2 * MAXGAIN);
				leftProcessor.midBand3.setGain(gain);
				rightProcessor.midBand3.setGain(gain);
			}
			if (hasInputParameterChanged(data, kQMid3Id)){
				float param = getInputParameterChange(data, kQMid3Id);
				float Q = 1 + (MAXQ - 1) * param;
				leftProcessor.midBand3.setQ(Q);
				rightProcessor.midBand3.setQ(Q);
			}
            if (hasInputParameterChanged(data, kBypassMid3Id)){
				bool param = getInputParameterChange(data, kBypassMid3Id);
				leftProcessor.midBand3.setBypass(param);
				rightProcessor.midBand3.setBypass(param);
			}
            
            /* --- Mid Band 4 Changes --- */
            
			if (hasInputParameterChanged(data, kFilterTypeMid4Id)){
				float value = getInputParameterChange(data, kFilterTypeMid4Id);
				FilterType filterType = (FilterType) std::min<int8> ((int8)(NUMTYPES * value), NUMTYPES - 1);
				leftProcessor.midBand4.setType(filterType);
				rightProcessor.midBand4.setType(filterType);
			}
			if (hasInputParameterChanged(data, kFrequencyMid4Id)){
				float param = getInputParameterChange(data, kFrequencyMid4Id);
				float frequency = MINFREQ_mid4 + param * (MAXFREQ_mid4 - MINFREQ_mid4);
				leftProcessor.midBand4.setFrequency(frequency);
				rightProcessor.midBand4.setFrequency(frequency);
			}
			if (hasInputParameterChanged(data, kGainMid4Id)){
				float param = getInputParameterChange(data, kGainMid4Id);
				float gain = -MAXGAIN + (param * 2 * MAXGAIN);
				leftProcessor.midBand4.setGain(gain);
				rightProcessor.midBand4.setGain(gain);
			}
			if (hasInputParameterChanged(data, kQMid4Id)){
				float param = getInputParameterChange(data, kQMid4Id);
				float Q = 1 + (MAXQ - 1) * param;
				leftProcessor.midBand4.setQ(Q);
				rightProcessor.midBand4.setQ(Q);
			}
            if (hasInputParameterChanged(data, kBypassMid4Id)){
				bool param = getInputParameterChange(data, kBypassMid4Id);
				leftProcessor.midBand4.setBypass(param);
				rightProcessor.midBand4.setBypass(param);
			}
            
			/* --- high Band Changes --- */

			if (hasInputParameterChanged(data, kFilterTypeHighId)){
				float value = getInputParameterChange(data, kFilterTypeHighId);
				FilterType filterType = (FilterType) std::min<int8> ((int8)(NUMTYPES * value), NUMTYPES - 1);
				leftProcessor.highBand.setType(filterType);
				rightProcessor.highBand.setType(filterType);
			}
			if (hasInputParameterChanged(data, kFrequencyHighId)){
				float param = getInputParameterChange(data, kFrequencyHighId);
				float frequency = MINFREQ_high + param * (MAXFREQ_high - MINFREQ_high);
				leftProcessor.highBand.setFrequency(frequency);
				rightProcessor.highBand.setFrequency(frequency);
			}
			if (hasInputParameterChanged(data, kGainHighId)){
				float param = getInputParameterChange(data, kGainHighId);
				float gain = -MAXGAIN + (param * 2 * MAXGAIN);
				leftProcessor.highBand.setGain(gain);
				rightProcessor.highBand.setGain(gain);
			}
			if (hasInputParameterChanged(data, kQHighId)){
				float param = getInputParameterChange(data, kQHighId);		
				float Q = 1 + (MAXQ - 1) * param;
				leftProcessor.highBand.setQ(Q);
				rightProcessor.highBand.setQ(Q);
			}
            if (hasInputParameterChanged(data, kBypassHighId)){
				bool param = getInputParameterChange(data, kBypassHighId);
				leftProcessor.highBand.setBypass(param);
				rightProcessor.highBand.setBypass(param);
			}

			if (numChannels > 0){
				float* leftInputChannel = data.inputs[0].channelBuffers32[0];
				float* leftOutputChannel = data.outputs[0].channelBuffers32[0];
				leftProcessor.process(leftInputChannel, leftOutputChannel, data.numSamples);
			}
			if (numChannels > 1){
				float* rightInputChannel = data.inputs[0].channelBuffers32[1];
				float* rightOutputChannel = data.outputs[0].channelBuffers32[1];
				rightProcessor.process(rightInputChannel, rightOutputChannel, data.numSamples);
			}
			return kResultTrue;
		}


	}} // namespaces

