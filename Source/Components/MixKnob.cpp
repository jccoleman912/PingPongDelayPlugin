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
    
    knob = rawKnob.getClippedImage(knobCrop);
    
    rescaledKnob = knob.rescaled(58, 58);
    
    
    
    const float angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
    
    juce::AffineTransform rotator;
    
    g.drawImageTransformed(rescaledKnob, rotator.rotated(angle, (float)(rescaledKnob.getWidth()/2), (float)(rescaledKnob.getHeight()/2)));
    
}
