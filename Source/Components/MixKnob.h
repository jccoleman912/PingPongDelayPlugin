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
    
    juce::Image rawKnob = juce::ImageCache::getFromMemory(BinaryData::FinalKnob100_jpg, BinaryData::FinalKnob100_jpgSize);
    
    juce::Image rescaledKnob;
    juce::Image knob;
    
    const juce::Rectangle<int> knobCrop {8, 8, 232, 232};
    const juce::Rectangle<int> tripletONCrop {93, 138, 91, 34};
    
//    tripletOFF = rescaledSpriteSheet.getClippedImage(tripletOFFCrop);
//    tripletON = rescaledSpriteSheet.getClippedImage(tripletONCrop);
//
    
    void drawRotarySlider (juce::Graphics& g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, juce::Slider& slider);
    
    
};
