/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Coleman_HW2AudioProcessor::Coleman_HW2AudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       ), state(*this, nullptr, "PingPongParams", createParameterLayout())
#endif
{
}

Coleman_HW2AudioProcessor::~Coleman_HW2AudioProcessor()
{
}


juce::AudioProcessorValueTreeState::ParameterLayout Coleman_HW2AudioProcessor::createParameterLayout() {
    
    std::vector<std::unique_ptr<juce::RangedAudioParameter>> params;
    
    params.push_back(std::make_unique<juce::AudioParameterFloat> ("initialDropValue",
                                                                   "Initial dB Drop",
                                                                   juce::NormalisableRange<float> (-60.f,   24.f), -10.f));
    params.push_back(std::make_unique<juce::AudioParameterFloat> ("l2RDropValue",
                                                                   "Left to Right dB Drop",
                                                                   juce::NormalisableRange<float> (-60.f,   24.f), 0.f));
    params.push_back(std::make_unique<juce::AudioParameterFloat> ("r2LDropValue",
                                                                   "Right to Left dB Drop",
                                                                   juce::NormalisableRange<float> (-60.f,   24.f), -6.f));
    
    params.push_back(std::make_unique<juce::AudioParameterFloat> ("tempoValue",
                                                                   "Tempo",
                                                                   juce::NormalisableRange<float> (40.f,   240.f), 120.f));
    params.push_back(std::make_unique<juce::AudioParameterFloat> ("mixValue",
                                                                   "Mix %",
                                                                   juce::NormalisableRange<float> (0.f,   100.f), 100.f));
    params.push_back(std::make_unique<juce::AudioParameterFloat> ("smoothKnobValue",
                                                                   "Smooth (MS)",
                                                                   juce::NormalisableRange<float> (0.f,   500.f), 0.f));
    
    
    
    
    params.push_back(std::make_unique<juce::AudioParameterBool> ("tripletValue",
                                                                   "Triplet",
                                                                   false));
    
    params.push_back(std::make_unique<juce::AudioParameterBool> ("dottedValue",
                                                                   "Dotted",
                                                                   false));
    
    params.push_back(std::make_unique<juce::AudioParameterBool> ("bypassValue",
                                                                   "Bypass",
                                                                   false));
    
    params.push_back(std::make_unique<juce::AudioParameterBool> ("syncValue",
                                                                   "Sync",
                                                                   false));
    
    params.push_back(std::make_unique<juce::AudioParameterBool> ("leftFirstValue",
                                                                   "Left First",
                                                                   true));
    params.push_back(std::make_unique<juce::AudioParameterBool> ("rightFirstValue",
                                                                   "Right First",
                                                                   false));
    
    params.push_back(std::make_unique<juce::AudioParameterBool> ("wholeNoteValue",
                                                                   "Whole Note",
                                                                   false));
    params.push_back(std::make_unique<juce::AudioParameterBool> ("halfNoteValue",
                                                                   "Half Note",
                                                                   false));
    params.push_back(std::make_unique<juce::AudioParameterBool> ("quarterNoteValue",
                                                                   "Quarter Note",
                                                                   false));
    params.push_back(std::make_unique<juce::AudioParameterBool> ("8thNoteValue",
                                                                   "8th Note",
                                                                   true));
    params.push_back(std::make_unique<juce::AudioParameterBool> ("16thNoteValue",
                                                                   "16th Note",
                                                                   false));
    params.push_back(std::make_unique<juce::AudioParameterBool> ("32ndNoteValue",
                                                                   "32nd Note",
                                                                   false));
    
    params.push_back(std::make_unique<juce::AudioParameterBool> ("smoothButtonValue",
                                                                   "Smooth Engage",
                                                                   false));
    
//    params.push_back(std::make_unique<juce::AudioParameterChoice> ("noteValue", "Note Type", juce::StringArray {"Whole", "Half", "Quarter", "8th", "16th", "32nd", "64th"}, 3));
                     
   
    
    return {params.begin() , params.end()};
    
}

//==============================================================================
const juce::String Coleman_HW2AudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool Coleman_HW2AudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool Coleman_HW2AudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool Coleman_HW2AudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double Coleman_HW2AudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int Coleman_HW2AudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int Coleman_HW2AudioProcessor::getCurrentProgram()
{
    return 0;
}

void Coleman_HW2AudioProcessor::setCurrentProgram (int index)
{
}

const juce::String Coleman_HW2AudioProcessor::getProgramName (int index)
{
    return {};
}

void Coleman_HW2AudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void Coleman_HW2AudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    pingPongDelay.prepareToPlay(sampleRate, samplesPerBlock);

    float tr = 0.08f; // 80 ms response time for smoothing
    alpha = std::exp(-log(9.f)/(sampleRate * tr));


}

