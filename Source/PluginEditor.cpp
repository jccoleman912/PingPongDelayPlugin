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
    setSize (625, 625);
    
    
    bgImage = juce::ImageCache::getFromMemory(BinaryData::FullScalePingpongDelayUI_jpg, BinaryData::FullScalePingpongDelayUI_jpgSize);
    
    bgImage = bgImage.rescaled(625, 625, juce::Graphics::highResamplingQuality);
    
    
    //
    // Initial Gain Knob
    //
    
//    initialGainKnob.addListener(this);
    // Specify location in window (xPos,yPos,width,height)
    initialGainKnob.setBounds(250,25,100,100);
    initialGainKnob.setRange(-60.0,24.0,0.1); // (min, max, interval)
    initialGainKnob.setValue(-9.0); // initial value
    initialGainKnob.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    initialGainKnob.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 75, 25);
    initialGainKnob.setName("Initial dB Drop");
    initialGainKnob.getTitle();
    addAndMakeVisible(initialGainKnob);
    
    
    //
    // Left to Right Gain Knob
    //
    
//    l2RGainKnob.addListener(this);
    // Specify location in window (xPos,yPos,width,height)
    l2RGainKnob.setBounds(75,170,100,100);
    l2RGainKnob.setRange(-60.0,24.0,0.1); // (min, max, interval)
    l2RGainKnob.setValue(0.0); // initial value
    l2RGainKnob.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    l2RGainKnob.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 75, 25);
    l2RGainKnob.setName("Left to Right dB Drop");
    l2RGainKnob.getTitle();
    addAndMakeVisible(l2RGainKnob);
    
    
    //
    // Right to Left Gain Knob
    //
    
