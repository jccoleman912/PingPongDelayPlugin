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

    /*
     The knobs and sliders of the interface.
    */
    
    // Gain knobs
    juce::Slider initialGainKnob;
    juce::Slider l2RGainKnob;
    juce::Slider r2LGainKnob;
    
    // Tempo slider
    juce::Slider tempoSelector;
    
    // Mix knob
    juce::Slider mixKnob;

    // Smooth knob
    juce::Slider smoothKnob;
    
    /*
     The buttons of the interface.
    */
    
    // Bypass button
    juce::ToggleButton bypassButton;
    
    // Note selector buttons
    juce::ToggleButton wholeNoteButton;
    juce::ToggleButton halfNoteButton;
    juce::ToggleButton quarterNoteButton;
    juce::ToggleButton eighthNoteButton;
    juce::ToggleButton sixteenthNoteButton;
    juce::ToggleButton thirtysecondNoteButton;
    
    // Other rhythm buttons
    juce::ToggleButton tripletButton;
    juce::ToggleButton dottedButton;
    juce::ToggleButton syncButton;

    // Left/Right first selector
    juce::ToggleButton leftFirstButton;
    juce::ToggleButton rightFirstButton;
    
    // Smooth button
    juce::ToggleButton smoothButton;
    
    // Images of interface and buttons from Binary Data
    juce::Image bgImage;
    juce::Image spriteSheet;
    juce::Image rescaledSpriteSheet;
    
    juce::Image bypassOFFImage;
    juce::Image bypassONImage;
    
    juce::Image syncOFFImage;
    juce::Image syncONImage;
    
    juce::Image noteSelectorWhole;
    juce::Image noteSelectorHalf;
    juce::Image noteSelectorQuarter;
    juce::Image noteSelector8th;
    juce::Image noteSelector16th;
    juce::Image noteSelector32nd;
    
    juce::Image tripletOFFImage;
    juce::Image tripletONImage;
    
    juce::Image dottedOFFImage;
    juce::Image dottedONImage;
    
    juce::Image leftFirstImage;
    juce::Image rightFirstImage;
    
    juce::Image smoothOFFImage;
    juce::Image smoothONImage;
    


    // Images that are clipped portions of the sprite sheet.
    // These are associated with the correct boolean outcome of the button's toggle state.
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
//
//    juce::Image leftFirstImage;
//    juce::Image rightFirstImage;
    
    juce::Image smoothOFF;
    juce::Image smoothON;
    
    // Images placed in the paint() method that are updated in the listener using repaint().
    juce::Image bypassOutcome;
    juce::Image syncOutcome;
    juce::Image noteOutcome;
    juce::Image tripletOutcome;
    juce::Image dottedOutcome;
    juce::Image leftRightOutcome;
    juce::Image smoothOutcome;
    
    // Rectangles that are used for .rescale() in the constructor.
//    const juce::Rectangle<int> bypassCrop {0, 0, 128, 80};
//    const juce::Rectangle<int> bypassONCrop {128, 0, 128, 80};
//
//    const juce::Rectangle<int> syncOFFCrop {0, 64, 128, 80};
//    const juce::Rectangle<int> syncONCrop {128, 64, 128, 64};
//
//    const juce::Rectangle<int> tripletOFFCrop {0, 128, 128, 80};
//    const juce::Rectangle<int> tripletONCrop {128, 128, 128, 80};
//
//    const juce::Rectangle<int> dottedOFFCrop {0, 192, 128, 64};
//    const juce::Rectangle<int> dottedONCrop {128, 192, 128, 64};
//
//    const juce::Rectangle<int> leftFirstCrop {0, 256, 128, 64};
//    const juce::Rectangle<int> rightFirstCrop {128, 256, 128, 64};
//
//    const juce::Rectangle<int> noteSelectorCrop {0, 320, 128, 96};
//
//    const juce::Rectangle<int> smoothOFFCrop {0, 416, 128, 64};
//    const juce::Rectangle<int> smoothONCrop {128, 416, 128, 64};
    
