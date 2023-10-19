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
    
    /*
     Various variables used
     */
    float Fs = 48000;
    
    float y = 0.f;
    
    float x = 0.f;
    
    float alpha = 0.9999f;
    
    float alphaDelay = 0.9999f;
    
    float smoothInitialGainDropdB[2] = {-10.f};
    float smoothL2RGainDropdB[2] = {0.f};
    
    float smoothR2LGainDropdB[2] = {-6.f};
    
    float smoothMix[2] = {1.f};
    
    float smoothDelayMS[2] = {500.f};
    float noteMultiplier = 1.f;
    float delayMS = 500.f;
    float trDelay = 0.f;
    
    float finalTempo = 120.f;
    
    /*
     The variables that will be assigned the Value Tree State values in processBlock().
     */
    float initialdBDropValue;
    float l2RdBDropValue;
    float r2LdBDropValue;
    
    float mixValue;
    
    bool boolBypassValue;
    
    bool boolSyncValue;
    
    float tempoValue;
    
    float smoothKnobValue;
    
    bool boolTripletValue;
    bool boolDottedValue;
    
    bool boolWhole;
    bool boolHalf;
    bool boolQuarter;
    bool bool8th;
    bool bool16th;
    bool bool32nd;
    
    bool boolSmooth;
    bool boolLeftFirstValue;
    
    float hwBufferSize;
private:
    
    PingPongDelay pingPongDelay;
    
    juce::AudioPlayHead* playHead;
    
    juce::AudioPlayHead::CurrentPositionInfo positionInfo;
    
public:
    
    juce::AudioProcessorValueTreeState state;
    
    //Function to fill the value tree.
    
    juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout();
   
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Coleman_HW2AudioProcessor)
};
