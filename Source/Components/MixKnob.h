/*
  ==============================================================================

    MixKnob.h
    Created: 17 May 2023 12:39:24pm
    Author:  Jackson Coleman

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class MixKnob : public juce::LookAndFeel_V4
{
    
    juce::Image knob = juce::ImageCache::getFromMemory(BinaryData::PingPongButtonSpriteSheet_jpg, BinaryData::PingPongButtonSpriteSheet_jpgSize);
    
    void drawRotarySlider (juce::Graphics& g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, juce::Slider& slider);
    
    
};