//    const juce::Rectangle<int> imageCrop {0, 0, 400, 250};
//
//    const juce::Rectangle<int> syncCrop {0, 0, 400, 250};
//
//    const juce::Rectangle<int> tripletCrop {0, 0, 400, 250};
//
//    const juce::Rectangle<int> dottedCrop {0, 0, 400, 250};
//
//    const juce::Rectangle<int> leftRightCrop {0, 0, 400, 250};
//
//    const juce::Rectangle<int> smoothCrop {0, 0, 400, 250};
    
    
    juce::Image knobPosition;
    
//    juce::Image emptyInitial;
//    juce::DrawableImage emptyInitialDrawable;
//    juce::Image orangeInitial;
//    juce::DrawableImage orangeInitialDrawable;
//    juce::Image redInitial;
//    juce::DrawableImage redInitialDrawable;
    
    juce::Image baseInitialDrop;
    juce::Image baseL2RDrop;
    juce::Image baseR2LDrop;
    juce::Image baseR2LFinalDrop;
    
    juce::Image redInitialDrop;
    juce::Image redL2RDrop;
    juce::Image redR2LDrop;
    juce::Image redR2LFinalDrop;
    
    juce::DrawableImage baseInitialDropDrawable;
    juce::DrawableImage redInitialDropDrawable;
    
    juce::DrawableImage baseL2RDropADrawable;
    juce::DrawableImage redL2RDropADrawable;
    
    juce::DrawableImage baseR2LDropADrawable;
    juce::DrawableImage redR2LDropADrawable;
    
    juce::DrawableImage baseL2RDropBDrawable;
    juce::DrawableImage redL2RDropBDrawable;
    
    juce::DrawableImage baseR2LDropFinalDrawable;
    juce::DrawableImage redR2LDropFinalDrawable;
    
    juce::Image leftPingPong;
    juce::Image rightPingPong;
    juce::Image leftPingPongRed;
    juce::Image rightPingPongRed;
    
    juce::DrawableImage leftPingPongA;
    juce::DrawableImage rightPingPongA;
    juce::DrawableImage leftPingPongB;
    juce::DrawableImage rightPingPongB;
    
    juce::DrawableImage leftPingPongRedA;
    juce::DrawableImage rightPingPongRedA;
    juce::DrawableImage leftPingPongRedB;
    juce::DrawableImage rightPingPongRedB;

    
    
    float redInitialOpacity;
    float orangeInitialOpacity;
    float emptyBaseOpacity;
    
    
    
    float redOpacity[122] = {0.f, 0.03f, 0.06f, 0.09f, 0.12f, 0.15f, 0.18f, 0.21f, 0.24f,
        0.27f, 0.3f, 0.32f, 0.34f, 0.36f, 0.38f, 0.4f, 0.42f, 0.44f, 0.46f, 0.48f, 0.5f,
        0.52f, 0.54f, 0.56f, 0.58f, 0.59f, 0.6f, 0.61f, 0.62f, 0.63f, 0.64f, 0.65f, 0.66f,
        0.67f, 0.68f, 0.69f, 0.7f, 0.71f, 0.72f, 0.73f, 0.74f, 0.75f, 0.757f, 0.764f,
        0.769f, 0.772f, 0.775f, 0.778f, 0.781f, 0.784f, 0.787f, 0.79f, 0.793f,
        0.796f, 0.799f, 0.802f, 0.805f, 0.808f, 0.811f, 0.814f, 0.817f, 0.82f, 0.823f,
        0.826f, 0.829f, 0.832f, 0.835f, 0.838f, 0.841f, 0.844f, 0.847f, 0.85f, 0.853f,
        0.856f, 0.859f, 0.862f, 0.865f, 0.868f, 0.871f, 0.874f, 0.877f, 0.88f, 0.883f,
        0.886f, 0.889f, 0.892f, 0.895f, 0.898f, 0.901f, 0.904f, 0.907f, 0.91f, 0.913f,
        0.916f, 0.919f, 0.922f, 0.925f, 0.928f, 0.931f, 0.934f, 0.937f, 0.94f, 0.943f,
        0.946f, 0.949f, 0.952f, 0.955f, 0.958f, 0.961f, 0.964f, 0.967f, 0.97f, 0.973f,
        0.976f, 0.979f, 0.982f, 0.985f, 0.988f, 0.991f, 0.994f, 0.997f, 1.f};
    
    float baseOpacity[201] =
    {0.f, 0.005f, 0.01f, 0.015f, 0.02f, 0.025f, 0.03f, 0.035f, 0.04f, 0.045f,
        0.05f, 0.055f, 0.06f, 0.065f, 0.07f, 0.075f, 0.08f, 0.085f, 0.09f, 0.095f,
        0.1f, 0.105f, 0.11f, 0.115f, 0.12f, 0.125f, 0.13f, 0.135f, 0.14f, 0.145f,
        0.15f, 0.155f, 0.16f, 0.165f, 0.17f, 0.175f, 0.18f, 0.185f, 0.19f, 0.195f,
        0.2f, 0.205f, 0.21f, 0.215f, 0.22f, 0.225f, 0.23f, 0.235f, 0.24f, 0.245f,
        0.25f, 0.255f, 0.26f, 0.265f, 0.27f, 0.275f, 0.28f, 0.285f, 0.29f, 0.295f,
        0.3f, 0.305f, 0.31f, 0.315f, 0.32f, 0.325f, 0.33f, 0.335f, 0.34f, 0.345f,
        0.35f, 0.355f, 0.36f, 0.365f, 0.37f, 0.375f, 0.38f, 0.385f, 0.39f, 0.395f,
        0.4f, 0.405f, 0.41f, 0.415f, 0.42f, 0.425f, 0.43f, 0.435f, 0.44f, 0.445f,
        0.45f, 0.455f, 0.46f, 0.465f, 0.47f, 0.475f, 0.48f, 0.485f, 0.49f, 0.495f,
        0.5f, 0.505f, 0.51f, 0.515f, 0.52f, 0.525f, 0.53f, 0.535f, 0.54f, 0.545f,
        0.55f, 0.555f, 0.56f, 0.565f, 0.57f, 0.575f, 0.58f, 0.585f, 0.59f, 0.595f,
        0.6f, 0.605f, 0.61f, 0.615f, 0.62f, 0.625f, 0.63f, 0.635f, 0.64f, 0.645f,
        0.65f, 0.655f, 0.66f, 0.665f, 0.67f, 0.675f, 0.68f, 0.685f, 0.69f, 0.695f,
        0.7f, 0.705f, 0.71f, 0.715f, 0.72f, 0.725f, 0.73f, 0.735f, 0.74f, 0.745f,
        0.75f, 0.755f, 0.76f, 0.765f, 0.77f, 0.775f, 0.78f, 0.785f, 0.79f, 0.795f,
        0.8f, 0.805f, 0.81f, 0.815f, 0.82f, 0.825f, 0.83f, 0.835f, 0.84f, 0.845f,
        0.85f, 0.855f, 0.86f, 0.865f, 0.87f, 0.875f, 0.88f, 0.885f, 0.89f, 0.895f,
        0.9f, 0.905f, 0.91f, 0.915f, 0.92f, 0.925f, 0.93f, 0.935f, 0.94f, 0.945f,
        0.95f, 0.955f, 0.96f, 0.965f, 0.97f, 0.975f, 0.98f, 0.985f, 0.99f, 0.995,
        1.f};
    
    
    juce::DrawableImage redI100;
    juce::Image redI50;
    juce::Image redI0;
    
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
