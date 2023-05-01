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
    
    if(!leftFirst) {
        
        
        
        wet = delayBuffer5[r5[c]][c];
        
        y = (wet) * (initialLeftDropLinear);
        
        delayBuffer5[w5[1]][1] = x;
        
        
        left = delayBuffer6[r6[c]][c];
        
        yLeft = (left * pingPongDropLinear);
        
        delayBuffer6[w6[c]][c] = y + yLeft;
        
        
        
        rightInitial = delayBuffer7[r7[c]][c];
        
        yRightInitial = (rightInitial * initialRightDropLinear);
        
        delayBuffer7[w7[0]][0] = x;
        
        
        right = delayBuffer8[r8[c]][c];
        
        yRight = (right * pingPongDropLinear);
        
        delayBuffer8[w8[c]][c] = yRightInitial + yRight;
        

    
        
    } else {
        
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
        
    }
    
    
    
    

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
    
    // Increment Index
    w5[c]++;
    if (w5[c] >= SIZE){
        w5[c] = 0; // circular indexing
    }

    // Increment Index
    r5[c]++;
    if (r5[c] >= SIZE){
        r5[c] = 0; // circular indexing
    }
    
    // Increment Index
    w6[c]++;
    if (w6[c] >= SIZE){
        w6[c] = 0; // circular indexing
    }

    // Increment Index
    r6[c]++;
    if (r6[c] >= SIZE){
        r6[c] = 0; // circular indexing
    }
    
    // Increment Index
    w7[c]++;
    if (w7[c] >= SIZE){
        w7[c] = 0; // circular indexing
    }

    // Increment Index
    r7[c]++;
    if (r7[c] >= SIZE){
        r7[c] = 0; // circular indexing
    }
    
    // Increment Index
    w8[c]++;
    if (w8[c] >= SIZE){
        w8[c] = 0; // circular indexing
    }

    // Increment Index
    r8[c]++;
    if (r8[c] >= SIZE){
        r8[c] = 0; // circular indexing
    }
    
    return y + yLeft + yRightInitial + yRight;

}


//float PingPongDelay::processSampleRightFirst(float x, const int c) {
//    // one sample of delay
//    //int currentIndex = i[c];
//
//    wet = delayBuffer[r[c]][c];
//
//    float y = (wet) * (initialLeftDropLinear);
//
//    delayBuffer[w[1]][1] = x;
//
//
//    left = delayBuffer2[r2[c]][c];
//
//    float yLeft = (left * pingPongDropLinear);
//
//    delayBuffer2[w2[c]][c] = y + yLeft;
//
//
//
//    rightInitial = delayBuffer3[r3[c]][c];
//
//    float yRightInitial = (right * initialRightDropLinear);
//    
//    delayBuffer3[w3[0]][0] = x;
//
//
//    right = delayBuffer4[r4[c]][c];
//
//    float yRight = (right * pingPongDropLinear);
//
//    delayBuffer4[w4[c]][c] = yRightInitial + yRight;
//
//
//
//
//
//
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
//
//    // Increment Index
//    w2[c]++;
//    if (w2[c] >= SIZE){
//        w2[c] = 0; // circular indexing
//    }
//
//    // Increment Index
//    r2[c]++;
//    if (r2[c] >= SIZE){
//        r2[c] = 0; // circular indexing
//    }
//
//    // Increment Index
//    w3[c]++;
//    if (w3[c] >= SIZE){
//        w3[c] = 0; // circular indexing
//    }
//
//    // Increment Index
//    r3[c]++;
//    if (r3[c] >= SIZE){
//        r3[c] = 0; // circular indexing
//    }
//
//    // Increment Index
//    w4[c]++;
//    if (w4[c] >= SIZE){
//        w4[c] = 0; // circular indexing
//    }
//
//    // Increment Index
//    r4[c]++;
//    if (r4[c] >= SIZE){
//        r4[c] = 0; // circular indexing
//    }
//
//    return y + yLeft + yRightInitial + yRight;
//
//}


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
    
    r4[0] = w4[0] - (delaySamples * 2);
    if (r4[0] < 0){
        r4[0] += SIZE;
    }
    r4[1] = w4[1] - (delaySamples * 2);
    if (r4[1] < 0){
        r4[1] += SIZE;
    }
    
    r5[0] = w5[0] - delaySamples;
    if (r5[0] < 0){
        r5[0] += SIZE;
    }
    r5[1] = w5[1] - delaySamples;
    if (r5[1] < 0){
        r5[1] += SIZE;
    }
    
    r6[0] = w6[0] - (delaySamples * 2);
    if (r6[0] < 0){
        r6[0] += SIZE;
    }
    r6[1] = w6[1] - (delaySamples * 2);
    if (r6[1] < 0){
        r6[1] += SIZE;
    }
    
    r7[0] = w7[0] - (delaySamples * 2);
    if (r7[0] < 0){
        r7[0] += SIZE;
    }
    r7[1] = w7[1] - (delaySamples * 2);
    if (r7[1] < 0){
        r7[1] += SIZE;
    }
    
    r8[0] = w8[0] - (delaySamples * 2);
    if (r8[0] < 0){
        r8[0] += SIZE;
    }
    r8[1] = w8[1] - (delaySamples * 2);
    if (r8[1] < 0){
        r8[1] += SIZE;
    }
}

void PingPongDelay::setInitialdBDrop(float mInitialdBDrop) {
    initialdBDrop = mInitialdBDrop;
}

void PingPongDelay::setL2RdBDrop(float mL2RdBDrop) {
    l2RdBDrop = mL2RdBDrop;
}

void PingPongDelay::setR2LdBDrop(float mR2LdBDrop) {
    r2LdBDrop = mR2LdBDrop;
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

void PingPongDelay::setLeftFirst(bool mLeftFirst)
{
    leftFirst = mLeftFirst;
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
