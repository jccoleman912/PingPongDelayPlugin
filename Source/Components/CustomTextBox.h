/*
  ==============================================================================

    CustomTextBox.h
    Created: 12 Jun 2023 1:34:45pm
    Author:  Jackson Coleman

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

namespace juce {

class CustomTextBox : public LookAndFeel_V4
{

    Font textFont;
    
    void fillTextEditorBackground (Graphics&, int width, int height, TextEditor&) override;
    
    void drawTextEditorOutline (Graphics&, int width, int height, TextEditor&) override;
    
    
};

}

