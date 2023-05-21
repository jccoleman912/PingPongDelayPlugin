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
    
//    for(int n = 0; n < 200; n++) {
//        startingY[n] = 2 + (n * );
//    }
//
    
    bgImage = juce::ImageCache::getFromMemory(BinaryData::FullScalePingpongDelayUI_jpg, BinaryData::FullScalePingpongDelayUI_jpgSize);
    
    spriteSheet = juce::ImageCache::getFromMemory(BinaryData::PingPongButtonSpriteSheet_jpg, BinaryData::PingPongButtonSpriteSheet_jpgSize);
    
    spriteSheetBottomNotes = juce::ImageCache::getFromMemory(BinaryData::PingPongButtonSpriteSheetBOTTOMNOTES_jpg, BinaryData::PingPongButtonSpriteSheetBOTTOMNOTES_jpgSize);
    
    mix0 =  juce::ImageCache::getFromMemory(BinaryData::Mix0Knob_jpg, BinaryData::Mix0Knob_jpgSize);
    
    mix10 =  juce::ImageCache::getFromMemory(BinaryData::Mix10Knob_jpg, BinaryData::Mix10Knob_jpgSize);
    
    mix20 =  juce::ImageCache::getFromMemory(BinaryData::Mix20Knob_jpg, BinaryData::Mix20Knob_jpgSize);
    
    mix30 =  juce::ImageCache::getFromMemory(BinaryData::Mix30Knob_jpg, BinaryData::Mix30Knob_jpgSize);
    
    mix40 =  juce::ImageCache::getFromMemory(BinaryData::Mix40Knob_jpg, BinaryData::Mix40Knob_jpgSize);
    
    mix50 =  juce::ImageCache::getFromMemory(BinaryData::Mix50Knob_jpg, BinaryData::Mix50Knob_jpgSize);
    
    mix60 =  juce::ImageCache::getFromMemory(BinaryData::Mix60Knob_jpg, BinaryData::Mix60Knob_jpgSize);
    
    mix70 =  juce::ImageCache::getFromMemory(BinaryData::Mix70Knob_jpg, BinaryData::Mix70Knob_jpgSize);
    
    mix80 =  juce::ImageCache::getFromMemory(BinaryData::Mix80Knob_jpg, BinaryData::Mix80Knob_jpgSize);
    
    mix90 =  juce::ImageCache::getFromMemory(BinaryData::Mix90Knob_jpg, BinaryData::Mix90Knob_jpgSize);
    
    mix100 =  juce::ImageCache::getFromMemory(BinaryData::Mix100Knob_jpg, BinaryData::Mix100Knob_jpgSize);
    
    knobPosition = mix100;
    

        
        
    bgImage = bgImage.rescaled(625, 625, juce::Graphics::highResamplingQuality);
        
    rescaledSpriteSheet = spriteSheet.rescaled(625, 625, juce::Graphics::highResamplingQuality);
    
    rescaledSpriteSheetBottomNoteSelector = spriteSheetBottomNotes.rescaled(625, 625, juce::Graphics::highResamplingQuality);
    
    
    
        
    bypassOFF = rescaledSpriteSheet.getClippedImage(bypassOFFCrop);
    bypassON = rescaledSpriteSheet.getClippedImage(bypassONCrop);
        
    syncOFF = rescaledSpriteSheet.getClippedImage(syncOFFCrop);
    syncON = rescaledSpriteSheet.getClippedImage(syncONCrop);
        
    noteWHOLE = rescaledSpriteSheet.getClippedImage(noteWHOLECrop);
    noteHALF = rescaledSpriteSheet.getClippedImage(noteHALFCrop);
    noteQUARTER = rescaledSpriteSheet.getClippedImage(noteQUARTERCrop);
    note8TH = rescaledSpriteSheetBottomNoteSelector.getClippedImage(note8THCrop);
    note16TH = rescaledSpriteSheetBottomNoteSelector.getClippedImage(note16THCrop);
    note32ND = rescaledSpriteSheetBottomNoteSelector.getClippedImage(note32NDCrop);
        
    tripletOFF = rescaledSpriteSheet.getClippedImage(tripletOFFCrop);
    tripletON = rescaledSpriteSheet.getClippedImage(tripletONCrop);
        
    dottedOFF = rescaledSpriteSheet.getClippedImage(dottedOFFCrop);
    dottedON = rescaledSpriteSheet.getClippedImage(dottedONCrop);
        
    leftFirstImage = rescaledSpriteSheetBottomNoteSelector.getClippedImage(leftFirstCrop);
    rightFirstImage = rescaledSpriteSheetBottomNoteSelector.getClippedImage(rightFirstCrop);


    
    
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
    mixKnob.setBounds(20,450,100,100);
    mixKnob.setRange(0.f,100.f,0.1); // (min, max, interval)
    mixKnob.setValue(100.f); // initial value
    mixKnob.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    mixKnob.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 75, 25);
    mixKnob.setName("Mix");
    mixKnob.getTitle();
