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
    
    float processSampleRightFirst(float x, const int c);
    
    void processBlock(juce::AudioBuffer<float> &buffer);
    
    void processInPlace(float * buffer, const int numSamples, const int c);
    
    void prepareToPlay(double sampleRate, int bufferSize){
        Fs = (float) sampleRate;
//        r[0] = w[0] - delaySamples;
//        r[1] = w[1] - delaySamples;
//
//        r2[0] = w2[0] - (delaySamples * 2);
//        r2[1] = w2[1] - (delaySamples * 2);
//
//        r3[0] = w3[0] - (delaySamples * 2);
//        r3[1] = w3[1] - (delaySamples * 2);
//
//        r4[0] = w4[0] - (delaySamples * 2);
//        r4[1] = w4[1] - (delaySamples * 2);
        
        read = write - delaySamples;
        read2 = write2 - delaySamples;
    }
    
    void setDelayMS(float delayMS);
    
    void setLinearGains(float mInitialdBDrop, float mL2RdBDrop, float mR2LdBDrop);
    
    void setLeftOrRight(bool leftFirst);
    
    
private:
    
    
    // One sample of delay
    static const int SIZE = 1158000;
    float delayBuffer[SIZE][2] = {0.f}; // left and right channels
    int w[2] = {SIZE-1}; // write index for buffer (input), initialize to end of buffer
    int r[2] = {0}; // read index for buffer (output)
    
    float leftBuffer[SIZE] = {0.f};
    float rightBuffer[SIZE] = {0.f};
    int write = SIZE - 1;
    int read = 0;
    int write2 = SIZE - 1;
    int read2 = 0;
    
    float output;
    
    bool leftDelayFirst;
    
    
    
//    float delayBuffer2[SIZE][2] = {0.f}; // left and right channels
//    int w2[2] = {SIZE-1}; // write index for buffer (input), initialize to end of buffer
//    int r2[2] = {0}; // read index for buffer (output)
//
//
//
//    float delayBuffer3[SIZE][2] = {0.f}; // left and right channels
//    int w3[2] = {SIZE-1}; // write index for buffer (input), initialize to end of buffer
//    int r3[2] = {0}; // read index for buffer (output)
//
//
//
//    float delayBuffer4[SIZE][2] = {0.f}; // left and right channels
//    int w4[2] = {SIZE-1}; // write index for buffer (input), initialize to end of buffer
//    int r4[2] = {0}; // read index for buffer (output)
//
//
    
    int delaySamples = 10000;
    float Fs = 48000.f;
    
    float initialLeftDropLinear = 0.5f;
    float initialRightDropLinear = 0.5f;
    float pingPongDropLinear = 0.5f;
    
    float initialLeftDropdB = -9.f;
    float initialRightDropdB = -9.f;
    float pingPongDropdB = -6.f;
    
    float wet = 0.f;
    float rightInitial = 0.f;
    float right = 0.f;
    float left = 0.f;
    
    float y = 0.f;
    float yLeft = 0.f;
    float yRightInitial = 0.f;
    float yRight = 0.f;
    
};