void Coleman_HW2AudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool Coleman_HW2AudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void Coleman_HW2AudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
    

    float initialdBDropValue = *state.getRawParameterValue("initialDropValue");
    
    float l2RdBDropValue = *state.getRawParameterValue("l2RDropValue");
    
    float r2LdBDropValue = *state.getRawParameterValue("r2LDropValue");
    
    float mixValue = *state.getRawParameterValue("mixValue");
    
    mixValue /= 100;
    
    
    bool boolBypassValue = *state.getRawParameterValue("bypassValue");
    
    
    bool boolSyncValue = *state.getRawParameterValue("syncValue");
    
    float tempoValue = *state.getRawParameterValue("tempoValue");
    
    float smoothKnobValue = *state.getRawParameterValue("smoothKnobValue");
    
    
    bool boolTripletValue = *state.getRawParameterValue("tripletValue");
    
    bool boolDottedValue = *state.getRawParameterValue("dottedValue");
    
    bool boolWhole = *state.getRawParameterValue("wholeNoteValue");
    
    bool boolHalf = *state.getRawParameterValue("halfNoteValue");
    
    bool boolQuarter = *state.getRawParameterValue("quarterNoteValue");
    
    bool bool8th = *state.getRawParameterValue("8thNoteValue");
    
    bool bool16th = *state.getRawParameterValue("16thNoteValue");
    
    bool bool32nd = *state.getRawParameterValue("32ndNoteValue");
    
    bool boolSmooth = *state.getRawParameterValue("smoothButtonValue");

    
    bool boolLeftFirstValue = *state.getRawParameterValue("leftFirstValue");
    
    if(boolWhole) {
        
        noteMultiplier = 4.f;
        
    } else if(boolHalf) {
        
        noteMultiplier = 2.f;
        
    } else if(boolQuarter) {
        
        noteMultiplier = 1.f;
        
    } else if(bool8th) {
        
        noteMultiplier = 0.5f;
        
    } else if(bool16th) {
        
        noteMultiplier = 0.25f;
        
    } else if(bool32nd) {
        
        noteMultiplier = 0.125f;
        
    } else {
        
        noteMultiplier = 1.f;
        
    };
    
    pingPongDelay.setLeftOrRight(boolLeftFirstValue);
    
    
    delayMS = 1000.f * noteMultiplier * (60.f / tempoValue);
    
    
    if(boolTripletValue) {
        
        delayMS *= (2.f/3.f);
        
    }
    
    if(boolDottedValue) {
        
        delayMS *= 1.5f;
    }
        

    float y = 0.f;
    
    float Fs = pingPongDelay.getSampleRate();

    if(!boolBypassValue) {
        
        for (int channel = 0; channel < totalNumInputChannels; ++channel)
        {
            for (int n = 0; n < buffer.getNumSamples(); ++n)
            {
                
                if(!boolSmooth) {
                    trDelay = 0.f; // 100 ms response time for smoothing
                } else {
                    trDelay = smoothKnobValue/1000;
                }

                alphaDelay = std::exp(-log(9.f)/(Fs * trDelay));
                
                smoothDelayMS[channel] = alphaDelay * smoothDelayMS[channel] + (1.f - alphaDelay) * delayMS;
                
                pingPongDelay.setDelayMS(smoothDelayMS[channel]);
                
                smoothInitialGainDropdB[channel] = alpha * smoothInitialGainDropdB[channel] + (1.f - alpha) * initialdBDropValue;
                
                pingPongDelay.setInitialDropLinear(juce::Decibels::decibelsToGain(smoothInitialGainDropdB[channel]));
                
                smoothL2RGainDropdB[channel] = alpha * smoothL2RGainDropdB[channel] + (1.f - alpha) * l2RdBDropValue;
                
                pingPongDelay.setL2RDropLinear(juce::Decibels::decibelsToGain(smoothL2RGainDropdB[channel]));
                
                smoothR2LGainDropdB[channel] = alpha * smoothR2LGainDropdB[channel] + (1.f - alpha) * r2LdBDropValue;
                
                pingPongDelay.setR2LDropLinear(juce::Decibels::decibelsToGain(smoothR2LGainDropdB[channel]));
 
                
                float x = buffer.getWritePointer(channel)[n];

                    
                y = pingPongDelay.processSample(x, channel);
                
                smoothMix[channel] = alpha * smoothMix[channel] + (1 - alpha) * mixValue;

                    
                buffer.getWritePointer(channel)[n] = (smoothMix[channel] * y) + ((1 - smoothMix[channel]) * x);
                    
                }
            
        }
        
    } else { pingPongDelay.clearBuffers(); }
}

//==============================================================================
bool Coleman_HW2AudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* Coleman_HW2AudioProcessor::createEditor()
{
    return new Coleman_HW2AudioProcessorEditor (*this);
}

//==============================================================================
void Coleman_HW2AudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
    
    auto currentState = state.copyState();
    std::unique_ptr<juce::XmlElement> xml (currentState.createXml());
    copyXmlToBinary(*xml, destData);
}

void Coleman_HW2AudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    std::unique_ptr<juce::XmlElement> xml (getXmlFromBinary(data, sizeInBytes));
    if (xml && xml->hasTagName(state.state.getType())){
        state.replaceState(juce::ValueTree::fromXml(*xml));
        
    }
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new Coleman_HW2AudioProcessor();
}
