/*
  ==============================================================================

    PingPongDelay.cpp
    Created: 6 Mar 2023 8:56:00pm
    Author:  Jackson Coleman

  ==============================================================================
*/

#include "PingPongDelay.h"

float PingPongDelay::processSample(float x, const int c){
   
    if(leftDelayFirst) {
        
        yLeft = leftBuffer[read];
        
        yRight = rightBuffer[read2];
        
        rightBuffer[write2] = (leftBuffer[read2] * l2RDropLinear);
        
        leftBuffer[write] = (x * initialDropLinear) + (rightBuffer[read] * r2LDropLinear);
        
        // Increment Index
        if(c == 0) {
            write++;
            if (write >= SIZE){
                write = 0; // circular indexing
            }
            
            // Increment Index
            read++;
            if (read >= SIZE){
                read = 0; // circular indexing
            }
        }
        
        // Increment Index
        if(c == 1) {
            write2++;
            if (write2 >= SIZE){
                write2 = 0; // circular indexing
            }
            
            // Increment Index
            read2++;
            if (read2 >= SIZE){
                read2 = 0; // circular indexing
            }
        }
        
        if(c == 0) {
            output = yLeft;
        }
        if(c == 1) {
            output = yRight;
        }
    }
    else {
        
        yRight = rightBuffer[read];
        
        yLeft = leftBuffer[read2];
        
        leftBuffer[write2] = (rightBuffer[read2] * l2RDropLinear);
        
        rightBuffer[write] = (x * initialDropLinear) + (leftBuffer[read] * r2LDropLinear);
        
        // Increment Index
        if(c == 1) {
            write++;
            if (write >= SIZE){
                write = 0; // circular indexing
            }
            
            // Increment Index
            read++;
            if (read >= SIZE){
                read = 0; // circular indexing
            }
        }
        
        // Increment Index
        if(c == 0) {
            write2++;
            if (write2 >= SIZE){
                write2 = 0; // circular indexing
            }
            
            // Increment Index
            read2++;
            if (read2 >= SIZE){
                read2 = 0; // circular indexing
            }
        }
        
        if(c == 0) {
            output = yLeft;
        }
        if(c == 1) {
            output = yRight;
        }
    }
        return output;
}


/*
 Setting the delay in MS, called in PluginProcessor.cpp
 */
void PingPongDelay::setDelayMS(float delayMS){
    
    float delaySec = delayMS / 1000.f;
    delaySamples = delaySec * Fs;
    delaySamples = juce::jmin(delaySamples,1157999);

    read = write - delaySamples;
    
    if (read < 0){
        read += SIZE;
    }
    
    read2 = write2 - delaySamples;
    if (read2 < 0){
        read2 += SIZE;
    }
}


/*
 Setting the L/R first delay, called in PluginProcessor.cpp
 */
void PingPongDelay::setLeftOrRight(bool leftFirst) {
    leftDelayFirst = leftFirst;
}


/*
 Setting the linear gain changes, called in PluginProcessor.cpp
 */
void PingPongDelay::setInitialDropLinear(float initialLinear) {
    if(initialLinear > 0.0012f) {
        initialDropLinear = initialLinear;
    } else {
        initialDropLinear = 0.f;
    }
}

void PingPongDelay::setL2RDropLinear(float l2RLinear) {
    if(l2RLinear > 0.0012f) {
        l2RDropLinear = l2RLinear;
    } else {
        l2RDropLinear = 0.f;
    }
}

void PingPongDelay::setR2LDropLinear(float r2LLinear) {
    if(r2LLinear > 0.0012f) {
        r2LDropLinear = r2LLinear;
    } else {
        r2LDropLinear = 0.f;
    }
}


/*
 A method that clears the opposite side's arrays when the L/R switch is flipped.
 */
void PingPongDelay::clearBuffers() {
    std::fill(leftBuffer, leftBuffer + SIZE, 0);
    std::fill(rightBuffer, rightBuffer + SIZE, 0);
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

float PingPongDelay::getSampleRate() {
    return Fs;
}

void PingPongDelay::processInPlace(float * buffer, const int numSamples, const int c){
    
    for (int n = 0 ; n < numSamples; ++n){
        float x = (*buffer); // de-reference current value
        
        x = processSample(x, c);
        
        *buffer = x; // over-write current value
        
        ++buffer; // move pointer to the next sample
    }
}
