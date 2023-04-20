/*
  ==============================================================================

    PingPongDelay.cpp
    Created: 6 Mar 2023 8:56:00pm
    Author:  Jackson Coleman

  ==============================================================================
*/

#include "PingPongDelay.h"



//float PingPongDelay::processSample(float x, const int c){
//
//    // one sample of delay
//    int currentIndex = i[c];
//    float y = delayBuffer[currentIndex][c];
//
//    delayBuffer[currentIndex][c] = x;
//
//    // Increment Index
//    i[c] += increment;
//    if (i[c] >= delaySamples){
//        increment = -1;
//        i[c] += increment; // circular indexing
//    }
//    if (i[c] <= 0){
//        increment = 1;
//        i[c] += increment;
//    }
//
//    return y;
//
//}

//
//void RevDelayEffect::setDelayMS(float delayMS){
//
//    float delaySec = delayMS / 1000.f;
//    delaySamples = delaySec * Fs;
//    delaySamples = juce::jmin(delaySamples,23999);
//}
//



float PingPongDelay::processSample(float x, const int c){

    // one sample of delay
    //int currentIndex = i[c];
    float z = delayBuffer[r[c]][c];

    float y = z * (initialLinDrop * (l2RLinDrop + r2LLinDrop));

    delayBuffer[w[c]][c] = x;

    // Increment Index
    w[c]++;
    if (w[c] >= SIZE){
        w[c] = 0; // circular indexing
    }

    // Increment Index
    r[c]++;
    if (r[c] >= SIZE){
        r[c] = 0; // circular indexing
    }
    return y;

}


void PingPongDelay::setDelayMS(float delayMS){
    
    float delaySec = delayMS / 1000.f;
    delaySamples = delaySec * Fs;
    delaySamples = juce::jmin(delaySamples,95999);
    r[0] = w[0] - delaySamples;
    if (r[0] < 0){
        r[0] += SIZE;
    }
    r[1] = w[1] - delaySamples;
    if (r[1] < 0){
        r[1] += SIZE;
    }
}

void PingPongDelay::setInitialLinDrop(float mInitialLinDrop) {
    initialLinDrop = mInitialLinDrop;
}

void PingPongDelay::setL2RLinDrop(float mL2RLinDrop) {
    l2RLinDrop = mL2RLinDrop;
}

void PingPongDelay::setR2LLinDrop(float mR2LLinDrop) {
    r2LLinDrop = mR2LLinDrop;
}


void PingPongDelay::processBlock(juce::AudioBuffer<float> &buffer)
{
    const int numChannels = buffer.getNumChannels();
    const int numSamples = buffer.getNumSamples();
    
    for (int c = 0; c < numChannels ; ++c){
        
        for (int n = 0; n < numSamples ; ++n){
            
            float x = buffer.getWritePointer(c) [n];
            
            x = processSample(x, c);
            
            buffer.getWritePointer(c) [n] = x;
        }
        
    }
}

void PingPongDelay::processInPlace(float * buffer, const int numSamples, const int c){
    
    for (int n = 0 ; n < numSamples; ++n){
        float x = (*buffer); // de-reference current value
        
        x = processSample(x, c);
        
        *buffer = x; // over-write current value
        
        ++buffer; // move pointer to the next sample
    }
    
}
