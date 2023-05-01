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
                       )
#endif
{
}

Coleman_HW2AudioProcessor::~Coleman_HW2AudioProcessor()
{
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
    
    float tr = 0.1; // 100 ms response time for smoothing
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
    
    
    int numSamples = buffer.getNumSamples();
    
    
    
    if(isTriplet) {
        delayMS = 1000.f * noteMultiplier * (120.f / (3.f * tempo));
        
    }
    else {
        
        delayMS = 1000.f * noteMultiplier * (60.f / tempo);
        
    }
    
    
    pingPongDelay.setInitialLinDrop(juce::Decibels::decibelsToGain(initialGainDropdB));
    pingPongDelay.setL2RLinDrop(juce::Decibels::decibelsToGain(l2RGainDropdB));
    pingPongDelay.setR2LLinDrop(juce::Decibels::decibelsToGain(r2LGainDropdB));
    pingPongDelay.setDelayMS(delayMS);
    
    float y = 0.f;


    if(!isBypassed) {
        for (int channel = 0; channel < totalNumInputChannels; ++channel)
        {
            for (int n = 0; n < buffer.getNumSamples(); ++n)
            {
                
                float x = buffer.getWritePointer(channel)[n];
                
                if(!leftFirst) {
                    y = pingPongDelay.processSampleRightFirst(x, channel);
                } else {
                    y = pingPongDelay.processSample(x, channel);
                }
                
                buffer.getWritePointer(channel)[n] = y;
                
            }
             
        }
    }
}

//float xL = buffer.getWritePointer(channel)[n];
//
//float yL = pingPongDelay.processSample(xL,channel);
//
//float yR = pingPongDelay.processSample(yL, channel);
//
//yL = pingPongDelay.processSample(yR, channel);
//
//if(channel == 0) {
//    buffer.getWritePointer(channel)[n] = yL;
//} else {
//    buffer.getWritePointer(channel)[n] = yR;
//}

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
}

void Coleman_HW2AudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new Coleman_HW2AudioProcessor();
}
