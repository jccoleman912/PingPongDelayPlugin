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
        r[0] = w[0] - delaySamples;
        r[1] = w[1] - delaySamples;
    }
    
    void setDelayMS(float delayMS);
    
private:
    
    // One sample of delay
    static const int SIZE = 24000;
    float delayBuffer[SIZE][2] = {0.f}; // left and right channels
    int w[2] = {SIZE-1}; // write index for buffer (input), initialize to end of buffer
    int r[2] = {0}; // read index for buffer (output)
    
    int delaySamples = 10000;
    float Fs = 48000.f;
    
};



class DelayEffect {
 
public:
    
    float processSample(float x, const int c);
    
    void setDelayMS(float delayMS);
    
    void prepareToPlay(double sampleRate, int bufferSize){
        Fs = (float) sampleRate;
        r[0] = w[0] - delaySamples;
        r[1] = w[1] - delaySamples;
    }
    
private:
    
    // One sample of delay
    static const int SIZE = 24000;
    float delayBuffer[SIZE][2] = {0.f}; // left and right channels
    int w[2] = {SIZE-1}; // write index for buffer (input), initialize to end of buffer
    int r[2] = {0}; // read index for buffer (output)
    
    int delaySamples = 10000;
    float Fs = 48000.f;
};
