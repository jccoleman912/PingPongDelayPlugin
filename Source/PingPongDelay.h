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
    
//    float processSampleRightFirst(float x, const int c);
    
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
        
        r4[0] = w4[0] - (delaySamples * 2);
        r4[1] = w4[1] - (delaySamples * 2);
        
        r5[0] = w5[0] - delaySamples;
        r5[1] = w5[1] - delaySamples;
        
        r6[0] = w6[0] - (delaySamples * 2);
        r6[1] = w6[1] - (delaySamples * 2);
        
        r7[0] = w7[0] - (delaySamples * 2);
        r7[1] = w7[1] - (delaySamples * 2);
    
        r8[0] = w8[0] - (delaySamples * 2);
        r8[1] = w8[1] - (delaySamples * 2);
    }
    
    void setDelayMS(float delayMS);
    
    void setInitialdBDrop(float initialLinDrop);
    
    void setL2RdBDrop(float l2RLinDrop);
    
    void setR2LdBDrop(float rLRLinDrop);
    
    void setInitialLeftDropLinear();
    
    void setInitialRightDropLiner();
    
    void setPingPongDropLinear();
    
    void setLinearGains(float mInitialdBDrop, float mL2RdBDrop, float mR2LdBDrop);
    
    void setLeftFirst(bool mLeftFirst);
    
    
private:
    
    // One sample of delay
    static const int SIZE = 1158000;
    float delayBuffer[SIZE][2] = {0.f}; // left and right channels
    int w[2] = {SIZE-1}; // write index for buffer (input), initialize to end of buffer
    int r[2] = {0}; // read index for buffer (output)
    
    
    
    float delayBuffer2[SIZE][2] = {0.f}; // left and right channels
    int w2[2] = {SIZE-1}; // write index for buffer (input), initialize to end of buffer
    int r2[2] = {0}; // read index for buffer (output)
    
    
    
    float delayBuffer3[SIZE][2] = {0.f}; // left and right channels
    int w3[2] = {SIZE-1}; // write index for buffer (input), initialize to end of buffer
    int r3[2] = {0}; // read index for buffer (output)
    
    
    
    float delayBuffer4[SIZE][2] = {0.f}; // left and right channels
    int w4[2] = {SIZE-1}; // write index for buffer (input), initialize to end of buffer
    int r4[2] = {0}; // read index for buffer (output)
    
    
    
    float delayBuffer5[SIZE][2] = {0.f}; // left and right channels
    int w5[2] = {SIZE-1}; // write index for buffer (input), initialize to end of buffer
    int r5[2] = {0}; // read index for buffer (output)
    
    
    
    float delayBuffer6[SIZE][2] = {0.f}; // left and right channels
    int w6[2] = {SIZE-1}; // write index for buffer (input), initialize to end of buffer
    int r6[2] = {0}; // read index for buffer (output)
    
    
    
    float delayBuffer7[SIZE][2] = {0.f}; // left and right channels
    int w7[2] = {SIZE-1}; // write index for buffer (input), initialize to end of buffer
    int r7[2] = {0}; // read index for buffer (output)

    
    
    float delayBuffer8[SIZE][2] = {0.f}; // left and right channels
    int w8[2] = {SIZE-1}; // write index for buffer (input), initialize to end of buffer
    int r8[2] = {0}; // read index for buffer (output)
    
    
    
    int delaySamples = 10000;
    float Fs = 48000.f;
    
    float initialLeftDropLinear = 0.5f;
    float initialRightDropLinear = 0.5f;
    float pingPongDropLinear = 0.5f;
    
    float initialLeftDropdB = -6.f;
    float initialRightDropdB = -6.f;
    float pingPongDropdB = -6.f;
    
    float initialdBDrop = -10.f;
    float l2RdBDrop = -12.f;
    float r2LdBDrop = -2.f;
    
    float wet = 0.f;
    float rightInitial = 0.f;
    float right = 0.f;
    float left = 0.f;
    
    float y = 0.f;
    float yLeft = 0.f;
    float yRightInitial = 0.f;
    float yRight = 0.f;
    
    bool leftFirst;
    
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
