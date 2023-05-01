/*
  ==============================================================================

    PingPongDelay.cpp
    Created: 6 Mar 2023 8:56:00pm
    Author:  Jackson Coleman

  ==============================================================================
*/

#include "PingPongDelay.h"


float PingPongDelay::processSample(float x, const int c){
   
        
    wet = delayBuffer[r[c]][c];
    
    y = (wet) * (initialLeftDropLinear);
    
    delayBuffer[w[0]][0] = x;
    
    
    left = delayBuffer2[r2[c]][c];
        
    yLeft = (left * pingPongDropLinear);
        
    delayBuffer2[w2[c]][c] = y + yLeft;
        
        
        
    rightInitial = delayBuffer3[r3[c]][c];
    
    yRightInitial = (rightInitial * initialRightDropLinear);
        
    delayBuffer3[w3[1]][1] = x;
        
        
    right = delayBuffer4[r4[c]][c];
        
    yRight = (right * pingPongDropLinear);
        
    delayBuffer4[w4[c]][c] = yRightInitial + yRight;
        

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
    
    // Increment Index
    w4[c]++;
    if (w4[c] >= SIZE){
        w4[c] = 0; // circular indexing
    }

    // Increment Index
    r4[c]++;
    if (r4[c] >= SIZE){
        r4[c] = 0; // circular indexing
    }

    return y + yLeft + yRightInitial + yRight;

}


float PingPongDelay::processSampleRightFirst(float x, const int c) {
    
    wet = delayBuffer[r[c]][c];
    
    y = (wet) * (initialLeftDropLinear);
    
    delayBuffer[w[1]][1] = x;
    
    
    left = delayBuffer2[r2[c]][c];
        
    yLeft = (left * pingPongDropLinear);
        
    delayBuffer2[w2[c]][c] = y + yLeft;
        
        
        
    rightInitial = delayBuffer3[r3[c]][c];
    
    yRightInitial = (rightInitial * initialRightDropLinear);
        
    delayBuffer3[w3[0]][0] = x;
        
        
    right = delayBuffer4[r4[c]][c];
        
    yRight = (right * pingPongDropLinear);
        
    delayBuffer4[w4[c]][c] = yRightInitial + yRight;
        

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
    
    // Increment Index
    w4[c]++;
    if (w4[c] >= SIZE){
        w4[c] = 0; // circular indexing
    }

    // Increment Index
    r4[c]++;
    if (r4[c] >= SIZE){
        r4[c] = 0; // circular indexing
    }

    return y + yLeft + yRightInitial + yRight;
}


void PingPongDelay::setDelayMS(float delayMS){
    
    float delaySec = delayMS / 1000.f;
    delaySamples = delaySec * Fs;
    delaySamples = juce::jmin(delaySamples,1157999);
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
    
    r4[0] = w4[0] - (delaySamples * 2);
    if (r4[0] < 0){
        r4[0] += SIZE;
    }
    r4[1] = w4[1] - (delaySamples * 2);
    if (r4[1] < 0){
        r4[1] += SIZE;
    }
}


void PingPongDelay::setLinearGains(float mInitialdBDrop, float mL2RdBDrop, float mR2LdBDrop)
{
    initialLeftDropdB = mInitialdBDrop;
    initialRightDropdB = mInitialdBDrop + mL2RdBDrop;
    pingPongDropdB = mL2RdBDrop + mR2LdBDrop;
    
    initialLeftDropLinear = juce::Decibels::decibelsToGain(initialLeftDropdB);
    initialRightDropLinear = juce::Decibels::decibelsToGain(initialRightDropdB);
    pingPongDropLinear = juce::Decibels::decibelsToGain(pingPongDropdB);
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
