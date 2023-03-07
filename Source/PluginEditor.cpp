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
    setSize (600, 600);
    
    //
    // Initial Gain Knob
    //
    
    initialGainKnob.addListener(this);
    // Specify location in window (xPos,yPos,width,height)
    initialGainKnob.setBounds(250,25,100,100);
    initialGainKnob.setValue(0.0); // initial value
    initialGainKnob.setRange(-48.0,12.0,0.1); // (min, max, interval)
    initialGainKnob.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    initialGainKnob.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 75, 25);
    initialGainKnob.setName("Initial dB Drop");
    initialGainKnob.getTitle();
    addAndMakeVisible(initialGainKnob);
    
    
    //
    // Left to Right Gain Knob
    //
    
    l2RGainKnob.addListener(this);
    // Specify location in window (xPos,yPos,width,height)
    l2RGainKnob.setBounds(50,150,100,100);
    l2RGainKnob.setValue(0.0); // initial value
    l2RGainKnob.setRange(-48.0,12.0,0.1); // (min, max, interval)
    l2RGainKnob.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    l2RGainKnob.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 75, 25);
    l2RGainKnob.setName("Left to Right dB Drop");
    l2RGainKnob.getTitle();
    addAndMakeVisible(l2RGainKnob);
    
    
    //
    // Right to Left Gain Knob
    //
    
    r2LGainKnob.addListener(this);
    // Specify location in window (xPos,yPos,width,height)
    r2LGainKnob.setBounds(450,150,100,100);
    r2LGainKnob.setValue(0.0); // initial value
    r2LGainKnob.setRange(-48.0,12.0,0.1); // (min, max, interval)
    r2LGainKnob.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    r2LGainKnob.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 75, 25);
    r2LGainKnob.setName("Right to Left dB Drop");
    r2LGainKnob.getTitle();
    addAndMakeVisible(r2LGainKnob);
    
    
    //
    // Right to Left Toggle
    //
    
    
    
    
    
    //
    // Triplet Toggle
    //
    
    
    
    //
    // Bypass Toggle
    //
    
    
//
//    // Combo Box
//    noteSelector.addListener(this);
//    noteSelector.setBounds(450, 10, 100, 50);
//    noteSelector.addItem("Whole",1);
//    noteSelector.addItem("Half",2);
//    noteSelector.addItem("Quarter",3);
//    noteSelector.addItem("8th",4);
//    noteSelector.addItem("16th",5);
//    noteSelector.setText("Select note...");
//    addAndMakeVisible(noteSelector);
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
    g.drawFittedText ("Ping Pong Delay", getLocalBounds(), juce::Justification::centred, 1);
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
        if (noteSelector.getSelectedId() == 5){
            // Do something for 8th note
        }
    }
    
}
