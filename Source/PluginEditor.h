/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class Coleman_HW2AudioProcessorEditor  : public juce::AudioProcessorEditor,
public juce::Slider::Listener,
public juce::Button::Listener,
public juce::ComboBox::Listener
{
public:
    Coleman_HW2AudioProcessorEditor (Coleman_HW2AudioProcessor&);
    ~Coleman_HW2AudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    void sliderValueChanged(juce::Slider *slider) override;
    void buttonClicked (juce::Button *button) override;
    void comboBoxChanged (juce::ComboBox *comboBox) override;
    
private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Coleman_HW2AudioProcessor& audioProcessor;
    
    juce::Slider initialGainKnob;
    juce::Slider l2RGainKnob;
    juce::Slider r2LGainKnob;
    
    juce::Slider tempoSelector;
    
    juce::Slider mixKnob;
    
    juce::ToggleButton tripletButton;
    juce::ToggleButton dottedButton;
    juce::ToggleButton bypassButton;
    juce::ToggleButton syncButton;
    
    juce::ToggleButton leftFirstButton;
    juce::ToggleButton rightFirstButton;
    
    juce::ToggleButton wholeNoteButton;
    juce::ToggleButton halfNoteButton;
    juce::ToggleButton quarterNoteButton;
    juce::ToggleButton eighthNoteButton;
    juce::ToggleButton sixteenthNoteButton;
    juce::ToggleButton thirtysecondNoteButton;
    
    juce::ComboBox noteSelector;
    
    juce::Colour color = juce::Colours::darkseagreen;
    
    
//    juce::ScaledImage bgImage;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Coleman_HW2AudioProcessorEditor)
    
public:
    
    std::vector<std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment>> sliderAttachment;
    std::vector<std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment>> buttonAttachment;
    std::vector<std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment>> comboBoxAttachment;
    
};