//    mixKnob.setLookAndFeel(&mixKnobLookAndFeel);
    addAndMakeVisible(mixKnob);
    
    //
    // Smooth Knob
    //
    
    smoothKnob.addListener(this);
    // Specify location in window (xPos,yPos,width,height)
    smoothKnob.setBounds(260,400,160,100);
    smoothKnob.setRange(0.f,500.f,0.1); // (min, max, interval)
    smoothKnob.setValue(0.f); // initial value
    smoothKnob.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    smoothKnob.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 75, 25);
    smoothKnob.setName("Smooth MS");
    smoothKnob.getTitle();
    addAndMakeVisible(smoothKnob);
        
    
    
    //
    // Bypass Toggle
    //
    
    bypassButton.addListener(this);
    bypassButton.setBounds(17,22,91,41);
    bypassButton.setToggleState(false, juce::dontSendNotification);
    addAndMakeVisible(bypassButton);
    bypassButton.setAlpha(0.f);
    
    //
    // Sync Toggle
    //
    
    syncButton.addListener(this);
    syncButton.setBounds(17,103,91,34);
    syncButton.setToggleState(false, juce::dontSendNotification);
    addAndMakeVisible(syncButton);
    syncButton.setAlpha(0.f);
    
    //
    // Note Selection Buttons
    //
    
    wholeNoteButton.addListener(this);
    wholeNoteButton.setBounds(17,252,30,30);
    wholeNoteButton.setToggleState(false, juce::dontSendNotification);
    wholeNoteButton.setRadioGroupId(2);
    addAndMakeVisible(wholeNoteButton);
    wholeNoteButton.setAlpha(0.f);
    
    halfNoteButton.addListener(this);
    halfNoteButton.setBounds(48,252,30,30);
    halfNoteButton.setToggleState(false, juce::dontSendNotification);
    halfNoteButton.setRadioGroupId(2);
    addAndMakeVisible(halfNoteButton);
    halfNoteButton.setAlpha(0.f);
    
    quarterNoteButton.addListener(this);
    quarterNoteButton.setBounds(79,252,30,30);
    quarterNoteButton.setToggleState(true, juce::dontSendNotification);
    quarterNoteButton.setRadioGroupId(2);
    addAndMakeVisible(quarterNoteButton);
    quarterNoteButton.setAlpha(0.f);
    
    eighthNoteButton.addListener(this);
    eighthNoteButton.setBounds(17,283,30,30);
    eighthNoteButton.setToggleState(false, juce::dontSendNotification);
    eighthNoteButton.setRadioGroupId(2);
    addAndMakeVisible(eighthNoteButton);
    eighthNoteButton.setAlpha(0.f);
    
    sixteenthNoteButton.addListener(this);
    sixteenthNoteButton.setBounds(48,283,30,30);
    sixteenthNoteButton.setToggleState(false, juce::dontSendNotification);
    sixteenthNoteButton.setRadioGroupId(2);
    addAndMakeVisible(sixteenthNoteButton);
    sixteenthNoteButton.setAlpha(0.f);
    
    thirtysecondNoteButton.addListener(this);
    thirtysecondNoteButton.setBounds(79,283,30,30);
    thirtysecondNoteButton.setToggleState(false, juce::dontSendNotification);
    thirtysecondNoteButton.setRadioGroupId(2);
    addAndMakeVisible(thirtysecondNoteButton);
    thirtysecondNoteButton.setAlpha(0.f);
    
    //
    // Triplet Toggle
    //
    
    tripletButton.addListener(this);
    tripletButton.setBounds(17,329,91,34);
    tripletButton.setToggleState(false, juce::dontSendNotification);
    addAndMakeVisible(tripletButton);
    tripletButton.setAlpha(0.f);
    
    //
    // Dotted Toggle
    //
    
    dottedButton.addListener(this);
    dottedButton.setBounds(17,374,91,34);
    dottedButton.setToggleState(false, juce::dontSendNotification);
    addAndMakeVisible(dottedButton);
    dottedButton.setAlpha(0.f);
    
    //
    // L/R Selection Buttons
    //
    
    leftFirstButton.addListener(this);
    leftFirstButton.setBounds(17,555,38,40);
    leftFirstButton.setToggleState(true, juce::dontSendNotification);
    leftFirstButton.setRadioGroupId(1);
    addAndMakeVisible(leftFirstButton);
    leftFirstButton.setAlpha(0.f);
    
    rightFirstButton.addListener(this);
    rightFirstButton.setBounds(70,555,38,40);
    rightFirstButton.setToggleState(false, juce::dontSendNotification);
    rightFirstButton.setRadioGroupId(1);
    addAndMakeVisible(rightFirstButton);
    rightFirstButton.setAlpha(0.f);
    
    //
    // Smooth Toggle
    //
    
    smoothButton.addListener(this);
    smoothButton.setBounds(400,400,40,40);
    smoothButton.setToggleState(false, juce::dontSendNotification);
    smoothButton.setButtonText("Smooth MS");
    addAndMakeVisible(smoothButton);
