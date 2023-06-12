/*
  ==============================================================================

    CustomTextBox.cpp
    Created: 12 Jun 2023 1:34:45pm
    Author:  Jackson Coleman

  ==============================================================================
*/

#include "CustomTextBox.h"

namespace juce {

void CustomTextBox::fillTextEditorBackground (Graphics& g, int width, int height, TextEditor& textEditor)
{
//    if (dynamic_cast<AlertWindow*> (textEditor.getParentComponent()) != nullptr)
//    {
//        g.setColour (textEditor.findColour (TextEditor::backgroundColourId));
//        g.fillRect (0, 0, width, height);
//
//        g.setColour (textEditor.findColour (TextEditor::outlineColourId));
//        g.drawHorizontalLine (height - 1, 0.0f, static_cast<float> (width));
//    }
//    else
//    {
//        LookAndFeel_V2::fillTextEditorBackground (g, width, height, textEditor);
//    }
}

void CustomTextBox::drawTextEditorOutline (Graphics& g, int width, int height, TextEditor& textEditor)
{
//    if (dynamic_cast<AlertWindow*> (textEditor.getParentComponent()) == nullptr)
//    {
//        if (textEditor.isEnabled())
//        {
//            if (textEditor.hasKeyboardFocus (true) && ! textEditor.isReadOnly())
//            {
//                g.setColour (textEditor.findColour (TextEditor::focusedOutlineColourId));
//                g.drawRect (0, 0, width, height, 2);
//            }
//            else
//            {
//                g.setColour (textEditor.findColour (TextEditor::outlineColourId));
//                g.drawRect (0, 0, width, height);
//            }
//        }
//    }
}
    
}

