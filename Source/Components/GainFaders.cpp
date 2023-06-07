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
    
//
//        auto isThreeVal = (style == Slider::SliderStyle::ThreeValueVertical || style == Slider::SliderStyle::ThreeValueHorizontal);
//
//        auto trackWidth = jmin (6.0f, slider.isHorizontal() ? (float) height * 0.25f : (float) width * 0.25f);
//
//        Point<float> startPoint (slider.isHorizontal() ? (float) x : (float) x + (float) width * 0.5f,
//                                 slider.isHorizontal() ? (float) y + (float) height * 0.5f : (float) (height + y));
//
//        Point<float> endPoint (slider.isHorizontal() ? (float) (width + x) : startPoint.x,
//                               slider.isHorizontal() ? startPoint.y : (float) y);
//
//        Path backgroundTrack;
//        backgroundTrack.startNewSubPath (startPoint);
//        backgroundTrack.lineTo (endPoint);
//        g.setColour (slider.findColour (Slider::backgroundColourId));
//        g.strokePath (backgroundTrack, { trackWidth, PathStrokeType::curved, PathStrokeType::rounded });
//
//        Path valueTrack;
//        Point<float> minPoint, maxPoint, thumbPoint;
//
//
//        auto kx = slider.isHorizontal() ? sliderPos : ((float) x + (float) width * 0.5f);
//        auto ky = slider.isHorizontal() ? ((float) y + (float) height * 0.5f) : sliderPos;
//
//        minPoint = startPoint;
//        maxPoint = { kx, ky };
//
//
//        auto thumbWidth = getSliderThumbRadius (slider);
//
//        valueTrack.startNewSubPath (minPoint);
//        valueTrack.lineTo (isThreeVal ? thumbPoint : maxPoint);
//        g.setColour (slider.findColour (Slider::trackColourId));
//        g.strokePath (valueTrack, { trackWidth, PathStrokeType::curved, PathStrokeType::rounded });
//
//
//        g.setColour (slider.findColour (Slider::thumbColourId));
//        g.fillEllipse (Rectangle<float> (static_cast<float> (thumbWidth), static_cast<float> (thumbWidth)).withCentre (isThreeVal ? thumbPoint : maxPoint));
    
    rescaledFader = faderImage.rescaled(64, 64, Graphics::highResamplingQuality);
    fader = rescaledFader.getClippedImage(faderCrop);
    
    juce::AffineTransform linearChange;
    
    g.drawImageTransformed(fader, linearChange.translated(((width/2.f) - 10.5f), (sliderPos - 19.5f)));
    
//    linearChange.tran

    
}

}
