/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PingPongDelay.h"

//==============================================================================
/**
*/
class Coleman_HW2AudioProcessor  : public juce::AudioProcessor
                            #if JucePlugin_Enable_ARA
                             , public juce::AudioProcessorARAExtension
                            #endif
{
public:
    //==============================================================================
    Coleman_HW2AudioProcessor();
    ~Coleman_HW2AudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    float alpha = 0.9999f;
    
    float alphaDelay = 0.9999f;
    
    float initialGainDropdB = -9.f;
    float smoothInitialGainDrop[2] = {-10.f};
   
    float l2RGainDropdB = 0.f;
    float smoothL2RGainDropdB[2] = {0.f};
    
    float r2LGainDropdB = -6.f;
    float smoothR2LGainDropdB[2] = {-6.f};
    
    
    float tempo = 120.f;
    float smoothDelayMS[2] = {500.f};
    
    bool isBypassed = false;
    bool isTriplet = false;
    bool isDotted = false;
    bool leftFirst = true;
    bool isSynced = false;
    
    std::string noteType = "quarter";
    float noteMultiplier = 1.f;
    float delayMS = 500.f;

private:
    
    PingPongDelay pingPongDelay;
    
    PingPongDelay pingPongDelayRightFirst;
    
    void setTempo (float tempo);
    
//    juce::SmoothedValue<float,juce::ValueSmoothingTypes::Linear> smoothedInitialGainDropdBL {-9.f};
//    juce::SmoothedValue<float,juce::ValueSmoothingTypes::Linear> smoothedInitialGainDropdBR {-9.f};
//    juce::SmoothedValue<float,juce::ValueSmoothingTypes::Linear> smoothedL2RGainDropdBL {0.f};
//    juce::SmoothedValue<float,juce::ValueSmoothingTypes::Linear> smoothedL2RGainDropdBR {0.f};
//    juce::SmoothedValue<float,juce::ValueSmoothingTypes::Linear> smoothedR2LGainDropdBL {-6.f};
//    juce::SmoothedValue<float,juce::ValueSmoothingTypes::Linear> smoothedR2RGainDropdBR {-6.f};
//    juce::SmoothedValue<float,juce::ValueSmoothingTypes::Linear> smoothedTempoL {120.f};
//    juce::SmoothedValue<float,juce::ValueSmoothingTypes::Linear> smoothedTempoR {120.f};
    
    
    
    
    int countL = 0;
    
    int countR = 0;
    
public:
    
    juce::AudioProcessorValueTreeState state;
    
    //Function to fill the value tree.
    
    juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout();
   
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Coleman_HW2AudioProcessor)
};
