/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Components/MixKnob.h"

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
    
    int startingY[200];
    
    juce::Slider initialGainKnob;
    juce::Slider l2RGainKnob;
    juce::Slider r2LGainKnob;
    
    juce::Slider tempoSelector;
    
    juce::Slider mixKnob;
    
    MixKnob mixKnobLookAndFeel;
    
    juce::Slider smoothKnob;
    
    juce::ToggleButton wholeNoteButton;
    juce::ToggleButton halfNoteButton;
    juce::ToggleButton quarterNoteButton;
    juce::ToggleButton eighthNoteButton;
    juce::ToggleButton sixteenthNoteButton;
    juce::ToggleButton thirtysecondNoteButton;
    
    juce::ToggleButton tripletButton;
    juce::ToggleButton dottedButton;
    juce::ToggleButton bypassButton;
    juce::ToggleButton syncButton;
    
    juce::ToggleButton leftFirstButton;
    juce::ToggleButton rightFirstButton;
    
    juce::ToggleButton smoothButton;
    
    juce::Colour color = juce::Colours::darkseagreen;
    
    
    juce::Image bgImage;
    juce::Image spriteSheet;
    juce::Image rescaledSpriteSheet;
    juce::Image spriteSheetBottomNotes;
    juce::Image rescaledSpriteSheetBottomNoteSelector;
    
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
    const juce::Rectangle<int> note8THCrop {0, 76, 91, 61};
    const juce::Rectangle<int> note16THCrop {93, 76, 91, 61};
    const juce::Rectangle<int> note32NDCrop {186, 76, 91, 61};
    
    const juce::Rectangle<int> tripletOFFCrop {0, 138, 91, 34};
    const juce::Rectangle<int> tripletONCrop {93, 138, 91, 34};
    
    const juce::Rectangle<int> dottedOFFCrop {0, 173, 91, 34};
    const juce::Rectangle<int> dottedONCrop {93, 173, 91, 34};
    
    const juce::Rectangle<int> leftFirstCrop {0, 208, 91, 40};
    const juce::Rectangle<int> rightFirstCrop {93, 208, 91, 40};
    
    const juce::Rectangle<int> knobSpriteSheetCrop {0, 0, 248, 50000};
    
    
    juce::Image knobPosition;
    
    // Knob images 0 - 9.5
    juce::Image mix0;
    juce::Image mix0x5;
    juce::Image mix1;
    juce::Image mix1x5;
    juce::Image mix2;
    juce::Image mix2x5;
    juce::Image mix3;
    juce::Image mix3x5;
    juce::Image mix4;
    juce::Image mix4x5;
    juce::Image mix5;
    juce::Image mix5x5;
    juce::Image mix6;
    juce::Image mix6x5;
    juce::Image mix7;
    juce::Image mix7x5;
    juce::Image mix8;
    juce::Image mix8x5;
    juce::Image mix9;
    juce::Image mix9x5;

    // Knob images 10 - 19.5
    juce::Image mix10;
    juce::Image mix10x5;
    juce::Image mix11;
    juce::Image mix11x5;
    juce::Image mix12;
    juce::Image mix12x5;
    juce::Image mix13;
    juce::Image mix13x5;
    juce::Image mix14;
    juce::Image mix14x5;
    juce::Image mix15;
    juce::Image mix15x5;
    juce::Image mix16;
    juce::Image mix16x5;
    juce::Image mix17;
    juce::Image mix17x5;
    juce::Image mix18;
    juce::Image mix18x5;
    juce::Image mix19;
    juce::Image mix19x5;
    
    // Knob images 20 - 29.5
    juce::Image mix20;
    juce::Image mix20x5;
    juce::Image mix21;
    juce::Image mix21x5;
    juce::Image mix22;
    juce::Image mix22x5;
    juce::Image mix23;
    juce::Image mix23x5;
    juce::Image mix24;
    juce::Image mix24x5;
    juce::Image mix25;
    juce::Image mix25x5;
    juce::Image mix26;
    juce::Image mix26x5;
    juce::Image mix27;
    juce::Image mix27x5;
    juce::Image mix28;
    juce::Image mix28x5;
    juce::Image mix29;
    juce::Image mix29x5;
    
    // Knob images 30 - 39.5
    juce::Image mix30;
    juce::Image mix30x5;
    juce::Image mix31;
    juce::Image mix31x5;
    juce::Image mix32;
    juce::Image mix32x5;
    juce::Image mix33;
    juce::Image mix33x5;
    juce::Image mix34;
    juce::Image mix34x5;
    juce::Image mix35;
    juce::Image mix35x5;
    juce::Image mix36;
    juce::Image mix36x5;
    juce::Image mix37;
    juce::Image mix37x5;
    juce::Image mix38;
    juce::Image mix38x5;
    juce::Image mix39;
    juce::Image mix39x5;
    
    // Knob images 40 - 49.5
    juce::Image mix40;
    juce::Image mix40x5;
    juce::Image mix41;
    juce::Image mix41x5;
    juce::Image mix42;
    juce::Image mix42x5;
    juce::Image mix43;
    juce::Image mix43x5;
    juce::Image mix44;
    juce::Image mix44x5;
    juce::Image mix45;
    juce::Image mix45x5;
    juce::Image mix46;
    juce::Image mix46x5;
    juce::Image mix47;
    juce::Image mix47x5;
    juce::Image mix48;
    juce::Image mix48x5;
    juce::Image mix49;
    juce::Image mix49x5;

    // Knob images 50 - 59.5
    juce::Image mix50;
    juce::Image mix50x5;
    juce::Image mix51;
    juce::Image mix51x5;
    juce::Image mix52;
    juce::Image mix52x5;
    juce::Image mix53;
    juce::Image mix53x5;
    juce::Image mix54;
    juce::Image mix54x5;
    juce::Image mix55;
    juce::Image mix55x5;
    juce::Image mix56;
    juce::Image mix56x5;
    juce::Image mix57;
    juce::Image mix57x5;
    juce::Image mix58;
    juce::Image mix58x5;
    juce::Image mix59;
    juce::Image mix59x5;
    
    // Knob images 60 - 69.5
    juce::Image mix60;
    juce::Image mix60x5;
    juce::Image mix61;
    juce::Image mix61x5;
    juce::Image mix62;
    juce::Image mix62x5;
    juce::Image mix63;
    juce::Image mix63x5;
    juce::Image mix64;
    juce::Image mix64x5;
    juce::Image mix65;
    juce::Image mix65x5;
    juce::Image mix66;
    juce::Image mix66x5;
    juce::Image mix67;
    juce::Image mix67x5;
    juce::Image mix68;
    juce::Image mix68x5;
    juce::Image mix69;
    juce::Image mix69x5;
  
    // Knob images 70 - 79.5
    juce::Image mix70;
    juce::Image mix70x5;
    juce::Image mix71;
    juce::Image mix71x5;
    juce::Image mix72;
    juce::Image mix72x5;
    juce::Image mix73;
    juce::Image mix73x5;
    juce::Image mix74;
    juce::Image mix74x5;
    juce::Image mix75;
    juce::Image mix75x5;
    juce::Image mix76;
    juce::Image mix76x5;
    juce::Image mix77;
    juce::Image mix77x5;
    juce::Image mix78;
    juce::Image mix78x5;
    juce::Image mix79;
    juce::Image mix79x5;
   
    // Knob images 80 - 89.5
    juce::Image mix80;
    juce::Image mix80x5;
    juce::Image mix81;
    juce::Image mix81x5;
    juce::Image mix82;
    juce::Image mix82x5;
    juce::Image mix83;
    juce::Image mix83x5;
    juce::Image mix84;
    juce::Image mix84x5;
    juce::Image mix85;
    juce::Image mix85x5;
    juce::Image mix86;
    juce::Image mix86x5;
    juce::Image mix87;
    juce::Image mix87x5;
    juce::Image mix88;
    juce::Image mix88x5;
    juce::Image mix89;
    juce::Image mix89x5;
  
    // Knob images 90 - 99.5
    juce::Image mix90;
    juce::Image mix90x5;
    juce::Image mix91;
    juce::Image mix91x5;
    juce::Image mix92;
    juce::Image mix92x5;
    juce::Image mix93;
    juce::Image mix93x5;
    juce::Image mix94;
    juce::Image mix94x5;
    juce::Image mix95;
    juce::Image mix95x5;
    juce::Image mix96;
    juce::Image mix96x5;
    juce::Image mix97;
    juce::Image mix97x5;
    juce::Image mix98;
    juce::Image mix98x5;
    juce::Image mix99;
    juce::Image mix99x5;
   
    // Knob image 100
    juce::Image mix100;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Coleman_HW2AudioProcessorEditor)
    
public:
    
    std::vector<std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment>> sliderAttachment;
    std::vector<std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment>> buttonAttachment;
    
};