//    r2LGainKnob.addListener(this);
    // Specify location in window (xPos,yPos,width,height)
    r2LGainKnob.setBounds(425,170,100,100);
    r2LGainKnob.setRange(-60.0,24.0,0.1); // (min, max, interval)
    r2LGainKnob.setValue(-6.0); // initial value
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
    tempoSelector.setRange(40.0,240.0,0.1); // (min, max, interval)
    tempoSelector.setValue(120.0); // initial value
    tempoSelector.setSliderStyle(juce::Slider::SliderStyle::LinearHorizontal);
    tempoSelector.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 75, 25);
    tempoSelector.setName("Tempo");
    tempoSelector.getTitle();
    addAndMakeVisible(tempoSelector);
    
    
    //
    // Mix Knob
    //
    
    mixKnob.addListener(this);
    // Specify location in window (xPos,yPos,width,height)
    mixKnob.setBounds(340,320,160,100);
    mixKnob.setRange(0.f,100.f,0.1); // (min, max, interval)
    mixKnob.setValue(100.f); // initial value
    mixKnob.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    mixKnob.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 75, 25);
    mixKnob.setName("Mix");
    mixKnob.getTitle();
    addAndMakeVisible(mixKnob);
        
    
    
    //
    // Triplet Toggle
    //
    
    tripletButton.addListener(this);
    tripletButton.setBounds(15,434,100,40);
    tripletButton.setButtonText("Triplet");
    tripletButton.setToggleState(false, juce::dontSendNotification);
    addAndMakeVisible(tripletButton);
    
    //
    // Dotted Toggle
    //
    
    dottedButton.addListener(this);
    dottedButton.setBounds(15,405,100,40);
    dottedButton.setButtonText("Dotted");
    dottedButton.setToggleState(false, juce::dontSendNotification);
    addAndMakeVisible(dottedButton);
    
    
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
    // Note Selection Buttons
    //
    
    wholeNoteButton.addListener(this);
    wholeNoteButton.setBounds(15,475,30,30);
    wholeNoteButton.setButtonText("Whole");
    wholeNoteButton.setToggleState(false, juce::dontSendNotification);
    wholeNoteButton.setRadioGroupId(2);
    addAndMakeVisible(wholeNoteButton);
    
    halfNoteButton.addListener(this);
    halfNoteButton.setBounds(50,475,30,30);
    halfNoteButton.setButtonText("Half");
    halfNoteButton.setToggleState(false, juce::dontSendNotification);
    halfNoteButton.setRadioGroupId(2);
    addAndMakeVisible(halfNoteButton);
    
    quarterNoteButton.addListener(this);
    quarterNoteButton.setBounds(85,475,30,30);
    quarterNoteButton.setButtonText("Quarter");
    quarterNoteButton.setToggleState(true, juce::dontSendNotification);
    quarterNoteButton.setRadioGroupId(2);
    addAndMakeVisible(quarterNoteButton);
    
    eighthNoteButton.addListener(this);
    eighthNoteButton.setBounds(15,520,30,30);
    eighthNoteButton.setButtonText("8th");
    eighthNoteButton.setToggleState(false, juce::dontSendNotification);
    eighthNoteButton.setRadioGroupId(2);
    addAndMakeVisible(eighthNoteButton);
    
    sixteenthNoteButton.addListener(this);
    sixteenthNoteButton.setBounds(50,520,30,30);
    sixteenthNoteButton.setButtonText("16th");
    sixteenthNoteButton.setToggleState(false, juce::dontSendNotification);
    sixteenthNoteButton.setRadioGroupId(2);
    addAndMakeVisible(sixteenthNoteButton);
    
    thirtysecondNoteButton.addListener(this);
    thirtysecondNoteButton.setBounds(85,520,30,30);
    thirtysecondNoteButton.setButtonText("32nd");
    thirtysecondNoteButton.setToggleState(false, juce::dontSendNotification);
    thirtysecondNoteButton.setRadioGroupId(2);
    addAndMakeVisible(thirtysecondNoteButton);
    
    
    
    sliderAttachment.emplace_back(new juce::AudioProcessorValueTreeState::SliderAttachment(audioProcessor.state, "initialDropValue", initialGainKnob));
    sliderAttachment.emplace_back(new juce::AudioProcessorValueTreeState::SliderAttachment(audioProcessor.state, "l2RDropValue", l2RGainKnob));
    sliderAttachment.emplace_back(new juce::AudioProcessorValueTreeState::SliderAttachment(audioProcessor.state, "r2LDropValue", r2LGainKnob));
    sliderAttachment.emplace_back(new juce::AudioProcessorValueTreeState::SliderAttachment(audioProcessor.state, "tempoValue", tempoSelector));
    sliderAttachment.emplace_back(new juce::AudioProcessorValueTreeState::SliderAttachment(audioProcessor.state, "mixValue", mixKnob));
    
    buttonAttachment.emplace_back(new juce::AudioProcessorValueTreeState::ButtonAttachment(audioProcessor.state, "tripletValue", tripletButton));
    buttonAttachment.emplace_back(new juce::AudioProcessorValueTreeState::ButtonAttachment(audioProcessor.state, "dottedValue", dottedButton));
    buttonAttachment.emplace_back(new juce::AudioProcessorValueTreeState::ButtonAttachment(audioProcessor.state, "bypassValue", bypassButton));
    buttonAttachment.emplace_back(new juce::AudioProcessorValueTreeState::ButtonAttachment(audioProcessor.state, "syncValue", syncButton));
    buttonAttachment.emplace_back(new juce::AudioProcessorValueTreeState::ButtonAttachment(audioProcessor.state, "leftFirstValue", leftFirstButton));
    buttonAttachment.emplace_back(new juce::AudioProcessorValueTreeState::ButtonAttachment(audioProcessor.state, "rightFirstValue", rightFirstButton));
    buttonAttachment.emplace_back(new juce::AudioProcessorValueTreeState::ButtonAttachment(audioProcessor.state, "wholeNoteValue", wholeNoteButton));
    buttonAttachment.emplace_back(new juce::AudioProcessorValueTreeState::ButtonAttachment(audioProcessor.state, "halfNoteValue", halfNoteButton));
    buttonAttachment.emplace_back(new juce::AudioProcessorValueTreeState::ButtonAttachment(audioProcessor.state, "quarterNoteValue", quarterNoteButton));
    buttonAttachment.emplace_back(new juce::AudioProcessorValueTreeState::ButtonAttachment(audioProcessor.state, "8thNoteValue", eighthNoteButton));
    buttonAttachment.emplace_back(new juce::AudioProcessorValueTreeState::ButtonAttachment(audioProcessor.state, "16thNoteValue", sixteenthNoteButton));
    buttonAttachment.emplace_back(new juce::AudioProcessorValueTreeState::ButtonAttachment(audioProcessor.state, "32ndNoteValue", thirtysecondNoteButton));

    
    
    
