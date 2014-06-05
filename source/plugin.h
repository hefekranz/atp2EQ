#ifndef __plugin__
#define __plugin__
#include "pluginadapter.h"
#include "FilterProcessor.h"

namespace Steinberg {
namespace Vst {

// change these numbers!
// every plugin needs a unique UID
static const FUID PluginProcessorUID (0x84E8AE6F, 0x92554F53, 0x96AAE413, 0x3C935A18);
static const FUID PluginControllerUID (0xD39D3BA5, 0xD7AF42FA, 0x843F4AC8, 0x41EB04F0);

// define parameter tags here:
enum
{
	kFilterTypeLowId = 0,
	kFrequencyLowId,
	kQLowId,
	kGainLowId,
	kBypassLowId,

	kFilterTypeMid1Id,
	kFrequencyMid1Id,
	kQMid1Id,
	kGainMid1Id,
    kBypassMid1Id,

	kFilterTypeMid2Id,
	kFrequencyMid2Id,
	kQMid2Id,
	kGainMid2Id,
    kBypassMid2Id,

    kFilterTypeMid3Id,
	kFrequencyMid3Id,
	kQMid3Id,
	kGainMid3Id,
    kBypassMid3Id,
    
    kFilterTypeMid4Id,
	kFrequencyMid4Id,
	kQMid4Id,
	kGainMid4Id,
    kBypassMid4Id,
    
	kFilterTypeHighId,
	kFrequencyHighId,
	kQHighId,
	kGainHighId,
    kBypassHighId
};


class Plugin : public PluginAdapter
{
public:
	Plugin ();
	virtual ~Plugin (){}
	tresult PLUGIN_API process (ProcessData& data);
	void startProcessing(int numChannels, SampleRate sampleRate);	
	static FUnknown* createInstance (void*) { return (IAudioProcessor*)new Plugin (); }
private:
	int numChannels;
	SampleRate sampleRate;
private:
	FilterProcessor leftProcessor;
	FilterProcessor rightProcessor;
};




}} // namespaces

#endif //__plugin__
