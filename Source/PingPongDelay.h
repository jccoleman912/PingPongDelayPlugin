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
        
        r2[0] = w2[0] - (delaySamples * 2);
        r2[1] = w2[1] - (delaySamples * 2);
        
        r3[0] = w3[0] - (delaySamples * 2);
        r3[1] = w3[1] - (delaySamples * 2);
    }
    
    void setDelayMS(float delayMS);
    
    void setInitialLinDrop(float initialLinDrop);
    
    void setL2RLinDrop(float l2RLinDrop);
    
    void setR2LLinDrop(float rLRLinDrop);
    
private:
    
    // One sample of delay
    static const int SIZE = 4608000;
    float delayBuffer[SIZE][2] = {0.f}; // left and right channels
    int w[2] = {SIZE-1}; // write index for buffer (input), initialize to end of buffer
    int r[2] = {0}; // read index for buffer (output)
    
    float delayBuffer2[SIZE][2] = {0.f}; // left and right channels
    int w2[2] = {SIZE-1}; // write index for buffer (input), initialize to end of buffer
    int r2[2] = {0}; // read index for buffer (output)
    
    float delayBuffer3[SIZE][2] = {0.f}; // left and right channels
    int w3[2] = {SIZE-1}; // write index for buffer (input), initialize to end of buffer
    int r3[2] = {0}; // read index for buffer (output)
    
    int delaySamples = 10000;
    float Fs = 48000.f;
    
    float initialLinDrop = -10.f;
    float l2RLinDrop = -4.f;
    float r2LLinDrop = -4.f;
    
    float wet = 0.f;
    float right = 0.f;
    float left = 0.f;
    
};



//class DelayEffect {
//
//public:
//
//    float processSample(float x, const int c);
//
//    void setDelayMS(float delayMS);
//
//    void prepareToPlay(double sampleRate, int bufferSize){
//        Fs = (float) sampleRate;
//        r[0] = w[0] - delaySamples;
//        r[1] = w[1] - delaySamples;
//    }
//
//private:
//
//    // One sample of delay
//    static const int SIZE = 24000;
//    float delayBuffer[SIZE][2] = {0.f}; // left and right channels
//    int w[2] = {SIZE-1}; // write index for buffer (input), initialize to end of buffer
//    int r[2] = {0}; // read index for buffer (output)
//
//    int delaySamples = 10000;
//    float Fs = 48000.f;
//};
