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
public juce::Button::Listener
{
public:
    Coleman_HW2AudioProcessorEditor (Coleman_HW2AudioProcessor&);
    ~Coleman_HW2AudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    void sliderValueChanged(juce::Slider *slider) override;
    void buttonClicked (juce::Button *button) override;
    
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
    
    juce::Colour color = juce::Colours::darkseagreen;
    
    
    juce::Image bgImage;
    juce::Image spriteSheet;
    juce::Image rescaledSpriteSheet;
    
    juce::Image bypassOFF;
    juce::Image bypassON;
    
    juce::Image syncOFF;
    juce::Image syncON;
    
    juce::Image noteWHOLE;
    juce::Image noteHALF;
    juce::Image noteQUARTER;
    juce::Image note8TH;
    juce::Image note16TH;
    juce::Image note32ND;
    
    juce::Image tripletOFF;
    juce::Image tripletON;
    
    juce::Image dottedOFF;
    juce::Image dottedON;
    
    juce::Image leftFirstImage;
    juce::Image rightFirstImage;
    
    juce::Image bypassImage = bypassOFF;
    juce::Image syncImage = syncOFF;
    juce::Image noteImage = noteQUARTER;
    juce::Image tripletImage = tripletOFF;
    juce::Image dottedImage = dottedOFF;
    juce::Image leftOrRightImage = leftFirstImage;
    
    
    const juce::Rectangle<int> bypassOFFCrop {0, 0, 91, 41};
    const juce::Rectangle<int> bypassONCrop {93, 0, 91, 41};
    
    const juce::Rectangle<int> syncOFFCrop {0, 42, 91, 34};
    const juce::Rectangle<int> syncONCrop {93, 42, 91, 34};
    
    const juce::Rectangle<int> noteWHOLECrop {0, 76, 91, 61};
    const juce::Rectangle<int> noteHALFCrop {93, 76, 91, 61};
    const juce::Rectangle<int> noteQUARTERCrop {186, 76, 91, 61};
    const juce::Rectangle<int> note8THCrop {279, 76, 91, 61};
    const juce::Rectangle<int> note16THCrop {372, 76, 91, 61};
    const juce::Rectangle<int> note32NDCrop {465, 76, 91, 61};
    
    const juce::Rectangle<int> tripletOFFCrop {0, 138, 91, 34};
    const juce::Rectangle<int> tripletONCrop {93, 138, 91, 34};
    
    const juce::Rectangle<int> dottedOFFCrop {0, 173, 91, 34};
    const juce::Rectangle<int> dottedONCrop {93, 173, 91, 34};
    
    const juce::Rectangle<int> leftFirstCrop {0, 208, 91, 40};
    const juce::Rectangle<int> rightFirstCrop {93, 208, 91, 40};


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Coleman_HW2AudioProcessorEditor)
    
public:
    
    std::vector<std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment>> sliderAttachment;
    std::vector<std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment>> buttonAttachment;
    
};
