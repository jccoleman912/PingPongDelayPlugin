/*
  ==============================================================================

    PingPongDelay.h
    Created: 6 Mar 2023 8:56:00pm
    Author:  Jackson Coleman

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class PingPongDelay
{
public:
    
    float processSample(float x, const int c);
    
    void processBlock(juce::AudioBuffer<float> &buffer);
    
    void processInPlace(float * buffer, const int numSamples, const int c);
    
    void prepareToPlay(double sampleRate, int bufferSize){
        Fs = (float) sampleRate;
        
        read = write - delaySamples;
        read2 = write2 - delaySamples;
    }
    
    void setDelayMS(float delayMS);
    
    void setInitialDropLinear(float initialLinear);
    
    void setL2RDropLinear(float l2RLinear);
    
    void setR2LDropLinear(float r2LLinear);
    
    void setLeftOrRight(bool leftFirst);
    
    void setBypassSelected(bool bypass);
    
    float getSampleRate();

    
private:
    
    /*
     The longest amount of delay samples possible
     */
    static const int SIZE = 864000;
    
    /*
     Left/right arrays and the read/write pointers.
     */
    float leftBuffer[SIZE] = {0.f};
    float rightBuffer[SIZE] = {0.f};
    
    int write = SIZE - 1;
    int read = 0;
    int write2 = SIZE - 1;
    int read2 = 0;
    
    /*
     The final output of processSample() and the left and right components of the output.
     */
    float output;
    
    float yLeft = 0.f;
    float yRight = 0.f;

    /*
     The boolean check to see which L/R button is selected.
     */
    bool leftDelayFirst;
    
    bool bypassSelected;
    
    /*
     All three linear gain slider values.
     */
    float initialDropLinear = 0.5f;
    float l2RDropLinear = 0.0f;
    float r2LDropLinear = 0.5f;
    
    
    
    /*
     Audio Device information needed for time-based calculations.
     */
    int delaySamples = 10000;
    float Fs = 48000.f;
};
