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



//float PingPongDelay::processSample(float x, const int c){
//
//    // one sample of delay
//    //int currentIndex = i[c];
//    float z = delayBuffer[r[c]][c];
//
//    float y = z * (initialLinDrop * (l2RLinDrop + r2LLinDrop));
//
//    delayBuffer[w[c]][c] = x;
//
//    // Increment Index
//    w[c]++;
//    if (w[c] >= SIZE){
//        w[c] = 0; // circular indexing
//    }
//
//    // Increment Index
//    r[c]++;
//    if (r[c] >= SIZE){
//        r[c] = 0; // circular indexing
//    }
//    return y;
//
//}

float PingPongDelay::processSample(float x, const int c){

    // one sample of delay
    //int currentIndex = i[c];
    
    wet = delayBuffer[r[c]][c];

    float y = (wet) * (initialLinDrop);

    delayBuffer[w[0]][0] = x;
    
    
    left = delayBuffer2[r2[c]][c];
    
    float yOut = (left * r2LLinDrop);
    
    delayBuffer2[w2[c]][c] = y;
    
    
    
    right = delayBuffer3[r3[c]][c];
    
    float yRight = (right * l2RLinDrop);
    
    delayBuffer3[w3[1]][1] = x;
    
    
    
    
    
    
    

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
    
    // Increment Index
    w2[c]++;
    if (w2[c] >= SIZE){
        w2[c] = 0; // circular indexing
    }

    // Increment Index
    r2[c]++;
    if (r2[c] >= SIZE){
        r2[c] = 0; // circular indexing
    }
    
    // Increment Index
    w3[c]++;
    if (w3[c] >= SIZE){
        w3[c] = 0; // circular indexing
    }

    // Increment Index
    r3[c]++;
    if (r3[c] >= SIZE){
        r3[c] = 0; // circular indexing
    }
    
    return y + yOut;

}


void PingPongDelay::setDelayMS(float delayMS){
    
    float delaySec = delayMS / 1000.f;
    delaySamples = delaySec * Fs;
//    delaySamples = juce::jmin(delaySamples,95999);
    r[0] = w[0] - delaySamples;
    if (r[0] < 0){
        r[0] += SIZE;
    }
    r[1] = w[1] - delaySamples;
    if (r[1] < 0){
        r[1] += SIZE;
    }
    
    r2[0] = w2[0] - (delaySamples * 2);
    if (r2[0] < 0){
        r2[0] += SIZE;
    }
    r2[1] = w2[1] - (delaySamples * 2);
    if (r2[1] < 0){
        r2[1] += SIZE;
    }
    
    r3[0] = w3[0] - (delaySamples * 2);
    if (r3[0] < 0){
        r3[0] += SIZE;
    }
    r3[1] = w3[1] - (delaySamples * 2);
    if (r3[1] < 0){
        r3[1] += SIZE;
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
