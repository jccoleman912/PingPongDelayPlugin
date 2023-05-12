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
    
    spriteSheet = juce::ImageCache::getFromMemory(BinaryData::PingPongButtonSpriteSheet_jpg, BinaryData::PingPongButtonSpriteSheet_jpgSize);
        
        
        bgImage = bgImage.rescaled(625, 625, juce::Graphics::highResamplingQuality);
        
        rescaledSpriteSheet = spriteSheet.rescaled(625, 625, juce::Graphics::highResamplingQuality);
        
        bypassOFF = rescaledSpriteSheet.getClippedImage(bypassOFFCrop);
        bypassON = rescaledSpriteSheet.getClippedImage(bypassONCrop);
        
        syncOFF = rescaledSpriteSheet.getClippedImage(syncOFFCrop);
        syncON = rescaledSpriteSheet.getClippedImage(syncONCrop);
        
        noteWHOLE = rescaledSpriteSheet.getClippedImage(noteWHOLECrop);
        noteHALF = rescaledSpriteSheet.getClippedImage(noteHALFCrop);
        noteQUARTER = rescaledSpriteSheet.getClippedImage(noteQUARTERCrop);
        note8TH = rescaledSpriteSheet.getClippedImage(note8THCrop);
        note16TH = rescaledSpriteSheet.getClippedImage(note16THCrop);
        note32ND = rescaledSpriteSheet.getClippedImage(note32NDCrop);
        
        tripletOFF = rescaledSpriteSheet.getClippedImage(tripletOFFCrop);
        tripletON = rescaledSpriteSheet.getClippedImage(tripletONCrop);
        
        dottedOFF = rescaledSpriteSheet.getClippedImage(dottedOFFCrop);
        dottedON = rescaledSpriteSheet.getClippedImage(dottedONCrop);
        
        leftFirstImage = rescaledSpriteSheet.getClippedImage(leftFirstCrop);
        rightFirstImage = rescaledSpriteSheet.getClippedImage(rightFirstCrop);

    
    
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
    l2RGainKnob.setBounds(145,170,100,100);
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
    // Bypass Toggle
    //
    
    bypassButton.addListener(this);
    bypassButton.setBounds(17,22,91,41);
    bypassButton.setToggleState(false, juce::dontSendNotification);
    addAndMakeVisible(bypassButton);
    
    //
    // Sync Toggle
    //
    
    syncButton.addListener(this);
    syncButton.setBounds(17,103,91,34);
    syncButton.setToggleState(false, juce::dontSendNotification);
    addAndMakeVisible(syncButton);
    
    //
    // Note Selection Buttons
    //
    
    wholeNoteButton.addListener(this);
    wholeNoteButton.setBounds(17,252,30,30);
    wholeNoteButton.setToggleState(false, juce::dontSendNotification);
    wholeNoteButton.setRadioGroupId(2);
    addAndMakeVisible(wholeNoteButton);
    
    halfNoteButton.addListener(this);
    halfNoteButton.setBounds(48,252,30,30);
    halfNoteButton.setToggleState(false, juce::dontSendNotification);
    halfNoteButton.setRadioGroupId(2);
    addAndMakeVisible(halfNoteButton);
    
    quarterNoteButton.addListener(this);
    quarterNoteButton.setBounds(79,252,30,30);
    quarterNoteButton.setToggleState(true, juce::dontSendNotification);
    quarterNoteButton.setRadioGroupId(2);
    addAndMakeVisible(quarterNoteButton);
    
    eighthNoteButton.addListener(this);
    eighthNoteButton.setBounds(17,283,30,30);
    eighthNoteButton.setToggleState(false, juce::dontSendNotification);
    eighthNoteButton.setRadioGroupId(2);
    addAndMakeVisible(eighthNoteButton);
    
    sixteenthNoteButton.addListener(this);
    sixteenthNoteButton.setBounds(48,283,30,30);
    sixteenthNoteButton.setToggleState(false, juce::dontSendNotification);
    sixteenthNoteButton.setRadioGroupId(2);
    addAndMakeVisible(sixteenthNoteButton);
    
    thirtysecondNoteButton.addListener(this);
    thirtysecondNoteButton.setBounds(79,283,30,30);
    thirtysecondNoteButton.setToggleState(false, juce::dontSendNotification);
    thirtysecondNoteButton.setRadioGroupId(2);
    addAndMakeVisible(thirtysecondNoteButton);
    
    //
    // Triplet Toggle
    //
    
    tripletButton.addListener(this);
    tripletButton.setBounds(17,329,91,34);
    tripletButton.setToggleState(false, juce::dontSendNotification);
    addAndMakeVisible(tripletButton);
    
    //
    // Dotted Toggle
    //
    
    dottedButton.addListener(this);
    dottedButton.setBounds(17,374,91,34);
    dottedButton.setToggleState(false, juce::dontSendNotification);
    addAndMakeVisible(dottedButton);
    
    //
    // L/R Selection Buttons
    //
    
    leftFirstButton.addListener(this);
    leftFirstButton.setBounds(17,555,38,40);
    leftFirstButton.setToggleState(true, juce::dontSendNotification);
    leftFirstButton.setRadioGroupId(1);
    addAndMakeVisible(leftFirstButton);
    
    rightFirstButton.addListener(this);
    rightFirstButton.setBounds(70,555,38,40);
    rightFirstButton.setToggleState(false, juce::dontSendNotification);
    rightFirstButton.setRadioGroupId(1);
    addAndMakeVisible(rightFirstButton);
    
    
    
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
    
    g.drawImageAt(bypassImage, 17, 22);
        
    g.drawImageAt(syncImage, 17, 103);
    
    g.drawImageAt(noteImage, 17, 252);
        
    g.drawImageAt(tripletImage, 17, 329);
        
    g.drawImageAt(dottedImage, 17, 374);
        
    g.drawImageAt(leftOrRightImage, 17, 555);

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
            bypassImage = bypassON;
            repaint();
        } else {
            bypassImage = bypassOFF;
            repaint();
        }
    }
    
    if (button == &tripletButton){
        bool tripletState = tripletButton.getToggleState();
        if(tripletState) {
            tripletImage = tripletON;
            repaint();
        } else {
            tripletImage = tripletOFF;
            repaint();
        }
    }
    
    if (button == &syncButton) {
        bool syncState = syncButton.getToggleState();
        if(syncState) {
            syncImage = syncON;
            repaint();
        } else {
            syncImage = syncOFF;
            repaint();
        }
    }
    
    if (button == &wholeNoteButton) {

            noteImage = noteWHOLE;
            repaint();

    }
    if (button == &halfNoteButton) {

            noteImage = noteHALF;
            repaint();

    }
    if (button == &quarterNoteButton) {

            noteImage = noteQUARTER;
            repaint();

    }
    if (button == &eighthNoteButton) {

            noteImage = note8TH;
            repaint();

    }
    if (button == &sixteenthNoteButton) {

            noteImage = note16TH;
            repaint();

    }
    if (button == &thirtysecondNoteButton) {

            noteImage = note32ND;
            repaint();

    }
    
    if (button == &dottedButton) {
        bool dottedState = dottedButton.getToggleState();
        if(dottedState) {
            dottedImage = dottedON;
            repaint();
        } else {
            dottedImage = dottedOFF;
            repaint();
        }
    }
    
    if (button == &leftFirstButton) {
        bool leftState = leftFirstButton.getToggleState();
        if(leftState) {
            leftOrRightImage = leftFirstImage;
            repaint();
        } else {
            leftOrRightImage = rightFirstImage;
            repaint();
        }
    }
    
    if (button == &rightFirstButton) {
        bool rightState = rightFirstButton.getToggleState();
        if(rightState) {
            leftOrRightImage = rightFirstImage;
            repaint();
        } else {
            leftOrRightImage = leftFirstImage;
            repaint();
        }
    }

}
