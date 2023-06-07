/*
  ==============================================================================

    GainFaders.cpp
    Created: 6 Jun 2023 1:16:25pm
    Author:  Jackson Coleman

  ==============================================================================
*/

#include "GainFaders.h"

namespace juce {

void GainFaders::drawLinearSlider (Graphics& g, int x, int y, int width, int height,
                                   float sliderPos, float minSliderPos, float maxSliderPos,
                                   const Slider::SliderStyle style, Slider& slider) {

    rescaledFader = faderImage.rescaled(64, 64, Graphics::highResamplingQuality);
    fader = rescaledFader.getClippedImage(faderCrop);
    
    juce::AffineTransform linearChange;
    
    g.drawImageTransformed(fader, linearChange.translated(((width/2.f) - 10.5f), (sliderPos - 19.5f)));
    
}

}
