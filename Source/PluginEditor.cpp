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
    initialGainKnob.setRange(-60.0,12.0,0.1); // (min, max, interval)
    initialGainKnob.setValue(-10.0); // initial value
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
    l2RGainKnob.setBounds(75,170,100,100);
    l2RGainKnob.setRange(-60.0,12.0,0.1); // (min, max, interval)
    l2RGainKnob.setValue(-4.0); // initial value
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
    r2LGainKnob.setBounds(425,170,100,100);
    r2LGainKnob.setRange(-60.0,12.0,0.1); // (min, max, interval)
    r2LGainKnob.setValue(-4.0); // initial value
    r2LGainKnob.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    r2LGainKnob.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 75, 25);
    r2LGainKnob.setName("Right to Left dB Drop");
    r2LGainKnob.getTitle();
    addAndMakeVisible(r2LGainKnob);
    
    
    //
    // Tempo Slider
    //
    
    tempoSelector.addListener(this);
    // Specify location in window (xPos,yPos,width,height)
    tempoSelector.setBounds(425,450,160,100);
    tempoSelector.setRange(20.0,240.0,0.1); // (min, max, interval)
    tempoSelector.setValue(120.0); // initial value
    tempoSelector.setSliderStyle(juce::Slider::SliderStyle::LinearHorizontal);
    tempoSelector.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 75, 25);
    tempoSelector.setName("Tempo");
    tempoSelector.getTitle();
    addAndMakeVisible(tempoSelector);
        
    
    
    //
    // Triplet Toggle
    //
    
    tripletButton.addListener(this);
    tripletButton.setBounds(15,420,100,40);
    tripletButton.setButtonText("Triplet");
    tripletButton.setToggleState(false, juce::dontSendNotification);
    addAndMakeVisible(tripletButton);
    
    
    //
    // Bypass Toggle
    //
    
    bypassButton.addListener(this);
    bypassButton.setBounds(15,15,100,40);
    bypassButton.setButtonText("Bypass");
    bypassButton.setToggleState(false, juce::dontSendNotification);
    addAndMakeVisible(bypassButton);
    
    
    //
    // Sync Toggle
    //
    
    syncButton.addListener(this);
    syncButton.setBounds(485,420,100,40);
    syncButton.setButtonText("Sync");
    syncButton.setToggleState(false, juce::dontSendNotification);
    addAndMakeVisible(syncButton);
    
    
    //
    // L/R Selection Buttons
    //
    
    leftFirstButton.addListener(this);
    leftFirstButton.setBounds(250,465,100,40);
    leftFirstButton.setButtonText("Left");
    leftFirstButton.setToggleState(true, juce::dontSendNotification);
    leftFirstButton.setRadioGroupId(1);
    addAndMakeVisible(leftFirstButton);
    
    rightFirstButton.addListener(this);
    rightFirstButton.setBounds(250,490,100,40);
    rightFirstButton.setButtonText("Right");
    rightFirstButton.setToggleState(false, juce::dontSendNotification);
    rightFirstButton.setRadioGroupId(1);
    addAndMakeVisible(rightFirstButton);
    
    

    //
    // Note Selection Combo Box
    //
    
    // Combo Box
    noteSelector.addListener(this);
    noteSelector.setBounds(15, 475, 150, 50);
    noteSelector.addItem("Whole",1);
    noteSelector.addItem("Half",2);
    noteSelector.addItem("Quarter",3);
    noteSelector.addItem("8th",4);
    noteSelector.addItem("16th",5);
    noteSelector.addItem("32nd",6);
    noteSelector.addItem("64th",7);
    noteSelector.setText("Select note...");
    addAndMakeVisible(noteSelector);

}

Coleman_HW2AudioProcessorEditor::~Coleman_HW2AudioProcessorEditor()
{
}

//==============================================================================
void Coleman_HW2AudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::darkseagreen);

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
        audioProcessor.initialGainDropdB = slider->getValue();
    }
    if (slider == &l2RGainKnob){
        audioProcessor.l2RGainDropdB = slider->getValue();
    }
    if (slider == &r2LGainKnob){
        audioProcessor.r2LGainDropdB = slider->getValue();
    }
    if (slider == &tempoSelector) {
        audioProcessor.tempo = slider->getValue();
    }
}

void Coleman_HW2AudioProcessorEditor::buttonClicked(juce::Button *button){
    if (button == &bypassButton){
        audioProcessor.isBypassed = bypassButton.getToggleState();
    }
    if (button == &tripletButton){
        audioProcessor.isTriplet = tripletButton.getToggleState();
    }
    if (button == &syncButton) {
        audioProcessor.isSynced = syncButton.getToggleState();
    }
    if (button == &rightFirstButton) {
        audioProcessor.leftFirst = false;
    }
    if (button == &leftFirstButton) {
        audioProcessor.leftFirst = true;
    }
}

void Coleman_HW2AudioProcessorEditor::comboBoxChanged(juce::ComboBox *comboBox){
    
    if (comboBox == &noteSelector){
        if (noteSelector.getSelectedId() == 1){
            audioProcessor.noteMultiplier = 4.f;
        }
        if (noteSelector.getSelectedId() == 2){
            audioProcessor.noteMultiplier = 2.f;
        }
        if (noteSelector.getSelectedId() == 3){
            audioProcessor.noteMultiplier = 1.f;
        }
        if (noteSelector.getSelectedId() == 4){
            audioProcessor.noteMultiplier = 0.5f;
        }
        if (noteSelector.getSelectedId() == 5){
            audioProcessor.noteMultiplier = 0.25f;
        }
        if (noteSelector.getSelectedId() == 6){
            audioProcessor.noteMultiplier = 0.125f;
        }
        if (noteSelector.getSelectedId() == 7){
            audioProcessor.noteMultiplier = 0.0625f;
        }
    }
    
}