//    smoothButton.setAlpha(0.f);
    
    
    
    sliderAttachment.emplace_back(new juce::AudioProcessorValueTreeState::SliderAttachment(audioProcessor.state, "initialDropValue", initialGainKnob));
    sliderAttachment.emplace_back(new juce::AudioProcessorValueTreeState::SliderAttachment(audioProcessor.state, "l2RDropValue", l2RGainKnob));
    sliderAttachment.emplace_back(new juce::AudioProcessorValueTreeState::SliderAttachment(audioProcessor.state, "r2LDropValue", r2LGainKnob));
    sliderAttachment.emplace_back(new juce::AudioProcessorValueTreeState::SliderAttachment(audioProcessor.state, "tempoValue", tempoSelector));
    sliderAttachment.emplace_back(new juce::AudioProcessorValueTreeState::SliderAttachment(audioProcessor.state, "mixValue", mixKnob));
    sliderAttachment.emplace_back(new juce::AudioProcessorValueTreeState::SliderAttachment(audioProcessor.state, "smoothKnobValue", smoothKnob));
    
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
    buttonAttachment.emplace_back(new juce::AudioProcessorValueTreeState::ButtonAttachment(audioProcessor.state, "smoothButtonValue", smoothButton));


}

Coleman_HW2AudioProcessorEditor::~Coleman_HW2AudioProcessorEditor()
{
    setLookAndFeel(nullptr);
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
    
    g.drawImage(knobPosition, 17, 400, 50, 50, 0, 0, 1000, 1000);
    

}

