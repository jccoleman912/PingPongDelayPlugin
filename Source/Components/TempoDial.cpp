/*
  ==============================================================================

    TempoDial.cpp
    Created: 7 Jun 2023 2:07:18pm
    Author:  Jackson Coleman

  ==============================================================================
*/

#include "TempoDial.h"

namespace juce {

void TempoDial::drawLinearSlider (Graphics& g, int x, int y, int width, int height,
                                   float sliderPos, float minSliderPos, float maxSliderPos,
                                   const Slider::SliderStyle style, Slider& slider) {
    

    rescaledDial = dialImage.rescaled(32, 32, Graphics::highResamplingQuality);
//    fader = rescaledFader.getClippedImage(dialCrop);
    
    juce::AffineTransform linearChange;
    
    g.drawImageTransformed(rescaledDial, linearChange.translated(sliderPos - 16.f, 0.f));


    
}

}
