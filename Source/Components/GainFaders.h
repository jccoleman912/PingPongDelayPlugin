/*
  ==============================================================================

    GainFaders.h
    Created: 6 Jun 2023 1:16:25pm
    Author:  Jackson Coleman

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

namespace juce {

class GainFaders : public LookAndFeel_V4
{
    
    Image faderImage = juce::ImageCache::getFromMemory(BinaryData::FaderPingPong_png, BinaryData::FaderPingPong_pngSize);
    
    Image rescaledFader;
    Image fader;
    
    const Rectangle<int> faderCrop {16, 16, 32, 48};
    
    //    tripletOFF = rescaledSpriteSheet.getClippedImage(tripletOFFCrop);
    //    tripletON = rescaledSpriteSheet.getClippedImage(tripletONCrop);
    //
    
    void drawLinearSlider (juce::Graphics& g, int x, int y, int width, int height,
                           float sliderPos, float minSliderPos, float maxSliderPos,
                           const juce::Slider::SliderStyle style, juce::Slider& slider);
    
    
    
};

}