void Coleman_HW2AudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
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
    if (slider == &mixKnob) {
        float mixValue = slider->getValue();
//
//        if(mixValue < 0.5f) {
//
//        } else if (mixValue < 1.f) {
//
//        } else if (mixValue < 1.5f) {
//
//        } else if (mixValue < 2.f) {
//
//        } else if (mixValue < 2.5f) {
//
//        } else if (mixValue < 3.f) {
//
//        } else if (mixValue < 3.5f) {
//
//        } else if (mixValue < 4.f) {
//
//        } else if (mixValue < 4.5f) {
//
//        } else if (mixValue < 5.f) {
//
//        } else if (mixValue < 5.5f) {
//
//        } else if (mixValue < 6.f) {
//
//        } else if (mixValue < 6.5f) {
//
//        } else if (mixValue < 7.f) {
//
//        } else if (mixValue < 7.5f) {
//
//        } else if (mixValue < 8.f) {
//
//        } else if (mixValue < 8.5f) {
//
//        } else if (mixValue < 9.f) {
//
//        } else if (mixValue < 9.5f) {
//
//        } else if (mixValue < 10.f) {
//
//        } else if (mixValue < 10.5f) {
//
//        } else if (mixValue < 11.f) {
//
//        } else if (mixValue < 11.5f) {
//
//        } else if (mixValue < 12.f) {
//
//        } else if (mixValue < 12.5f) {
//
//        } else if (mixValue < 13.f) {
//
//        } else if (mixValue < 13.5f) {
//
//        } else if (mixValue < 14.f) {
//
//        } else if (mixValue < 14.5f) {
//
//        } else if (mixValue < 15.f) {
//
//        } else if (mixValue < 15.5f) {
//
//        } else if (mixValue < 16.f) {
//
//        } else if (mixValue < 16.5f) {
//
//        } else if (mixValue < 17.f) {
//
//        } else if (mixValue < 17.5f) {
//
//        } else if (mixValue < 18.f) {
//
//        } else if (mixValue < 18.5f) {
//
//        } else if (mixValue < 19.f) {
//
//        } else if (mixValue < 19.5f) {
//
//        } else if (mixValue < 20.f) {
//
//        } else if (mixValue < 20.5f) {
//
//        } else if (mixValue < 21.f) {
//
//        } else if (mixValue < 21.5f) {
//
//        } else if (mixValue < 22.f) {
//
//        } else if (mixValue < 22.5f) {
//
//        } else if (mixValue < 23.f) {
//
//        } else if (mixValue < 23.5f) {
//
//        } else if (mixValue < 24.f) {
//
//        } else if (mixValue < 24.5f) {
//
//        } else if (mixValue < 25.f) {
//
//        } else if (mixValue < 25.5f) {
//
//        } else if (mixValue < 26.f) {
//
//        } else if (mixValue < 26.5f) {
//
//        } else if (mixValue < 27.f) {
//
//        } else if (mixValue < 27.5f) {
//
//        } else if (mixValue < 28.f) {
//
//        } else if (mixValue < 28.5f) {
//
//        } else if (mixValue < 29.f) {
//
//        } else if (mixValue < 29.5f) {
//
//        } else if (mixValue < 30.f) {
//
//        } else if (mixValue < 30.5f) {
//
//        } else if (mixValue < 31.f) {
//
//        } else if (mixValue < 31.5f) {
//
//        } else if (mixValue < 32.f) {
//
//        } else if (mixValue < 32.5f) {
//
//        } else if (mixValue < 33.f) {
//
//        } else if (mixValue < 33.5f) {
//
//        } else if (mixValue < 34.f) {
//
//        } else if (mixValue < 34.5f) {
//
//        } else if (mixValue < 35.f) {
//
//        } else if (mixValue < 35.5f) {
//
//        } else if (mixValue < 36.f) {
//
//        } else if (mixValue < 36.5f) {
//
//        } else if (mixValue < 37.f) {
//
//        } else if (mixValue < 37.5f) {
//
//        } else if (mixValue < 38.f) {
//
//        } else if (mixValue < 38.5f) {
//
//        } else if (mixValue < 39.f) {
//
//        } else if (mixValue < 39.5f) {
//
//        } else if (mixValue < 40.f) {
//
//        } else if (mixValue < 40.5f) {
//
//        } else if (mixValue < 41.f) {
//
//        } else if (mixValue < 41.5f) {
//
//        } else if (mixValue < 42.f) {
//
//        } else if (mixValue < 42.5f) {
//
//        } else if (mixValue < 43.f) {
//
//        } else if (mixValue < 43.5f) {
//
//        } else if (mixValue < 44.f) {
//
//        } else if (mixValue < 44.5f) {
//
//        } else if (mixValue < 45.f) {
//
//        } else if (mixValue < 45.5f) {
//
//        } else if (mixValue < 46.f) {
//
//        } else if (mixValue < 46.5f) {
//
//        } else if (mixValue < 47.f) {
//
//        } else if (mixValue < 47.5f) {
//
//        } else if (mixValue < 48.f) {
//
//        } else if (mixValue < 48.5f) {
//
//        } else if (mixValue < 49.f) {
//
//        } else if (mixValue < 49.5f) {
//
//        } else if (mixValue < 50.f) {
//
//            knobPosition = mix0;
//
//        } else if (mixValue < 50.5f) {
//
//        } else if (mixValue < 51.f) {
//
//        } else if (mixValue < 51.5f) {
//
//        } else if (mixValue < 52.f) {
//
//        } else if (mixValue < 52.5f) {
//
//        } else if (mixValue < 53.f) {
//
//        } else if (mixValue < 53.5f) {
//
//        } else if (mixValue < 54.f) {
//
//        } else if (mixValue < 54.5f) {
//
//        } else if (mixValue < 55.f) {
//
//        } else if (mixValue < 55.5f) {
//
//        } else if (mixValue < 56.f) {
//
//        } else if (mixValue < 56.5f) {
//
//        } else if (mixValue < 57.f) {
//
//        } else if (mixValue < 57.5f) {
//
//        } else if (mixValue < 58.f) {
//
//        } else if (mixValue < 58.5f) {
//
//        } else if (mixValue < 59.f) {
//
//        } else if (mixValue < 59.5f) {
//
//        } else if (mixValue < 60.f) {
//
//        } else if (mixValue < 60.5f) {
//
//        } else if (mixValue < 61.f) {
//
//        } else if (mixValue < 61.5f) {
//
//        } else if (mixValue < 62.f) {
//
//        } else if (mixValue < 62.5f) {
//
//        } else if (mixValue < 63.f) {
//
//        } else if (mixValue < 63.5f) {
//
//        } else if (mixValue < 64.f) {
//
//        } else if (mixValue < 64.5f) {
//
//        } else if (mixValue < 65.f) {
//
//        } else if (mixValue < 65.5f) {
//
//        } else if (mixValue < 66.f) {
//
//        } else if (mixValue < 66.5f) {
//
//        } else if (mixValue < 67.f) {
//
//        } else if (mixValue < 67.5f) {
//
//        } else if (mixValue < 68.f) {
//
//        } else if (mixValue < 68.5f) {
//
//        } else if (mixValue < 69.f) {
//
//        } else if (mixValue < 69.5f) {
//
//        } else if (mixValue < 70.f) {
//
//        } else if (mixValue < 70.5f) {
//
//        } else if (mixValue < 71.f) {
//
//        } else if (mixValue < 71.5f) {
//
//        } else if (mixValue < 72.f) {
//
//        } else if (mixValue < 72.5f) {
//
//        } else if (mixValue < 73.f) {
//
//        } else if (mixValue < 73.5f) {
//
//        } else if (mixValue < 74.f) {
//
//        } else if (mixValue < 74.5f) {
//
//        } else if (mixValue < 75.f) {
//
//        } else if (mixValue < 75.5f) {
//
//        } else if (mixValue < 76.f) {
//
//        } else if (mixValue < 76.5f) {
//
//        } else if (mixValue < 77.f) {
//
//        } else if (mixValue < 77.5f) {
//
//        } else if (mixValue < 78.f) {
//
//        } else if (mixValue < 78.5f) {
//
//        } else if (mixValue < 79.f) {
//
//        } else if (mixValue < 79.5f) {
//
//        } else if (mixValue < 80.f) {
//
//        } else if (mixValue < 80.5f) {
//
//        } else if (mixValue < 81.f) {
//
//        } else if (mixValue < 81.5f) {
//
//        } else if (mixValue < 82.f) {
//
//        } else if (mixValue < 82.5f) {
//
//        } else if (mixValue < 83.f) {
//
//        } else if (mixValue < 83.5f) {
//
//        } else if (mixValue < 84.f) {
//
//        } else if (mixValue < 84.5f) {
//
//        } else if (mixValue < 85.f) {
//
//        } else if (mixValue < 85.5f) {
//
//        } else if (mixValue < 86.f) {
//
//        } else if (mixValue < 86.5f) {
//
//        } else if (mixValue < 87.f) {
//
//        } else if (mixValue < 87.5f) {
//
//        } else if (mixValue < 88.f) {
//
//        } else if (mixValue < 88.5f) {
//
//        } else if (mixValue < 89.f) {
//
//        } else if (mixValue < 89.5f) {
//
//        } else if (mixValue < 90.f) {
//
//        } else if (mixValue < 90.5f) {
//
//        } else if (mixValue < 91.f) {
//
//        } else if (mixValue < 91.5f) {
//
//        } else if (mixValue < 92.f) {
//
//        } else if (mixValue < 92.5f) {
//
//        } else if (mixValue < 93.f) {
//
//        } else if (mixValue < 93.5f) {
//
//        } else if (mixValue < 94.f) {
//
//        } else if (mixValue < 94.5f) {
//
//        } else if (mixValue < 95.f) {
//
//        } else if (mixValue < 95.5f) {
//
//        } else if (mixValue < 96.f) {
//
//        } else if (mixValue < 96.5f) {
//
//        } else if (mixValue < 97.f) {
//
//        } else if (mixValue < 97.5f) {
//
//        } else if (mixValue < 98.f) {
//
//        } else if (mixValue < 98.5f) {
//
//        } else if (mixValue < 99.f) {
//
//        } else if (mixValue < 99.5f) {
//
//        } else if (mixValue < 100.f) {
//
//        } else {
//
//            knobPosition = mix100;
//
//        }
        
        if(mixValue < 10.f) {knobPosition = mix0;}
        else if (mixValue < 20.f) {knobPosition = mix10;}
        else if (mixValue < 30.f) {knobPosition = mix20;}
        else if (mixValue < 40.f) {knobPosition = mix30;}
        else if (mixValue < 50.f) {knobPosition = mix40;}
        else if (mixValue < 60.f) {knobPosition = mix50;}
        else if (mixValue < 70.f) {knobPosition = mix60;}
        else if (mixValue < 80.f) {knobPosition = mix70;}
        else if (mixValue < 90.f) {knobPosition = mix80;}
        else if (mixValue < 100.f) {knobPosition = mix90;}
        else {knobPosition = mix100;}
        repaint();
    }
}