//    comboBoxAttachment.emplace_back(new juce::AudioProcessorValueTreeState::ComboBoxAttachment(audioProcessor.state, "noteValue", noteSelector));

}

Coleman_HW2AudioProcessorEditor::~Coleman_HW2AudioProcessorEditor()
{
}

//==============================================================================
void Coleman_HW2AudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
  
    g.fillAll (color);

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    
    g.drawImageAt(bgImage, 0, 0);

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
//        audioProcessor.initialGainDropdB = slider->getValue();
    }
    if (slider == &l2RGainKnob){
//        audioProcessor.l2RGainDropdB = slider->getValue();
    }
    if (slider == &r2LGainKnob){
//        audioProcessor.r2LGainDropdB = slider->getValue();
    }
    if (slider == &tempoSelector) {
//        audioProcessor.tempo = slider->getValue();
    }
}

void Coleman_HW2AudioProcessorEditor::buttonClicked(juce::Button *button){
    if (button == &bypassButton){
        bool bypassState = bypassButton.getToggleState();
        if(bypassState) {
            color = juce::Colours::slateblue;
            repaint();
        } else {
            color = juce::Colours::darkseagreen;
            repaint();
        }
    }
    if (button == &tripletButton){
        bool tripletState = tripletButton.getToggleState();
        if(tripletState) {
            color = juce::Colours::rosybrown;
            repaint();
        } else {
            color = juce::Colours::darkseagreen;
            repaint();
        }
    }
    if (button == &syncButton) {
        bool syncState = syncButton.getToggleState();
        if(syncState) {
            color = juce::Colours::darksalmon;
            repaint();
        } else {
            color = juce::Colours::darkseagreen;
            repaint();
        }
    }
    if (button == &dottedButton) {
        bool dottedState = dottedButton.getToggleState();
        if(dottedState) {
            color = juce::Colour (0xff008840);
            repaint();
        } else {
            color = juce::Colours::darkseagreen;
            repaint();
        }
    }
    if (button == &leftFirstButton) {
        bool dottedState = leftFirstButton.getToggleState();
        if(!dottedState) {
            color = juce::Colours::moccasin;
            repaint();
        } else {
            color = juce::Colours::darkseagreen;
            repaint();
        }
    }

}

void Coleman_HW2AudioProcessorEditor::comboBoxChanged(juce::ComboBox *comboBox){
    
    if (comboBox == &noteSelector){
        if (noteSelector.getSelectedId() == 1){
//            audioProcessor.noteType = "whole";
        }
        if (noteSelector.getSelectedId() == 2){
//            audioProcessor.noteType = "half";
        }
        if (noteSelector.getSelectedId() == 3){
//            audioProcessor.noteType = "quarter";
        }
        if (noteSelector.getSelectedId() == 4){
//            audioProcessor.noteType = "8th";
        }
        if (noteSelector.getSelectedId() == 5){
//            audioProcessor.noteType = "16th";
        }
        if (noteSelector.getSelectedId() == 6){
//            audioProcessor.noteType = "32nd";
        }
    }
    
}
