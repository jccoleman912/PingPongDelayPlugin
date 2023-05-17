/*
  ==============================================================================

    MixKnob.cpp
    Created: 17 May 2023 12:39:24pm
    Author:  Jackson Coleman

  ==============================================================================
*/

#include "MixKnob.h"

void MixKnob::drawRotarySlider (juce::Graphics& g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, juce::Slider& slider)
{
    
    const float angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
    
    juce::AffineTransform rotator;
    
    g.drawImageTransformed(knob, rotator.rotated(angle, (float)(knob.getWidth()/2), (float)(knob.getHeight()/2)));
    
}
