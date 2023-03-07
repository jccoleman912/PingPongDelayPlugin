/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Coleman_HW2AudioProcessorEditor::Coleman_HW2AudioProcessorEditor (Coleman_HW2AudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
}

Coleman_HW2AudioProcessorEditor::~Coleman_HW2AudioProcessorEditor()
{
}

//==============================================================================
void Coleman_HW2AudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void Coleman_HW2AudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}


void Coleman_HW2AudioProcessorEditor::sliderValueChanged(juce::Slider * slider)
{
    // This is how we check which slider was moved
    if (slider == &initialGainKnob){
        auto value = slider->getValue();
    }
    if (slider == &l2RGainKnob){
    }
    if (slider == &r2LGainKnob){
    }
}

void Coleman_HW2AudioProcessorEditor::buttonClicked(juce::Button *button){
    if (button == &bypassButton){
    }
    if (button == &leftOrRight){
    }
    if (button == &triplet){
    }
}

void Coleman_HW2AudioProcessorEditor::comboBoxChanged(juce::ComboBox *comboBox){
    
    if (comboBox == &noteSelector){
        if (noteSelector.getSelectedId() == 1){
            // Do something for whole note
        }
        if (noteSelector.getSelectedId() == 2){
            // Do something for half note
        }
        if (noteSelector.getSelectedId() == 3){
            // Do something for quarter note
        }
        if (noteSelector.getSelectedId() == 4){
            // Do something for 8th note
        }
    }
    
}
