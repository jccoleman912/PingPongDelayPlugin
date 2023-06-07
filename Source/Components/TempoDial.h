/*
  ==============================================================================

    TempoDial.h
    Created: 7 Jun 2023 2:07:18pm
    Author:  Jackson Coleman

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

namespace juce {

class TempoDial : public LookAndFeel_V4
{
    
    Image dialImage = juce::ImageCache::getFromMemory(BinaryData::TempoDial_png, BinaryData::TempoDial_pngSize);

    Image rescaledDial;
    Image dial;
    
    const Rectangle<int> dialCrop {16, 16, 32, 48};
    
    //    tripletOFF = rescaledSpriteSheet.getClippedImage(tripletOFFCrop);
    //    tripletON = rescaledSpriteSheet.getClippedImage(tripletONCrop);
    //
    
    void drawLinearSlider (juce::Graphics& g, int x, int y, int width, int height,
                           float sliderPos, float minSliderPos, float maxSliderPos,
                           const juce::Slider::SliderStyle style, juce::Slider& slider);
    
    
};

}
