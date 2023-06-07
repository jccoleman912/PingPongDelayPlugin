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

    setResizable(false, false);
    setSize (800, 640);
    

    
    bgImage = juce::ImageCache::getFromMemory(BinaryData::PingPongDelayUI_jpg, BinaryData::PingPongDelayUI_jpgSize);
    
    bgImage = bgImage.rescaled(800, 640, juce::Graphics::highResamplingQuality);
    
    sideColorBGImage = juce::ImageCache::getFromMemory(BinaryData::SideColorBGPingPong_jpg, BinaryData::SideColorBGPingPong_jpgSize);
    tempoOverlay.setImage(sideColorBGImage.rescaled(128, 48));
    smoothOverlay.setImage(sideColorBGImage.rescaled(128, 128));
    
    
    
//    spriteSheet = juce::ImageCache::getFromMemory(BinaryData::FinalPingPongSpriteSheet_jpg, BinaryData::FinalPingPongSpriteSheet_jpgSize);
//
//    rescaledSpriteSheet = spriteSheet.rescaled(800, 800, juce::Graphics::highResamplingQuality);
    
    //
    // Setting up the note selector images
    //
    
//    noteSelectorHalf = juce::ImageCache::getFromMemory(BinaryData::PingPongSpriteSheetHalfNote_jpg, BinaryData::PingPongSpriteSheetHalfNote_jpgSize);
//
//    rescaledNoteSelectorHalf = noteSelectorHalf.rescaled(800, 800, juce::Graphics::highResamplingQuality);
//
//    noteSelectorQuarter = juce::ImageCache::getFromMemory(BinaryData::PingPongSpriteSheetWholeNote_jpg, BinaryData::PingPongSpriteSheetWholeNote_jpgSize);
//
//    rescaledNoteSelectorQuarter = noteSelectorQuarter.rescaled(800, 800, juce::Graphics::highResamplingQuality);
//
//    noteSelector8th = juce::ImageCache::getFromMemory(BinaryData::FinalPingPongSpriteSheetBottomNotes_jpg, BinaryData::FinalPingPongSpriteSheetBottomNotes_jpgSize);
//
//    rescaledNoteSelector8th = noteSelector8th.rescaled(800, 800, juce::Graphics::highResamplingQuality);
//
//    noteSelector16th = juce::ImageCache::getFromMemory(BinaryData::PingPongSpriteSheetSixteenthNote_jpg, BinaryData::PingPongSpriteSheetSixteenthNote_jpgSize);
//
//    rescaledNoteSelector16th = noteSelector16th.rescaled(800, 800, juce::Graphics::highResamplingQuality);
//
//    noteSelector32nd = juce::ImageCache::getFromMemory(BinaryData::PingPongSpriteSheetThirtysecondNote_jpg, BinaryData::PingPongSpriteSheetThirtysecondNote_jpgSize);
//
//    rescaledNoteSelector32nd = noteSelector32nd.rescaled(800, 800, juce::Graphics::highResamplingQuality);
//
//    bypassOFF = rescaledSpriteSheet.getClippedImage(bypassOFFCrop);
//    bypassON = rescaledSpriteSheet.getClippedImage(bypassONCrop);
//
//    syncOFF = rescaledSpriteSheet.getClippedImage(syncOFFCrop);
//    syncON = rescaledSpriteSheet.getClippedImage(syncONCrop);
//
//    noteWHOLE = rescaledSpriteSheet.getClippedImage(noteSelectorCrop);
//    noteHALF = rescaledNoteSelectorHalf.getClippedImage(noteSelectorCrop);
//    noteQUARTER = rescaledNoteSelectorQuarter.getClippedImage(noteSelectorCrop);
//    note8TH = rescaledNoteSelector8th.getClippedImage(noteSelectorCrop);
//    note16TH = rescaledNoteSelector16th.getClippedImage(noteSelectorCrop);
//    note32ND = rescaledNoteSelector32nd.getClippedImage(noteSelectorCrop);
//
//    tripletOFF = rescaledSpriteSheet.getClippedImage(tripletOFFCrop);
//    tripletON = rescaledSpriteSheet.getClippedImage(tripletONCrop);
//
//    dottedOFF = rescaledSpriteSheet.getClippedImage(dottedOFFCrop);
//    dottedON = rescaledSpriteSheet.getClippedImage(dottedONCrop);
//
//    leftFirstImage = rescaledSpriteSheet.getClippedImage(leftFirstCrop);
//    rightFirstImage = rescaledSpriteSheet.getClippedImage(rightFirstCrop);
//
//    smoothOFF = rescaledSpriteSheet.getClippedImage(smoothOFFCrop);
//    smoothON = rescaledSpriteSheet.getClippedImage(smoothONCrop);
//
//
//
    
    faderBackgroundImage = juce::ImageCache::getFromMemory(BinaryData::FaderBackground_png, BinaryData::FaderBackground_pngSize);
    
    bypassOFFImage = juce::ImageCache::getFromMemory(BinaryData::BypassOFF_jpg, BinaryData::BypassOFF_jpgSize);
    bypassONImage = juce::ImageCache::getFromMemory(BinaryData::BypassON_jpg, BinaryData::BypassON_jpgSize);
    
    syncOFFImage = juce::ImageCache::getFromMemory(BinaryData::SyncOFF_jpg, BinaryData::SyncOFF_jpgSize);
    syncONImage = juce::ImageCache::getFromMemory(BinaryData::SyncON_jpg, BinaryData::SyncON_jpgSize);
    
    noteSelectorWhole = juce::ImageCache::getFromMemory(BinaryData::WholeNoteSelected_jpg, BinaryData::WholeNoteSelected_jpgSize);
    noteSelectorHalf = juce::ImageCache::getFromMemory(BinaryData::HalfNoteSelected_jpg, BinaryData::HalfNoteSelected_jpgSize);
    noteSelectorQuarter = juce::ImageCache::getFromMemory(BinaryData::QuarterNoteSelected_jpg, BinaryData::QuarterNoteSelected_jpgSize);
    noteSelector8th = juce::ImageCache::getFromMemory(BinaryData::EighthNoteSelected_jpg, BinaryData::EighthNoteSelected_jpgSize);
    noteSelector16th = juce::ImageCache::getFromMemory(BinaryData::SixteenthNoteSelected_jpg, BinaryData::SixteenthNoteSelected_jpgSize);
    noteSelector32nd = juce::ImageCache::getFromMemory(BinaryData::ThirtysecondNoteSelected_jpg, BinaryData::ThirtysecondNoteSelected_jpgSize);
    
    tripletOFFImage = juce::ImageCache::getFromMemory(BinaryData::TripletOFF_jpg, BinaryData::TripletOFF_jpgSize);
    tripletONImage = juce::ImageCache::getFromMemory(BinaryData::TripletON_jpg, BinaryData::TripletON_jpgSize);
    
    dottedOFFImage = juce::ImageCache::getFromMemory(BinaryData::DottedOFF_jpg, BinaryData::DottedOFF_jpgSize);
    dottedONImage = juce::ImageCache::getFromMemory(BinaryData::DottedON_jpg, BinaryData::DottedON_jpgSize);
    
    leftFirstImage = juce::ImageCache::getFromMemory(BinaryData::LeftSelected_jpg, BinaryData::LeftSelected_jpgSize);
    rightFirstImage = juce::ImageCache::getFromMemory(BinaryData::RightSelected_jpg, BinaryData::RightSelected_jpgSize);
    
    smoothOFFImage = juce::ImageCache::getFromMemory(BinaryData::SmoothOFF_jpg, BinaryData::SmoothOFF_jpgSize);
    smoothONImage = juce::ImageCache::getFromMemory(BinaryData::SmoothON_jpg, BinaryData::SmoothON_jpgSize);
    
//    bypassOFFImage = bypassOFFImage.rescaled(128, 96, juce::Graphics::highResamplingQuality);
//    bypassONImage = bypassONImage.rescaled(128, 96, juce::Graphics::highResamplingQuality);
//
//    syncOFFImage = syncOFFImage.rescaled(128, 96, juce::Graphics::highResamplingQuality);
//    syncONImage = syncONImage.rescaled(128, 96, juce::Graphics::highResamplingQuality);
//
//    noteSelectorWhole = noteSelectorWhole.rescaled(128, 96, juce::Graphics::highResamplingQuality);
//    noteSelectorHalf = noteSelectorHalf.rescaled(128, 96, juce::Graphics::highResamplingQuality);
//    noteSelectorQuarter = bypassOFFImage.rescaled(128, 96, juce::Graphics::highResamplingQuality);
//    noteSelector8th = bypassOFFImage.rescaled(128, 96, juce::Graphics::highResamplingQuality);
//    noteSelector16th = bypassOFFImage.rescaled(128, 96, juce::Graphics::highResamplingQuality);
//    noteSelector32nd = bypassOFFImage.rescaled(128, 96, juce::Graphics::highResamplingQuality);
//
//    tripletOFFImage = bypassOFFImage.rescaled(128, 96, juce::Graphics::highResamplingQuality);
//    tripletONImage = bypassOFFImage.rescaled(128, 96, juce::Graphics::highResamplingQuality);
//
//    dottedOFFImage = bypassOFFImage.rescaled(128, 96, juce::Graphics::highResamplingQuality);
//    dottedONImage = bypassOFFImage.rescaled(128, 96, juce::Graphics::highResamplingQuality);
//
//    leftFirstImage = bypassOFFImage.rescaled(128, 96, juce::Graphics::highResamplingQuality);
//    rightFirstImage = bypassOFFImage.rescaled(128, 96, juce::Graphics::highResamplingQuality);
//
//    smoothOFFImage = bypassOFFImage.rescaled(128, 96, juce::Graphics::highResamplingQuality);
//    smoothONImage = bypassOFFImage.rescaled(128, 96, juce::Graphics::highResamplingQuality);
    
    
    
//    emptyInitial = juce::ImageCache::getFromMemory(BinaryData::InitialEmpty_jpg, BinaryData::InitialEmpty_jpgSize);
//    orangeInitial = juce::ImageCache::getFromMemory(BinaryData::InitialOrange_jpg, BinaryData::InitialOrange_jpgSize);
//    redInitial = juce::ImageCache::getFromMemory(BinaryData::InitialRed_jpg, BinaryData::InitialRed_jpgSize);
//
//    emptyInitial = emptyInitial.rescaled(150, 75);
//    orangeInitial = orangeInitial.rescaled(150, 75);
//    redInitial = redInitial.rescaled(150, 75);
    
    leftPingPong = juce::ImageCache::getFromMemory(BinaryData::LeftPingPong_png, BinaryData::LeftPingPong_pngSize);
    rightPingPong = juce::ImageCache::getFromMemory(BinaryData::RightPingPong_png, BinaryData::RightPingPong_pngSize);
    leftPingPongRed = juce::ImageCache::getFromMemory(BinaryData::LeftPingPongRed_png, BinaryData::LeftPingPongRed_pngSize);
    rightPingPongRed = juce::ImageCache::getFromMemory(BinaryData::RightPingPongRed_png, BinaryData::RightPingPongRed_pngSize);
    
    leftPingPong = leftPingPong.rescaled(80, 80, juce::Graphics::highResamplingQuality);
    rightPingPong = rightPingPong.rescaled(80, 80, juce::Graphics::highResamplingQuality);
    leftPingPongRed = leftPingPongRed.rescaled(80, 80, juce::Graphics::highResamplingQuality);
    rightPingPongRed = rightPingPongRed.rescaled(80, 80, juce::Graphics::highResamplingQuality);
    
    baseInitialDrop = juce::ImageCache::getFromMemory(BinaryData::BaseArrowInitialGain_png, BinaryData::BaseArrowInitialGain_pngSize);
    baseL2RDrop = juce::ImageCache::getFromMemory(BinaryData::BaseArrowL2RGain_png, BinaryData::BaseArrowL2RGain_pngSize);
    baseR2LDrop = juce::ImageCache::getFromMemory(BinaryData::BaseArrowR2LGain_png, BinaryData::BaseArrowR2LGain_pngSize);
    baseR2LFinalDrop = juce::ImageCache::getFromMemory(BinaryData::BaseArrowFinalGain_png, BinaryData::BaseArrowFinalGain_pngSize);
    
    redInitialDrop = juce::ImageCache::getFromMemory(BinaryData::RedArrowInitialGain_png, BinaryData::RedArrowInitialGain_pngSize);
    redL2RDrop = juce::ImageCache::getFromMemory(BinaryData::RedArrowL2RGain_png, BinaryData::RedArrowL2RGain_pngSize);
    redR2LDrop = juce::ImageCache::getFromMemory(BinaryData::RedArrowR2LGain_png, BinaryData::RedArrowR2LGain_pngSize);
    redR2LFinalDrop = juce::ImageCache::getFromMemory(BinaryData::RedArrowFinalGain_png, BinaryData::RedArrowFinalGain_pngSize);
    
    baseInitialDrop = baseInitialDrop.rescaled(192, 96, juce::Graphics::highResamplingQuality);
    baseL2RDrop = baseL2RDrop.rescaled(320, 192, juce::Graphics::highResamplingQuality);
    baseR2LDrop = baseR2LDrop.rescaled(320, 192, juce::Graphics::highResamplingQuality);
    baseR2LFinalDrop = baseR2LFinalDrop.rescaled(320, 192, juce::Graphics::highResamplingQuality);
    
    redInitialDrop = redInitialDrop.rescaled(192, 96, juce::Graphics::highResamplingQuality);
    redL2RDrop = redL2RDrop.rescaled(320, 192, juce::Graphics::highResamplingQuality);
    redR2LDrop = redR2LDrop.rescaled(320, 192, juce::Graphics::highResamplingQuality);
    redR2LFinalDrop = redR2LFinalDrop.rescaled(320, 192, juce::Graphics::highResamplingQuality);
    
    baseInitialDropDrawable.setImage(baseInitialDrop);
    redInitialDropDrawable.setImage(redInitialDrop);
    
    baseL2RDropADrawable.setImage(baseL2RDrop);
    redL2RDropADrawable.setImage(redL2RDrop);
    
    baseR2LDropADrawable.setImage(baseR2LDrop);
    redR2LDropADrawable.setImage(redR2LDrop);
    
    baseL2RDropBDrawable.setImage(baseL2RDrop);
    redL2RDropBDrawable.setImage(redL2RDrop);
    
    baseR2LDropFinalDrawable.setImage(baseR2LFinalDrop);
    redR2LDropFinalDrawable.setImage(redR2LFinalDrop);

    
    // Knob images 0 - 9.5 YYY
    mix0 = juce::ImageCache::getFromMemory(BinaryData::Mix0Knob_jpg, BinaryData::Mix0Knob_jpgSize);
    mix0x5 = juce::ImageCache::getFromMemory(BinaryData::Mix0x5Knob_jpg, BinaryData::Mix0x5Knob_jpgSize);
    mix1 = juce::ImageCache::getFromMemory(BinaryData::Mix1Knob_jpg, BinaryData::Mix1Knob_jpgSize);
    mix1x5 = juce::ImageCache::getFromMemory(BinaryData::Mix1x5Knob_jpg, BinaryData::Mix1x5Knob_jpgSize);
    mix2 = juce::ImageCache::getFromMemory(BinaryData::Mix2Knob_jpg, BinaryData::Mix2Knob_jpgSize);
    mix2x5 = juce::ImageCache::getFromMemory(BinaryData::Mix2x5Knob_jpg, BinaryData::Mix2x5Knob_jpgSize);
    mix3 = juce::ImageCache::getFromMemory(BinaryData::Mix3Knob_jpg, BinaryData::Mix3Knob_jpgSize);
    mix3x5 = juce::ImageCache::getFromMemory(BinaryData::Mix3x5Knob_jpg, BinaryData::Mix3x5Knob_jpgSize);
    mix4 = juce::ImageCache::getFromMemory(BinaryData::Mix4Knob_jpg, BinaryData::Mix4Knob_jpgSize);
    mix4x5 = juce::ImageCache::getFromMemory(BinaryData::Mix4x5Knob_jpg, BinaryData::Mix4x5Knob_jpgSize);
    mix5 = juce::ImageCache::getFromMemory(BinaryData::Mix5Knob_jpg, BinaryData::Mix5Knob_jpgSize);
    mix5x5 = juce::ImageCache::getFromMemory(BinaryData::Mix5x5Knob_jpg, BinaryData::Mix5x5Knob_jpgSize);
    mix6 = juce::ImageCache::getFromMemory(BinaryData::Mix6Knob_jpg, BinaryData::Mix6Knob_jpgSize);
    mix6x5 = juce::ImageCache::getFromMemory(BinaryData::Mix6x5Knob_jpg, BinaryData::Mix6x5Knob_jpgSize);
    mix7 = juce::ImageCache::getFromMemory(BinaryData::Mix7Knob_jpg, BinaryData::Mix7Knob_jpgSize);
    mix7x5 = juce::ImageCache::getFromMemory(BinaryData::Mix7x5Knob_jpg, BinaryData::Mix7x5Knob_jpgSize);
    mix8 = juce::ImageCache::getFromMemory(BinaryData::Mix8Knob_jpg, BinaryData::Mix8Knob_jpgSize);
    mix8x5 = juce::ImageCache::getFromMemory(BinaryData::Mix8x5Knob_jpg, BinaryData::Mix8x5Knob_jpgSize);
    mix9 = juce::ImageCache::getFromMemory(BinaryData::Mix9Knob_jpg, BinaryData::Mix9Knob_jpgSize);
    mix9x5 = juce::ImageCache::getFromMemory(BinaryData::Mix9x5Knob_jpg, BinaryData::Mix9x5Knob_jpgSize);
    
    // Knob images 10 - 19.5
    mix10 =  juce::ImageCache::getFromMemory(BinaryData::Mix10Knob_jpg, BinaryData::Mix10Knob_jpgSize);
    mix10x5 = juce::ImageCache::getFromMemory(BinaryData::Mix10x5Knob_jpg, BinaryData::Mix10x5Knob_jpgSize);
    mix11 = juce::ImageCache::getFromMemory(BinaryData::Mix11Knob_jpg, BinaryData::Mix11Knob_jpgSize);
    mix11x5 = juce::ImageCache::getFromMemory(BinaryData::Mix11x5Knob_jpg, BinaryData::Mix11x5Knob_jpgSize);
    mix12 = juce::ImageCache::getFromMemory(BinaryData::Mix12Knob_jpg, BinaryData::Mix12Knob_jpgSize);
    mix12x5 = juce::ImageCache::getFromMemory(BinaryData::Mix12x5Knob_jpg, BinaryData::Mix12x5Knob_jpgSize);
    mix13 = juce::ImageCache::getFromMemory(BinaryData::Mix13Knob_jpg, BinaryData::Mix13Knob_jpgSize);
    mix13x5 = juce::ImageCache::getFromMemory(BinaryData::Mix13x5Knob_jpg, BinaryData::Mix13x5Knob_jpgSize);
    mix14 = juce::ImageCache::getFromMemory(BinaryData::Mix14Knob_jpg, BinaryData::Mix14Knob_jpgSize);
    mix14x5 = juce::ImageCache::getFromMemory(BinaryData::Mix14x5Knob_jpg, BinaryData::Mix14x5Knob_jpgSize);
    mix15 = juce::ImageCache::getFromMemory(BinaryData::Mix15Knob_jpg, BinaryData::Mix15Knob_jpgSize);
    mix15x5 = juce::ImageCache::getFromMemory(BinaryData::Mix15x5Knob_jpg, BinaryData::Mix15x5Knob_jpgSize);
    mix16 = juce::ImageCache::getFromMemory(BinaryData::Mix16Knob_jpg, BinaryData::Mix16Knob_jpgSize);
    mix16x5 = juce::ImageCache::getFromMemory(BinaryData::Mix16x5Knob_jpg, BinaryData::Mix16x5Knob_jpgSize);
    mix17 = juce::ImageCache::getFromMemory(BinaryData::Mix17Knob_jpg, BinaryData::Mix17Knob_jpgSize);
    mix17x5 = juce::ImageCache::getFromMemory(BinaryData::Mix17x5Knob_jpg, BinaryData::Mix17x5Knob_jpgSize);
    mix18 = juce::ImageCache::getFromMemory(BinaryData::Mix18Knob_jpg, BinaryData::Mix18Knob_jpgSize);
    mix18x5 = juce::ImageCache::getFromMemory(BinaryData::Mix18x5Knob_jpg, BinaryData::Mix18x5Knob_jpgSize);
    mix19 = juce::ImageCache::getFromMemory(BinaryData::Mix19Knob_jpg, BinaryData::Mix19Knob_jpgSize);
    mix19x5 = juce::ImageCache::getFromMemory(BinaryData::Mix19x5Knob_jpg, BinaryData::Mix19x5Knob_jpgSize);
    
    // Knob images 20 - 29.5
    mix20 =  juce::ImageCache::getFromMemory(BinaryData::Mix20Knob_jpg, BinaryData::Mix20Knob_jpgSize);
    mix20x5 = juce::ImageCache::getFromMemory(BinaryData::Mix20x5Knob_jpg, BinaryData::Mix20x5Knob_jpgSize);
    mix21 = juce::ImageCache::getFromMemory(BinaryData::Mix21Knob_jpg, BinaryData::Mix21Knob_jpgSize);
    mix21x5 = juce::ImageCache::getFromMemory(BinaryData::Mix21x5Knob_jpg, BinaryData::Mix21x5Knob_jpgSize);
    mix22 = juce::ImageCache::getFromMemory(BinaryData::Mix22Knob_jpg, BinaryData::Mix22Knob_jpgSize);
    mix22x5 = juce::ImageCache::getFromMemory(BinaryData::Mix22x5Knob_jpg, BinaryData::Mix22x5Knob_jpgSize);
    mix23 = juce::ImageCache::getFromMemory(BinaryData::Mix23Knob_jpg, BinaryData::Mix23Knob_jpgSize);
    mix23x5 = juce::ImageCache::getFromMemory(BinaryData::Mix23x5Knob_jpg, BinaryData::Mix23x5Knob_jpgSize);
    mix24 = juce::ImageCache::getFromMemory(BinaryData::Mix24Knob_jpg, BinaryData::Mix24Knob_jpgSize);
    mix24x5 = juce::ImageCache::getFromMemory(BinaryData::Mix24x5Knob_jpg, BinaryData::Mix24x5Knob_jpgSize);
    mix25 = juce::ImageCache::getFromMemory(BinaryData::Mix25Knob_jpg, BinaryData::Mix25Knob_jpgSize);
    mix25x5 = juce::ImageCache::getFromMemory(BinaryData::Mix25x5Knob_jpg, BinaryData::Mix25x5Knob_jpgSize);
    mix26 = juce::ImageCache::getFromMemory(BinaryData::Mix26Knob_jpg, BinaryData::Mix26Knob_jpgSize);
    mix26x5 = juce::ImageCache::getFromMemory(BinaryData::Mix26x5Knob_jpg, BinaryData::Mix26x5Knob_jpgSize);
    mix27 = juce::ImageCache::getFromMemory(BinaryData::Mix27Knob_jpg, BinaryData::Mix27Knob_jpgSize);
    mix27x5 = juce::ImageCache::getFromMemory(BinaryData::Mix27x5Knob_jpg, BinaryData::Mix27x5Knob_jpgSize);
    mix28 = juce::ImageCache::getFromMemory(BinaryData::Mix28Knob_jpg, BinaryData::Mix28Knob_jpgSize);
    mix28x5 = juce::ImageCache::getFromMemory(BinaryData::Mix28x5Knob_jpg, BinaryData::Mix28x5Knob_jpgSize);
    mix29 = juce::ImageCache::getFromMemory(BinaryData::Mix29Knob_jpg, BinaryData::Mix29Knob_jpgSize);
    mix29x5 = juce::ImageCache::getFromMemory(BinaryData::Mix29x5Knob_jpg, BinaryData::Mix29x5Knob_jpgSize);
    
    // Knob images 30 - 39.5
    mix30 =  juce::ImageCache::getFromMemory(BinaryData::Mix30Knob_jpg, BinaryData::Mix30Knob_jpgSize);
    mix30x5 = juce::ImageCache::getFromMemory(BinaryData::Mix30x5Knob_jpg, BinaryData::Mix30x5Knob_jpgSize);
    mix31 = juce::ImageCache::getFromMemory(BinaryData::Mix31Knob_jpg, BinaryData::Mix31Knob_jpgSize);
    mix31x5 = juce::ImageCache::getFromMemory(BinaryData::Mix31x5Knob_jpg, BinaryData::Mix31x5Knob_jpgSize);
    mix32 = juce::ImageCache::getFromMemory(BinaryData::Mix32Knob_jpg, BinaryData::Mix32Knob_jpgSize);
    mix32x5 = juce::ImageCache::getFromMemory(BinaryData::Mix32x5Knob_jpg, BinaryData::Mix32x5Knob_jpgSize);
    mix33 = juce::ImageCache::getFromMemory(BinaryData::Mix33Knob_jpg, BinaryData::Mix33Knob_jpgSize);
    mix33x5 = juce::ImageCache::getFromMemory(BinaryData::Mix33x5Knob_jpg, BinaryData::Mix33x5Knob_jpgSize);
    mix34 = juce::ImageCache::getFromMemory(BinaryData::Mix34Knob_jpg, BinaryData::Mix34Knob_jpgSize);
    mix34x5 = juce::ImageCache::getFromMemory(BinaryData::Mix34x5Knob_jpg, BinaryData::Mix34x5Knob_jpgSize);
    mix35 = juce::ImageCache::getFromMemory(BinaryData::Mix35Knob_jpg, BinaryData::Mix35Knob_jpgSize);
    mix35x5 = juce::ImageCache::getFromMemory(BinaryData::Mix35x5Knob_jpg, BinaryData::Mix35x5Knob_jpgSize);
    mix36 = juce::ImageCache::getFromMemory(BinaryData::Mix36Knob_jpg, BinaryData::Mix36Knob_jpgSize);
    mix36x5 = juce::ImageCache::getFromMemory(BinaryData::Mix36x5Knob_jpg, BinaryData::Mix36x5Knob_jpgSize);
    mix37 = juce::ImageCache::getFromMemory(BinaryData::Mix37Knob_jpg, BinaryData::Mix37Knob_jpgSize);
    mix37x5 = juce::ImageCache::getFromMemory(BinaryData::Mix37x5Knob_jpg, BinaryData::Mix37x5Knob_jpgSize);
    mix38 = juce::ImageCache::getFromMemory(BinaryData::Mix38Knob_jpg, BinaryData::Mix38Knob_jpgSize);
    mix38x5 = juce::ImageCache::getFromMemory(BinaryData::Mix38x5Knob_jpg, BinaryData::Mix38x5Knob_jpgSize);
    mix39 = juce::ImageCache::getFromMemory(BinaryData::Mix39Knob_jpg, BinaryData::Mix39Knob_jpgSize);
    mix39x5 = juce::ImageCache::getFromMemory(BinaryData::Mix39x5Knob_jpg, BinaryData::Mix39x5Knob_jpgSize);
    
    // Knob images 40 - 49.5
    mix40 =  juce::ImageCache::getFromMemory(BinaryData::Mix40Knob_jpg, BinaryData::Mix40Knob_jpgSize);
    mix40x5 = juce::ImageCache::getFromMemory(BinaryData::Mix40x5Knob_jpg, BinaryData::Mix40x5Knob_jpgSize);
    mix41 = juce::ImageCache::getFromMemory(BinaryData::Mix41Knob_jpg, BinaryData::Mix41Knob_jpgSize);
    mix41x5 = juce::ImageCache::getFromMemory(BinaryData::Mix41x5Knob_jpg, BinaryData::Mix41x5Knob_jpgSize);
    mix42 = juce::ImageCache::getFromMemory(BinaryData::Mix42Knob_jpg, BinaryData::Mix42Knob_jpgSize);
    mix42x5 = juce::ImageCache::getFromMemory(BinaryData::Mix42x5Knob_jpg, BinaryData::Mix42x5Knob_jpgSize);
    mix43 = juce::ImageCache::getFromMemory(BinaryData::Mix43Knob_jpg, BinaryData::Mix43Knob_jpgSize);
    mix43x5 = juce::ImageCache::getFromMemory(BinaryData::Mix43x5Knob_jpg, BinaryData::Mix43x5Knob_jpgSize);
    mix44 = juce::ImageCache::getFromMemory(BinaryData::Mix44Knob_jpg, BinaryData::Mix44Knob_jpgSize);
    mix44x5 = juce::ImageCache::getFromMemory(BinaryData::Mix44x5Knob_jpg, BinaryData::Mix44x5Knob_jpgSize);
    mix45 = juce::ImageCache::getFromMemory(BinaryData::Mix45Knob_jpg, BinaryData::Mix45Knob_jpgSize);
    mix45x5 = juce::ImageCache::getFromMemory(BinaryData::Mix45x5Knob_jpg, BinaryData::Mix45x5Knob_jpgSize);
    mix46 = juce::ImageCache::getFromMemory(BinaryData::Mix46Knob_jpg, BinaryData::Mix46Knob_jpgSize);
    mix46x5 = juce::ImageCache::getFromMemory(BinaryData::Mix46x5Knob_jpg, BinaryData::Mix46x5Knob_jpgSize);
    mix47 = juce::ImageCache::getFromMemory(BinaryData::Mix47Knob_jpg, BinaryData::Mix47Knob_jpgSize);
    mix47x5 = juce::ImageCache::getFromMemory(BinaryData::Mix47x5Knob_jpg, BinaryData::Mix47x5Knob_jpgSize);
    mix48 = juce::ImageCache::getFromMemory(BinaryData::Mix48Knob_jpg, BinaryData::Mix48Knob_jpgSize);
    mix48x5 = juce::ImageCache::getFromMemory(BinaryData::Mix48x5Knob_jpg, BinaryData::Mix48x5Knob_jpgSize);
    mix49 = juce::ImageCache::getFromMemory(BinaryData::Mix49Knob_jpg, BinaryData::Mix49Knob_jpgSize);
    mix49x5 = juce::ImageCache::getFromMemory(BinaryData::Mix49x5Knob_jpg, BinaryData::Mix49x5Knob_jpgSize);
    
    // Knob images 50 - 59.5
    mix50 =  juce::ImageCache::getFromMemory(BinaryData::Mix50Knob_jpg, BinaryData::Mix50Knob_jpgSize);
    mix50x5 = juce::ImageCache::getFromMemory(BinaryData::Mix50x5Knob_jpg, BinaryData::Mix50x5Knob_jpgSize);
    mix51 = juce::ImageCache::getFromMemory(BinaryData::Mix51Knob_jpg, BinaryData::Mix51Knob_jpgSize);
    mix51x5 = juce::ImageCache::getFromMemory(BinaryData::Mix51x5Knob_jpg, BinaryData::Mix51x5Knob_jpgSize);
    mix52 = juce::ImageCache::getFromMemory(BinaryData::Mix52Knob_jpg, BinaryData::Mix52Knob_jpgSize);
    mix52x5 = juce::ImageCache::getFromMemory(BinaryData::Mix52x5Knob_jpg, BinaryData::Mix52x5Knob_jpgSize);
    mix53 = juce::ImageCache::getFromMemory(BinaryData::Mix53Knob_jpg, BinaryData::Mix53Knob_jpgSize);
    mix53x5 = juce::ImageCache::getFromMemory(BinaryData::Mix53x5Knob_jpg, BinaryData::Mix53x5Knob_jpgSize);
    mix54 = juce::ImageCache::getFromMemory(BinaryData::Mix54Knob_jpg, BinaryData::Mix54Knob_jpgSize);
    mix54x5 = juce::ImageCache::getFromMemory(BinaryData::Mix54x5Knob_jpg, BinaryData::Mix54x5Knob_jpgSize);
    mix55 = juce::ImageCache::getFromMemory(BinaryData::Mix55Knob_jpg, BinaryData::Mix55Knob_jpgSize);
    mix55x5 = juce::ImageCache::getFromMemory(BinaryData::Mix55x5Knob_jpg, BinaryData::Mix55x5Knob_jpgSize);
    mix56 = juce::ImageCache::getFromMemory(BinaryData::Mix56Knob_jpg, BinaryData::Mix56Knob_jpgSize);
    mix56x5 = juce::ImageCache::getFromMemory(BinaryData::Mix56x5Knob_jpg, BinaryData::Mix56x5Knob_jpgSize);
    mix57 = juce::ImageCache::getFromMemory(BinaryData::Mix57Knob_jpg, BinaryData::Mix57Knob_jpgSize);
    mix57x5 = juce::ImageCache::getFromMemory(BinaryData::Mix57x5Knob_jpg, BinaryData::Mix57x5Knob_jpgSize);
    mix58 = juce::ImageCache::getFromMemory(BinaryData::Mix58Knob_jpg, BinaryData::Mix58Knob_jpgSize);
    mix58x5 = juce::ImageCache::getFromMemory(BinaryData::Mix58x5Knob_jpg, BinaryData::Mix58x5Knob_jpgSize);
    mix59 = juce::ImageCache::getFromMemory(BinaryData::Mix59Knob_jpg, BinaryData::Mix59Knob_jpgSize);
    mix59x5 = juce::ImageCache::getFromMemory(BinaryData::Mix59x5Knob_jpg, BinaryData::Mix59x5Knob_jpgSize);
    
    // Knob images 60 - 69.5
    mix60 =  juce::ImageCache::getFromMemory(BinaryData::Mix60Knob_jpg, BinaryData::Mix60Knob_jpgSize);
    mix60x5 = juce::ImageCache::getFromMemory(BinaryData::Mix60x5Knob_jpg, BinaryData::Mix60x5Knob_jpgSize);
    mix61 = juce::ImageCache::getFromMemory(BinaryData::Mix61Knob_jpg, BinaryData::Mix61Knob_jpgSize);
    mix61x5 = juce::ImageCache::getFromMemory(BinaryData::Mix61x5Knob_jpg, BinaryData::Mix61x5Knob_jpgSize);
    mix62 = juce::ImageCache::getFromMemory(BinaryData::Mix62Knob_jpg, BinaryData::Mix62Knob_jpgSize);
    mix62x5 = juce::ImageCache::getFromMemory(BinaryData::Mix62x5Knob_jpg, BinaryData::Mix62x5Knob_jpgSize);
    mix63 = juce::ImageCache::getFromMemory(BinaryData::Mix63Knob_jpg, BinaryData::Mix63Knob_jpgSize);
    mix63x5 = juce::ImageCache::getFromMemory(BinaryData::Mix63x5Knob_jpg, BinaryData::Mix63x5Knob_jpgSize);
    mix64 = juce::ImageCache::getFromMemory(BinaryData::Mix64Knob_jpg, BinaryData::Mix64Knob_jpgSize);
    mix64x5 = juce::ImageCache::getFromMemory(BinaryData::Mix64x5Knob_jpg, BinaryData::Mix64x5Knob_jpgSize);
    mix65 = juce::ImageCache::getFromMemory(BinaryData::Mix65Knob_jpg, BinaryData::Mix65Knob_jpgSize);
    mix65x5 = juce::ImageCache::getFromMemory(BinaryData::Mix65x5Knob_jpg, BinaryData::Mix65x5Knob_jpgSize);
    mix66 = juce::ImageCache::getFromMemory(BinaryData::Mix66Knob_jpg, BinaryData::Mix66Knob_jpgSize);
    mix66x5 = juce::ImageCache::getFromMemory(BinaryData::Mix66x5Knob_jpg, BinaryData::Mix66x5Knob_jpgSize);
    mix67 = juce::ImageCache::getFromMemory(BinaryData::Mix67Knob_jpg, BinaryData::Mix67Knob_jpgSize);
    mix67x5 = juce::ImageCache::getFromMemory(BinaryData::Mix67x5Knob_jpg, BinaryData::Mix67x5Knob_jpgSize);
    mix68 = juce::ImageCache::getFromMemory(BinaryData::Mix68Knob_jpg, BinaryData::Mix68Knob_jpgSize);
    mix68x5 = juce::ImageCache::getFromMemory(BinaryData::Mix68x5Knob_jpg, BinaryData::Mix68x5Knob_jpgSize);
    mix69 = juce::ImageCache::getFromMemory(BinaryData::Mix69Knob_jpg, BinaryData::Mix69Knob_jpgSize);
    mix69x5 = juce::ImageCache::getFromMemory(BinaryData::Mix69x5Knob_jpg, BinaryData::Mix69x5Knob_jpgSize);
    
    // Knob images 70 - 79.5
    mix70 =  juce::ImageCache::getFromMemory(BinaryData::Mix70Knob_jpg, BinaryData::Mix70Knob_jpgSize);
    mix70x5 = juce::ImageCache::getFromMemory(BinaryData::Mix70x5Knob_jpg, BinaryData::Mix70x5Knob_jpgSize);
    mix71 = juce::ImageCache::getFromMemory(BinaryData::Mix71Knob_jpg, BinaryData::Mix71Knob_jpgSize);
    mix71x5 = juce::ImageCache::getFromMemory(BinaryData::Mix71x5Knob_jpg, BinaryData::Mix71x5Knob_jpgSize);
    mix72 = juce::ImageCache::getFromMemory(BinaryData::Mix72Knob_jpg, BinaryData::Mix72Knob_jpgSize);
    mix72x5 = juce::ImageCache::getFromMemory(BinaryData::Mix72x5Knob_jpg, BinaryData::Mix72x5Knob_jpgSize);
    mix73 = juce::ImageCache::getFromMemory(BinaryData::Mix73Knob_jpg, BinaryData::Mix73Knob_jpgSize);
    mix73x5 = juce::ImageCache::getFromMemory(BinaryData::Mix73x5Knob_jpg, BinaryData::Mix73x5Knob_jpgSize);
    mix74 = juce::ImageCache::getFromMemory(BinaryData::Mix74Knob_jpg, BinaryData::Mix74Knob_jpgSize);
    mix74x5 = juce::ImageCache::getFromMemory(BinaryData::Mix74x5Knob_jpg, BinaryData::Mix74x5Knob_jpgSize);
    mix75 = juce::ImageCache::getFromMemory(BinaryData::Mix75Knob_jpg, BinaryData::Mix75Knob_jpgSize);
    mix75x5 = juce::ImageCache::getFromMemory(BinaryData::Mix75x5Knob_jpg, BinaryData::Mix75x5Knob_jpgSize);
    mix76 = juce::ImageCache::getFromMemory(BinaryData::Mix76Knob_jpg, BinaryData::Mix76Knob_jpgSize);
    mix76x5 = juce::ImageCache::getFromMemory(BinaryData::Mix76x5Knob_jpg, BinaryData::Mix76x5Knob_jpgSize);
    mix77 = juce::ImageCache::getFromMemory(BinaryData::Mix77Knob_jpg, BinaryData::Mix77Knob_jpgSize);
    mix77x5 = juce::ImageCache::getFromMemory(BinaryData::Mix77x5Knob_jpg, BinaryData::Mix77x5Knob_jpgSize);
    mix78 = juce::ImageCache::getFromMemory(BinaryData::Mix78Knob_jpg, BinaryData::Mix78Knob_jpgSize);
    mix78x5 = juce::ImageCache::getFromMemory(BinaryData::Mix78x5Knob_jpg, BinaryData::Mix78x5Knob_jpgSize);
    mix79 = juce::ImageCache::getFromMemory(BinaryData::Mix79Knob_jpg, BinaryData::Mix79Knob_jpgSize);
    mix79x5 = juce::ImageCache::getFromMemory(BinaryData::Mix79x5Knob_jpg, BinaryData::Mix79x5Knob_jpgSize);
    
    // Knob images 80 - 89.5
    mix80 =  juce::ImageCache::getFromMemory(BinaryData::Mix80Knob_jpg, BinaryData::Mix80Knob_jpgSize);
    mix80x5 = juce::ImageCache::getFromMemory(BinaryData::Mix80x5Knob_jpg, BinaryData::Mix80x5Knob_jpgSize);
    mix81 = juce::ImageCache::getFromMemory(BinaryData::Mix81Knob_jpg, BinaryData::Mix81Knob_jpgSize);
    mix81x5 = juce::ImageCache::getFromMemory(BinaryData::Mix81x5Knob_jpg, BinaryData::Mix81x5Knob_jpgSize);
    mix82 = juce::ImageCache::getFromMemory(BinaryData::Mix82Knob_jpg, BinaryData::Mix82Knob_jpgSize);
    mix82x5 = juce::ImageCache::getFromMemory(BinaryData::Mix82x5Knob_jpg, BinaryData::Mix82x5Knob_jpgSize);
    mix83 = juce::ImageCache::getFromMemory(BinaryData::Mix83Knob_jpg, BinaryData::Mix83Knob_jpgSize);
    mix83x5 = juce::ImageCache::getFromMemory(BinaryData::Mix83x5Knob_jpg, BinaryData::Mix83x5Knob_jpgSize);
    mix84 = juce::ImageCache::getFromMemory(BinaryData::Mix84Knob_jpg, BinaryData::Mix84Knob_jpgSize);
    mix84x5 = juce::ImageCache::getFromMemory(BinaryData::Mix84x5Knob_jpg, BinaryData::Mix84x5Knob_jpgSize);
    mix85 = juce::ImageCache::getFromMemory(BinaryData::Mix85Knob_jpg, BinaryData::Mix85Knob_jpgSize);
    mix85x5 = juce::ImageCache::getFromMemory(BinaryData::Mix85x5Knob_jpg, BinaryData::Mix85x5Knob_jpgSize);
    mix86 = juce::ImageCache::getFromMemory(BinaryData::Mix86Knob_jpg, BinaryData::Mix86Knob_jpgSize);
    mix86x5 = juce::ImageCache::getFromMemory(BinaryData::Mix86x5Knob_jpg, BinaryData::Mix86x5Knob_jpgSize);
    mix87 = juce::ImageCache::getFromMemory(BinaryData::Mix87Knob_jpg, BinaryData::Mix87Knob_jpgSize);
    mix87x5 = juce::ImageCache::getFromMemory(BinaryData::Mix87x5Knob_jpg, BinaryData::Mix87x5Knob_jpgSize);
    mix88 = juce::ImageCache::getFromMemory(BinaryData::Mix88Knob_jpg, BinaryData::Mix88Knob_jpgSize);
    mix88x5 = juce::ImageCache::getFromMemory(BinaryData::Mix88x5Knob_jpg, BinaryData::Mix88x5Knob_jpgSize);
    mix89 = juce::ImageCache::getFromMemory(BinaryData::Mix89Knob_jpg, BinaryData::Mix89Knob_jpgSize);
    mix89x5 = juce::ImageCache::getFromMemory(BinaryData::Mix89x5Knob_jpg, BinaryData::Mix89x5Knob_jpgSize);
    
    // Knob images 90 - 99.5
    mix90 =  juce::ImageCache::getFromMemory(BinaryData::Mix90Knob_jpg, BinaryData::Mix90Knob_jpgSize);
    mix90x5 = juce::ImageCache::getFromMemory(BinaryData::Mix90x5Knob_jpg, BinaryData::Mix90x5Knob_jpgSize);
    mix91 = juce::ImageCache::getFromMemory(BinaryData::Mix91Knob_jpg, BinaryData::Mix91Knob_jpgSize);
    mix91x5 = juce::ImageCache::getFromMemory(BinaryData::Mix91x5Knob_jpg, BinaryData::Mix91x5Knob_jpgSize);
    mix92 = juce::ImageCache::getFromMemory(BinaryData::Mix92Knob_jpg, BinaryData::Mix92Knob_jpgSize);
    mix92x5 = juce::ImageCache::getFromMemory(BinaryData::Mix92x5Knob_jpg, BinaryData::Mix92x5Knob_jpgSize);
    mix93 = juce::ImageCache::getFromMemory(BinaryData::Mix93Knob_jpg, BinaryData::Mix93Knob_jpgSize);
    mix93x5 = juce::ImageCache::getFromMemory(BinaryData::Mix93x5Knob_jpg, BinaryData::Mix93x5Knob_jpgSize);
    mix94 = juce::ImageCache::getFromMemory(BinaryData::Mix94Knob_jpg, BinaryData::Mix94Knob_jpgSize);
    mix94x5 = juce::ImageCache::getFromMemory(BinaryData::Mix94x5Knob_jpg, BinaryData::Mix94x5Knob_jpgSize);
    mix95 = juce::ImageCache::getFromMemory(BinaryData::Mix95Knob_jpg, BinaryData::Mix95Knob_jpgSize);
    mix95x5 = juce::ImageCache::getFromMemory(BinaryData::Mix95x5Knob_jpg, BinaryData::Mix95x5Knob_jpgSize);
    mix96 = juce::ImageCache::getFromMemory(BinaryData::Mix96Knob_jpg, BinaryData::Mix96Knob_jpgSize);
    mix96x5 = juce::ImageCache::getFromMemory(BinaryData::Mix96x5Knob_jpg, BinaryData::Mix96x5Knob_jpgSize);
    mix97 = juce::ImageCache::getFromMemory(BinaryData::Mix97Knob_jpg, BinaryData::Mix97Knob_jpgSize);
    mix97x5 = juce::ImageCache::getFromMemory(BinaryData::Mix97x5Knob_jpg, BinaryData::Mix97x5Knob_jpgSize);
    mix98 = juce::ImageCache::getFromMemory(BinaryData::Mix98Knob_jpg, BinaryData::Mix98Knob_jpgSize);
    mix98x5 = juce::ImageCache::getFromMemory(BinaryData::Mix98x5Knob_jpg, BinaryData::Mix98x5Knob_jpgSize);
    mix99 = juce::ImageCache::getFromMemory(BinaryData::Mix99Knob_jpg, BinaryData::Mix99Knob_jpgSize);
    mix99x5 = juce::ImageCache::getFromMemory(BinaryData::Mix99x5Knob_jpg, BinaryData::Mix99x5Knob_jpgSize);
    
    // Knob image 100
    mix100 =  juce::ImageCache::getFromMemory(BinaryData::Mix100Knob_jpg, BinaryData::Mix100Knob_jpgSize);
    
    knobPosition = mix100;
    
    smoothKnobPosition = mix0;
    
    
    //
    // Initial Gain Knob
    //
    
    initialGainKnob.addListener(this);
    // Specify location in window (xPos,yPos,width,height)
    initialGainKnob.setBounds(379, 4, 40, 152);
    initialGainKnob.setRange(-70.f, 38.f, 0.1f); // (min, max, interval)
    initialGainKnob.setValue(-9.f); // initial value
    initialGainKnob.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    initialGainKnob.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 75, 25);
    initialGainKnob.setLookAndFeel(&gainLNF);
    addAndMakeVisible(initialGainKnob);

    
    //
    // Left to Right Gain Knob
    //
    
    l2RGainKnob.addListener(this);
    // Specify location in window (xPos,yPos,width,height)
    l2RGainKnob.setBounds(299, 100, 40, 152);
    l2RGainKnob.setRange(-70.f, 38.f, 0.1f); // (min, max, interval)
    l2RGainKnob.setValue(0.f); // initial value
    l2RGainKnob.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    l2RGainKnob.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 75, 25);
    l2RGainKnob.setLookAndFeel(&gainLNF);
    addAndMakeVisible(l2RGainKnob);
    
    //
    // Right to Left Gain Knob
    //
    
    r2LGainKnob.addListener(this);
    // Specify location in window (xPos,yPos,width,height)
    r2LGainKnob.setBounds(459, 244, 40, 152);
    r2LGainKnob.setRange(-70.f, 38.f, 0.1f); // (min, max, interval)
    r2LGainKnob.setValue(-6.f); // initial value
    r2LGainKnob.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    r2LGainKnob.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 75, 25);
    r2LGainKnob.setLookAndFeel(&gainLNF);
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
    mixKnob.setBounds(682,194,76,104);
    mixKnob.setRange(0.f,100.f,0.1); // (min, max, interval)
    mixKnob.setValue(100.f); // initial value
    mixKnob.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    mixKnob.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 75, 25);
    addAndMakeVisible(mixKnob);
    mixKnob.setAlpha(0.f);
    
    //
    // Smooth Knob
    //
    
    smoothKnob.addListener(this);
    // Specify location in window (xPos,yPos,width,height)
    smoothKnob.setBounds(682,462,76,104);
    smoothKnob.setRange(0.f,500.f,0.1); // (min, max, interval)
    smoothKnob.setValue(0.f); // initial value
    smoothKnob.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    smoothKnob.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 75, 25);
    addAndMakeVisible(smoothKnob);
    smoothKnob.setAlpha(0.f);
        
    
    
    //
    // Bypass Toggle
    //
    
    bypassButton.addListener(this);
    bypassButton.setBounds(20,37,116,52);
    bypassButton.setToggleState(false, juce::dontSendNotification);
    addAndMakeVisible(bypassButton);
    bypassButton.setAlpha(0.f);
    
    //
    // Sync Toggle
    //
    
    syncButton.addListener(this);
    syncButton.setBounds(20,157,116,43);
    syncButton.setToggleState(false, juce::dontSendNotification);
    addAndMakeVisible(syncButton);
    syncButton.setAlpha(0.f);
    
    //
    // Note Selection Buttons
    //
    
    wholeNoteButton.addListener(this);
    wholeNoteButton.setBounds(20,382,38,38);
    wholeNoteButton.setToggleState(false, juce::dontSendNotification);
    wholeNoteButton.setRadioGroupId(2);
    addAndMakeVisible(wholeNoteButton);
    wholeNoteButton.setAlpha(0.f);
    
    halfNoteButton.addListener(this);
    halfNoteButton.setBounds(60,382,38,38);
    halfNoteButton.setToggleState(false, juce::dontSendNotification);
    halfNoteButton.setRadioGroupId(2);
    addAndMakeVisible(halfNoteButton);
    halfNoteButton.setAlpha(0.f);
    
    quarterNoteButton.addListener(this);
    quarterNoteButton.setBounds(99,382,38,38);
    quarterNoteButton.setToggleState(true, juce::dontSendNotification);
    quarterNoteButton.setRadioGroupId(2);
    addAndMakeVisible(quarterNoteButton);
    quarterNoteButton.setAlpha(0.f);
    
    eighthNoteButton.addListener(this);
    eighthNoteButton.setBounds(20,421,38,38);
    eighthNoteButton.setToggleState(false, juce::dontSendNotification);
    eighthNoteButton.setRadioGroupId(2);
    addAndMakeVisible(eighthNoteButton);
    eighthNoteButton.setAlpha(0.f);
    
    sixteenthNoteButton.addListener(this);
    sixteenthNoteButton.setBounds(60,421,38,38);
    sixteenthNoteButton.setToggleState(false, juce::dontSendNotification);
    sixteenthNoteButton.setRadioGroupId(2);
    addAndMakeVisible(sixteenthNoteButton);
    sixteenthNoteButton.setAlpha(0.f);
    
    thirtysecondNoteButton.addListener(this);
    thirtysecondNoteButton.setBounds(99,421,38,38);
    thirtysecondNoteButton.setToggleState(false, juce::dontSendNotification);
    thirtysecondNoteButton.setRadioGroupId(2);
    addAndMakeVisible(thirtysecondNoteButton);
    thirtysecondNoteButton.setAlpha(0.f);
    
    //
    // Triplet Toggle
    //
    
    tripletButton.addListener(this);
    tripletButton.setBounds(20,490,116,43);
    tripletButton.setToggleState(false, juce::dontSendNotification);
    addAndMakeVisible(tripletButton);
    tripletButton.setAlpha(0.f);
    
    //
    // Dotted Toggle
    //
    
    dottedButton.addListener(this);
    dottedButton.setBounds(20,554,116,43);
    dottedButton.setToggleState(false, juce::dontSendNotification);
    addAndMakeVisible(dottedButton);
    dottedButton.setAlpha(0.f);
    
    //
    // L/R Selection Buttons
    //
    
    leftFirstButton.addListener(this);
    leftFirstButton.setBounds(662,37,52,52);
    leftFirstButton.setToggleState(true, juce::dontSendNotification);
    leftFirstButton.setRadioGroupId(1);
    addAndMakeVisible(leftFirstButton);
    leftFirstButton.setAlpha(0.f);
    
    rightFirstButton.addListener(this);
    rightFirstButton.setBounds(728,37,52,52);
    rightFirstButton.setToggleState(false, juce::dontSendNotification);
    rightFirstButton.setRadioGroupId(1);
    addAndMakeVisible(rightFirstButton);
    rightFirstButton.setAlpha(0.f);
    
    //
    // Smooth Toggle
    //
    
    smoothButton.addListener(this);
    smoothButton.setBounds(662,382,116,43);
    smoothButton.setToggleState(false, juce::dontSendNotification);
    smoothButton.setButtonText("Smooth MS");
    addAndMakeVisible(smoothButton);
    smoothButton.setAlpha(0.f);
    
    smoothOverlayOpacity = 0.65f;
    
    
    if(((&initialGainKnob)->getValue()) > 24.f) {
        initialGainKnob.setValue(24.0);
    }
    if(((&l2RGainKnob)->getValue()) > 24.f) {
        l2RGainKnob.setValue(24.0);
    }
    if(((&r2LGainKnob)->getValue()) > 24.f) {
        r2LGainKnob.setValue(24.0);
    }
    if(((&initialGainKnob)->getValue()) < -60.f) {
        initialGainKnob.setValue(-60.0);
    }
    if(((&l2RGainKnob)->getValue()) < -60.f) {
        l2RGainKnob.setValue(-60.0);
    }
    if(((&r2LGainKnob)->getValue()) < -60.f) {
        r2LGainKnob.setValue(-60.0);
    }

    
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
    g.drawImageAt(bgImage, 0, 0);

    
    
    if(!bypassOutcome.isValid()) {
        bypassOutcome = bypassOFFImage;
    }
    if(!syncOutcome.isValid()) {
        syncOutcome = syncOFFImage;
    }
    if(!noteOutcome.isValid()) {
        noteOutcome = noteSelector8th;
    }
    if(!tripletOutcome.isValid()) {
        tripletOutcome = tripletOFFImage;
    }
    if(!dottedOutcome.isValid()) {
        dottedOutcome = dottedOFFImage;
    }
    if(!leftRightOutcome.isValid()) {
        leftRightOutcome = leftFirstImage;
    }
    if(!smoothOutcome.isValid()) {
        smoothOutcome = smoothOFFImage;
    }
    
    
    g.drawImage(bypassOutcome, 16, 32, 128, 80, 0, 0, 400, 250);
    
    g.drawImage(syncOutcome, 16, 144, 128, 80, 0, 0, 400, 250);
    
    g.drawImage(noteOutcome, 16, 368, 128, 96, 0, 0, 400, 300);
    
    g.drawImage(tripletOutcome, 16, 480, 128, 80, 0, 0, 400, 250);
    
    g.drawImage(dottedOutcome, 16, 544, 128, 80, 0, 0, 400, 250);
    
    g.drawImage(leftRightOutcome, 656, 32, 128, 80, 0, 0, 400, 250);
    
    g.drawImage(smoothOutcome, 656, 368, 128, 80, 0, 0, 400, 250);

    g.drawImage(knobPosition, 674, 188, 90, 90, 0, 0, 1000, 1000);
    
    g.drawImage(smoothKnobPosition, 674, 456, 90, 90, 0, 0, 1000, 1000);
    

    

    
//    emptyInitialDrawable.setImage(emptyInitial);
//
//    emptyInitialDrawable.drawAt(g, 300, 20, emptyBaseOpacity);
    
    
    
//    baseInitialDropDrawable.setImage(baseInitialDrop);
    baseInitialDropDrawable.drawAt(g, 240, 32, baseInitialOpacity);
    
//    redInitialDropDrawable.setImage(redInitialDrop);
    redInitialDropDrawable.drawAt(g, 240, 32, redInitialOpacity);
    
    
//    baseL2RDropADrawable.setImage(baseL2RDrop);
    baseL2RDropADrawable.drawAt(g, 240, 112, baseL2RAOpacity);
    
//    redL2RDropADrawable.setImage(redL2RDrop);
    redL2RDropADrawable.drawAt(g, 240, 112, redL2RAOpacity);
    
    
//    baseR2LDropADrawable.setImage(baseR2LDrop);
    baseR2LDropADrawable.drawAt(g, 240, 256, baseR2LOpacity);
    
//    redR2LDropADrawable.setImage(redR2LDrop);
    redR2LDropADrawable.drawAt(g, 240, 256, redR2LOpacity);
    
    
//    baseL2RDropBDrawable.setImage(baseL2RDrop);
    baseL2RDropBDrawable.drawAt(g, 240, 400, baseL2RBOpacity);
    
//    redL2RDropBDrawable.setImage(redL2RDrop);
    redL2RDropBDrawable.drawAt(g, 240, 400, redL2RBOpacity);
    
    
//    baseR2LDropFinalDrawable.setImage(baseR2LFinalDrop);
    baseR2LDropFinalDrawable.drawAt(g, 240, 544, baseFinalOpacity);
    
//    redR2LDropFinalDrawable.setImage(redR2LFinalDrop);
    redR2LDropFinalDrawable.drawAt(g, 240, 544, redFinalOpacity);
    

    tempoOverlay.drawAt(g, 16, 224, tempoOverlayOpacity);
    smoothOverlay.drawAt(g, 656, 432, smoothOverlayOpacity);
    

    leftPingPongA.setImage(leftPingPong);
    rightPingPongA.setImage(rightPingPong);
    leftPingPongB.setImage(leftPingPong);
    rightPingPongB.setImage(rightPingPong);
    
    leftPingPongRedA.setImage(leftPingPongRed);
    rightPingPongRedA.setImage(rightPingPongRed);
    leftPingPongRedB.setImage(leftPingPongRed);
    rightPingPongRedB.setImage(rightPingPongRed);
    
    leftPingPongA.drawAt(g, 192, 80, baseInitialOpacity);
    rightPingPongA.drawAt(g, 544, 224, baseL2RAOpacity);
    leftPingPongB.drawAt(g, 192, 368, baseR2LOpacity);
    rightPingPongB.drawAt(g, 544, 512, baseL2RBOpacity);
    
    leftPingPongRedA.drawAt(g, 192, 80, redInitialOpacity);
    rightPingPongRedA.drawAt(g, 544, 224, redL2RAOpacity);
    leftPingPongRedB.drawAt(g, 192, 368, redR2LOpacity);
    rightPingPongRedB.drawAt(g, 544, 512, redL2RBOpacity);
    
    
    g.drawImage(faderBackgroundImage, 368, 0, 64, 160, 0, 16, 200, 500);
    
    g.drawImage(faderBackgroundImage, 288, 96, 64, 160, 0, 16, 200, 500);
    
    g.drawImage(faderBackgroundImage, 448, 240, 64, 160, 0, 16, 200, 500);
    

//
//    orangeInitialDrawable.setImage(orangeInitial);
//
//    orangeInitialDrawable.drawAt(g, 300, 20, 1.f);
    

    


//    g.drawImage(emptyInitial, 300, 20, 150, 75, 0, 0, 600, 300);
//    g.drawImage(orangeInitial, 300, 20, 150, 75, 0, 0, 600, 300);
    

}

void Coleman_HW2AudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

//g.drawImageAt(bypassOutcome, 16, 32);
//
//g.drawImageAt(syncOutcome, 16, 144);
//
//g.drawImageAt(noteOutcome, 16, 368);
//
//g.drawImageAt(tripletOutcome, 16, 480);
//
//g.drawImageAt(dottedOutcome, 16, 544);
//
//g.drawImageAt(leftRightOutcome, 656, 32);
//
//g.drawImageAt(smoothOutcome, 656, 480);

void Coleman_HW2AudioProcessorEditor::buttonClicked(juce::Button *button){
    if (button == &bypassButton){
        bool bypassBool = bypassButton.getToggleState();
        if(bypassBool) {
            bypassOutcome = bypassONImage;
        } else {
            bypassOutcome = bypassOFFImage;
        }
        repaint(16, 32, 128, 64);
    }
    if (button == &syncButton) {
        bool syncBool = syncButton.getToggleState();
        if(syncBool) {
            syncOutcome = syncONImage;
            tempoOverlayOpacity = 0.65f;
        } else {
            syncOutcome = syncOFFImage;
            tempoOverlayOpacity = 0.f;
        }
//        repaint(16, 144, 128, 64);
        repaint();
    }
    if (button == &wholeNoteButton) {
        noteOutcome = noteSelectorWhole;
        repaint(16, 368, 128, 96);
    }
    if (button == &halfNoteButton) {
        noteOutcome = noteSelectorHalf;
        repaint(16, 368, 128, 96);
    }
    if (button == &quarterNoteButton) {
        noteOutcome = noteSelectorQuarter;
        repaint(16, 368, 128, 96);
    }
    if (button == &eighthNoteButton) {
        noteOutcome = noteSelector8th;
        repaint(16, 368, 128, 96);
    }
    if (button == &sixteenthNoteButton) {
        noteOutcome = noteSelector16th;
        repaint(16, 368, 128, 96);
    }
    if (button == &thirtysecondNoteButton) {
        noteOutcome = noteSelector32nd;
        repaint(16, 368, 128, 96);
    }
    if (button == &tripletButton){
        bool tripletBool = tripletButton.getToggleState();
        if(tripletBool) {
            tripletOutcome = tripletONImage;
        } else {
            tripletOutcome = tripletOFFImage;
        }
        repaint(16, 480, 128, 64);
    }
    if (button == &dottedButton) {
        bool dottedBool = dottedButton.getToggleState();
        if(dottedBool) {
            dottedOutcome = dottedONImage;
        } else {
            dottedOutcome = dottedOFFImage;
        }
        repaint(16, 544, 128, 64);
    }
    if (button == &leftFirstButton) {
        bool leftSelectedBool = leftFirstButton.getToggleState();
        if(leftSelectedBool) {
            leftRightOutcome = leftFirstImage;
            repaint(656, 32, 128, 64);
        }
    }
    if (button == &rightFirstButton) {
        bool rightSelectedBool = rightFirstButton.getToggleState();
        if(rightSelectedBool) {
            leftRightOutcome = rightFirstImage;
            repaint(656, 32, 128, 64);
        }
    }
    if (button == &smoothButton) {
        bool smoothBool = smoothButton.getToggleState();
        if(smoothBool) {
            smoothOutcome = smoothONImage;
            smoothOverlayOpacity = 0.f;
        } else {
            smoothOutcome = smoothOFFImage;
            smoothOverlayOpacity = 0.65f;
        }
        repaint();
    }
}

void Coleman_HW2AudioProcessorEditor::sliderValueChanged(juce::Slider * slider)
{
    // This is how we check which slider was moved
    if (slider == &initialGainKnob || slider == &l2RGainKnob || slider == &r2LGainKnob){
        
        float initialValue = (&initialGainKnob)->getValue();
        float l2RValueRaw = (&l2RGainKnob)->getValue();
        float r2LValueRaw = (&r2LGainKnob)->getValue();
        float l2RAValue = initialValue + l2RValueRaw;
        float r2LValue = r2LValueRaw + initialValue + l2RValueRaw;
        float l2RBValue = l2RValueRaw + r2LValueRaw + initialValue + l2RValueRaw;
        float finalValue = r2LValueRaw + l2RValueRaw + r2LValueRaw + initialValue + l2RValueRaw;
        
        // Red values < 6 dB
        if(initialValue <= 0.f) {redInitialOpacity = redOpacity[0];}
        else if(initialValue < 0.2f) {redInitialOpacity = redOpacity[1];}
        else if(initialValue < 0.4f) {redInitialOpacity = redOpacity[2];}
        else if(initialValue < 0.6f) {redInitialOpacity = redOpacity[3];}
        else if(initialValue < 0.8f) {redInitialOpacity = redOpacity[4];}
        else if(initialValue < 1.f)  {redInitialOpacity = redOpacity[5];}
        else if(initialValue < 1.2f) {redInitialOpacity = redOpacity[6];}
        else if(initialValue < 1.4f) {redInitialOpacity = redOpacity[7];}
        else if(initialValue < 1.6f) {redInitialOpacity = redOpacity[8];}
        else if(initialValue < 1.8f) {redInitialOpacity = redOpacity[9];}
        else if(initialValue < 2.f)  {redInitialOpacity = redOpacity[10];}
        else if(initialValue < 2.2f) {redInitialOpacity = redOpacity[11];}
        else if(initialValue < 2.4f) {redInitialOpacity = redOpacity[12];}
        else if(initialValue < 2.6f) {redInitialOpacity = redOpacity[13];}
        else if(initialValue < 2.8f) {redInitialOpacity = redOpacity[14];}
        else if(initialValue < 3.f)  {redInitialOpacity = redOpacity[15];}
        else if(initialValue < 3.2f) {redInitialOpacity = redOpacity[16];}
        else if(initialValue < 3.4f) {redInitialOpacity = redOpacity[17];}
        else if(initialValue < 3.6f) {redInitialOpacity = redOpacity[18];}
        else if(initialValue < 3.8f) {redInitialOpacity = redOpacity[19];}
        else if(initialValue < 4.f)  {redInitialOpacity = redOpacity[20];}
        else if(initialValue < 4.2f) {redInitialOpacity = redOpacity[21];}
        else if(initialValue < 4.4f) {redInitialOpacity = redOpacity[22];}
        else if(initialValue < 4.6f) {redInitialOpacity = redOpacity[23];}
        else if(initialValue < 4.8f) {redInitialOpacity = redOpacity[24];}
        else if(initialValue < 5.f)  {redInitialOpacity = redOpacity[25];}
        else if(initialValue < 5.2f) {redInitialOpacity = redOpacity[26];}
        else if(initialValue < 5.4f) {redInitialOpacity = redOpacity[27];}
        else if(initialValue < 5.6f) {redInitialOpacity = redOpacity[28];}
        else if(initialValue < 5.8f) {redInitialOpacity = redOpacity[29];}
        else if(initialValue < 6.f)  {redInitialOpacity = redOpacity[30];}
        
        // 6 dB <= Red values < 12 dB
        else if(initialValue < 6.2f) {redInitialOpacity = redOpacity[31];}
        else if(initialValue < 6.4f) {redInitialOpacity = redOpacity[32];}
        else if(initialValue < 6.6f) {redInitialOpacity = redOpacity[33];}
        else if(initialValue < 6.8f) {redInitialOpacity = redOpacity[34];}
        else if(initialValue < 7.f)  {redInitialOpacity = redOpacity[35];}
        else if(initialValue < 7.2f) {redInitialOpacity = redOpacity[36];}
        else if(initialValue < 7.4f) {redInitialOpacity = redOpacity[37];}
        else if(initialValue < 7.6f) {redInitialOpacity = redOpacity[38];}
        else if(initialValue < 7.8f) {redInitialOpacity = redOpacity[39];}
        else if(initialValue < 8.f)  {redInitialOpacity = redOpacity[40];}
        else if(initialValue < 8.2f) {redInitialOpacity = redOpacity[41];}
        else if(initialValue < 8.4f) {redInitialOpacity = redOpacity[42];}
        else if(initialValue < 8.6f) {redInitialOpacity = redOpacity[43];}
        else if(initialValue < 8.8f) {redInitialOpacity = redOpacity[44];}
        else if(initialValue < 9.f)  {redInitialOpacity = redOpacity[45];}
        else if(initialValue < 9.2f) {redInitialOpacity = redOpacity[46];}
        else if(initialValue < 9.4f) {redInitialOpacity = redOpacity[47];}
        else if(initialValue < 9.6f) {redInitialOpacity = redOpacity[48];}
        else if(initialValue < 9.8f) {redInitialOpacity = redOpacity[49];}
        else if(initialValue < 10.f) {redInitialOpacity = redOpacity[50];}
        else if(initialValue < 10.2f) {redInitialOpacity = redOpacity[51];}
        else if(initialValue < 10.4f) {redInitialOpacity = redOpacity[52];}
        else if(initialValue < 10.6f) {redInitialOpacity = redOpacity[53];}
        else if(initialValue < 10.8f) {redInitialOpacity = redOpacity[54];}
        else if(initialValue < 11.f)  {redInitialOpacity = redOpacity[55];}
        else if(initialValue < 11.2f) {redInitialOpacity = redOpacity[56];}
        else if(initialValue < 11.4f) {redInitialOpacity = redOpacity[57];}
        else if(initialValue < 11.6f) {redInitialOpacity = redOpacity[58];}
        else if(initialValue < 11.8f) {redInitialOpacity = redOpacity[59];}
        else if(initialValue < 12.f)  {redInitialOpacity = redOpacity[60];}
        
        // 12 dB <= Red values < 18 dB
        else if(initialValue < 12.2f) {redInitialOpacity = redOpacity[61];}
        else if(initialValue < 12.4f) {redInitialOpacity = redOpacity[62];}
        else if(initialValue < 12.6f) {redInitialOpacity = redOpacity[63];}
        else if(initialValue < 12.8f) {redInitialOpacity = redOpacity[64];}
        else if(initialValue < 13.f)  {redInitialOpacity = redOpacity[65];}
        else if(initialValue < 13.2f) {redInitialOpacity = redOpacity[66];}
        else if(initialValue < 13.4f) {redInitialOpacity = redOpacity[67];}
        else if(initialValue < 13.6f) {redInitialOpacity = redOpacity[68];}
        else if(initialValue < 13.8f) {redInitialOpacity = redOpacity[69];}
        else if(initialValue < 14.f)  {redInitialOpacity = redOpacity[70];}
        else if(initialValue < 14.2f) {redInitialOpacity = redOpacity[71];}
        else if(initialValue < 14.4f) {redInitialOpacity = redOpacity[72];}
        else if(initialValue < 14.6f) {redInitialOpacity = redOpacity[73];}
        else if(initialValue < 14.8f) {redInitialOpacity = redOpacity[74];}
        else if(initialValue < 15.f)  {redInitialOpacity = redOpacity[75];}
        else if(initialValue < 15.2f) {redInitialOpacity = redOpacity[76];}
        else if(initialValue < 15.4f) {redInitialOpacity = redOpacity[77];}
        else if(initialValue < 15.6f) {redInitialOpacity = redOpacity[78];}
        else if(initialValue < 15.8f) {redInitialOpacity = redOpacity[79];}
        else if(initialValue < 16.f)  {redInitialOpacity = redOpacity[80];}
        else if(initialValue < 16.2f) {redInitialOpacity = redOpacity[81];}
        else if(initialValue < 16.4f) {redInitialOpacity = redOpacity[82];}
        else if(initialValue < 16.6f) {redInitialOpacity = redOpacity[83];}
        else if(initialValue < 16.8f) {redInitialOpacity = redOpacity[84];}
        else if(initialValue < 17.f)  {redInitialOpacity = redOpacity[85];}
        else if(initialValue < 17.2f) {redInitialOpacity = redOpacity[86];}
        else if(initialValue < 17.4f) {redInitialOpacity = redOpacity[87];}
        else if(initialValue < 17.6f) {redInitialOpacity = redOpacity[88];}
        else if(initialValue < 17.8f) {redInitialOpacity = redOpacity[89];}
        else if(initialValue < 18.f)  {redInitialOpacity = redOpacity[90];}
        
        // 18 dB <= Red values <= 24 dB
        else if(initialValue < 18.2f) {redInitialOpacity = redOpacity[91];}
        else if(initialValue < 18.4f) {redInitialOpacity = redOpacity[92];}
        else if(initialValue < 18.6f) {redInitialOpacity = redOpacity[93];}
        else if(initialValue < 18.8f) {redInitialOpacity = redOpacity[94];}
        else if(initialValue < 19.f)  {redInitialOpacity = redOpacity[95];}
        else if(initialValue < 19.2f) {redInitialOpacity = redOpacity[96];}
        else if(initialValue < 19.4f) {redInitialOpacity = redOpacity[97];}
        else if(initialValue < 19.6f) {redInitialOpacity = redOpacity[98];}
        else if(initialValue < 19.8f) {redInitialOpacity = redOpacity[99];}
        else if(initialValue < 20.f)  {redInitialOpacity = redOpacity[100];}
        else if(initialValue < 20.2f) {redInitialOpacity = redOpacity[101];}
        else if(initialValue < 20.4f) {redInitialOpacity = redOpacity[102];}
        else if(initialValue < 20.6f) {redInitialOpacity = redOpacity[103];}
        else if(initialValue < 20.8f) {redInitialOpacity = redOpacity[104];}
        else if(initialValue < 21.f)  {redInitialOpacity = redOpacity[105];}
        else if(initialValue < 21.2f) {redInitialOpacity = redOpacity[106];}
        else if(initialValue < 21.4f) {redInitialOpacity = redOpacity[107];}
        else if(initialValue < 21.6f) {redInitialOpacity = redOpacity[108];}
        else if(initialValue < 21.8f) {redInitialOpacity = redOpacity[109];}
        else if(initialValue < 22.f)  {redInitialOpacity = redOpacity[110];}
        else if(initialValue < 22.2f) {redInitialOpacity = redOpacity[111];}
        else if(initialValue < 22.4f) {redInitialOpacity = redOpacity[112];}
        else if(initialValue < 22.6f) {redInitialOpacity = redOpacity[113];}
        else if(initialValue < 22.8f) {redInitialOpacity = redOpacity[114];}
        else if(initialValue < 23.f)  {redInitialOpacity = redOpacity[115];}
        else if(initialValue < 23.2f) {redInitialOpacity = redOpacity[116];}
        else if(initialValue < 23.4f) {redInitialOpacity = redOpacity[117];}
        else if(initialValue < 23.6f) {redInitialOpacity = redOpacity[118];}
        else if(initialValue < 23.8f) {redInitialOpacity = redOpacity[119];}
        else if(initialValue < 24.f)  {redInitialOpacity = redOpacity[120];}
        else if(initialValue >= 24.f) {redInitialOpacity = redOpacity[121];}
        else {redInitialOpacity = redOpacity[0];}
        
        
        if(initialValue == 0.f) {baseInitialOpacity = baseOpacity[200];}
        else if(initialValue > -0.2f) {baseInitialOpacity = baseOpacity[199];}
        else if(initialValue > -0.4f) {baseInitialOpacity = baseOpacity[198];}
        else if(initialValue > -0.6f) {baseInitialOpacity = baseOpacity[197];}
        else if(initialValue > -0.8f) {baseInitialOpacity = baseOpacity[196];}
        else if(initialValue > -1.f)  {baseInitialOpacity = baseOpacity[195];}
        else if(initialValue > -1.2f) {baseInitialOpacity = baseOpacity[194];}
        else if(initialValue > -1.4f) {baseInitialOpacity = baseOpacity[193];}
        else if(initialValue > -1.6f) {baseInitialOpacity = baseOpacity[192];}
        else if(initialValue > -1.8f) {baseInitialOpacity = baseOpacity[191];}
        else if(initialValue > -2.f)  {baseInitialOpacity = baseOpacity[190];}
        else if(initialValue > -2.2f) {baseInitialOpacity = baseOpacity[189];}
        else if(initialValue > -2.4f) {baseInitialOpacity = baseOpacity[188];}
        else if(initialValue > -2.6f) {baseInitialOpacity = baseOpacity[187];}
        else if(initialValue > -2.8f) {baseInitialOpacity = baseOpacity[186];}
        else if(initialValue > -3.f)  {baseInitialOpacity = baseOpacity[185];}
        else if(initialValue > -3.2f) {baseInitialOpacity = baseOpacity[184];}
        else if(initialValue > -3.4f) {baseInitialOpacity = baseOpacity[183];}
        else if(initialValue > -3.6f) {baseInitialOpacity = baseOpacity[182];}
        else if(initialValue > -3.8f) {baseInitialOpacity = baseOpacity[181];}
        else if(initialValue > -4.f)  {baseInitialOpacity = baseOpacity[180];}
        else if(initialValue > -4.2f) {baseInitialOpacity = baseOpacity[179];}
        else if(initialValue > -4.4f) {baseInitialOpacity = baseOpacity[178];}
        else if(initialValue > -4.6f) {baseInitialOpacity = baseOpacity[177];}
        else if(initialValue > -4.8f) {baseInitialOpacity = baseOpacity[176];}
        else if(initialValue > -5.f)  {baseInitialOpacity = baseOpacity[175];}
        else if(initialValue > -5.2f) {baseInitialOpacity = baseOpacity[174];}
        else if(initialValue > -5.4f) {baseInitialOpacity = baseOpacity[173];}
        else if(initialValue > -5.6f) {baseInitialOpacity = baseOpacity[172];}
        else if(initialValue > -5.8f) {baseInitialOpacity = baseOpacity[171];}
        else if(initialValue > -6.f)  {baseInitialOpacity = baseOpacity[170];}

        // 6 dB <= Red values < 12 dB
        else if(initialValue > -6.2f) {baseInitialOpacity = baseOpacity[169];}
        else if(initialValue > -6.4f) {baseInitialOpacity = baseOpacity[168];}
        else if(initialValue > -6.6f) {baseInitialOpacity = baseOpacity[167];}
        else if(initialValue > -6.8f) {baseInitialOpacity = baseOpacity[166];}
        else if(initialValue > -7.f)  {baseInitialOpacity = baseOpacity[165];}
        else if(initialValue > -7.2f) {baseInitialOpacity = baseOpacity[164];}
        else if(initialValue > -7.4f) {baseInitialOpacity = baseOpacity[163];}
        else if(initialValue > -7.6f) {baseInitialOpacity = baseOpacity[162];}
        else if(initialValue > -7.8f) {baseInitialOpacity = baseOpacity[161];}
        else if(initialValue > -8.f)  {baseInitialOpacity = baseOpacity[160];}
        else if(initialValue > -8.2f) {baseInitialOpacity = baseOpacity[159];}
        else if(initialValue > -8.4f) {baseInitialOpacity = baseOpacity[158];}
        else if(initialValue > -8.6f) {baseInitialOpacity = baseOpacity[157];}
        else if(initialValue > -8.8f) {baseInitialOpacity = baseOpacity[156];}
        else if(initialValue > -9.f)  {baseInitialOpacity = baseOpacity[155];}
        else if(initialValue > -9.2f) {baseInitialOpacity = baseOpacity[154];}
        else if(initialValue > -9.4f) {baseInitialOpacity = baseOpacity[153];}
        else if(initialValue > -9.6f) {baseInitialOpacity = baseOpacity[152];}
        else if(initialValue > -9.8f) {baseInitialOpacity = baseOpacity[151];}
        else if(initialValue > -10.f) {baseInitialOpacity = baseOpacity[150];}
        else if(initialValue > -10.2f) {baseInitialOpacity = baseOpacity[149];}
        else if(initialValue > -10.4f) {baseInitialOpacity = baseOpacity[148];}
        else if(initialValue > -10.6f) {baseInitialOpacity = baseOpacity[147];}
        else if(initialValue > -10.8f) {baseInitialOpacity = baseOpacity[146];}
        else if(initialValue > -11.f)  {baseInitialOpacity = baseOpacity[145];}
        else if(initialValue > -11.2f) {baseInitialOpacity = baseOpacity[144];}
        else if(initialValue > -11.4f) {baseInitialOpacity = baseOpacity[143];}
        else if(initialValue > -11.6f) {baseInitialOpacity = baseOpacity[142];}
        else if(initialValue > -11.8f) {baseInitialOpacity = baseOpacity[141];}
        else if(initialValue > -12.f)  {baseInitialOpacity = baseOpacity[140];}

        // 12 dB <= Red values < 18 dB
        else if(initialValue > -12.2f) {baseInitialOpacity = baseOpacity[139];}
        else if(initialValue > -12.4f) {baseInitialOpacity = baseOpacity[138];}
        else if(initialValue > -12.6f) {baseInitialOpacity = baseOpacity[137];}
        else if(initialValue > -12.8f) {baseInitialOpacity = baseOpacity[136];}
        else if(initialValue > -13.f)  {baseInitialOpacity = baseOpacity[135];}
        else if(initialValue > -13.2f) {baseInitialOpacity = baseOpacity[134];}
        else if(initialValue > -13.4f) {baseInitialOpacity = baseOpacity[133];}
        else if(initialValue > -13.6f) {baseInitialOpacity = baseOpacity[132];}
        else if(initialValue > -13.8f) {baseInitialOpacity = baseOpacity[131];}
        else if(initialValue > -14.f)  {baseInitialOpacity = baseOpacity[130];}
        else if(initialValue > -14.2f) {baseInitialOpacity = baseOpacity[129];}
        else if(initialValue > -14.4f) {baseInitialOpacity = baseOpacity[128];}
        else if(initialValue > -14.6f) {baseInitialOpacity = baseOpacity[127];}
        else if(initialValue > -14.8f) {baseInitialOpacity = baseOpacity[126];}
        else if(initialValue > -15.f)  {baseInitialOpacity = baseOpacity[125];}
        else if(initialValue > -15.2f) {baseInitialOpacity = baseOpacity[124];}
        else if(initialValue > -15.4f) {baseInitialOpacity = baseOpacity[123];}
        else if(initialValue > -15.6f) {baseInitialOpacity = baseOpacity[122];}
        else if(initialValue > -15.8f) {baseInitialOpacity = baseOpacity[121];}
        else if(initialValue > -16.f)  {baseInitialOpacity = baseOpacity[120];}
        else if(initialValue > -16.2f) {baseInitialOpacity = baseOpacity[119];}
        else if(initialValue > -16.4f) {baseInitialOpacity = baseOpacity[118];}
        else if(initialValue > -16.6f) {baseInitialOpacity = baseOpacity[117];}
        else if(initialValue > -16.8f) {baseInitialOpacity = baseOpacity[116];}
        else if(initialValue > -17.f)  {baseInitialOpacity = baseOpacity[115];}
        else if(initialValue > -17.2f) {baseInitialOpacity = baseOpacity[114];}
        else if(initialValue > -17.4f) {baseInitialOpacity = baseOpacity[113];}
        else if(initialValue > -17.6f) {baseInitialOpacity = baseOpacity[112];}
        else if(initialValue > -17.8f) {baseInitialOpacity = baseOpacity[111];}
        else if(initialValue > -18.f)  {baseInitialOpacity = baseOpacity[110];}

        // 18 dB <= Red values <= 24 dB
        else if(initialValue > -18.2f) {baseInitialOpacity = baseOpacity[109];}
        else if(initialValue > -18.4f) {baseInitialOpacity = baseOpacity[108];}
        else if(initialValue > -18.6f) {baseInitialOpacity = baseOpacity[107];}
        else if(initialValue > -18.8f) {baseInitialOpacity = baseOpacity[106];}
        else if(initialValue > -19.f)  {baseInitialOpacity = baseOpacity[105];}
        else if(initialValue > -19.2f) {baseInitialOpacity = baseOpacity[104];}
        else if(initialValue > -19.4f) {baseInitialOpacity = baseOpacity[103];}
        else if(initialValue > -19.6f) {baseInitialOpacity = baseOpacity[102];}
        else if(initialValue > -19.8f) {baseInitialOpacity = baseOpacity[101];}
        else if(initialValue > -20.f)  {baseInitialOpacity = baseOpacity[100];}
        else if(initialValue > -20.2f) {baseInitialOpacity = baseOpacity[99];}
        else if(initialValue > -20.4f) {baseInitialOpacity = baseOpacity[98];}
        else if(initialValue > -20.6f) {baseInitialOpacity = baseOpacity[97];}
        else if(initialValue > -20.8f) {baseInitialOpacity = baseOpacity[96];}
        else if(initialValue > -21.f)  {baseInitialOpacity = baseOpacity[95];}
        else if(initialValue > -21.2f) {baseInitialOpacity = baseOpacity[94];}
        else if(initialValue > -21.4f) {baseInitialOpacity = baseOpacity[93];}
        else if(initialValue > -21.6f) {baseInitialOpacity = baseOpacity[92];}
        else if(initialValue > -21.8f) {baseInitialOpacity = baseOpacity[91];}
        else if(initialValue > -22.f)  {baseInitialOpacity = baseOpacity[90];}
        else if(initialValue > -22.2f) {baseInitialOpacity = baseOpacity[89];}
        else if(initialValue > -22.4f) {baseInitialOpacity = baseOpacity[88];}
        else if(initialValue > -22.6f) {baseInitialOpacity = baseOpacity[87];}
        else if(initialValue > -22.8f) {baseInitialOpacity = baseOpacity[86];}
        else if(initialValue > -23.f)  {baseInitialOpacity = baseOpacity[85];}
        else if(initialValue > -23.2f) {baseInitialOpacity = baseOpacity[84];}
        else if(initialValue > -23.4f) {baseInitialOpacity = baseOpacity[83];}
        else if(initialValue > -23.6f) {baseInitialOpacity = baseOpacity[82];}
        else if(initialValue > -23.8f) {baseInitialOpacity = baseOpacity[81];}
        else if(initialValue > -24.f)  {baseInitialOpacity = baseOpacity[80];}

        // 18 dB <= Red values <= 24 dB
        else if(initialValue > -24.3f) {baseInitialOpacity = baseOpacity[79];}
        else if(initialValue > -24.6f) {baseInitialOpacity = baseOpacity[78];}
        else if(initialValue > -24.9f) {baseInitialOpacity = baseOpacity[77];}
        else if(initialValue > -25.2f) {baseInitialOpacity = baseOpacity[76];}
        else if(initialValue > -25.5f) {baseInitialOpacity = baseOpacity[75];}
        else if(initialValue > -25.8f) {baseInitialOpacity = baseOpacity[74];}
        else if(initialValue > -26.1f) {baseInitialOpacity = baseOpacity[73];}
        else if(initialValue > -26.4f) {baseInitialOpacity = baseOpacity[72];}
        else if(initialValue > -26.7f) {baseInitialOpacity = baseOpacity[71];}
        else if(initialValue > -27.f)  {baseInitialOpacity = baseOpacity[70];}
        else if(initialValue > -27.3f) {baseInitialOpacity = baseOpacity[69];}
        else if(initialValue > -27.6f) {baseInitialOpacity = baseOpacity[68];}
        else if(initialValue > -27.9f) {baseInitialOpacity = baseOpacity[67];}
        else if(initialValue > -28.2f) {baseInitialOpacity = baseOpacity[66];}
        else if(initialValue > -28.5f) {baseInitialOpacity = baseOpacity[65];}
        else if(initialValue > -28.8f) {baseInitialOpacity = baseOpacity[64];}
        else if(initialValue > -29.1f) {baseInitialOpacity = baseOpacity[63];}
        else if(initialValue > -29.4f) {baseInitialOpacity = baseOpacity[62];}
        else if(initialValue > -29.7f) {baseInitialOpacity = baseOpacity[61];}
        else if(initialValue > -30.f)  {baseInitialOpacity = baseOpacity[60];}
        
        else if(initialValue > -30.3f) {baseInitialOpacity = baseOpacity[59];}
        else if(initialValue > -30.6f) {baseInitialOpacity = baseOpacity[58];}
        else if(initialValue > -30.9f) {baseInitialOpacity = baseOpacity[57];}
        else if(initialValue > -31.2f) {baseInitialOpacity = baseOpacity[56];}
        else if(initialValue > -31.5f) {baseInitialOpacity = baseOpacity[55];}
        else if(initialValue > -31.8f) {baseInitialOpacity = baseOpacity[54];}
        else if(initialValue > -32.1f) {baseInitialOpacity = baseOpacity[53];}
        else if(initialValue > -32.4f) {baseInitialOpacity = baseOpacity[52];}
        else if(initialValue > -32.7f) {baseInitialOpacity = baseOpacity[51];}
        else if(initialValue > -33.f)  {baseInitialOpacity = baseOpacity[50];}
        else if(initialValue > -33.3f) {baseInitialOpacity = baseOpacity[49];}
        else if(initialValue > -33.6f) {baseInitialOpacity = baseOpacity[48];}
        else if(initialValue > -33.9f) {baseInitialOpacity = baseOpacity[47];}
        else if(initialValue > -34.2f) {baseInitialOpacity = baseOpacity[46];}
        else if(initialValue > -34.5f) {baseInitialOpacity = baseOpacity[45];}
        else if(initialValue > -34.8f) {baseInitialOpacity = baseOpacity[44];}
        else if(initialValue > -35.1f) {baseInitialOpacity = baseOpacity[43];}
        else if(initialValue > -35.4f) {baseInitialOpacity = baseOpacity[42];}
        else if(initialValue > -35.7f) {baseInitialOpacity = baseOpacity[41];}
        else if(initialValue > -36.f)  {baseInitialOpacity = baseOpacity[40];}
        
        
        else if(initialValue > -36.6f) {baseInitialOpacity = baseOpacity[39];}
        else if(initialValue > -37.2f) {baseInitialOpacity = baseOpacity[38];}
        else if(initialValue > -37.8f) {baseInitialOpacity = baseOpacity[37];}
        else if(initialValue > -38.4f) {baseInitialOpacity = baseOpacity[36];}
        else if(initialValue > -39.f)  {baseInitialOpacity = baseOpacity[35];}
        else if(initialValue > -39.6f) {baseInitialOpacity = baseOpacity[34];}
        else if(initialValue > -40.2f) {baseInitialOpacity = baseOpacity[33];}
        else if(initialValue > -40.8f) {baseInitialOpacity = baseOpacity[32];}
        else if(initialValue > -41.4f) {baseInitialOpacity = baseOpacity[31];}
        else if(initialValue > -42.f)  {baseInitialOpacity = baseOpacity[30];}
        
        else if(initialValue > -42.6f) {baseInitialOpacity = baseOpacity[29];}
        else if(initialValue > -43.2f) {baseInitialOpacity = baseOpacity[28];}
        else if(initialValue > -43.8f) {baseInitialOpacity = baseOpacity[27];}
        else if(initialValue > -44.4f) {baseInitialOpacity = baseOpacity[26];}
        else if(initialValue > -45.f)  {baseInitialOpacity = baseOpacity[25];}
        else if(initialValue > -45.6f) {baseInitialOpacity = baseOpacity[24];}
        else if(initialValue > -46.2f) {baseInitialOpacity = baseOpacity[23];}
        else if(initialValue > -46.8f) {baseInitialOpacity = baseOpacity[22];}
        else if(initialValue > -47.4f) {baseInitialOpacity = baseOpacity[21];}
        else if(initialValue > -48.f)  {baseInitialOpacity = baseOpacity[20];}
        
        else if(initialValue > -48.6f) {baseInitialOpacity = baseOpacity[19];}
        else if(initialValue > -49.2f) {baseInitialOpacity = baseOpacity[18];}
        else if(initialValue > -49.8f) {baseInitialOpacity = baseOpacity[17];}
        else if(initialValue > -50.4f) {baseInitialOpacity = baseOpacity[16];}
        else if(initialValue > -51.f)  {baseInitialOpacity = baseOpacity[15];}
        else if(initialValue > -51.6f) {baseInitialOpacity = baseOpacity[14];}
        else if(initialValue > -52.2f) {baseInitialOpacity = baseOpacity[13];}
        else if(initialValue > -52.8f) {baseInitialOpacity = baseOpacity[12];}
        else if(initialValue > -53.4f) {baseInitialOpacity = baseOpacity[11];}
        else if(initialValue > -54.f)  {baseInitialOpacity = baseOpacity[10];}
        
        else if(initialValue > -54.6f) {baseInitialOpacity = baseOpacity[9];}
        else if(initialValue > -55.2f) {baseInitialOpacity = baseOpacity[8];}
        else if(initialValue > -55.8f) {baseInitialOpacity = baseOpacity[7];}
        else if(initialValue > -56.4f) {baseInitialOpacity = baseOpacity[6];}
        else if(initialValue > -57.f)  {baseInitialOpacity = baseOpacity[5];}
        else if(initialValue > -57.6f) {baseInitialOpacity = baseOpacity[4];}
        else if(initialValue > -58.2f) {baseInitialOpacity = baseOpacity[3];}
        else if(initialValue > -58.8f) {baseInitialOpacity = baseOpacity[2];}
        else if(initialValue > -59.4f) {baseInitialOpacity = baseOpacity[1];}
        else if(initialValue > -60.f)  {baseInitialOpacity = baseOpacity[0];}
        else if(initialValue <= -60.f) {baseInitialOpacity = baseOpacity[0];}
        else {baseInitialOpacity = baseOpacity[0];}
        
    // L2RA
        
        if(l2RAValue <= 0.f) {redL2RAOpacity = redOpacity[0];}
        else if(l2RAValue < 0.2f) {redL2RAOpacity = redOpacity[1];}
        else if(l2RAValue < 0.4f) {redL2RAOpacity = redOpacity[2];}
        else if(l2RAValue < 0.6f) {redL2RAOpacity = redOpacity[3];}
        else if(l2RAValue < 0.8f) {redL2RAOpacity = redOpacity[4];}
        else if(l2RAValue < 1.f)  {redL2RAOpacity = redOpacity[5];}
        else if(l2RAValue < 1.2f) {redL2RAOpacity = redOpacity[6];}
        else if(l2RAValue < 1.4f) {redL2RAOpacity = redOpacity[7];}
        else if(l2RAValue < 1.6f) {redL2RAOpacity = redOpacity[8];}
        else if(l2RAValue < 1.8f) {redL2RAOpacity = redOpacity[9];}
        else if(l2RAValue < 2.f)  {redL2RAOpacity = redOpacity[10];}
        else if(l2RAValue < 2.2f) {redL2RAOpacity = redOpacity[11];}
        else if(l2RAValue < 2.4f) {redL2RAOpacity = redOpacity[12];}
        else if(l2RAValue < 2.6f) {redL2RAOpacity = redOpacity[13];}
        else if(l2RAValue < 2.8f) {redL2RAOpacity = redOpacity[14];}
        else if(l2RAValue < 3.f)  {redL2RAOpacity = redOpacity[15];}
        else if(l2RAValue < 3.2f) {redL2RAOpacity = redOpacity[16];}
        else if(l2RAValue < 3.4f) {redL2RAOpacity = redOpacity[17];}
        else if(l2RAValue < 3.6f) {redL2RAOpacity = redOpacity[18];}
        else if(l2RAValue < 3.8f) {redL2RAOpacity = redOpacity[19];}
        else if(l2RAValue < 4.f)  {redL2RAOpacity = redOpacity[20];}
        else if(l2RAValue < 4.2f) {redL2RAOpacity = redOpacity[21];}
        else if(l2RAValue < 4.4f) {redL2RAOpacity = redOpacity[22];}
        else if(l2RAValue < 4.6f) {redL2RAOpacity = redOpacity[23];}
        else if(l2RAValue < 4.8f) {redL2RAOpacity = redOpacity[24];}
        else if(l2RAValue < 5.f)  {redL2RAOpacity = redOpacity[25];}
        else if(l2RAValue < 5.2f) {redL2RAOpacity = redOpacity[26];}
        else if(l2RAValue < 5.4f) {redL2RAOpacity = redOpacity[27];}
        else if(l2RAValue < 5.6f) {redL2RAOpacity = redOpacity[28];}
        else if(l2RAValue < 5.8f) {redL2RAOpacity = redOpacity[29];}
        else if(l2RAValue < 6.f)  {redL2RAOpacity = redOpacity[30];}

        // 6 dB <= Red values < 12 dB
        else if(l2RAValue < 6.2f) {redL2RAOpacity = redOpacity[31];}
        else if(l2RAValue < 6.4f) {redL2RAOpacity = redOpacity[32];}
        else if(l2RAValue < 6.6f) {redL2RAOpacity = redOpacity[33];}
        else if(l2RAValue < 6.8f) {redL2RAOpacity = redOpacity[34];}
        else if(l2RAValue < 7.f)  {redL2RAOpacity = redOpacity[35];}
        else if(l2RAValue < 7.2f) {redL2RAOpacity = redOpacity[36];}
        else if(l2RAValue < 7.4f) {redL2RAOpacity = redOpacity[37];}
        else if(l2RAValue < 7.6f) {redL2RAOpacity = redOpacity[38];}
        else if(l2RAValue < 7.8f) {redL2RAOpacity = redOpacity[39];}
        else if(l2RAValue < 8.f)  {redL2RAOpacity = redOpacity[40];}
        else if(l2RAValue < 8.2f) {redL2RAOpacity = redOpacity[41];}
        else if(l2RAValue < 8.4f) {redL2RAOpacity = redOpacity[42];}
        else if(l2RAValue < 8.6f) {redL2RAOpacity = redOpacity[43];}
        else if(l2RAValue < 8.8f) {redL2RAOpacity = redOpacity[44];}
        else if(l2RAValue < 9.f)  {redL2RAOpacity = redOpacity[45];}
        else if(l2RAValue < 9.2f) {redL2RAOpacity = redOpacity[46];}
        else if(l2RAValue < 9.4f) {redL2RAOpacity = redOpacity[47];}
        else if(l2RAValue < 9.6f) {redL2RAOpacity = redOpacity[48];}
        else if(l2RAValue < 9.8f) {redL2RAOpacity = redOpacity[49];}
        else if(l2RAValue < 10.f) {redL2RAOpacity = redOpacity[50];}
        else if(l2RAValue < 10.2f) {redL2RAOpacity = redOpacity[51];}
        else if(l2RAValue < 10.4f) {redL2RAOpacity = redOpacity[52];}
        else if(l2RAValue < 10.6f) {redL2RAOpacity = redOpacity[53];}
        else if(l2RAValue < 10.8f) {redL2RAOpacity = redOpacity[54];}
        else if(l2RAValue < 11.f)  {redL2RAOpacity = redOpacity[55];}
        else if(l2RAValue < 11.2f) {redL2RAOpacity = redOpacity[56];}
        else if(l2RAValue < 11.4f) {redL2RAOpacity = redOpacity[57];}
        else if(l2RAValue < 11.6f) {redL2RAOpacity = redOpacity[58];}
        else if(l2RAValue < 11.8f) {redL2RAOpacity = redOpacity[59];}
        else if(l2RAValue < 12.f)  {redL2RAOpacity = redOpacity[60];}

        // 12 dB <= Red values < 18 dB
        else if(l2RAValue < 12.2f) {redL2RAOpacity = redOpacity[61];}
        else if(l2RAValue < 12.4f) {redL2RAOpacity = redOpacity[62];}
        else if(l2RAValue < 12.6f) {redL2RAOpacity = redOpacity[63];}
        else if(l2RAValue < 12.8f) {redL2RAOpacity = redOpacity[64];}
        else if(l2RAValue < 13.f)  {redL2RAOpacity = redOpacity[65];}
        else if(l2RAValue < 13.2f) {redL2RAOpacity = redOpacity[66];}
        else if(l2RAValue < 13.4f) {redL2RAOpacity = redOpacity[67];}
        else if(l2RAValue < 13.6f) {redL2RAOpacity = redOpacity[68];}
        else if(l2RAValue < 13.8f) {redL2RAOpacity = redOpacity[69];}
        else if(l2RAValue < 14.f)  {redL2RAOpacity = redOpacity[70];}
        else if(l2RAValue < 14.2f) {redL2RAOpacity = redOpacity[71];}
        else if(l2RAValue < 14.4f) {redL2RAOpacity = redOpacity[72];}
        else if(l2RAValue < 14.6f) {redL2RAOpacity = redOpacity[73];}
        else if(l2RAValue < 14.8f) {redL2RAOpacity = redOpacity[74];}
        else if(l2RAValue < 15.f)  {redL2RAOpacity = redOpacity[75];}
        else if(l2RAValue < 15.2f) {redL2RAOpacity = redOpacity[76];}
        else if(l2RAValue < 15.4f) {redL2RAOpacity = redOpacity[77];}
        else if(l2RAValue < 15.6f) {redL2RAOpacity = redOpacity[78];}
        else if(l2RAValue < 15.8f) {redL2RAOpacity = redOpacity[79];}
        else if(l2RAValue < 16.f)  {redL2RAOpacity = redOpacity[80];}
        else if(l2RAValue < 16.2f) {redL2RAOpacity = redOpacity[81];}
        else if(l2RAValue < 16.4f) {redL2RAOpacity = redOpacity[82];}
        else if(l2RAValue < 16.6f) {redL2RAOpacity = redOpacity[83];}
        else if(l2RAValue < 16.8f) {redL2RAOpacity = redOpacity[84];}
        else if(l2RAValue < 17.f)  {redL2RAOpacity = redOpacity[85];}
        else if(l2RAValue < 17.2f) {redL2RAOpacity = redOpacity[86];}
        else if(l2RAValue < 17.4f) {redL2RAOpacity = redOpacity[87];}
        else if(l2RAValue < 17.6f) {redL2RAOpacity = redOpacity[88];}
        else if(l2RAValue < 17.8f) {redL2RAOpacity = redOpacity[89];}
        else if(l2RAValue < 18.f)  {redL2RAOpacity = redOpacity[90];}

        // 18 dB <= Red values <= 24 dB
        else if(l2RAValue < 18.2f) {redL2RAOpacity = redOpacity[91];}
        else if(l2RAValue < 18.4f) {redL2RAOpacity = redOpacity[92];}
        else if(l2RAValue < 18.6f) {redL2RAOpacity = redOpacity[93];}
        else if(l2RAValue < 18.8f) {redL2RAOpacity = redOpacity[94];}
        else if(l2RAValue < 19.f)  {redL2RAOpacity = redOpacity[95];}
        else if(l2RAValue < 19.2f) {redL2RAOpacity = redOpacity[96];}
        else if(l2RAValue < 19.4f) {redL2RAOpacity = redOpacity[97];}
        else if(l2RAValue < 19.6f) {redL2RAOpacity = redOpacity[98];}
        else if(l2RAValue < 19.8f) {redL2RAOpacity = redOpacity[99];}
        else if(l2RAValue < 20.f)  {redL2RAOpacity = redOpacity[100];}
        else if(l2RAValue < 20.2f) {redL2RAOpacity = redOpacity[101];}
        else if(l2RAValue < 20.4f) {redL2RAOpacity = redOpacity[102];}
        else if(l2RAValue < 20.6f) {redL2RAOpacity = redOpacity[103];}
        else if(l2RAValue < 20.8f) {redL2RAOpacity = redOpacity[104];}
        else if(l2RAValue < 21.f)  {redL2RAOpacity = redOpacity[105];}
        else if(l2RAValue < 21.2f) {redL2RAOpacity = redOpacity[106];}
        else if(l2RAValue < 21.4f) {redL2RAOpacity = redOpacity[107];}
        else if(l2RAValue < 21.6f) {redL2RAOpacity = redOpacity[108];}
        else if(l2RAValue < 21.8f) {redL2RAOpacity = redOpacity[109];}
        else if(l2RAValue < 22.f)  {redL2RAOpacity = redOpacity[110];}
        else if(l2RAValue < 22.2f) {redL2RAOpacity = redOpacity[111];}
        else if(l2RAValue < 22.4f) {redL2RAOpacity = redOpacity[112];}
        else if(l2RAValue < 22.6f) {redL2RAOpacity = redOpacity[113];}
        else if(l2RAValue < 22.8f) {redL2RAOpacity = redOpacity[114];}
        else if(l2RAValue < 23.f)  {redL2RAOpacity = redOpacity[115];}
        else if(l2RAValue < 23.2f) {redL2RAOpacity = redOpacity[116];}
        else if(l2RAValue < 23.4f) {redL2RAOpacity = redOpacity[117];}
        else if(l2RAValue < 23.6f) {redL2RAOpacity = redOpacity[118];}
        else if(l2RAValue < 23.8f) {redL2RAOpacity = redOpacity[119];}
        else if(l2RAValue < 24.f)  {redL2RAOpacity = redOpacity[120];}
        else if(l2RAValue >= 24.f) {redL2RAOpacity = redOpacity[121];}
        else {redL2RAOpacity = redOpacity[0];}


        if(l2RAValue == 0.f) {baseL2RAOpacity = baseOpacity[200];}
        else if(l2RAValue > -0.2f) {baseL2RAOpacity = baseOpacity[199];}
        else if(l2RAValue > -0.4f) {baseL2RAOpacity = baseOpacity[198];}
        else if(l2RAValue > -0.6f) {baseL2RAOpacity = baseOpacity[197];}
        else if(l2RAValue > -0.8f) {baseL2RAOpacity = baseOpacity[196];}
        else if(l2RAValue > -1.f)  {baseL2RAOpacity = baseOpacity[195];}
        else if(l2RAValue > -1.2f) {baseL2RAOpacity = baseOpacity[194];}
        else if(l2RAValue > -1.4f) {baseL2RAOpacity = baseOpacity[193];}
        else if(l2RAValue > -1.6f) {baseL2RAOpacity = baseOpacity[192];}
        else if(l2RAValue > -1.8f) {baseL2RAOpacity = baseOpacity[191];}
        else if(l2RAValue > -2.f)  {baseL2RAOpacity = baseOpacity[190];}
        else if(l2RAValue > -2.2f) {baseL2RAOpacity = baseOpacity[189];}
        else if(l2RAValue > -2.4f) {baseL2RAOpacity = baseOpacity[188];}
        else if(l2RAValue > -2.6f) {baseL2RAOpacity = baseOpacity[187];}
        else if(l2RAValue > -2.8f) {baseL2RAOpacity = baseOpacity[186];}
        else if(l2RAValue > -3.f)  {baseL2RAOpacity = baseOpacity[185];}
        else if(l2RAValue > -3.2f) {baseL2RAOpacity = baseOpacity[184];}
        else if(l2RAValue > -3.4f) {baseL2RAOpacity = baseOpacity[183];}
        else if(l2RAValue > -3.6f) {baseL2RAOpacity = baseOpacity[182];}
        else if(l2RAValue > -3.8f) {baseL2RAOpacity = baseOpacity[181];}
        else if(l2RAValue > -4.f)  {baseL2RAOpacity = baseOpacity[180];}
        else if(l2RAValue > -4.2f) {baseL2RAOpacity = baseOpacity[179];}
        else if(l2RAValue > -4.4f) {baseL2RAOpacity = baseOpacity[178];}
        else if(l2RAValue > -4.6f) {baseL2RAOpacity = baseOpacity[177];}
        else if(l2RAValue > -4.8f) {baseL2RAOpacity = baseOpacity[176];}
        else if(l2RAValue > -5.f)  {baseL2RAOpacity = baseOpacity[175];}
        else if(l2RAValue > -5.2f) {baseL2RAOpacity = baseOpacity[174];}
        else if(l2RAValue > -5.4f) {baseL2RAOpacity = baseOpacity[173];}
        else if(l2RAValue > -5.6f) {baseL2RAOpacity = baseOpacity[172];}
        else if(l2RAValue > -5.8f) {baseL2RAOpacity = baseOpacity[171];}
        else if(l2RAValue > -6.f)  {baseL2RAOpacity = baseOpacity[170];}

        // 6 dB <= Red values < 12 dB
        else if(l2RAValue > -6.2f) {baseL2RAOpacity = baseOpacity[169];}
        else if(l2RAValue > -6.4f) {baseL2RAOpacity = baseOpacity[168];}
        else if(l2RAValue > -6.6f) {baseL2RAOpacity = baseOpacity[167];}
        else if(l2RAValue > -6.8f) {baseL2RAOpacity = baseOpacity[166];}
        else if(l2RAValue > -7.f)  {baseL2RAOpacity = baseOpacity[165];}
        else if(l2RAValue > -7.2f) {baseL2RAOpacity = baseOpacity[164];}
        else if(l2RAValue > -7.4f) {baseL2RAOpacity = baseOpacity[163];}
        else if(l2RAValue > -7.6f) {baseL2RAOpacity = baseOpacity[162];}
        else if(l2RAValue > -7.8f) {baseL2RAOpacity = baseOpacity[161];}
        else if(l2RAValue > -8.f)  {baseL2RAOpacity = baseOpacity[160];}
        else if(l2RAValue > -8.2f) {baseL2RAOpacity = baseOpacity[159];}
        else if(l2RAValue > -8.4f) {baseL2RAOpacity = baseOpacity[158];}
        else if(l2RAValue > -8.6f) {baseL2RAOpacity = baseOpacity[157];}
        else if(l2RAValue > -8.8f) {baseL2RAOpacity = baseOpacity[156];}
        else if(l2RAValue > -9.f)  {baseL2RAOpacity = baseOpacity[155];}
        else if(l2RAValue > -9.2f) {baseL2RAOpacity = baseOpacity[154];}
        else if(l2RAValue > -9.4f) {baseL2RAOpacity = baseOpacity[153];}
        else if(l2RAValue > -9.6f) {baseL2RAOpacity = baseOpacity[152];}
        else if(l2RAValue > -9.8f) {baseL2RAOpacity = baseOpacity[151];}
        else if(l2RAValue > -10.f) {baseL2RAOpacity = baseOpacity[150];}
        else if(l2RAValue > -10.2f) {baseL2RAOpacity = baseOpacity[149];}
        else if(l2RAValue > -10.4f) {baseL2RAOpacity = baseOpacity[148];}
        else if(l2RAValue > -10.6f) {baseL2RAOpacity = baseOpacity[147];}
        else if(l2RAValue > -10.8f) {baseL2RAOpacity = baseOpacity[146];}
        else if(l2RAValue > -11.f)  {baseL2RAOpacity = baseOpacity[145];}
        else if(l2RAValue > -11.2f) {baseL2RAOpacity = baseOpacity[144];}
        else if(l2RAValue > -11.4f) {baseL2RAOpacity = baseOpacity[143];}
        else if(l2RAValue > -11.6f) {baseL2RAOpacity = baseOpacity[142];}
        else if(l2RAValue > -11.8f) {baseL2RAOpacity = baseOpacity[141];}
        else if(l2RAValue > -12.f)  {baseL2RAOpacity = baseOpacity[140];}

        // 12 dB <= Red values < 18 dB
        else if(l2RAValue > -12.2f) {baseL2RAOpacity = baseOpacity[139];}
        else if(l2RAValue > -12.4f) {baseL2RAOpacity = baseOpacity[138];}
        else if(l2RAValue > -12.6f) {baseL2RAOpacity = baseOpacity[137];}
        else if(l2RAValue > -12.8f) {baseL2RAOpacity = baseOpacity[136];}
        else if(l2RAValue > -13.f)  {baseL2RAOpacity = baseOpacity[135];}
        else if(l2RAValue > -13.2f) {baseL2RAOpacity = baseOpacity[134];}
        else if(l2RAValue > -13.4f) {baseL2RAOpacity = baseOpacity[133];}
        else if(l2RAValue > -13.6f) {baseL2RAOpacity = baseOpacity[132];}
        else if(l2RAValue > -13.8f) {baseL2RAOpacity = baseOpacity[131];}
        else if(l2RAValue > -14.f)  {baseL2RAOpacity = baseOpacity[130];}
        else if(l2RAValue > -14.2f) {baseL2RAOpacity = baseOpacity[129];}
        else if(l2RAValue > -14.4f) {baseL2RAOpacity = baseOpacity[128];}
        else if(l2RAValue > -14.6f) {baseL2RAOpacity = baseOpacity[127];}
        else if(l2RAValue > -14.8f) {baseL2RAOpacity = baseOpacity[126];}
        else if(l2RAValue > -15.f)  {baseL2RAOpacity = baseOpacity[125];}
        else if(l2RAValue > -15.2f) {baseL2RAOpacity = baseOpacity[124];}
        else if(l2RAValue > -15.4f) {baseL2RAOpacity = baseOpacity[123];}
        else if(l2RAValue > -15.6f) {baseL2RAOpacity = baseOpacity[122];}
        else if(l2RAValue > -15.8f) {baseL2RAOpacity = baseOpacity[121];}
        else if(l2RAValue > -16.f)  {baseL2RAOpacity = baseOpacity[120];}
        else if(l2RAValue > -16.2f) {baseL2RAOpacity = baseOpacity[119];}
        else if(l2RAValue > -16.4f) {baseL2RAOpacity = baseOpacity[118];}
        else if(l2RAValue > -16.6f) {baseL2RAOpacity = baseOpacity[117];}
        else if(l2RAValue > -16.8f) {baseL2RAOpacity = baseOpacity[116];}
        else if(l2RAValue > -17.f)  {baseL2RAOpacity = baseOpacity[115];}
        else if(l2RAValue > -17.2f) {baseL2RAOpacity = baseOpacity[114];}
        else if(l2RAValue > -17.4f) {baseL2RAOpacity = baseOpacity[113];}
        else if(l2RAValue > -17.6f) {baseL2RAOpacity = baseOpacity[112];}
        else if(l2RAValue > -17.8f) {baseL2RAOpacity = baseOpacity[111];}
        else if(l2RAValue > -18.f)  {baseL2RAOpacity = baseOpacity[110];}

        // 18 dB <= Red values <= 24 dB
        else if(l2RAValue > -18.2f) {baseL2RAOpacity = baseOpacity[109];}
        else if(l2RAValue > -18.4f) {baseL2RAOpacity = baseOpacity[108];}
        else if(l2RAValue > -18.6f) {baseL2RAOpacity = baseOpacity[107];}
        else if(l2RAValue > -18.8f) {baseL2RAOpacity = baseOpacity[106];}
        else if(l2RAValue > -19.f)  {baseL2RAOpacity = baseOpacity[105];}
        else if(l2RAValue > -19.2f) {baseL2RAOpacity = baseOpacity[104];}
        else if(l2RAValue > -19.4f) {baseL2RAOpacity = baseOpacity[103];}
        else if(l2RAValue > -19.6f) {baseL2RAOpacity = baseOpacity[102];}
        else if(l2RAValue > -19.8f) {baseL2RAOpacity = baseOpacity[101];}
        else if(l2RAValue > -20.f)  {baseL2RAOpacity = baseOpacity[100];}
        else if(l2RAValue > -20.2f) {baseL2RAOpacity = baseOpacity[99];}
        else if(l2RAValue > -20.4f) {baseL2RAOpacity = baseOpacity[98];}
        else if(l2RAValue > -20.6f) {baseL2RAOpacity = baseOpacity[97];}
        else if(l2RAValue > -20.8f) {baseL2RAOpacity = baseOpacity[96];}
        else if(l2RAValue > -21.f)  {baseL2RAOpacity = baseOpacity[95];}
        else if(l2RAValue > -21.2f) {baseL2RAOpacity = baseOpacity[94];}
        else if(l2RAValue > -21.4f) {baseL2RAOpacity = baseOpacity[93];}
        else if(l2RAValue > -21.6f) {baseL2RAOpacity = baseOpacity[92];}
        else if(l2RAValue > -21.8f) {baseL2RAOpacity = baseOpacity[91];}
        else if(l2RAValue > -22.f)  {baseL2RAOpacity = baseOpacity[90];}
        else if(l2RAValue > -22.2f) {baseL2RAOpacity = baseOpacity[89];}
        else if(l2RAValue > -22.4f) {baseL2RAOpacity = baseOpacity[88];}
        else if(l2RAValue > -22.6f) {baseL2RAOpacity = baseOpacity[87];}
        else if(l2RAValue > -22.8f) {baseL2RAOpacity = baseOpacity[86];}
        else if(l2RAValue > -23.f)  {baseL2RAOpacity = baseOpacity[85];}
        else if(l2RAValue > -23.2f) {baseL2RAOpacity = baseOpacity[84];}
        else if(l2RAValue > -23.4f) {baseL2RAOpacity = baseOpacity[83];}
        else if(l2RAValue > -23.6f) {baseL2RAOpacity = baseOpacity[82];}
        else if(l2RAValue > -23.8f) {baseL2RAOpacity = baseOpacity[81];}
        else if(l2RAValue > -24.f)  {baseL2RAOpacity = baseOpacity[80];}

        // 18 dB <= Red values <= 24 dB
        else if(l2RAValue > -24.3f) {baseL2RAOpacity = baseOpacity[79];}
        else if(l2RAValue > -24.6f) {baseL2RAOpacity = baseOpacity[78];}
        else if(l2RAValue > -24.9f) {baseL2RAOpacity = baseOpacity[77];}
        else if(l2RAValue > -25.2f) {baseL2RAOpacity = baseOpacity[76];}
        else if(l2RAValue > -25.5f) {baseL2RAOpacity = baseOpacity[75];}
        else if(l2RAValue > -25.8f) {baseL2RAOpacity = baseOpacity[74];}
        else if(l2RAValue > -26.1f) {baseL2RAOpacity = baseOpacity[73];}
        else if(l2RAValue > -26.4f) {baseL2RAOpacity = baseOpacity[72];}
        else if(l2RAValue > -26.7f) {baseL2RAOpacity = baseOpacity[71];}
        else if(l2RAValue > -27.f)  {baseL2RAOpacity = baseOpacity[70];}
        else if(l2RAValue > -27.3f) {baseL2RAOpacity = baseOpacity[69];}
        else if(l2RAValue > -27.6f) {baseL2RAOpacity = baseOpacity[68];}
        else if(l2RAValue > -27.9f) {baseL2RAOpacity = baseOpacity[67];}
        else if(l2RAValue > -28.2f) {baseL2RAOpacity = baseOpacity[66];}
        else if(l2RAValue > -28.5f) {baseL2RAOpacity = baseOpacity[65];}
        else if(l2RAValue > -28.8f) {baseL2RAOpacity = baseOpacity[64];}
        else if(l2RAValue > -29.1f) {baseL2RAOpacity = baseOpacity[63];}
        else if(l2RAValue > -29.4f) {baseL2RAOpacity = baseOpacity[62];}
        else if(l2RAValue > -29.7f) {baseL2RAOpacity = baseOpacity[61];}
        else if(l2RAValue > -30.f)  {baseL2RAOpacity = baseOpacity[60];}

        else if(l2RAValue > -30.3f) {baseL2RAOpacity = baseOpacity[59];}
        else if(l2RAValue > -30.6f) {baseL2RAOpacity = baseOpacity[58];}
        else if(l2RAValue > -30.9f) {baseL2RAOpacity = baseOpacity[57];}
        else if(l2RAValue > -31.2f) {baseL2RAOpacity = baseOpacity[56];}
        else if(l2RAValue > -31.5f) {baseL2RAOpacity = baseOpacity[55];}
        else if(l2RAValue > -31.8f) {baseL2RAOpacity = baseOpacity[54];}
        else if(l2RAValue > -32.1f) {baseL2RAOpacity = baseOpacity[53];}
        else if(l2RAValue > -32.4f) {baseL2RAOpacity = baseOpacity[52];}
        else if(l2RAValue > -32.7f) {baseL2RAOpacity = baseOpacity[51];}
        else if(l2RAValue > -33.f)  {baseL2RAOpacity = baseOpacity[50];}
        else if(l2RAValue > -33.3f) {baseL2RAOpacity = baseOpacity[49];}
        else if(l2RAValue > -33.6f) {baseL2RAOpacity = baseOpacity[48];}
        else if(l2RAValue > -33.9f) {baseL2RAOpacity = baseOpacity[47];}
        else if(l2RAValue > -34.2f) {baseL2RAOpacity = baseOpacity[46];}
        else if(l2RAValue > -34.5f) {baseL2RAOpacity = baseOpacity[45];}
        else if(l2RAValue > -34.8f) {baseL2RAOpacity = baseOpacity[44];}
        else if(l2RAValue > -35.1f) {baseL2RAOpacity = baseOpacity[43];}
        else if(l2RAValue > -35.4f) {baseL2RAOpacity = baseOpacity[42];}
        else if(l2RAValue > -35.7f) {baseL2RAOpacity = baseOpacity[41];}
        else if(l2RAValue > -36.f)  {baseL2RAOpacity = baseOpacity[40];}


        else if(l2RAValue > -36.6f) {baseL2RAOpacity = baseOpacity[39];}
        else if(l2RAValue > -37.2f) {baseL2RAOpacity = baseOpacity[38];}
        else if(l2RAValue > -37.8f) {baseL2RAOpacity = baseOpacity[37];}
        else if(l2RAValue > -38.4f) {baseL2RAOpacity = baseOpacity[36];}
        else if(l2RAValue > -39.f)  {baseL2RAOpacity = baseOpacity[35];}
        else if(l2RAValue > -39.6f) {baseL2RAOpacity = baseOpacity[34];}
        else if(l2RAValue > -40.2f) {baseL2RAOpacity = baseOpacity[33];}
        else if(l2RAValue > -40.8f) {baseL2RAOpacity = baseOpacity[32];}
        else if(l2RAValue > -41.4f) {baseL2RAOpacity = baseOpacity[31];}
        else if(l2RAValue > -42.f)  {baseL2RAOpacity = baseOpacity[30];}

        else if(l2RAValue > -42.6f) {baseL2RAOpacity = baseOpacity[29];}
        else if(l2RAValue > -43.2f) {baseL2RAOpacity = baseOpacity[28];}
        else if(l2RAValue > -43.8f) {baseL2RAOpacity = baseOpacity[27];}
        else if(l2RAValue > -44.4f) {baseL2RAOpacity = baseOpacity[26];}
        else if(l2RAValue > -45.f)  {baseL2RAOpacity = baseOpacity[25];}
        else if(l2RAValue > -45.6f) {baseL2RAOpacity = baseOpacity[24];}
        else if(l2RAValue > -46.2f) {baseL2RAOpacity = baseOpacity[23];}
        else if(l2RAValue > -46.8f) {baseL2RAOpacity = baseOpacity[22];}
        else if(l2RAValue > -47.4f) {baseL2RAOpacity = baseOpacity[21];}
        else if(l2RAValue > -48.f)  {baseL2RAOpacity = baseOpacity[20];}

        else if(l2RAValue > -48.6f) {baseL2RAOpacity = baseOpacity[19];}
        else if(l2RAValue > -49.2f) {baseL2RAOpacity = baseOpacity[18];}
        else if(l2RAValue > -49.8f) {baseL2RAOpacity = baseOpacity[17];}
        else if(l2RAValue > -50.4f) {baseL2RAOpacity = baseOpacity[16];}
        else if(l2RAValue > -51.f)  {baseL2RAOpacity = baseOpacity[15];}
        else if(l2RAValue > -51.6f) {baseL2RAOpacity = baseOpacity[14];}
        else if(l2RAValue > -52.2f) {baseL2RAOpacity = baseOpacity[13];}
        else if(l2RAValue > -52.8f) {baseL2RAOpacity = baseOpacity[12];}
        else if(l2RAValue > -53.4f) {baseL2RAOpacity = baseOpacity[11];}
        else if(l2RAValue > -54.f)  {baseL2RAOpacity = baseOpacity[10];}

        else if(l2RAValue > -54.6f) {baseL2RAOpacity = baseOpacity[9];}
        else if(l2RAValue > -55.2f) {baseL2RAOpacity = baseOpacity[8];}
        else if(l2RAValue > -55.8f) {baseL2RAOpacity = baseOpacity[7];}
        else if(l2RAValue > -56.4f) {baseL2RAOpacity = baseOpacity[6];}
        else if(l2RAValue > -57.f)  {baseL2RAOpacity = baseOpacity[5];}
        else if(l2RAValue > -57.6f) {baseL2RAOpacity = baseOpacity[4];}
        else if(l2RAValue > -58.2f) {baseL2RAOpacity = baseOpacity[3];}
        else if(l2RAValue > -58.8f) {baseL2RAOpacity = baseOpacity[2];}
        else if(l2RAValue > -59.4f) {baseL2RAOpacity = baseOpacity[1];}
        else if(l2RAValue > -60.f)  {baseL2RAOpacity = baseOpacity[0];}
        else if(l2RAValue <= -60.f) {baseL2RAOpacity = baseOpacity[0];}
        else {baseL2RAOpacity = baseOpacity[0];}
        
    // R2L
        
        if(r2LValue <= 0.f) {redR2LOpacity = redOpacity[0];}
        else if(r2LValue < 0.2f) {redR2LOpacity = redOpacity[1];}
        else if(r2LValue < 0.4f) {redR2LOpacity = redOpacity[2];}
        else if(r2LValue < 0.6f) {redR2LOpacity = redOpacity[3];}
        else if(r2LValue < 0.8f) {redR2LOpacity = redOpacity[4];}
        else if(r2LValue < 1.f)  {redR2LOpacity = redOpacity[5];}
        else if(r2LValue < 1.2f) {redR2LOpacity = redOpacity[6];}
        else if(r2LValue < 1.4f) {redR2LOpacity = redOpacity[7];}
        else if(r2LValue < 1.6f) {redR2LOpacity = redOpacity[8];}
        else if(r2LValue < 1.8f) {redR2LOpacity = redOpacity[9];}
        else if(r2LValue < 2.f)  {redR2LOpacity = redOpacity[10];}
        else if(r2LValue < 2.2f) {redR2LOpacity = redOpacity[11];}
        else if(r2LValue < 2.4f) {redR2LOpacity = redOpacity[12];}
        else if(r2LValue < 2.6f) {redR2LOpacity = redOpacity[13];}
        else if(r2LValue < 2.8f) {redR2LOpacity = redOpacity[14];}
        else if(r2LValue < 3.f)  {redR2LOpacity = redOpacity[15];}
        else if(r2LValue < 3.2f) {redR2LOpacity = redOpacity[16];}
        else if(r2LValue < 3.4f) {redR2LOpacity = redOpacity[17];}
        else if(r2LValue < 3.6f) {redR2LOpacity = redOpacity[18];}
        else if(r2LValue < 3.8f) {redR2LOpacity = redOpacity[19];}
        else if(r2LValue < 4.f)  {redR2LOpacity = redOpacity[20];}
        else if(r2LValue < 4.2f) {redR2LOpacity = redOpacity[21];}
        else if(r2LValue < 4.4f) {redR2LOpacity = redOpacity[22];}
        else if(r2LValue < 4.6f) {redR2LOpacity = redOpacity[23];}
        else if(r2LValue < 4.8f) {redR2LOpacity = redOpacity[24];}
        else if(r2LValue < 5.f)  {redR2LOpacity = redOpacity[25];}
        else if(r2LValue < 5.2f) {redR2LOpacity = redOpacity[26];}
        else if(r2LValue < 5.4f) {redR2LOpacity = redOpacity[27];}
        else if(r2LValue < 5.6f) {redR2LOpacity = redOpacity[28];}
        else if(r2LValue < 5.8f) {redR2LOpacity = redOpacity[29];}
        else if(r2LValue < 6.f)  {redR2LOpacity = redOpacity[30];}

        // 6 dB <= Red values < 12 dB
        else if(r2LValue < 6.2f) {redR2LOpacity = redOpacity[31];}
        else if(r2LValue < 6.4f) {redR2LOpacity = redOpacity[32];}
        else if(r2LValue < 6.6f) {redR2LOpacity = redOpacity[33];}
        else if(r2LValue < 6.8f) {redR2LOpacity = redOpacity[34];}
        else if(r2LValue < 7.f)  {redR2LOpacity = redOpacity[35];}
        else if(r2LValue < 7.2f) {redR2LOpacity = redOpacity[36];}
        else if(r2LValue < 7.4f) {redR2LOpacity = redOpacity[37];}
        else if(r2LValue < 7.6f) {redR2LOpacity = redOpacity[38];}
        else if(r2LValue < 7.8f) {redR2LOpacity = redOpacity[39];}
        else if(r2LValue < 8.f)  {redR2LOpacity = redOpacity[40];}
        else if(r2LValue < 8.2f) {redR2LOpacity = redOpacity[41];}
        else if(r2LValue < 8.4f) {redR2LOpacity = redOpacity[42];}
        else if(r2LValue < 8.6f) {redR2LOpacity = redOpacity[43];}
        else if(r2LValue < 8.8f) {redR2LOpacity = redOpacity[44];}
        else if(r2LValue < 9.f)  {redR2LOpacity = redOpacity[45];}
        else if(r2LValue < 9.2f) {redR2LOpacity = redOpacity[46];}
        else if(r2LValue < 9.4f) {redR2LOpacity = redOpacity[47];}
        else if(r2LValue < 9.6f) {redR2LOpacity = redOpacity[48];}
        else if(r2LValue < 9.8f) {redR2LOpacity = redOpacity[49];}
        else if(r2LValue < 10.f) {redR2LOpacity = redOpacity[50];}
        else if(r2LValue < 10.2f) {redR2LOpacity = redOpacity[51];}
        else if(r2LValue < 10.4f) {redR2LOpacity = redOpacity[52];}
        else if(r2LValue < 10.6f) {redR2LOpacity = redOpacity[53];}
        else if(r2LValue < 10.8f) {redR2LOpacity = redOpacity[54];}
        else if(r2LValue < 11.f)  {redR2LOpacity = redOpacity[55];}
        else if(r2LValue < 11.2f) {redR2LOpacity = redOpacity[56];}
        else if(r2LValue < 11.4f) {redR2LOpacity = redOpacity[57];}
        else if(r2LValue < 11.6f) {redR2LOpacity = redOpacity[58];}
        else if(r2LValue < 11.8f) {redR2LOpacity = redOpacity[59];}
        else if(r2LValue < 12.f)  {redR2LOpacity = redOpacity[60];}

        // 12 dB <= Red values < 18 dB
        else if(r2LValue < 12.2f) {redR2LOpacity = redOpacity[61];}
        else if(r2LValue < 12.4f) {redR2LOpacity = redOpacity[62];}
        else if(r2LValue < 12.6f) {redR2LOpacity = redOpacity[63];}
        else if(r2LValue < 12.8f) {redR2LOpacity = redOpacity[64];}
        else if(r2LValue < 13.f)  {redR2LOpacity = redOpacity[65];}
        else if(r2LValue < 13.2f) {redR2LOpacity = redOpacity[66];}
        else if(r2LValue < 13.4f) {redR2LOpacity = redOpacity[67];}
        else if(r2LValue < 13.6f) {redR2LOpacity = redOpacity[68];}
        else if(r2LValue < 13.8f) {redR2LOpacity = redOpacity[69];}
        else if(r2LValue < 14.f)  {redR2LOpacity = redOpacity[70];}
        else if(r2LValue < 14.2f) {redR2LOpacity = redOpacity[71];}
        else if(r2LValue < 14.4f) {redR2LOpacity = redOpacity[72];}
        else if(r2LValue < 14.6f) {redR2LOpacity = redOpacity[73];}
        else if(r2LValue < 14.8f) {redR2LOpacity = redOpacity[74];}
        else if(r2LValue < 15.f)  {redR2LOpacity = redOpacity[75];}
        else if(r2LValue < 15.2f) {redR2LOpacity = redOpacity[76];}
        else if(r2LValue < 15.4f) {redR2LOpacity = redOpacity[77];}
        else if(r2LValue < 15.6f) {redR2LOpacity = redOpacity[78];}
        else if(r2LValue < 15.8f) {redR2LOpacity = redOpacity[79];}
        else if(r2LValue < 16.f)  {redR2LOpacity = redOpacity[80];}
        else if(r2LValue < 16.2f) {redR2LOpacity = redOpacity[81];}
        else if(r2LValue < 16.4f) {redR2LOpacity = redOpacity[82];}
        else if(r2LValue < 16.6f) {redR2LOpacity = redOpacity[83];}
        else if(r2LValue < 16.8f) {redR2LOpacity = redOpacity[84];}
        else if(r2LValue < 17.f)  {redR2LOpacity = redOpacity[85];}
        else if(r2LValue < 17.2f) {redR2LOpacity = redOpacity[86];}
        else if(r2LValue < 17.4f) {redR2LOpacity = redOpacity[87];}
        else if(r2LValue < 17.6f) {redR2LOpacity = redOpacity[88];}
        else if(r2LValue < 17.8f) {redR2LOpacity = redOpacity[89];}
        else if(r2LValue < 18.f)  {redR2LOpacity = redOpacity[90];}

        // 18 dB <= Red values <= 24 dB
        else if(r2LValue < 18.2f) {redR2LOpacity = redOpacity[91];}
        else if(r2LValue < 18.4f) {redR2LOpacity = redOpacity[92];}
        else if(r2LValue < 18.6f) {redR2LOpacity = redOpacity[93];}
        else if(r2LValue < 18.8f) {redR2LOpacity = redOpacity[94];}
        else if(r2LValue < 19.f)  {redR2LOpacity = redOpacity[95];}
        else if(r2LValue < 19.2f) {redR2LOpacity = redOpacity[96];}
        else if(r2LValue < 19.4f) {redR2LOpacity = redOpacity[97];}
        else if(r2LValue < 19.6f) {redR2LOpacity = redOpacity[98];}
        else if(r2LValue < 19.8f) {redR2LOpacity = redOpacity[99];}
        else if(r2LValue < 20.f)  {redR2LOpacity = redOpacity[100];}
        else if(r2LValue < 20.2f) {redR2LOpacity = redOpacity[101];}
        else if(r2LValue < 20.4f) {redR2LOpacity = redOpacity[102];}
        else if(r2LValue < 20.6f) {redR2LOpacity = redOpacity[103];}
        else if(r2LValue < 20.8f) {redR2LOpacity = redOpacity[104];}
        else if(r2LValue < 21.f)  {redR2LOpacity = redOpacity[105];}
        else if(r2LValue < 21.2f) {redR2LOpacity = redOpacity[106];}
        else if(r2LValue < 21.4f) {redR2LOpacity = redOpacity[107];}
        else if(r2LValue < 21.6f) {redR2LOpacity = redOpacity[108];}
        else if(r2LValue < 21.8f) {redR2LOpacity = redOpacity[109];}
        else if(r2LValue < 22.f)  {redR2LOpacity = redOpacity[110];}
        else if(r2LValue < 22.2f) {redR2LOpacity = redOpacity[111];}
        else if(r2LValue < 22.4f) {redR2LOpacity = redOpacity[112];}
        else if(r2LValue < 22.6f) {redR2LOpacity = redOpacity[113];}
        else if(r2LValue < 22.8f) {redR2LOpacity = redOpacity[114];}
        else if(r2LValue < 23.f)  {redR2LOpacity = redOpacity[115];}
        else if(r2LValue < 23.2f) {redR2LOpacity = redOpacity[116];}
        else if(r2LValue < 23.4f) {redR2LOpacity = redOpacity[117];}
        else if(r2LValue < 23.6f) {redR2LOpacity = redOpacity[118];}
        else if(r2LValue < 23.8f) {redR2LOpacity = redOpacity[119];}
        else if(r2LValue < 24.f)  {redR2LOpacity = redOpacity[120];}
        else if(r2LValue >= 24.f) {redR2LOpacity = redOpacity[121];}
        else {redR2LOpacity = redOpacity[0];}


        if(r2LValue == 0.f) {baseR2LOpacity = baseOpacity[200];}
        else if(r2LValue > -0.2f) {baseR2LOpacity = baseOpacity[199];}
        else if(r2LValue > -0.4f) {baseR2LOpacity = baseOpacity[198];}
        else if(r2LValue > -0.6f) {baseR2LOpacity = baseOpacity[197];}
        else if(r2LValue > -0.8f) {baseR2LOpacity = baseOpacity[196];}
        else if(r2LValue > -1.f)  {baseR2LOpacity = baseOpacity[195];}
        else if(r2LValue > -1.2f) {baseR2LOpacity = baseOpacity[194];}
        else if(r2LValue > -1.4f) {baseR2LOpacity = baseOpacity[193];}
        else if(r2LValue > -1.6f) {baseR2LOpacity = baseOpacity[192];}
        else if(r2LValue > -1.8f) {baseR2LOpacity = baseOpacity[191];}
        else if(r2LValue > -2.f)  {baseR2LOpacity = baseOpacity[190];}
        else if(r2LValue > -2.2f) {baseR2LOpacity = baseOpacity[189];}
        else if(r2LValue > -2.4f) {baseR2LOpacity = baseOpacity[188];}
        else if(r2LValue > -2.6f) {baseR2LOpacity = baseOpacity[187];}
        else if(r2LValue > -2.8f) {baseR2LOpacity = baseOpacity[186];}
        else if(r2LValue > -3.f)  {baseR2LOpacity = baseOpacity[185];}
        else if(r2LValue > -3.2f) {baseR2LOpacity = baseOpacity[184];}
        else if(r2LValue > -3.4f) {baseR2LOpacity = baseOpacity[183];}
        else if(r2LValue > -3.6f) {baseR2LOpacity = baseOpacity[182];}
        else if(r2LValue > -3.8f) {baseR2LOpacity = baseOpacity[181];}
        else if(r2LValue > -4.f)  {baseR2LOpacity = baseOpacity[180];}
        else if(r2LValue > -4.2f) {baseR2LOpacity = baseOpacity[179];}
        else if(r2LValue > -4.4f) {baseR2LOpacity = baseOpacity[178];}
        else if(r2LValue > -4.6f) {baseR2LOpacity = baseOpacity[177];}
        else if(r2LValue > -4.8f) {baseR2LOpacity = baseOpacity[176];}
        else if(r2LValue > -5.f)  {baseR2LOpacity = baseOpacity[175];}
        else if(r2LValue > -5.2f) {baseR2LOpacity = baseOpacity[174];}
        else if(r2LValue > -5.4f) {baseR2LOpacity = baseOpacity[173];}
        else if(r2LValue > -5.6f) {baseR2LOpacity = baseOpacity[172];}
        else if(r2LValue > -5.8f) {baseR2LOpacity = baseOpacity[171];}
        else if(r2LValue > -6.f)  {baseR2LOpacity = baseOpacity[170];}

        // 6 dB <= Red values < 12 dB
        else if(r2LValue > -6.2f) {baseR2LOpacity = baseOpacity[169];}
        else if(r2LValue > -6.4f) {baseR2LOpacity = baseOpacity[168];}
        else if(r2LValue > -6.6f) {baseR2LOpacity = baseOpacity[167];}
        else if(r2LValue > -6.8f) {baseR2LOpacity = baseOpacity[166];}
        else if(r2LValue > -7.f)  {baseR2LOpacity = baseOpacity[165];}
        else if(r2LValue > -7.2f) {baseR2LOpacity = baseOpacity[164];}
        else if(r2LValue > -7.4f) {baseR2LOpacity = baseOpacity[163];}
        else if(r2LValue > -7.6f) {baseR2LOpacity = baseOpacity[162];}
        else if(r2LValue > -7.8f) {baseR2LOpacity = baseOpacity[161];}
        else if(r2LValue > -8.f)  {baseR2LOpacity = baseOpacity[160];}
        else if(r2LValue > -8.2f) {baseR2LOpacity = baseOpacity[159];}
        else if(r2LValue > -8.4f) {baseR2LOpacity = baseOpacity[158];}
        else if(r2LValue > -8.6f) {baseR2LOpacity = baseOpacity[157];}
        else if(r2LValue > -8.8f) {baseR2LOpacity = baseOpacity[156];}
        else if(r2LValue > -9.f)  {baseR2LOpacity = baseOpacity[155];}
        else if(r2LValue > -9.2f) {baseR2LOpacity = baseOpacity[154];}
        else if(r2LValue > -9.4f) {baseR2LOpacity = baseOpacity[153];}
        else if(r2LValue > -9.6f) {baseR2LOpacity = baseOpacity[152];}
        else if(r2LValue > -9.8f) {baseR2LOpacity = baseOpacity[151];}
        else if(r2LValue > -10.f) {baseR2LOpacity = baseOpacity[150];}
        else if(r2LValue > -10.2f) {baseR2LOpacity = baseOpacity[149];}
        else if(r2LValue > -10.4f) {baseR2LOpacity = baseOpacity[148];}
        else if(r2LValue > -10.6f) {baseR2LOpacity = baseOpacity[147];}
        else if(r2LValue > -10.8f) {baseR2LOpacity = baseOpacity[146];}
        else if(r2LValue > -11.f)  {baseR2LOpacity = baseOpacity[145];}
        else if(r2LValue > -11.2f) {baseR2LOpacity = baseOpacity[144];}
        else if(r2LValue > -11.4f) {baseR2LOpacity = baseOpacity[143];}
        else if(r2LValue > -11.6f) {baseR2LOpacity = baseOpacity[142];}
        else if(r2LValue > -11.8f) {baseR2LOpacity = baseOpacity[141];}
        else if(r2LValue > -12.f)  {baseR2LOpacity = baseOpacity[140];}

        // 12 dB <= Red values < 18 dB
        else if(r2LValue > -12.2f) {baseR2LOpacity = baseOpacity[139];}
        else if(r2LValue > -12.4f) {baseR2LOpacity = baseOpacity[138];}
        else if(r2LValue > -12.6f) {baseR2LOpacity = baseOpacity[137];}
        else if(r2LValue > -12.8f) {baseR2LOpacity = baseOpacity[136];}
        else if(r2LValue > -13.f)  {baseR2LOpacity = baseOpacity[135];}
        else if(r2LValue > -13.2f) {baseR2LOpacity = baseOpacity[134];}
        else if(r2LValue > -13.4f) {baseR2LOpacity = baseOpacity[133];}
        else if(r2LValue > -13.6f) {baseR2LOpacity = baseOpacity[132];}
        else if(r2LValue > -13.8f) {baseR2LOpacity = baseOpacity[131];}
        else if(r2LValue > -14.f)  {baseR2LOpacity = baseOpacity[130];}
        else if(r2LValue > -14.2f) {baseR2LOpacity = baseOpacity[129];}
        else if(r2LValue > -14.4f) {baseR2LOpacity = baseOpacity[128];}
        else if(r2LValue > -14.6f) {baseR2LOpacity = baseOpacity[127];}
        else if(r2LValue > -14.8f) {baseR2LOpacity = baseOpacity[126];}
        else if(r2LValue > -15.f)  {baseR2LOpacity = baseOpacity[125];}
        else if(r2LValue > -15.2f) {baseR2LOpacity = baseOpacity[124];}
        else if(r2LValue > -15.4f) {baseR2LOpacity = baseOpacity[123];}
        else if(r2LValue > -15.6f) {baseR2LOpacity = baseOpacity[122];}
        else if(r2LValue > -15.8f) {baseR2LOpacity = baseOpacity[121];}
        else if(r2LValue > -16.f)  {baseR2LOpacity = baseOpacity[120];}
        else if(r2LValue > -16.2f) {baseR2LOpacity = baseOpacity[119];}
        else if(r2LValue > -16.4f) {baseR2LOpacity = baseOpacity[118];}
        else if(r2LValue > -16.6f) {baseR2LOpacity = baseOpacity[117];}
        else if(r2LValue > -16.8f) {baseR2LOpacity = baseOpacity[116];}
        else if(r2LValue > -17.f)  {baseR2LOpacity = baseOpacity[115];}
        else if(r2LValue > -17.2f) {baseR2LOpacity = baseOpacity[114];}
        else if(r2LValue > -17.4f) {baseR2LOpacity = baseOpacity[113];}
        else if(r2LValue > -17.6f) {baseR2LOpacity = baseOpacity[112];}
        else if(r2LValue > -17.8f) {baseR2LOpacity = baseOpacity[111];}
        else if(r2LValue > -18.f)  {baseR2LOpacity = baseOpacity[110];}

        // 18 dB <= Red values <= 24 dB
        else if(r2LValue > -18.2f) {baseR2LOpacity = baseOpacity[109];}
        else if(r2LValue > -18.4f) {baseR2LOpacity = baseOpacity[108];}
        else if(r2LValue > -18.6f) {baseR2LOpacity = baseOpacity[107];}
        else if(r2LValue > -18.8f) {baseR2LOpacity = baseOpacity[106];}
        else if(r2LValue > -19.f)  {baseR2LOpacity = baseOpacity[105];}
        else if(r2LValue > -19.2f) {baseR2LOpacity = baseOpacity[104];}
        else if(r2LValue > -19.4f) {baseR2LOpacity = baseOpacity[103];}
        else if(r2LValue > -19.6f) {baseR2LOpacity = baseOpacity[102];}
        else if(r2LValue > -19.8f) {baseR2LOpacity = baseOpacity[101];}
        else if(r2LValue > -20.f)  {baseR2LOpacity = baseOpacity[100];}
        else if(r2LValue > -20.2f) {baseR2LOpacity = baseOpacity[99];}
        else if(r2LValue > -20.4f) {baseR2LOpacity = baseOpacity[98];}
        else if(r2LValue > -20.6f) {baseR2LOpacity = baseOpacity[97];}
        else if(r2LValue > -20.8f) {baseR2LOpacity = baseOpacity[96];}
        else if(r2LValue > -21.f)  {baseR2LOpacity = baseOpacity[95];}
        else if(r2LValue > -21.2f) {baseR2LOpacity = baseOpacity[94];}
        else if(r2LValue > -21.4f) {baseR2LOpacity = baseOpacity[93];}
        else if(r2LValue > -21.6f) {baseR2LOpacity = baseOpacity[92];}
        else if(r2LValue > -21.8f) {baseR2LOpacity = baseOpacity[91];}
        else if(r2LValue > -22.f)  {baseR2LOpacity = baseOpacity[90];}
        else if(r2LValue > -22.2f) {baseR2LOpacity = baseOpacity[89];}
        else if(r2LValue > -22.4f) {baseR2LOpacity = baseOpacity[88];}
        else if(r2LValue > -22.6f) {baseR2LOpacity = baseOpacity[87];}
        else if(r2LValue > -22.8f) {baseR2LOpacity = baseOpacity[86];}
        else if(r2LValue > -23.f)  {baseR2LOpacity = baseOpacity[85];}
        else if(r2LValue > -23.2f) {baseR2LOpacity = baseOpacity[84];}
        else if(r2LValue > -23.4f) {baseR2LOpacity = baseOpacity[83];}
        else if(r2LValue > -23.6f) {baseR2LOpacity = baseOpacity[82];}
        else if(r2LValue > -23.8f) {baseR2LOpacity = baseOpacity[81];}
        else if(r2LValue > -24.f)  {baseR2LOpacity = baseOpacity[80];}

        // 18 dB <= Red values <= 24 dB
        else if(r2LValue > -24.3f) {baseR2LOpacity = baseOpacity[79];}
        else if(r2LValue > -24.6f) {baseR2LOpacity = baseOpacity[78];}
        else if(r2LValue > -24.9f) {baseR2LOpacity = baseOpacity[77];}
        else if(r2LValue > -25.2f) {baseR2LOpacity = baseOpacity[76];}
        else if(r2LValue > -25.5f) {baseR2LOpacity = baseOpacity[75];}
        else if(r2LValue > -25.8f) {baseR2LOpacity = baseOpacity[74];}
        else if(r2LValue > -26.1f) {baseR2LOpacity = baseOpacity[73];}
        else if(r2LValue > -26.4f) {baseR2LOpacity = baseOpacity[72];}
        else if(r2LValue > -26.7f) {baseR2LOpacity = baseOpacity[71];}
        else if(r2LValue > -27.f)  {baseR2LOpacity = baseOpacity[70];}
        else if(r2LValue > -27.3f) {baseR2LOpacity = baseOpacity[69];}
        else if(r2LValue > -27.6f) {baseR2LOpacity = baseOpacity[68];}
        else if(r2LValue > -27.9f) {baseR2LOpacity = baseOpacity[67];}
        else if(r2LValue > -28.2f) {baseR2LOpacity = baseOpacity[66];}
        else if(r2LValue > -28.5f) {baseR2LOpacity = baseOpacity[65];}
        else if(r2LValue > -28.8f) {baseR2LOpacity = baseOpacity[64];}
        else if(r2LValue > -29.1f) {baseR2LOpacity = baseOpacity[63];}
        else if(r2LValue > -29.4f) {baseR2LOpacity = baseOpacity[62];}
        else if(r2LValue > -29.7f) {baseR2LOpacity = baseOpacity[61];}
        else if(r2LValue > -30.f)  {baseR2LOpacity = baseOpacity[60];}

        else if(r2LValue > -30.3f) {baseR2LOpacity = baseOpacity[59];}
        else if(r2LValue > -30.6f) {baseR2LOpacity = baseOpacity[58];}
        else if(r2LValue > -30.9f) {baseR2LOpacity = baseOpacity[57];}
        else if(r2LValue > -31.2f) {baseR2LOpacity = baseOpacity[56];}
        else if(r2LValue > -31.5f) {baseR2LOpacity = baseOpacity[55];}
        else if(r2LValue > -31.8f) {baseR2LOpacity = baseOpacity[54];}
        else if(r2LValue > -32.1f) {baseR2LOpacity = baseOpacity[53];}
        else if(r2LValue > -32.4f) {baseR2LOpacity = baseOpacity[52];}
        else if(r2LValue > -32.7f) {baseR2LOpacity = baseOpacity[51];}
        else if(r2LValue > -33.f)  {baseR2LOpacity = baseOpacity[50];}
        else if(r2LValue > -33.3f) {baseR2LOpacity = baseOpacity[49];}
        else if(r2LValue > -33.6f) {baseR2LOpacity = baseOpacity[48];}
        else if(r2LValue > -33.9f) {baseR2LOpacity = baseOpacity[47];}
        else if(r2LValue > -34.2f) {baseR2LOpacity = baseOpacity[46];}
        else if(r2LValue > -34.5f) {baseR2LOpacity = baseOpacity[45];}
        else if(r2LValue > -34.8f) {baseR2LOpacity = baseOpacity[44];}
        else if(r2LValue > -35.1f) {baseR2LOpacity = baseOpacity[43];}
        else if(r2LValue > -35.4f) {baseR2LOpacity = baseOpacity[42];}
        else if(r2LValue > -35.7f) {baseR2LOpacity = baseOpacity[41];}
        else if(r2LValue > -36.f)  {baseR2LOpacity = baseOpacity[40];}


        else if(r2LValue > -36.6f) {baseR2LOpacity = baseOpacity[39];}
        else if(r2LValue > -37.2f) {baseR2LOpacity = baseOpacity[38];}
        else if(r2LValue > -37.8f) {baseR2LOpacity = baseOpacity[37];}
        else if(r2LValue > -38.4f) {baseR2LOpacity = baseOpacity[36];}
        else if(r2LValue > -39.f)  {baseR2LOpacity = baseOpacity[35];}
        else if(r2LValue > -39.6f) {baseR2LOpacity = baseOpacity[34];}
        else if(r2LValue > -40.2f) {baseR2LOpacity = baseOpacity[33];}
        else if(r2LValue > -40.8f) {baseR2LOpacity = baseOpacity[32];}
        else if(r2LValue > -41.4f) {baseR2LOpacity = baseOpacity[31];}
        else if(r2LValue > -42.f)  {baseR2LOpacity = baseOpacity[30];}

        else if(r2LValue > -42.6f) {baseR2LOpacity = baseOpacity[29];}
        else if(r2LValue > -43.2f) {baseR2LOpacity = baseOpacity[28];}
        else if(r2LValue > -43.8f) {baseR2LOpacity = baseOpacity[27];}
        else if(r2LValue > -44.4f) {baseR2LOpacity = baseOpacity[26];}
        else if(r2LValue > -45.f)  {baseR2LOpacity = baseOpacity[25];}
        else if(r2LValue > -45.6f) {baseR2LOpacity = baseOpacity[24];}
        else if(r2LValue > -46.2f) {baseR2LOpacity = baseOpacity[23];}
        else if(r2LValue > -46.8f) {baseR2LOpacity = baseOpacity[22];}
        else if(r2LValue > -47.4f) {baseR2LOpacity = baseOpacity[21];}
        else if(r2LValue > -48.f)  {baseR2LOpacity = baseOpacity[20];}

        else if(r2LValue > -48.6f) {baseR2LOpacity = baseOpacity[19];}
        else if(r2LValue > -49.2f) {baseR2LOpacity = baseOpacity[18];}
        else if(r2LValue > -49.8f) {baseR2LOpacity = baseOpacity[17];}
        else if(r2LValue > -50.4f) {baseR2LOpacity = baseOpacity[16];}
        else if(r2LValue > -51.f)  {baseR2LOpacity = baseOpacity[15];}
        else if(r2LValue > -51.6f) {baseR2LOpacity = baseOpacity[14];}
        else if(r2LValue > -52.2f) {baseR2LOpacity = baseOpacity[13];}
        else if(r2LValue > -52.8f) {baseR2LOpacity = baseOpacity[12];}
        else if(r2LValue > -53.4f) {baseR2LOpacity = baseOpacity[11];}
        else if(r2LValue > -54.f)  {baseR2LOpacity = baseOpacity[10];}

        else if(r2LValue > -54.6f) {baseR2LOpacity = baseOpacity[9];}
        else if(r2LValue > -55.2f) {baseR2LOpacity = baseOpacity[8];}
        else if(r2LValue > -55.8f) {baseR2LOpacity = baseOpacity[7];}
        else if(r2LValue > -56.4f) {baseR2LOpacity = baseOpacity[6];}
        else if(r2LValue > -57.f)  {baseR2LOpacity = baseOpacity[5];}
        else if(r2LValue > -57.6f) {baseR2LOpacity = baseOpacity[4];}
        else if(r2LValue > -58.2f) {baseR2LOpacity = baseOpacity[3];}
        else if(r2LValue > -58.8f) {baseR2LOpacity = baseOpacity[2];}
        else if(r2LValue > -59.4f) {baseR2LOpacity = baseOpacity[1];}
        else if(r2LValue > -60.f)  {baseR2LOpacity = baseOpacity[0];}
        else if(r2LValue <= -60.f) {baseR2LOpacity = baseOpacity[0];}
        else {baseR2LOpacity = baseOpacity[0];}
        
        
    // L2RB
        
        if(l2RBValue <= 0.f) {redL2RBOpacity = redOpacity[0];}
        else if(l2RBValue < 0.2f) {redL2RBOpacity = redOpacity[1];}
        else if(l2RBValue < 0.4f) {redL2RBOpacity = redOpacity[2];}
        else if(l2RBValue < 0.6f) {redL2RBOpacity = redOpacity[3];}
        else if(l2RBValue < 0.8f) {redL2RBOpacity = redOpacity[4];}
        else if(l2RBValue < 1.f)  {redL2RBOpacity = redOpacity[5];}
        else if(l2RBValue < 1.2f) {redL2RBOpacity = redOpacity[6];}
        else if(l2RBValue < 1.4f) {redL2RBOpacity = redOpacity[7];}
        else if(l2RBValue < 1.6f) {redL2RBOpacity = redOpacity[8];}
        else if(l2RBValue < 1.8f) {redL2RBOpacity = redOpacity[9];}
        else if(l2RBValue < 2.f)  {redL2RBOpacity = redOpacity[10];}
        else if(l2RBValue < 2.2f) {redL2RBOpacity = redOpacity[11];}
        else if(l2RBValue < 2.4f) {redL2RBOpacity = redOpacity[12];}
        else if(l2RBValue < 2.6f) {redL2RBOpacity = redOpacity[13];}
        else if(l2RBValue < 2.8f) {redL2RBOpacity = redOpacity[14];}
        else if(l2RBValue < 3.f)  {redL2RBOpacity = redOpacity[15];}
        else if(l2RBValue < 3.2f) {redL2RBOpacity = redOpacity[16];}
        else if(l2RBValue < 3.4f) {redL2RBOpacity = redOpacity[17];}
        else if(l2RBValue < 3.6f) {redL2RBOpacity = redOpacity[18];}
        else if(l2RBValue < 3.8f) {redL2RBOpacity = redOpacity[19];}
        else if(l2RBValue < 4.f)  {redL2RBOpacity = redOpacity[20];}
        else if(l2RBValue < 4.2f) {redL2RBOpacity = redOpacity[21];}
        else if(l2RBValue < 4.4f) {redL2RBOpacity = redOpacity[22];}
        else if(l2RBValue < 4.6f) {redL2RBOpacity = redOpacity[23];}
        else if(l2RBValue < 4.8f) {redL2RBOpacity = redOpacity[24];}
        else if(l2RBValue < 5.f)  {redL2RBOpacity = redOpacity[25];}
        else if(l2RBValue < 5.2f) {redL2RBOpacity = redOpacity[26];}
        else if(l2RBValue < 5.4f) {redL2RBOpacity = redOpacity[27];}
        else if(l2RBValue < 5.6f) {redL2RBOpacity = redOpacity[28];}
        else if(l2RBValue < 5.8f) {redL2RBOpacity = redOpacity[29];}
        else if(l2RBValue < 6.f)  {redL2RBOpacity = redOpacity[30];}

        // 6 dB <= Red values < 12 dB
        else if(l2RBValue < 6.2f) {redL2RBOpacity = redOpacity[31];}
        else if(l2RBValue < 6.4f) {redL2RBOpacity = redOpacity[32];}
        else if(l2RBValue < 6.6f) {redL2RBOpacity = redOpacity[33];}
        else if(l2RBValue < 6.8f) {redL2RBOpacity = redOpacity[34];}
        else if(l2RBValue < 7.f)  {redL2RBOpacity = redOpacity[35];}
        else if(l2RBValue < 7.2f) {redL2RBOpacity = redOpacity[36];}
        else if(l2RBValue < 7.4f) {redL2RBOpacity = redOpacity[37];}
        else if(l2RBValue < 7.6f) {redL2RBOpacity = redOpacity[38];}
        else if(l2RBValue < 7.8f) {redL2RBOpacity = redOpacity[39];}
        else if(l2RBValue < 8.f)  {redL2RBOpacity = redOpacity[40];}
        else if(l2RBValue < 8.2f) {redL2RBOpacity = redOpacity[41];}
        else if(l2RBValue < 8.4f) {redL2RBOpacity = redOpacity[42];}
        else if(l2RBValue < 8.6f) {redL2RBOpacity = redOpacity[43];}
        else if(l2RBValue < 8.8f) {redL2RBOpacity = redOpacity[44];}
        else if(l2RBValue < 9.f)  {redL2RBOpacity = redOpacity[45];}
        else if(l2RBValue < 9.2f) {redL2RBOpacity = redOpacity[46];}
        else if(l2RBValue < 9.4f) {redL2RBOpacity = redOpacity[47];}
        else if(l2RBValue < 9.6f) {redL2RBOpacity = redOpacity[48];}
        else if(l2RBValue < 9.8f) {redL2RBOpacity = redOpacity[49];}
        else if(l2RBValue < 10.f) {redL2RBOpacity = redOpacity[50];}
        else if(l2RBValue < 10.2f) {redL2RBOpacity = redOpacity[51];}
        else if(l2RBValue < 10.4f) {redL2RBOpacity = redOpacity[52];}
        else if(l2RBValue < 10.6f) {redL2RBOpacity = redOpacity[53];}
        else if(l2RBValue < 10.8f) {redL2RBOpacity = redOpacity[54];}
        else if(l2RBValue < 11.f)  {redL2RBOpacity = redOpacity[55];}
        else if(l2RBValue < 11.2f) {redL2RBOpacity = redOpacity[56];}
        else if(l2RBValue < 11.4f) {redL2RBOpacity = redOpacity[57];}
        else if(l2RBValue < 11.6f) {redL2RBOpacity = redOpacity[58];}
        else if(l2RBValue < 11.8f) {redL2RBOpacity = redOpacity[59];}
        else if(l2RBValue < 12.f)  {redL2RBOpacity = redOpacity[60];}

        // 12 dB <= Red values < 18 dB
        else if(l2RBValue < 12.2f) {redL2RBOpacity = redOpacity[61];}
        else if(l2RBValue < 12.4f) {redL2RBOpacity = redOpacity[62];}
        else if(l2RBValue < 12.6f) {redL2RBOpacity = redOpacity[63];}
        else if(l2RBValue < 12.8f) {redL2RBOpacity = redOpacity[64];}
        else if(l2RBValue < 13.f)  {redL2RBOpacity = redOpacity[65];}
        else if(l2RBValue < 13.2f) {redL2RBOpacity = redOpacity[66];}
        else if(l2RBValue < 13.4f) {redL2RBOpacity = redOpacity[67];}
        else if(l2RBValue < 13.6f) {redL2RBOpacity = redOpacity[68];}
        else if(l2RBValue < 13.8f) {redL2RBOpacity = redOpacity[69];}
        else if(l2RBValue < 14.f)  {redL2RBOpacity = redOpacity[70];}
        else if(l2RBValue < 14.2f) {redL2RBOpacity = redOpacity[71];}
        else if(l2RBValue < 14.4f) {redL2RBOpacity = redOpacity[72];}
        else if(l2RBValue < 14.6f) {redL2RBOpacity = redOpacity[73];}
        else if(l2RBValue < 14.8f) {redL2RBOpacity = redOpacity[74];}
        else if(l2RBValue < 15.f)  {redL2RBOpacity = redOpacity[75];}
        else if(l2RBValue < 15.2f) {redL2RBOpacity = redOpacity[76];}
        else if(l2RBValue < 15.4f) {redL2RBOpacity = redOpacity[77];}
        else if(l2RBValue < 15.6f) {redL2RBOpacity = redOpacity[78];}
        else if(l2RBValue < 15.8f) {redL2RBOpacity = redOpacity[79];}
        else if(l2RBValue < 16.f)  {redL2RBOpacity = redOpacity[80];}
        else if(l2RBValue < 16.2f) {redL2RBOpacity = redOpacity[81];}
        else if(l2RBValue < 16.4f) {redL2RBOpacity = redOpacity[82];}
        else if(l2RBValue < 16.6f) {redL2RBOpacity = redOpacity[83];}
        else if(l2RBValue < 16.8f) {redL2RBOpacity = redOpacity[84];}
        else if(l2RBValue < 17.f)  {redL2RBOpacity = redOpacity[85];}
        else if(l2RBValue < 17.2f) {redL2RBOpacity = redOpacity[86];}
        else if(l2RBValue < 17.4f) {redL2RBOpacity = redOpacity[87];}
        else if(l2RBValue < 17.6f) {redL2RBOpacity = redOpacity[88];}
        else if(l2RBValue < 17.8f) {redL2RBOpacity = redOpacity[89];}
        else if(l2RBValue < 18.f)  {redL2RBOpacity = redOpacity[90];}

        // 18 dB <= Red values <= 24 dB
        else if(l2RBValue < 18.2f) {redL2RBOpacity = redOpacity[91];}
        else if(l2RBValue < 18.4f) {redL2RBOpacity = redOpacity[92];}
        else if(l2RBValue < 18.6f) {redL2RBOpacity = redOpacity[93];}
        else if(l2RBValue < 18.8f) {redL2RBOpacity = redOpacity[94];}
        else if(l2RBValue < 19.f)  {redL2RBOpacity = redOpacity[95];}
        else if(l2RBValue < 19.2f) {redL2RBOpacity = redOpacity[96];}
        else if(l2RBValue < 19.4f) {redL2RBOpacity = redOpacity[97];}
        else if(l2RBValue < 19.6f) {redL2RBOpacity = redOpacity[98];}
        else if(l2RBValue < 19.8f) {redL2RBOpacity = redOpacity[99];}
        else if(l2RBValue < 20.f)  {redL2RBOpacity = redOpacity[100];}
        else if(l2RBValue < 20.2f) {redL2RBOpacity = redOpacity[101];}
        else if(l2RBValue < 20.4f) {redL2RBOpacity = redOpacity[102];}
        else if(l2RBValue < 20.6f) {redL2RBOpacity = redOpacity[103];}
        else if(l2RBValue < 20.8f) {redL2RBOpacity = redOpacity[104];}
        else if(l2RBValue < 21.f)  {redL2RBOpacity = redOpacity[105];}
        else if(l2RBValue < 21.2f) {redL2RBOpacity = redOpacity[106];}
        else if(l2RBValue < 21.4f) {redL2RBOpacity = redOpacity[107];}
        else if(l2RBValue < 21.6f) {redL2RBOpacity = redOpacity[108];}
        else if(l2RBValue < 21.8f) {redL2RBOpacity = redOpacity[109];}
        else if(l2RBValue < 22.f)  {redL2RBOpacity = redOpacity[110];}
        else if(l2RBValue < 22.2f) {redL2RBOpacity = redOpacity[111];}
        else if(l2RBValue < 22.4f) {redL2RBOpacity = redOpacity[112];}
        else if(l2RBValue < 22.6f) {redL2RBOpacity = redOpacity[113];}
        else if(l2RBValue < 22.8f) {redL2RBOpacity = redOpacity[114];}
        else if(l2RBValue < 23.f)  {redL2RBOpacity = redOpacity[115];}
        else if(l2RBValue < 23.2f) {redL2RBOpacity = redOpacity[116];}
        else if(l2RBValue < 23.4f) {redL2RBOpacity = redOpacity[117];}
        else if(l2RBValue < 23.6f) {redL2RBOpacity = redOpacity[118];}
        else if(l2RBValue < 23.8f) {redL2RBOpacity = redOpacity[119];}
        else if(l2RBValue < 24.f)  {redL2RBOpacity = redOpacity[120];}
        else if(l2RBValue >= 24.f) {redL2RBOpacity = redOpacity[121];}
        else {redL2RBOpacity = redOpacity[0];}


        if(l2RBValue == 0.f) {baseL2RBOpacity = baseOpacity[200];}
        else if(l2RBValue > -0.2f) {baseL2RBOpacity = baseOpacity[199];}
        else if(l2RBValue > -0.4f) {baseL2RBOpacity = baseOpacity[198];}
        else if(l2RBValue > -0.6f) {baseL2RBOpacity = baseOpacity[197];}
        else if(l2RBValue > -0.8f) {baseL2RBOpacity = baseOpacity[196];}
        else if(l2RBValue > -1.f)  {baseL2RBOpacity = baseOpacity[195];}
        else if(l2RBValue > -1.2f) {baseL2RBOpacity = baseOpacity[194];}
        else if(l2RBValue > -1.4f) {baseL2RBOpacity = baseOpacity[193];}
        else if(l2RBValue > -1.6f) {baseL2RBOpacity = baseOpacity[192];}
        else if(l2RBValue > -1.8f) {baseL2RBOpacity = baseOpacity[191];}
        else if(l2RBValue > -2.f)  {baseL2RBOpacity = baseOpacity[190];}
        else if(l2RBValue > -2.2f) {baseL2RBOpacity = baseOpacity[189];}
        else if(l2RBValue > -2.4f) {baseL2RBOpacity = baseOpacity[188];}
        else if(l2RBValue > -2.6f) {baseL2RBOpacity = baseOpacity[187];}
        else if(l2RBValue > -2.8f) {baseL2RBOpacity = baseOpacity[186];}
        else if(l2RBValue > -3.f)  {baseL2RBOpacity = baseOpacity[185];}
        else if(l2RBValue > -3.2f) {baseL2RBOpacity = baseOpacity[184];}
        else if(l2RBValue > -3.4f) {baseL2RBOpacity = baseOpacity[183];}
        else if(l2RBValue > -3.6f) {baseL2RBOpacity = baseOpacity[182];}
        else if(l2RBValue > -3.8f) {baseL2RBOpacity = baseOpacity[181];}
        else if(l2RBValue > -4.f)  {baseL2RBOpacity = baseOpacity[180];}
        else if(l2RBValue > -4.2f) {baseL2RBOpacity = baseOpacity[179];}
        else if(l2RBValue > -4.4f) {baseL2RBOpacity = baseOpacity[178];}
        else if(l2RBValue > -4.6f) {baseL2RBOpacity = baseOpacity[177];}
        else if(l2RBValue > -4.8f) {baseL2RBOpacity = baseOpacity[176];}
        else if(l2RBValue > -5.f)  {baseL2RBOpacity = baseOpacity[175];}
        else if(l2RBValue > -5.2f) {baseL2RBOpacity = baseOpacity[174];}
        else if(l2RBValue > -5.4f) {baseL2RBOpacity = baseOpacity[173];}
        else if(l2RBValue > -5.6f) {baseL2RBOpacity = baseOpacity[172];}
        else if(l2RBValue > -5.8f) {baseL2RBOpacity = baseOpacity[171];}
        else if(l2RBValue > -6.f)  {baseL2RBOpacity = baseOpacity[170];}

        // 6 dB <= Red values < 12 dB
        else if(l2RBValue > -6.2f) {baseL2RBOpacity = baseOpacity[169];}
        else if(l2RBValue > -6.4f) {baseL2RBOpacity = baseOpacity[168];}
        else if(l2RBValue > -6.6f) {baseL2RBOpacity = baseOpacity[167];}
        else if(l2RBValue > -6.8f) {baseL2RBOpacity = baseOpacity[166];}
        else if(l2RBValue > -7.f)  {baseL2RBOpacity = baseOpacity[165];}
        else if(l2RBValue > -7.2f) {baseL2RBOpacity = baseOpacity[164];}
        else if(l2RBValue > -7.4f) {baseL2RBOpacity = baseOpacity[163];}
        else if(l2RBValue > -7.6f) {baseL2RBOpacity = baseOpacity[162];}
        else if(l2RBValue > -7.8f) {baseL2RBOpacity = baseOpacity[161];}
        else if(l2RBValue > -8.f)  {baseL2RBOpacity = baseOpacity[160];}
        else if(l2RBValue > -8.2f) {baseL2RBOpacity = baseOpacity[159];}
        else if(l2RBValue > -8.4f) {baseL2RBOpacity = baseOpacity[158];}
        else if(l2RBValue > -8.6f) {baseL2RBOpacity = baseOpacity[157];}
        else if(l2RBValue > -8.8f) {baseL2RBOpacity = baseOpacity[156];}
        else if(l2RBValue > -9.f)  {baseL2RBOpacity = baseOpacity[155];}
        else if(l2RBValue > -9.2f) {baseL2RBOpacity = baseOpacity[154];}
        else if(l2RBValue > -9.4f) {baseL2RBOpacity = baseOpacity[153];}
        else if(l2RBValue > -9.6f) {baseL2RBOpacity = baseOpacity[152];}
        else if(l2RBValue > -9.8f) {baseL2RBOpacity = baseOpacity[151];}
        else if(l2RBValue > -10.f) {baseL2RBOpacity = baseOpacity[150];}
        else if(l2RBValue > -10.2f) {baseL2RBOpacity = baseOpacity[149];}
        else if(l2RBValue > -10.4f) {baseL2RBOpacity = baseOpacity[148];}
        else if(l2RBValue > -10.6f) {baseL2RBOpacity = baseOpacity[147];}
        else if(l2RBValue > -10.8f) {baseL2RBOpacity = baseOpacity[146];}
        else if(l2RBValue > -11.f)  {baseL2RBOpacity = baseOpacity[145];}
        else if(l2RBValue > -11.2f) {baseL2RBOpacity = baseOpacity[144];}
        else if(l2RBValue > -11.4f) {baseL2RBOpacity = baseOpacity[143];}
        else if(l2RBValue > -11.6f) {baseL2RBOpacity = baseOpacity[142];}
        else if(l2RBValue > -11.8f) {baseL2RBOpacity = baseOpacity[141];}
        else if(l2RBValue > -12.f)  {baseL2RBOpacity = baseOpacity[140];}

        // 12 dB <= Red values < 18 dB
        else if(l2RBValue > -12.2f) {baseL2RBOpacity = baseOpacity[139];}
        else if(l2RBValue > -12.4f) {baseL2RBOpacity = baseOpacity[138];}
        else if(l2RBValue > -12.6f) {baseL2RBOpacity = baseOpacity[137];}
        else if(l2RBValue > -12.8f) {baseL2RBOpacity = baseOpacity[136];}
        else if(l2RBValue > -13.f)  {baseL2RBOpacity = baseOpacity[135];}
        else if(l2RBValue > -13.2f) {baseL2RBOpacity = baseOpacity[134];}
        else if(l2RBValue > -13.4f) {baseL2RBOpacity = baseOpacity[133];}
        else if(l2RBValue > -13.6f) {baseL2RBOpacity = baseOpacity[132];}
        else if(l2RBValue > -13.8f) {baseL2RBOpacity = baseOpacity[131];}
        else if(l2RBValue > -14.f)  {baseL2RBOpacity = baseOpacity[130];}
        else if(l2RBValue > -14.2f) {baseL2RBOpacity = baseOpacity[129];}
        else if(l2RBValue > -14.4f) {baseL2RBOpacity = baseOpacity[128];}
        else if(l2RBValue > -14.6f) {baseL2RBOpacity = baseOpacity[127];}
        else if(l2RBValue > -14.8f) {baseL2RBOpacity = baseOpacity[126];}
        else if(l2RBValue > -15.f)  {baseL2RBOpacity = baseOpacity[125];}
        else if(l2RBValue > -15.2f) {baseL2RBOpacity = baseOpacity[124];}
        else if(l2RBValue > -15.4f) {baseL2RBOpacity = baseOpacity[123];}
        else if(l2RBValue > -15.6f) {baseL2RBOpacity = baseOpacity[122];}
        else if(l2RBValue > -15.8f) {baseL2RBOpacity = baseOpacity[121];}
        else if(l2RBValue > -16.f)  {baseL2RBOpacity = baseOpacity[120];}
        else if(l2RBValue > -16.2f) {baseL2RBOpacity = baseOpacity[119];}
        else if(l2RBValue > -16.4f) {baseL2RBOpacity = baseOpacity[118];}
        else if(l2RBValue > -16.6f) {baseL2RBOpacity = baseOpacity[117];}
        else if(l2RBValue > -16.8f) {baseL2RBOpacity = baseOpacity[116];}
        else if(l2RBValue > -17.f)  {baseL2RBOpacity = baseOpacity[115];}
        else if(l2RBValue > -17.2f) {baseL2RBOpacity = baseOpacity[114];}
        else if(l2RBValue > -17.4f) {baseL2RBOpacity = baseOpacity[113];}
        else if(l2RBValue > -17.6f) {baseL2RBOpacity = baseOpacity[112];}
        else if(l2RBValue > -17.8f) {baseL2RBOpacity = baseOpacity[111];}
        else if(l2RBValue > -18.f)  {baseL2RBOpacity = baseOpacity[110];}

        // 18 dB <= Red values <= 24 dB
        else if(l2RBValue > -18.2f) {baseL2RBOpacity = baseOpacity[109];}
        else if(l2RBValue > -18.4f) {baseL2RBOpacity = baseOpacity[108];}
        else if(l2RBValue > -18.6f) {baseL2RBOpacity = baseOpacity[107];}
        else if(l2RBValue > -18.8f) {baseL2RBOpacity = baseOpacity[106];}
        else if(l2RBValue > -19.f)  {baseL2RBOpacity = baseOpacity[105];}
        else if(l2RBValue > -19.2f) {baseL2RBOpacity = baseOpacity[104];}
        else if(l2RBValue > -19.4f) {baseL2RBOpacity = baseOpacity[103];}
        else if(l2RBValue > -19.6f) {baseL2RBOpacity = baseOpacity[102];}
        else if(l2RBValue > -19.8f) {baseL2RBOpacity = baseOpacity[101];}
        else if(l2RBValue > -20.f)  {baseL2RBOpacity = baseOpacity[100];}
        else if(l2RBValue > -20.2f) {baseL2RBOpacity = baseOpacity[99];}
        else if(l2RBValue > -20.4f) {baseL2RBOpacity = baseOpacity[98];}
        else if(l2RBValue > -20.6f) {baseL2RBOpacity = baseOpacity[97];}
        else if(l2RBValue > -20.8f) {baseL2RBOpacity = baseOpacity[96];}
        else if(l2RBValue > -21.f)  {baseL2RBOpacity = baseOpacity[95];}
        else if(l2RBValue > -21.2f) {baseL2RBOpacity = baseOpacity[94];}
        else if(l2RBValue > -21.4f) {baseL2RBOpacity = baseOpacity[93];}
        else if(l2RBValue > -21.6f) {baseL2RBOpacity = baseOpacity[92];}
        else if(l2RBValue > -21.8f) {baseL2RBOpacity = baseOpacity[91];}
        else if(l2RBValue > -22.f)  {baseL2RBOpacity = baseOpacity[90];}
        else if(l2RBValue > -22.2f) {baseL2RBOpacity = baseOpacity[89];}
        else if(l2RBValue > -22.4f) {baseL2RBOpacity = baseOpacity[88];}
        else if(l2RBValue > -22.6f) {baseL2RBOpacity = baseOpacity[87];}
        else if(l2RBValue > -22.8f) {baseL2RBOpacity = baseOpacity[86];}
        else if(l2RBValue > -23.f)  {baseL2RBOpacity = baseOpacity[85];}
        else if(l2RBValue > -23.2f) {baseL2RBOpacity = baseOpacity[84];}
        else if(l2RBValue > -23.4f) {baseL2RBOpacity = baseOpacity[83];}
        else if(l2RBValue > -23.6f) {baseL2RBOpacity = baseOpacity[82];}
        else if(l2RBValue > -23.8f) {baseL2RBOpacity = baseOpacity[81];}
        else if(l2RBValue > -24.f)  {baseL2RBOpacity = baseOpacity[80];}

        // 18 dB <= Red values <= 24 dB
        else if(l2RBValue > -24.3f) {baseL2RBOpacity = baseOpacity[79];}
        else if(l2RBValue > -24.6f) {baseL2RBOpacity = baseOpacity[78];}
        else if(l2RBValue > -24.9f) {baseL2RBOpacity = baseOpacity[77];}
        else if(l2RBValue > -25.2f) {baseL2RBOpacity = baseOpacity[76];}
        else if(l2RBValue > -25.5f) {baseL2RBOpacity = baseOpacity[75];}
        else if(l2RBValue > -25.8f) {baseL2RBOpacity = baseOpacity[74];}
        else if(l2RBValue > -26.1f) {baseL2RBOpacity = baseOpacity[73];}
        else if(l2RBValue > -26.4f) {baseL2RBOpacity = baseOpacity[72];}
        else if(l2RBValue > -26.7f) {baseL2RBOpacity = baseOpacity[71];}
        else if(l2RBValue > -27.f)  {baseL2RBOpacity = baseOpacity[70];}
        else if(l2RBValue > -27.3f) {baseL2RBOpacity = baseOpacity[69];}
        else if(l2RBValue > -27.6f) {baseL2RBOpacity = baseOpacity[68];}
        else if(l2RBValue > -27.9f) {baseL2RBOpacity = baseOpacity[67];}
        else if(l2RBValue > -28.2f) {baseL2RBOpacity = baseOpacity[66];}
        else if(l2RBValue > -28.5f) {baseL2RBOpacity = baseOpacity[65];}
        else if(l2RBValue > -28.8f) {baseL2RBOpacity = baseOpacity[64];}
        else if(l2RBValue > -29.1f) {baseL2RBOpacity = baseOpacity[63];}
        else if(l2RBValue > -29.4f) {baseL2RBOpacity = baseOpacity[62];}
        else if(l2RBValue > -29.7f) {baseL2RBOpacity = baseOpacity[61];}
        else if(l2RBValue > -30.f)  {baseL2RBOpacity = baseOpacity[60];}

        else if(l2RBValue > -30.3f) {baseL2RBOpacity = baseOpacity[59];}
        else if(l2RBValue > -30.6f) {baseL2RBOpacity = baseOpacity[58];}
        else if(l2RBValue > -30.9f) {baseL2RBOpacity = baseOpacity[57];}
        else if(l2RBValue > -31.2f) {baseL2RBOpacity = baseOpacity[56];}
        else if(l2RBValue > -31.5f) {baseL2RBOpacity = baseOpacity[55];}
        else if(l2RBValue > -31.8f) {baseL2RBOpacity = baseOpacity[54];}
        else if(l2RBValue > -32.1f) {baseL2RBOpacity = baseOpacity[53];}
        else if(l2RBValue > -32.4f) {baseL2RBOpacity = baseOpacity[52];}
        else if(l2RBValue > -32.7f) {baseL2RBOpacity = baseOpacity[51];}
        else if(l2RBValue > -33.f)  {baseL2RBOpacity = baseOpacity[50];}
        else if(l2RBValue > -33.3f) {baseL2RBOpacity = baseOpacity[49];}
        else if(l2RBValue > -33.6f) {baseL2RBOpacity = baseOpacity[48];}
        else if(l2RBValue > -33.9f) {baseL2RBOpacity = baseOpacity[47];}
        else if(l2RBValue > -34.2f) {baseL2RBOpacity = baseOpacity[46];}
        else if(l2RBValue > -34.5f) {baseL2RBOpacity = baseOpacity[45];}
        else if(l2RBValue > -34.8f) {baseL2RBOpacity = baseOpacity[44];}
        else if(l2RBValue > -35.1f) {baseL2RBOpacity = baseOpacity[43];}
        else if(l2RBValue > -35.4f) {baseL2RBOpacity = baseOpacity[42];}
        else if(l2RBValue > -35.7f) {baseL2RBOpacity = baseOpacity[41];}
        else if(l2RBValue > -36.f)  {baseL2RBOpacity = baseOpacity[40];}


        else if(l2RBValue > -36.6f) {baseL2RBOpacity = baseOpacity[39];}
        else if(l2RBValue > -37.2f) {baseL2RBOpacity = baseOpacity[38];}
        else if(l2RBValue > -37.8f) {baseL2RBOpacity = baseOpacity[37];}
        else if(l2RBValue > -38.4f) {baseL2RBOpacity = baseOpacity[36];}
        else if(l2RBValue > -39.f)  {baseL2RBOpacity = baseOpacity[35];}
        else if(l2RBValue > -39.6f) {baseL2RBOpacity = baseOpacity[34];}
        else if(l2RBValue > -40.2f) {baseL2RBOpacity = baseOpacity[33];}
        else if(l2RBValue > -40.8f) {baseL2RBOpacity = baseOpacity[32];}
        else if(l2RBValue > -41.4f) {baseL2RBOpacity = baseOpacity[31];}
        else if(l2RBValue > -42.f)  {baseL2RBOpacity = baseOpacity[30];}

        else if(l2RBValue > -42.6f) {baseL2RBOpacity = baseOpacity[29];}
        else if(l2RBValue > -43.2f) {baseL2RBOpacity = baseOpacity[28];}
        else if(l2RBValue > -43.8f) {baseL2RBOpacity = baseOpacity[27];}
        else if(l2RBValue > -44.4f) {baseL2RBOpacity = baseOpacity[26];}
        else if(l2RBValue > -45.f)  {baseL2RBOpacity = baseOpacity[25];}
        else if(l2RBValue > -45.6f) {baseL2RBOpacity = baseOpacity[24];}
        else if(l2RBValue > -46.2f) {baseL2RBOpacity = baseOpacity[23];}
        else if(l2RBValue > -46.8f) {baseL2RBOpacity = baseOpacity[22];}
        else if(l2RBValue > -47.4f) {baseL2RBOpacity = baseOpacity[21];}
        else if(l2RBValue > -48.f)  {baseL2RBOpacity = baseOpacity[20];}

        else if(l2RBValue > -48.6f) {baseL2RBOpacity = baseOpacity[19];}
        else if(l2RBValue > -49.2f) {baseL2RBOpacity = baseOpacity[18];}
        else if(l2RBValue > -49.8f) {baseL2RBOpacity = baseOpacity[17];}
        else if(l2RBValue > -50.4f) {baseL2RBOpacity = baseOpacity[16];}
        else if(l2RBValue > -51.f)  {baseL2RBOpacity = baseOpacity[15];}
        else if(l2RBValue > -51.6f) {baseL2RBOpacity = baseOpacity[14];}
        else if(l2RBValue > -52.2f) {baseL2RBOpacity = baseOpacity[13];}
        else if(l2RBValue > -52.8f) {baseL2RBOpacity = baseOpacity[12];}
        else if(l2RBValue > -53.4f) {baseL2RBOpacity = baseOpacity[11];}
        else if(l2RBValue > -54.f)  {baseL2RBOpacity = baseOpacity[10];}

        else if(l2RBValue > -54.6f) {baseL2RBOpacity = baseOpacity[9];}
        else if(l2RBValue > -55.2f) {baseL2RBOpacity = baseOpacity[8];}
        else if(l2RBValue > -55.8f) {baseL2RBOpacity = baseOpacity[7];}
        else if(l2RBValue > -56.4f) {baseL2RBOpacity = baseOpacity[6];}
        else if(l2RBValue > -57.f)  {baseL2RBOpacity = baseOpacity[5];}
        else if(l2RBValue > -57.6f) {baseL2RBOpacity = baseOpacity[4];}
        else if(l2RBValue > -58.2f) {baseL2RBOpacity = baseOpacity[3];}
        else if(l2RBValue > -58.8f) {baseL2RBOpacity = baseOpacity[2];}
        else if(l2RBValue > -59.4f) {baseL2RBOpacity = baseOpacity[1];}
        else if(l2RBValue > -60.f)  {baseL2RBOpacity = baseOpacity[0];}
        else if(l2RBValue <= -60.f) {baseL2RBOpacity = baseOpacity[0];}
        else {baseL2RBOpacity = baseOpacity[0];}
        
        
    // FINAL
        
        if(finalValue <= 0.f) {redFinalOpacity = redOpacity[0];}
        else if(finalValue < 0.2f) {redFinalOpacity = redOpacity[1];}
        else if(finalValue < 0.4f) {redFinalOpacity = redOpacity[2];}
        else if(finalValue < 0.6f) {redFinalOpacity = redOpacity[3];}
        else if(finalValue < 0.8f) {redFinalOpacity = redOpacity[4];}
        else if(finalValue < 1.f)  {redFinalOpacity = redOpacity[5];}
        else if(finalValue < 1.2f) {redFinalOpacity = redOpacity[6];}
        else if(finalValue < 1.4f) {redFinalOpacity = redOpacity[7];}
        else if(finalValue < 1.6f) {redFinalOpacity = redOpacity[8];}
        else if(finalValue < 1.8f) {redFinalOpacity = redOpacity[9];}
        else if(finalValue < 2.f)  {redFinalOpacity = redOpacity[10];}
        else if(finalValue < 2.2f) {redFinalOpacity = redOpacity[11];}
        else if(finalValue < 2.4f) {redFinalOpacity = redOpacity[12];}
        else if(finalValue < 2.6f) {redFinalOpacity = redOpacity[13];}
        else if(finalValue < 2.8f) {redFinalOpacity = redOpacity[14];}
        else if(finalValue < 3.f)  {redFinalOpacity = redOpacity[15];}
        else if(finalValue < 3.2f) {redFinalOpacity = redOpacity[16];}
        else if(finalValue < 3.4f) {redFinalOpacity = redOpacity[17];}
        else if(finalValue < 3.6f) {redFinalOpacity = redOpacity[18];}
        else if(finalValue < 3.8f) {redFinalOpacity = redOpacity[19];}
        else if(finalValue < 4.f)  {redFinalOpacity = redOpacity[20];}
        else if(finalValue < 4.2f) {redFinalOpacity = redOpacity[21];}
        else if(finalValue < 4.4f) {redFinalOpacity = redOpacity[22];}
        else if(finalValue < 4.6f) {redFinalOpacity = redOpacity[23];}
        else if(finalValue < 4.8f) {redFinalOpacity = redOpacity[24];}
        else if(finalValue < 5.f)  {redFinalOpacity = redOpacity[25];}
        else if(finalValue < 5.2f) {redFinalOpacity = redOpacity[26];}
        else if(finalValue < 5.4f) {redFinalOpacity = redOpacity[27];}
        else if(finalValue < 5.6f) {redFinalOpacity = redOpacity[28];}
        else if(finalValue < 5.8f) {redFinalOpacity = redOpacity[29];}
        else if(finalValue < 6.f)  {redFinalOpacity = redOpacity[30];}

        // 6 dB <= Red values < 12 dB
        else if(finalValue < 6.2f) {redFinalOpacity = redOpacity[31];}
        else if(finalValue < 6.4f) {redFinalOpacity = redOpacity[32];}
        else if(finalValue < 6.6f) {redFinalOpacity = redOpacity[33];}
        else if(finalValue < 6.8f) {redFinalOpacity = redOpacity[34];}
        else if(finalValue < 7.f)  {redFinalOpacity = redOpacity[35];}
        else if(finalValue < 7.2f) {redFinalOpacity = redOpacity[36];}
        else if(finalValue < 7.4f) {redFinalOpacity = redOpacity[37];}
        else if(finalValue < 7.6f) {redFinalOpacity = redOpacity[38];}
        else if(finalValue < 7.8f) {redFinalOpacity = redOpacity[39];}
        else if(finalValue < 8.f)  {redFinalOpacity = redOpacity[40];}
        else if(finalValue < 8.2f) {redFinalOpacity = redOpacity[41];}
        else if(finalValue < 8.4f) {redFinalOpacity = redOpacity[42];}
        else if(finalValue < 8.6f) {redFinalOpacity = redOpacity[43];}
        else if(finalValue < 8.8f) {redFinalOpacity = redOpacity[44];}
        else if(finalValue < 9.f)  {redFinalOpacity = redOpacity[45];}
        else if(finalValue < 9.2f) {redFinalOpacity = redOpacity[46];}
        else if(finalValue < 9.4f) {redFinalOpacity = redOpacity[47];}
        else if(finalValue < 9.6f) {redFinalOpacity = redOpacity[48];}
        else if(finalValue < 9.8f) {redFinalOpacity = redOpacity[49];}
        else if(finalValue < 10.f) {redFinalOpacity = redOpacity[50];}
        else if(finalValue < 10.2f) {redFinalOpacity = redOpacity[51];}
        else if(finalValue < 10.4f) {redFinalOpacity = redOpacity[52];}
        else if(finalValue < 10.6f) {redFinalOpacity = redOpacity[53];}
        else if(finalValue < 10.8f) {redFinalOpacity = redOpacity[54];}
        else if(finalValue < 11.f)  {redFinalOpacity = redOpacity[55];}
        else if(finalValue < 11.2f) {redFinalOpacity = redOpacity[56];}
        else if(finalValue < 11.4f) {redFinalOpacity = redOpacity[57];}
        else if(finalValue < 11.6f) {redFinalOpacity = redOpacity[58];}
        else if(finalValue < 11.8f) {redFinalOpacity = redOpacity[59];}
        else if(finalValue < 12.f)  {redFinalOpacity = redOpacity[60];}

        // 12 dB <= Red values < 18 dB
        else if(finalValue < 12.2f) {redFinalOpacity = redOpacity[61];}
        else if(finalValue < 12.4f) {redFinalOpacity = redOpacity[62];}
        else if(finalValue < 12.6f) {redFinalOpacity = redOpacity[63];}
        else if(finalValue < 12.8f) {redFinalOpacity = redOpacity[64];}
        else if(finalValue < 13.f)  {redFinalOpacity = redOpacity[65];}
        else if(finalValue < 13.2f) {redFinalOpacity = redOpacity[66];}
        else if(finalValue < 13.4f) {redFinalOpacity = redOpacity[67];}
        else if(finalValue < 13.6f) {redFinalOpacity = redOpacity[68];}
        else if(finalValue < 13.8f) {redFinalOpacity = redOpacity[69];}
        else if(finalValue < 14.f)  {redFinalOpacity = redOpacity[70];}
        else if(finalValue < 14.2f) {redFinalOpacity = redOpacity[71];}
        else if(finalValue < 14.4f) {redFinalOpacity = redOpacity[72];}
        else if(finalValue < 14.6f) {redFinalOpacity = redOpacity[73];}
        else if(finalValue < 14.8f) {redFinalOpacity = redOpacity[74];}
        else if(finalValue < 15.f)  {redFinalOpacity = redOpacity[75];}
        else if(finalValue < 15.2f) {redFinalOpacity = redOpacity[76];}
        else if(finalValue < 15.4f) {redFinalOpacity = redOpacity[77];}
        else if(finalValue < 15.6f) {redFinalOpacity = redOpacity[78];}
        else if(finalValue < 15.8f) {redFinalOpacity = redOpacity[79];}
        else if(finalValue < 16.f)  {redFinalOpacity = redOpacity[80];}
        else if(finalValue < 16.2f) {redFinalOpacity = redOpacity[81];}
        else if(finalValue < 16.4f) {redFinalOpacity = redOpacity[82];}
        else if(finalValue < 16.6f) {redFinalOpacity = redOpacity[83];}
        else if(finalValue < 16.8f) {redFinalOpacity = redOpacity[84];}
        else if(finalValue < 17.f)  {redFinalOpacity = redOpacity[85];}
        else if(finalValue < 17.2f) {redFinalOpacity = redOpacity[86];}
        else if(finalValue < 17.4f) {redFinalOpacity = redOpacity[87];}
        else if(finalValue < 17.6f) {redFinalOpacity = redOpacity[88];}
        else if(finalValue < 17.8f) {redFinalOpacity = redOpacity[89];}
        else if(finalValue < 18.f)  {redFinalOpacity = redOpacity[90];}

        // 18 dB <= Red values <= 24 dB
        else if(finalValue < 18.2f) {redFinalOpacity = redOpacity[91];}
        else if(finalValue < 18.4f) {redFinalOpacity = redOpacity[92];}
        else if(finalValue < 18.6f) {redFinalOpacity = redOpacity[93];}
        else if(finalValue < 18.8f) {redFinalOpacity = redOpacity[94];}
        else if(finalValue < 19.f)  {redFinalOpacity = redOpacity[95];}
        else if(finalValue < 19.2f) {redFinalOpacity = redOpacity[96];}
        else if(finalValue < 19.4f) {redFinalOpacity = redOpacity[97];}
        else if(finalValue < 19.6f) {redFinalOpacity = redOpacity[98];}
        else if(finalValue < 19.8f) {redFinalOpacity = redOpacity[99];}
        else if(finalValue < 20.f)  {redFinalOpacity = redOpacity[100];}
        else if(finalValue < 20.2f) {redFinalOpacity = redOpacity[101];}
        else if(finalValue < 20.4f) {redFinalOpacity = redOpacity[102];}
        else if(finalValue < 20.6f) {redFinalOpacity = redOpacity[103];}
        else if(finalValue < 20.8f) {redFinalOpacity = redOpacity[104];}
        else if(finalValue < 21.f)  {redFinalOpacity = redOpacity[105];}
        else if(finalValue < 21.2f) {redFinalOpacity = redOpacity[106];}
        else if(finalValue < 21.4f) {redFinalOpacity = redOpacity[107];}
        else if(finalValue < 21.6f) {redFinalOpacity = redOpacity[108];}
        else if(finalValue < 21.8f) {redFinalOpacity = redOpacity[109];}
        else if(finalValue < 22.f)  {redFinalOpacity = redOpacity[110];}
        else if(finalValue < 22.2f) {redFinalOpacity = redOpacity[111];}
        else if(finalValue < 22.4f) {redFinalOpacity = redOpacity[112];}
        else if(finalValue < 22.6f) {redFinalOpacity = redOpacity[113];}
        else if(finalValue < 22.8f) {redFinalOpacity = redOpacity[114];}
        else if(finalValue < 23.f)  {redFinalOpacity = redOpacity[115];}
        else if(finalValue < 23.2f) {redFinalOpacity = redOpacity[116];}
        else if(finalValue < 23.4f) {redFinalOpacity = redOpacity[117];}
        else if(finalValue < 23.6f) {redFinalOpacity = redOpacity[118];}
        else if(finalValue < 23.8f) {redFinalOpacity = redOpacity[119];}
        else if(finalValue < 24.f)  {redFinalOpacity = redOpacity[120];}
        else if(finalValue >= 24.f) {redFinalOpacity = redOpacity[121];}
        else {redFinalOpacity = redOpacity[0];}


        if(finalValue == 0.f) {baseFinalOpacity = baseOpacity[200];}
        else if(finalValue > -0.2f) {baseFinalOpacity = baseOpacity[199];}
        else if(finalValue > -0.4f) {baseFinalOpacity = baseOpacity[198];}
        else if(finalValue > -0.6f) {baseFinalOpacity = baseOpacity[197];}
        else if(finalValue > -0.8f) {baseFinalOpacity = baseOpacity[196];}
        else if(finalValue > -1.f)  {baseFinalOpacity = baseOpacity[195];}
        else if(finalValue > -1.2f) {baseFinalOpacity = baseOpacity[194];}
        else if(finalValue > -1.4f) {baseFinalOpacity = baseOpacity[193];}
        else if(finalValue > -1.6f) {baseFinalOpacity = baseOpacity[192];}
        else if(finalValue > -1.8f) {baseFinalOpacity = baseOpacity[191];}
        else if(finalValue > -2.f)  {baseFinalOpacity = baseOpacity[190];}
        else if(finalValue > -2.2f) {baseFinalOpacity = baseOpacity[189];}
        else if(finalValue > -2.4f) {baseFinalOpacity = baseOpacity[188];}
        else if(finalValue > -2.6f) {baseFinalOpacity = baseOpacity[187];}
        else if(finalValue > -2.8f) {baseFinalOpacity = baseOpacity[186];}
        else if(finalValue > -3.f)  {baseFinalOpacity = baseOpacity[185];}
        else if(finalValue > -3.2f) {baseFinalOpacity = baseOpacity[184];}
        else if(finalValue > -3.4f) {baseFinalOpacity = baseOpacity[183];}
        else if(finalValue > -3.6f) {baseFinalOpacity = baseOpacity[182];}
        else if(finalValue > -3.8f) {baseFinalOpacity = baseOpacity[181];}
        else if(finalValue > -4.f)  {baseFinalOpacity = baseOpacity[180];}
        else if(finalValue > -4.2f) {baseFinalOpacity = baseOpacity[179];}
        else if(finalValue > -4.4f) {baseFinalOpacity = baseOpacity[178];}
        else if(finalValue > -4.6f) {baseFinalOpacity = baseOpacity[177];}
        else if(finalValue > -4.8f) {baseFinalOpacity = baseOpacity[176];}
        else if(finalValue > -5.f)  {baseFinalOpacity = baseOpacity[175];}
        else if(finalValue > -5.2f) {baseFinalOpacity = baseOpacity[174];}
        else if(finalValue > -5.4f) {baseFinalOpacity = baseOpacity[173];}
        else if(finalValue > -5.6f) {baseFinalOpacity = baseOpacity[172];}
        else if(finalValue > -5.8f) {baseFinalOpacity = baseOpacity[171];}
        else if(finalValue > -6.f)  {baseFinalOpacity = baseOpacity[170];}

        // 6 dB <= Red values < 12 dB
        else if(finalValue > -6.2f) {baseFinalOpacity = baseOpacity[169];}
        else if(finalValue > -6.4f) {baseFinalOpacity = baseOpacity[168];}
        else if(finalValue > -6.6f) {baseFinalOpacity = baseOpacity[167];}
        else if(finalValue > -6.8f) {baseFinalOpacity = baseOpacity[166];}
        else if(finalValue > -7.f)  {baseFinalOpacity = baseOpacity[165];}
        else if(finalValue > -7.2f) {baseFinalOpacity = baseOpacity[164];}
        else if(finalValue > -7.4f) {baseFinalOpacity = baseOpacity[163];}
        else if(finalValue > -7.6f) {baseFinalOpacity = baseOpacity[162];}
        else if(finalValue > -7.8f) {baseFinalOpacity = baseOpacity[161];}
        else if(finalValue > -8.f)  {baseFinalOpacity = baseOpacity[160];}
        else if(finalValue > -8.2f) {baseFinalOpacity = baseOpacity[159];}
        else if(finalValue > -8.4f) {baseFinalOpacity = baseOpacity[158];}
        else if(finalValue > -8.6f) {baseFinalOpacity = baseOpacity[157];}
        else if(finalValue > -8.8f) {baseFinalOpacity = baseOpacity[156];}
        else if(finalValue > -9.f)  {baseFinalOpacity = baseOpacity[155];}
        else if(finalValue > -9.2f) {baseFinalOpacity = baseOpacity[154];}
        else if(finalValue > -9.4f) {baseFinalOpacity = baseOpacity[153];}
        else if(finalValue > -9.6f) {baseFinalOpacity = baseOpacity[152];}
        else if(finalValue > -9.8f) {baseFinalOpacity = baseOpacity[151];}
        else if(finalValue > -10.f) {baseFinalOpacity = baseOpacity[150];}
        else if(finalValue > -10.2f) {baseFinalOpacity = baseOpacity[149];}
        else if(finalValue > -10.4f) {baseFinalOpacity = baseOpacity[148];}
        else if(finalValue > -10.6f) {baseFinalOpacity = baseOpacity[147];}
        else if(finalValue > -10.8f) {baseFinalOpacity = baseOpacity[146];}
        else if(finalValue > -11.f)  {baseFinalOpacity = baseOpacity[145];}
        else if(finalValue > -11.2f) {baseFinalOpacity = baseOpacity[144];}
        else if(finalValue > -11.4f) {baseFinalOpacity = baseOpacity[143];}
        else if(finalValue > -11.6f) {baseFinalOpacity = baseOpacity[142];}
        else if(finalValue > -11.8f) {baseFinalOpacity = baseOpacity[141];}
        else if(finalValue > -12.f)  {baseFinalOpacity = baseOpacity[140];}

        // 12 dB <= Red values < 18 dB
        else if(finalValue > -12.2f) {baseFinalOpacity = baseOpacity[139];}
        else if(finalValue > -12.4f) {baseFinalOpacity = baseOpacity[138];}
        else if(finalValue > -12.6f) {baseFinalOpacity = baseOpacity[137];}
        else if(finalValue > -12.8f) {baseFinalOpacity = baseOpacity[136];}
        else if(finalValue > -13.f)  {baseFinalOpacity = baseOpacity[135];}
        else if(finalValue > -13.2f) {baseFinalOpacity = baseOpacity[134];}
        else if(finalValue > -13.4f) {baseFinalOpacity = baseOpacity[133];}
        else if(finalValue > -13.6f) {baseFinalOpacity = baseOpacity[132];}
        else if(finalValue > -13.8f) {baseFinalOpacity = baseOpacity[131];}
        else if(finalValue > -14.f)  {baseFinalOpacity = baseOpacity[130];}
        else if(finalValue > -14.2f) {baseFinalOpacity = baseOpacity[129];}
        else if(finalValue > -14.4f) {baseFinalOpacity = baseOpacity[128];}
        else if(finalValue > -14.6f) {baseFinalOpacity = baseOpacity[127];}
        else if(finalValue > -14.8f) {baseFinalOpacity = baseOpacity[126];}
        else if(finalValue > -15.f)  {baseFinalOpacity = baseOpacity[125];}
        else if(finalValue > -15.2f) {baseFinalOpacity = baseOpacity[124];}
        else if(finalValue > -15.4f) {baseFinalOpacity = baseOpacity[123];}
        else if(finalValue > -15.6f) {baseFinalOpacity = baseOpacity[122];}
        else if(finalValue > -15.8f) {baseFinalOpacity = baseOpacity[121];}
        else if(finalValue > -16.f)  {baseFinalOpacity = baseOpacity[120];}
        else if(finalValue > -16.2f) {baseFinalOpacity = baseOpacity[119];}
        else if(finalValue > -16.4f) {baseFinalOpacity = baseOpacity[118];}
        else if(finalValue > -16.6f) {baseFinalOpacity = baseOpacity[117];}
        else if(finalValue > -16.8f) {baseFinalOpacity = baseOpacity[116];}
        else if(finalValue > -17.f)  {baseFinalOpacity = baseOpacity[115];}
        else if(finalValue > -17.2f) {baseFinalOpacity = baseOpacity[114];}
        else if(finalValue > -17.4f) {baseFinalOpacity = baseOpacity[113];}
        else if(finalValue > -17.6f) {baseFinalOpacity = baseOpacity[112];}
        else if(finalValue > -17.8f) {baseFinalOpacity = baseOpacity[111];}
        else if(finalValue > -18.f)  {baseFinalOpacity = baseOpacity[110];}

        // 18 dB <= Red values <= 24 dB
        else if(finalValue > -18.2f) {baseFinalOpacity = baseOpacity[109];}
        else if(finalValue > -18.4f) {baseFinalOpacity = baseOpacity[108];}
        else if(finalValue > -18.6f) {baseFinalOpacity = baseOpacity[107];}
        else if(finalValue > -18.8f) {baseFinalOpacity = baseOpacity[106];}
        else if(finalValue > -19.f)  {baseFinalOpacity = baseOpacity[105];}
        else if(finalValue > -19.2f) {baseFinalOpacity = baseOpacity[104];}
        else if(finalValue > -19.4f) {baseFinalOpacity = baseOpacity[103];}
        else if(finalValue > -19.6f) {baseFinalOpacity = baseOpacity[102];}
        else if(finalValue > -19.8f) {baseFinalOpacity = baseOpacity[101];}
        else if(finalValue > -20.f)  {baseFinalOpacity = baseOpacity[100];}
        else if(finalValue > -20.2f) {baseFinalOpacity = baseOpacity[99];}
        else if(finalValue > -20.4f) {baseFinalOpacity = baseOpacity[98];}
        else if(finalValue > -20.6f) {baseFinalOpacity = baseOpacity[97];}
        else if(finalValue > -20.8f) {baseFinalOpacity = baseOpacity[96];}
        else if(finalValue > -21.f)  {baseFinalOpacity = baseOpacity[95];}
        else if(finalValue > -21.2f) {baseFinalOpacity = baseOpacity[94];}
        else if(finalValue > -21.4f) {baseFinalOpacity = baseOpacity[93];}
        else if(finalValue > -21.6f) {baseFinalOpacity = baseOpacity[92];}
        else if(finalValue > -21.8f) {baseFinalOpacity = baseOpacity[91];}
        else if(finalValue > -22.f)  {baseFinalOpacity = baseOpacity[90];}
        else if(finalValue > -22.2f) {baseFinalOpacity = baseOpacity[89];}
        else if(finalValue > -22.4f) {baseFinalOpacity = baseOpacity[88];}
        else if(finalValue > -22.6f) {baseFinalOpacity = baseOpacity[87];}
        else if(finalValue > -22.8f) {baseFinalOpacity = baseOpacity[86];}
        else if(finalValue > -23.f)  {baseFinalOpacity = baseOpacity[85];}
        else if(finalValue > -23.2f) {baseFinalOpacity = baseOpacity[84];}
        else if(finalValue > -23.4f) {baseFinalOpacity = baseOpacity[83];}
        else if(finalValue > -23.6f) {baseFinalOpacity = baseOpacity[82];}
        else if(finalValue > -23.8f) {baseFinalOpacity = baseOpacity[81];}
        else if(finalValue > -24.f)  {baseFinalOpacity = baseOpacity[80];}

        // 18 dB <= Red values <= 24 dB
        else if(finalValue > -24.3f) {baseFinalOpacity = baseOpacity[79];}
        else if(finalValue > -24.6f) {baseFinalOpacity = baseOpacity[78];}
        else if(finalValue > -24.9f) {baseFinalOpacity = baseOpacity[77];}
        else if(finalValue > -25.2f) {baseFinalOpacity = baseOpacity[76];}
        else if(finalValue > -25.5f) {baseFinalOpacity = baseOpacity[75];}
        else if(finalValue > -25.8f) {baseFinalOpacity = baseOpacity[74];}
        else if(finalValue > -26.1f) {baseFinalOpacity = baseOpacity[73];}
        else if(finalValue > -26.4f) {baseFinalOpacity = baseOpacity[72];}
        else if(finalValue > -26.7f) {baseFinalOpacity = baseOpacity[71];}
        else if(finalValue > -27.f)  {baseFinalOpacity = baseOpacity[70];}
        else if(finalValue > -27.3f) {baseFinalOpacity = baseOpacity[69];}
        else if(finalValue > -27.6f) {baseFinalOpacity = baseOpacity[68];}
        else if(finalValue > -27.9f) {baseFinalOpacity = baseOpacity[67];}
        else if(finalValue > -28.2f) {baseFinalOpacity = baseOpacity[66];}
        else if(finalValue > -28.5f) {baseFinalOpacity = baseOpacity[65];}
        else if(finalValue > -28.8f) {baseFinalOpacity = baseOpacity[64];}
        else if(finalValue > -29.1f) {baseFinalOpacity = baseOpacity[63];}
        else if(finalValue > -29.4f) {baseFinalOpacity = baseOpacity[62];}
        else if(finalValue > -29.7f) {baseFinalOpacity = baseOpacity[61];}
        else if(finalValue > -30.f)  {baseFinalOpacity = baseOpacity[60];}

        else if(finalValue > -30.3f) {baseFinalOpacity = baseOpacity[59];}
        else if(finalValue > -30.6f) {baseFinalOpacity = baseOpacity[58];}
        else if(finalValue > -30.9f) {baseFinalOpacity = baseOpacity[57];}
        else if(finalValue > -31.2f) {baseFinalOpacity = baseOpacity[56];}
        else if(finalValue > -31.5f) {baseFinalOpacity = baseOpacity[55];}
        else if(finalValue > -31.8f) {baseFinalOpacity = baseOpacity[54];}
        else if(finalValue > -32.1f) {baseFinalOpacity = baseOpacity[53];}
        else if(finalValue > -32.4f) {baseFinalOpacity = baseOpacity[52];}
        else if(finalValue > -32.7f) {baseFinalOpacity = baseOpacity[51];}
        else if(finalValue > -33.f)  {baseFinalOpacity = baseOpacity[50];}
        else if(finalValue > -33.3f) {baseFinalOpacity = baseOpacity[49];}
        else if(finalValue > -33.6f) {baseFinalOpacity = baseOpacity[48];}
        else if(finalValue > -33.9f) {baseFinalOpacity = baseOpacity[47];}
        else if(finalValue > -34.2f) {baseFinalOpacity = baseOpacity[46];}
        else if(finalValue > -34.5f) {baseFinalOpacity = baseOpacity[45];}
        else if(finalValue > -34.8f) {baseFinalOpacity = baseOpacity[44];}
        else if(finalValue > -35.1f) {baseFinalOpacity = baseOpacity[43];}
        else if(finalValue > -35.4f) {baseFinalOpacity = baseOpacity[42];}
        else if(finalValue > -35.7f) {baseFinalOpacity = baseOpacity[41];}
        else if(finalValue > -36.f)  {baseFinalOpacity = baseOpacity[40];}


        else if(finalValue > -36.6f) {baseFinalOpacity = baseOpacity[39];}
        else if(finalValue > -37.2f) {baseFinalOpacity = baseOpacity[38];}
        else if(finalValue > -37.8f) {baseFinalOpacity = baseOpacity[37];}
        else if(finalValue > -38.4f) {baseFinalOpacity = baseOpacity[36];}
        else if(finalValue > -39.f)  {baseFinalOpacity = baseOpacity[35];}
        else if(finalValue > -39.6f) {baseFinalOpacity = baseOpacity[34];}
        else if(finalValue > -40.2f) {baseFinalOpacity = baseOpacity[33];}
        else if(finalValue > -40.8f) {baseFinalOpacity = baseOpacity[32];}
        else if(finalValue > -41.4f) {baseFinalOpacity = baseOpacity[31];}
        else if(finalValue > -42.f)  {baseFinalOpacity = baseOpacity[30];}

        else if(finalValue > -42.6f) {baseFinalOpacity = baseOpacity[29];}
        else if(finalValue > -43.2f) {baseFinalOpacity = baseOpacity[28];}
        else if(finalValue > -43.8f) {baseFinalOpacity = baseOpacity[27];}
        else if(finalValue > -44.4f) {baseFinalOpacity = baseOpacity[26];}
        else if(finalValue > -45.f)  {baseFinalOpacity = baseOpacity[25];}
        else if(finalValue > -45.6f) {baseFinalOpacity = baseOpacity[24];}
        else if(finalValue > -46.2f) {baseFinalOpacity = baseOpacity[23];}
        else if(finalValue > -46.8f) {baseFinalOpacity = baseOpacity[22];}
        else if(finalValue > -47.4f) {baseFinalOpacity = baseOpacity[21];}
        else if(finalValue > -48.f)  {baseFinalOpacity = baseOpacity[20];}

        else if(finalValue > -48.6f) {baseFinalOpacity = baseOpacity[19];}
        else if(finalValue > -49.2f) {baseFinalOpacity = baseOpacity[18];}
        else if(finalValue > -49.8f) {baseFinalOpacity = baseOpacity[17];}
        else if(finalValue > -50.4f) {baseFinalOpacity = baseOpacity[16];}
        else if(finalValue > -51.f)  {baseFinalOpacity = baseOpacity[15];}
        else if(finalValue > -51.6f) {baseFinalOpacity = baseOpacity[14];}
        else if(finalValue > -52.2f) {baseFinalOpacity = baseOpacity[13];}
        else if(finalValue > -52.8f) {baseFinalOpacity = baseOpacity[12];}
        else if(finalValue > -53.4f) {baseFinalOpacity = baseOpacity[11];}
        else if(finalValue > -54.f)  {baseFinalOpacity = baseOpacity[10];}

        else if(finalValue > -54.6f) {baseFinalOpacity = baseOpacity[9];}
        else if(finalValue > -55.2f) {baseFinalOpacity = baseOpacity[8];}
        else if(finalValue > -55.8f) {baseFinalOpacity = baseOpacity[7];}
        else if(finalValue > -56.4f) {baseFinalOpacity = baseOpacity[6];}
        else if(finalValue > -57.f)  {baseFinalOpacity = baseOpacity[5];}
        else if(finalValue > -57.6f) {baseFinalOpacity = baseOpacity[4];}
        else if(finalValue > -58.2f) {baseFinalOpacity = baseOpacity[3];}
        else if(finalValue > -58.8f) {baseFinalOpacity = baseOpacity[2];}
        else if(finalValue > -59.4f) {baseFinalOpacity = baseOpacity[1];}
        else if(finalValue > -60.f)  {baseFinalOpacity = baseOpacity[0];}
        else if(finalValue <= -60.f) {baseFinalOpacity = baseOpacity[0];}
        else {baseFinalOpacity = baseOpacity[0];}
        
        if((l2RValueRaw + r2LValueRaw) >= 0.f) {
            redL2RAOpacity = 1.f;
            redR2LOpacity = 1.f;
            redL2RBOpacity = 1.f;
            redFinalOpacity = 1.f;
        }
        
        if(((&initialGainKnob)->getValue()) > 24.f) {
            initialGainKnob.setValue(24.0);
        }
        if(((&l2RGainKnob)->getValue()) > 24.f) {
            l2RGainKnob.setValue(24.0);
        }
        if(((&r2LGainKnob)->getValue()) > 24.f) {
            r2LGainKnob.setValue(24.0);
        }
        if(((&initialGainKnob)->getValue()) < -60.f) {
            initialGainKnob.setValue(-60.0);
        }
        if(((&l2RGainKnob)->getValue()) < -60.f) {
            l2RGainKnob.setValue(-60.0);
        }
        if(((&r2LGainKnob)->getValue()) < -60.f) {
            r2LGainKnob.setValue(-60.0);
        }

        
        repaint();
            
    }
//    if (slider == &l2RGainKnob){
//        float l2RValue = slider -> getValue();
//    }
//    if (slider == &r2LGainKnob){
//        float r2LValue = slider -> getValue();
//    }
    if (slider == &tempoSelector) {

    }
    if (slider == &mixKnob) {
        float mixValue = slider->getValue();
        
        if(mixValue == 100) {knobPosition = mix100;}
        // Knob images 90 - 99.5
        else if (mixValue >= 99.5f) {knobPosition = mix99x5;}
        else if (mixValue >= 99.f) {knobPosition = mix99;}
        else if (mixValue >= 98.5f) {knobPosition = mix98x5;}
        else if (mixValue >= 98.f) {knobPosition = mix98;}
        else if (mixValue >= 97.5f) {knobPosition = mix97x5;}
        else if (mixValue >= 97.f) {knobPosition = mix97;}
        else if (mixValue >= 96.5f) {knobPosition = mix96x5;}
        else if (mixValue >= 96.f) {knobPosition = mix96;}
        else if (mixValue >= 95.5f) {knobPosition = mix95x5;}
        else if (mixValue >= 95.f) {knobPosition = mix95;}
        else if (mixValue >= 94.5f) {knobPosition = mix94x5;}
        else if (mixValue >= 94.f) {knobPosition = mix94;}
        else if (mixValue >= 93.5f) {knobPosition = mix93x5;}
        else if (mixValue >= 93.f) {knobPosition = mix93;}
        else if (mixValue >= 92.5f) {knobPosition = mix92x5;}
        else if (mixValue >= 92.f) {knobPosition = mix92;}
        else if (mixValue >= 91.5f) {knobPosition = mix91x5;}
        else if (mixValue >= 91.f) {knobPosition = mix91;}
        else if (mixValue >= 90.5f) {knobPosition = mix90x5;}
        else if (mixValue >= 90.f) {knobPosition = mix90;}
        // Knob images 80 - 89.5
        else if (mixValue >= 89.5f) {knobPosition = mix89x5;}
        else if (mixValue >= 89.f) {knobPosition = mix89;}
        else if (mixValue >= 88.5f) {knobPosition = mix88x5;}
        else if (mixValue >= 88.f) {knobPosition = mix88;}
        else if (mixValue >= 87.5f) {knobPosition = mix87x5;}
        else if (mixValue >= 87.f) {knobPosition = mix87;}
        else if (mixValue >= 86.5f) {knobPosition = mix86x5;}
        else if (mixValue >= 86.f) {knobPosition = mix86;}
        else if (mixValue >= 85.5f) {knobPosition = mix85x5;}
        else if (mixValue >= 85.f) {knobPosition = mix85;}
        else if (mixValue >= 84.5f) {knobPosition = mix84x5;}
        else if (mixValue >= 84.f) {knobPosition = mix84;}
        else if (mixValue >= 83.5f) {knobPosition = mix83x5;}
        else if (mixValue >= 83.f) {knobPosition = mix83;}
        else if (mixValue >= 82.5f) {knobPosition = mix82x5;}
        else if (mixValue >= 82.f) {knobPosition = mix82;}
        else if (mixValue >= 81.5f) {knobPosition = mix81x5;}
        else if (mixValue >= 81.f) {knobPosition = mix81;}
        else if (mixValue >= 80.5f) {knobPosition = mix80x5;}
        else if (mixValue >= 80.f) {knobPosition = mix80;}
        // Knob images 70 - 79.5
        else if (mixValue >= 79.5f) {knobPosition = mix79x5;}
        else if (mixValue >= 79.f) {knobPosition = mix79;}
        else if (mixValue >= 78.5f) {knobPosition = mix78x5;}
        else if (mixValue >= 78.f) {knobPosition = mix78;}
        else if (mixValue >= 77.5f) {knobPosition = mix77x5;}
        else if (mixValue >= 77.f) {knobPosition = mix77;}
        else if (mixValue >= 76.5f) {knobPosition = mix76x5;}
        else if (mixValue >= 76.f) {knobPosition = mix76;}
        else if (mixValue >= 75.5f) {knobPosition = mix75x5;}
        else if (mixValue >= 75.f) {knobPosition = mix75;}
        else if (mixValue >= 74.5f) {knobPosition = mix74x5;}
        else if (mixValue >= 74.f) {knobPosition = mix74;}
        else if (mixValue >= 73.5f) {knobPosition = mix73x5;}
        else if (mixValue >= 73.f) {knobPosition = mix73;}
        else if (mixValue >= 72.5f) {knobPosition = mix72x5;}
        else if (mixValue >= 72.f) {knobPosition = mix72;}
        else if (mixValue >= 71.5f) {knobPosition = mix71x5;}
        else if (mixValue >= 71.f) {knobPosition = mix71;}
        else if (mixValue >= 70.5f) {knobPosition = mix70x5;}
        else if (mixValue >= 70.f) {knobPosition = mix70;}
        // Knob images 60 - 69.5
        else if (mixValue >= 69.5f) {knobPosition = mix69x5;}
        else if (mixValue >= 69.f) {knobPosition = mix69;}
        else if (mixValue >= 68.5f) {knobPosition = mix68x5;}
        else if (mixValue >= 68.f) {knobPosition = mix68;}
        else if (mixValue >= 67.5f) {knobPosition = mix67x5;}
        else if (mixValue >= 67.f) {knobPosition = mix67;}
        else if (mixValue >= 66.5f) {knobPosition = mix66x5;}
        else if (mixValue >= 66.f) {knobPosition = mix66;}
        else if (mixValue >= 65.5f) {knobPosition = mix65x5;}
        else if (mixValue >= 65.f) {knobPosition = mix65;}
        else if (mixValue >= 64.5f) {knobPosition = mix64x5;}
        else if (mixValue >= 64.f) {knobPosition = mix64;}
        else if (mixValue >= 63.5f) {knobPosition = mix63x5;}
        else if (mixValue >= 63.f) {knobPosition = mix63;}
        else if (mixValue >= 62.5f) {knobPosition = mix62x5;}
        else if (mixValue >= 62.f) {knobPosition = mix62;}
        else if (mixValue >= 61.5f) {knobPosition = mix61x5;}
        else if (mixValue >= 61.f) {knobPosition = mix61;}
        else if (mixValue >= 60.5f) {knobPosition = mix60x5;}
        else if (mixValue >= 60.f) {knobPosition = mix60;}
        // Knob images 50 - 59.5
        else if (mixValue >= 59.5f) {knobPosition = mix59x5;}
        else if (mixValue >= 59.f) {knobPosition = mix59;}
        else if (mixValue >= 58.5f) {knobPosition = mix58x5;}
        else if (mixValue >= 58.f) {knobPosition = mix58;}
        else if (mixValue >= 57.5f) {knobPosition = mix57x5;}
        else if (mixValue >= 57.f) {knobPosition = mix57;}
        else if (mixValue >= 56.5f) {knobPosition = mix56x5;}
        else if (mixValue >= 56.f) {knobPosition = mix56;}
        else if (mixValue >= 55.5f) {knobPosition = mix55x5;}
        else if (mixValue >= 55.f) {knobPosition = mix55;}
        else if (mixValue >= 54.5f) {knobPosition = mix54x5;}
        else if (mixValue >= 54.f) {knobPosition = mix54;}
        else if (mixValue >= 53.5f) {knobPosition = mix53x5;}
        else if (mixValue >= 53.f) {knobPosition = mix53;}
        else if (mixValue >= 52.5f) {knobPosition = mix52x5;}
        else if (mixValue >= 52.f) {knobPosition = mix52;}
        else if (mixValue >= 51.5f) {knobPosition = mix51x5;}
        else if (mixValue >= 51.f) {knobPosition = mix51;}
        else if (mixValue >= 50.5f) {knobPosition = mix50x5;}
        else if (mixValue >= 50.f) {knobPosition = mix50;}
        // Knob images 40 - 49.5
        else if (mixValue >= 49.5f) {knobPosition = mix49x5;}
        else if (mixValue >= 49.f) {knobPosition = mix49;}
        else if (mixValue >= 48.5f) {knobPosition = mix48x5;}
        else if (mixValue >= 48.f) {knobPosition = mix48;}
        else if (mixValue >= 47.5f) {knobPosition = mix47x5;}
        else if (mixValue >= 47.f) {knobPosition = mix47;}
        else if (mixValue >= 46.5f) {knobPosition = mix46x5;}
        else if (mixValue >= 46.f) {knobPosition = mix46;}
        else if (mixValue >= 45.5f) {knobPosition = mix45x5;}
        else if (mixValue >= 45.f) {knobPosition = mix45;}
        else if (mixValue >= 44.5f) {knobPosition = mix44x5;}
        else if (mixValue >= 44.f) {knobPosition = mix44;}
        else if (mixValue >= 43.5f) {knobPosition = mix43x5;}
        else if (mixValue >= 43.f) {knobPosition = mix43;}
        else if (mixValue >= 42.5f) {knobPosition = mix42x5;}
        else if (mixValue >= 42.f) {knobPosition = mix42;}
        else if (mixValue >= 41.5f) {knobPosition = mix41x5;}
        else if (mixValue >= 41.f) {knobPosition = mix41;}
        else if (mixValue >= 40.5f) {knobPosition = mix40x5;}
        else if (mixValue >= 40.f) {knobPosition = mix40;}
        // Knob images 30 - 39.5
        else if (mixValue >= 39.5f) {knobPosition = mix39x5;}
        else if (mixValue >= 39.f) {knobPosition = mix39;}
        else if (mixValue >= 38.5f) {knobPosition = mix38x5;}
        else if (mixValue >= 38.f) {knobPosition = mix38;}
        else if (mixValue >= 37.5f) {knobPosition = mix37x5;}
        else if (mixValue >= 37.f) {knobPosition = mix37;}
        else if (mixValue >= 36.5f) {knobPosition = mix36x5;}
        else if (mixValue >= 36.f) {knobPosition = mix36;}
        else if (mixValue >= 35.5f) {knobPosition = mix35x5;}
        else if (mixValue >= 35.f) {knobPosition = mix35;}
        else if (mixValue >= 34.5f) {knobPosition = mix34x5;}
        else if (mixValue >= 34.f) {knobPosition = mix34;}
        else if (mixValue >= 33.5f) {knobPosition = mix33x5;}
        else if (mixValue >= 33.f) {knobPosition = mix33;}
        else if (mixValue >= 32.5f) {knobPosition = mix32x5;}
        else if (mixValue >= 32.f) {knobPosition = mix32;}
        else if (mixValue >= 31.5f) {knobPosition = mix31x5;}
        else if (mixValue >= 31.f) {knobPosition = mix31;}
        else if (mixValue >= 30.5f) {knobPosition = mix30x5;}
        else if (mixValue >= 30.f) {knobPosition = mix30;}
        // Knob images 20 - 29.5
        else if (mixValue >= 29.5f) {knobPosition = mix29x5;}
        else if (mixValue >= 29.f) {knobPosition = mix29;}
        else if (mixValue >= 28.5f) {knobPosition = mix28x5;}
        else if (mixValue >= 28.f) {knobPosition = mix28;}
        else if (mixValue >= 27.5f) {knobPosition = mix27x5;}
        else if (mixValue >= 27.f) {knobPosition = mix27;}
        else if (mixValue >= 26.5f) {knobPosition = mix26x5;}
        else if (mixValue >= 26.f) {knobPosition = mix26;}
        else if (mixValue >= 25.5f) {knobPosition = mix25x5;}
        else if (mixValue >= 25.f) {knobPosition = mix25;}
        else if (mixValue >= 24.5f) {knobPosition = mix24x5;}
        else if (mixValue >= 24.f) {knobPosition = mix24;}
        else if (mixValue >= 23.5f) {knobPosition = mix23x5;}
        else if (mixValue >= 23.f) {knobPosition = mix23;}
        else if (mixValue >= 22.5f) {knobPosition = mix22x5;}
        else if (mixValue >= 22.f) {knobPosition = mix22;}
        else if (mixValue >= 21.5f) {knobPosition = mix21x5;}
        else if (mixValue >= 21.f) {knobPosition = mix21;}
        else if (mixValue >= 20.5f) {knobPosition = mix20x5;}
        else if (mixValue >= 20.f) {knobPosition = mix20;}
        // Knob images 10 - 19.5
        else if (mixValue >= 19.5f) {knobPosition = mix19x5;}
        else if (mixValue >= 19.f) {knobPosition = mix19;}
        else if (mixValue >= 18.5f) {knobPosition = mix18x5;}
        else if (mixValue >= 18.f) {knobPosition = mix18;}
        else if (mixValue >= 17.5f) {knobPosition = mix17x5;}
        else if (mixValue >= 17.f) {knobPosition = mix17;}
        else if (mixValue >= 16.5f) {knobPosition = mix16x5;}
        else if (mixValue >= 16.f) {knobPosition = mix16;}
        else if (mixValue >= 15.5f) {knobPosition = mix15x5;}
        else if (mixValue >= 15.f) {knobPosition = mix15;}
        else if (mixValue >= 14.5f) {knobPosition = mix14x5;}
        else if (mixValue >= 14.f) {knobPosition = mix14;}
        else if (mixValue >= 13.5f) {knobPosition = mix13x5;}
        else if (mixValue >= 13.f) {knobPosition = mix13;}
        else if (mixValue >= 12.5f) {knobPosition = mix12x5;}
        else if (mixValue >= 12.f) {knobPosition = mix12;}
        else if (mixValue >= 11.5f) {knobPosition = mix11x5;}
        else if (mixValue >= 11.f) {knobPosition = mix11;}
        else if (mixValue >= 10.5f) {knobPosition = mix10x5;}
        else if (mixValue >= 10.f) {knobPosition = mix10;}
        // Knob images 0 - 9.5
        else if (mixValue >= 9.5f) {knobPosition = mix9x5;}
        else if (mixValue >= 9.f) {knobPosition = mix9;}
        else if (mixValue >= 8.5f) {knobPosition = mix8x5;}
        else if (mixValue >= 8.f) {knobPosition = mix8;}
        else if (mixValue >= 7.5f) {knobPosition = mix7x5;}
        else if (mixValue >= 7.f) {knobPosition = mix7;}
        else if (mixValue >= 6.5f) {knobPosition = mix6x5;}
        else if (mixValue >= 6.f) {knobPosition = mix6;}
        else if (mixValue >= 5.5f) {knobPosition = mix5x5;}
        else if (mixValue >= 5.f) {knobPosition = mix5;}
        else if (mixValue >= 4.5f) {knobPosition = mix4x5;}
        else if (mixValue >= 4.f) {knobPosition = mix4;}
        else if (mixValue >= 3.5f) {knobPosition = mix3x5;}
        else if (mixValue >= 3.f) {knobPosition = mix3;}
        else if (mixValue >= 2.5f) {knobPosition = mix2x5;}
        else if (mixValue >= 2.f) {knobPosition = mix2;}
        else if (mixValue >= 1.5f) {knobPosition = mix1x5;}
        else if (mixValue >= 1.f) {knobPosition = mix1;}
        else if (mixValue >= 0.5f) {knobPosition = mix0x5;}
        else if (mixValue >= 0.f) {knobPosition = mix0;}
        else {knobPosition = mix100;}
        
        repaint();
    }
    if(slider == &smoothKnob) {
        float smoothValue = slider->getValue();
        
        if(smoothValue == 500) {smoothKnobPosition = mix100;}
        // Knob images 90 - 99.5
        else if (smoothValue >= 497.5f) {smoothKnobPosition = mix99x5;}
        else if (smoothValue >= 495.f)  {smoothKnobPosition = mix99;}
        else if (smoothValue >= 492.5f) {smoothKnobPosition = mix98x5;}
        else if (smoothValue >= 490.f)  {smoothKnobPosition = mix98;}
        else if (smoothValue >= 487.5f) {smoothKnobPosition = mix97x5;}
        else if (smoothValue >= 485.f)  {smoothKnobPosition = mix97;}
        else if (smoothValue >= 482.5f) {smoothKnobPosition = mix96x5;}
        else if (smoothValue >= 480.f)  {smoothKnobPosition = mix96;}
        else if (smoothValue >= 477.5f) {smoothKnobPosition = mix95x5;}
        else if (smoothValue >= 475.f)  {smoothKnobPosition = mix95;}
        else if (smoothValue >= 472.5f) {smoothKnobPosition = mix94x5;}
        else if (smoothValue >= 470.f)  {smoothKnobPosition = mix94;}
        else if (smoothValue >= 467.5f) {smoothKnobPosition = mix93x5;}
        else if (smoothValue >= 465.f)  {smoothKnobPosition = mix93;}
        else if (smoothValue >= 462.5f) {smoothKnobPosition = mix92x5;}
        else if (smoothValue >= 460.f)  {smoothKnobPosition = mix92;}
        else if (smoothValue >= 457.5f) {smoothKnobPosition = mix91x5;}
        else if (smoothValue >= 455.f)  {smoothKnobPosition = mix91;}
        else if (smoothValue >= 452.5f) {smoothKnobPosition = mix90x5;}
        else if (smoothValue >= 450.f)  {smoothKnobPosition = mix90;}
        // Knob images 80 - 89.5
        else if (smoothValue >= 447.5f) {smoothKnobPosition = mix89x5;}
        else if (smoothValue >= 445.f)  {smoothKnobPosition = mix89;}
        else if (smoothValue >= 442.5f) {smoothKnobPosition = mix88x5;}
        else if (smoothValue >= 440.f)  {smoothKnobPosition = mix88;}
        else if (smoothValue >= 437.5f) {smoothKnobPosition = mix87x5;}
        else if (smoothValue >= 435.f)  {smoothKnobPosition = mix87;}
        else if (smoothValue >= 432.5f) {smoothKnobPosition = mix86x5;}
        else if (smoothValue >= 430.f)  {smoothKnobPosition = mix86;}
        else if (smoothValue >= 427.5f) {smoothKnobPosition = mix85x5;}
        else if (smoothValue >= 425.f)  {smoothKnobPosition = mix85;}
        else if (smoothValue >= 422.5f) {smoothKnobPosition = mix84x5;}
        else if (smoothValue >= 420.f)  {smoothKnobPosition = mix84;}
        else if (smoothValue >= 417.5f) {smoothKnobPosition = mix83x5;}
        else if (smoothValue >= 415.f)  {smoothKnobPosition = mix83;}
        else if (smoothValue >= 412.5f) {smoothKnobPosition = mix82x5;}
        else if (smoothValue >= 410.f)  {smoothKnobPosition = mix82;}
        else if (smoothValue >= 407.5f) {smoothKnobPosition = mix81x5;}
        else if (smoothValue >= 405.f)  {smoothKnobPosition = mix81;}
        else if (smoothValue >= 402.5f) {smoothKnobPosition = mix80x5;}
        else if (smoothValue >= 400.f)  {smoothKnobPosition = mix80;}
        // Knob images 90 - 99.5
        else if (smoothValue >= 397.5f) {smoothKnobPosition = mix79x5;}
        else if (smoothValue >= 395.f)  {smoothKnobPosition = mix79;}
        else if (smoothValue >= 392.5f) {smoothKnobPosition = mix78x5;}
        else if (smoothValue >= 390.f)  {smoothKnobPosition = mix78;}
        else if (smoothValue >= 387.5f) {smoothKnobPosition = mix77x5;}
        else if (smoothValue >= 385.f)  {smoothKnobPosition = mix77;}
        else if (smoothValue >= 382.5f) {smoothKnobPosition = mix76x5;}
        else if (smoothValue >= 380.f)  {smoothKnobPosition = mix76;}
        else if (smoothValue >= 377.5f) {smoothKnobPosition = mix75x5;}
        else if (smoothValue >= 375.f)  {smoothKnobPosition = mix75;}
        else if (smoothValue >= 372.5f) {smoothKnobPosition = mix74x5;}
        else if (smoothValue >= 370.f)  {smoothKnobPosition = mix74;}
        else if (smoothValue >= 367.5f) {smoothKnobPosition = mix73x5;}
        else if (smoothValue >= 365.f)  {smoothKnobPosition = mix73;}
        else if (smoothValue >= 362.5f) {smoothKnobPosition = mix72x5;}
        else if (smoothValue >= 360.f)  {smoothKnobPosition = mix72;}
        else if (smoothValue >= 357.5f) {smoothKnobPosition = mix71x5;}
        else if (smoothValue >= 355.f)  {smoothKnobPosition = mix71;}
        else if (smoothValue >= 352.5f) {smoothKnobPosition = mix70x5;}
        else if (smoothValue >= 350.f)  {smoothKnobPosition = mix70;}
        // Knob images 80 - 89.5
        else if (smoothValue >= 347.5f) {smoothKnobPosition = mix69x5;}
        else if (smoothValue >= 345.f)  {smoothKnobPosition = mix69;}
        else if (smoothValue >= 342.5f) {smoothKnobPosition = mix68x5;}
        else if (smoothValue >= 340.f)  {smoothKnobPosition = mix68;}
        else if (smoothValue >= 337.5f) {smoothKnobPosition = mix67x5;}
        else if (smoothValue >= 335.f)  {smoothKnobPosition = mix67;}
        else if (smoothValue >= 332.5f) {smoothKnobPosition = mix66x5;}
        else if (smoothValue >= 330.f)  {smoothKnobPosition = mix66;}
        else if (smoothValue >= 327.5f) {smoothKnobPosition = mix65x5;}
        else if (smoothValue >= 325.f)  {smoothKnobPosition = mix65;}
        else if (smoothValue >= 322.5f) {smoothKnobPosition = mix64x5;}
        else if (smoothValue >= 320.f)  {smoothKnobPosition = mix64;}
        else if (smoothValue >= 317.5f) {smoothKnobPosition = mix63x5;}
        else if (smoothValue >= 315.f)  {smoothKnobPosition = mix63;}
        else if (smoothValue >= 312.5f) {smoothKnobPosition = mix62x5;}
        else if (smoothValue >= 310.f)  {smoothKnobPosition = mix62;}
        else if (smoothValue >= 307.5f) {smoothKnobPosition = mix61x5;}
        else if (smoothValue >= 305.f)  {smoothKnobPosition = mix61;}
        else if (smoothValue >= 302.5f) {smoothKnobPosition = mix60x5;}
        else if (smoothValue >= 300.f)  {smoothKnobPosition = mix60;}
        // Knob images 90 - 99.5
        else if (smoothValue >= 297.5f) {smoothKnobPosition = mix59x5;}
        else if (smoothValue >= 295.f)  {smoothKnobPosition = mix59;}
        else if (smoothValue >= 292.5f) {smoothKnobPosition = mix58x5;}
        else if (smoothValue >= 290.f)  {smoothKnobPosition = mix58;}
        else if (smoothValue >= 287.5f) {smoothKnobPosition = mix57x5;}
        else if (smoothValue >= 285.f)  {smoothKnobPosition = mix57;}
        else if (smoothValue >= 282.5f) {smoothKnobPosition = mix56x5;}
        else if (smoothValue >= 280.f)  {smoothKnobPosition = mix56;}
        else if (smoothValue >= 277.5f) {smoothKnobPosition = mix55x5;}
        else if (smoothValue >= 275.f)  {smoothKnobPosition = mix55;}
        else if (smoothValue >= 272.5f) {smoothKnobPosition = mix54x5;}
        else if (smoothValue >= 270.f)  {smoothKnobPosition = mix54;}
        else if (smoothValue >= 267.5f) {smoothKnobPosition = mix53x5;}
        else if (smoothValue >= 265.f)  {smoothKnobPosition = mix53;}
        else if (smoothValue >= 262.5f) {smoothKnobPosition = mix52x5;}
        else if (smoothValue >= 260.f)  {smoothKnobPosition = mix52;}
        else if (smoothValue >= 257.5f) {smoothKnobPosition = mix51x5;}
        else if (smoothValue >= 255.f)  {smoothKnobPosition = mix51;}
        else if (smoothValue >= 252.5f) {smoothKnobPosition = mix50x5;}
        else if (smoothValue >= 250.f)  {smoothKnobPosition = mix50;}
        // Knob images 80 - 89.5
        else if (smoothValue >= 247.5f) {smoothKnobPosition = mix49x5;}
        else if (smoothValue >= 245.f)  {smoothKnobPosition = mix49;}
        else if (smoothValue >= 242.5f) {smoothKnobPosition = mix48x5;}
        else if (smoothValue >= 240.f)  {smoothKnobPosition = mix48;}
        else if (smoothValue >= 237.5f) {smoothKnobPosition = mix47x5;}
        else if (smoothValue >= 235.f)  {smoothKnobPosition = mix47;}
        else if (smoothValue >= 232.5f) {smoothKnobPosition = mix46x5;}
        else if (smoothValue >= 230.f)  {smoothKnobPosition = mix46;}
        else if (smoothValue >= 227.5f) {smoothKnobPosition = mix45x5;}
        else if (smoothValue >= 225.f)  {smoothKnobPosition = mix45;}
        else if (smoothValue >= 222.5f) {smoothKnobPosition = mix44x5;}
        else if (smoothValue >= 220.f)  {smoothKnobPosition = mix44;}
        else if (smoothValue >= 217.5f) {smoothKnobPosition = mix43x5;}
        else if (smoothValue >= 215.f)  {smoothKnobPosition = mix43;}
        else if (smoothValue >= 212.5f) {smoothKnobPosition = mix42x5;}
        else if (smoothValue >= 210.f)  {smoothKnobPosition = mix42;}
        else if (smoothValue >= 207.5f) {smoothKnobPosition = mix41x5;}
        else if (smoothValue >= 205.f)  {smoothKnobPosition = mix41;}
        else if (smoothValue >= 202.5f) {smoothKnobPosition = mix40x5;}
        else if (smoothValue >= 200.f)  {smoothKnobPosition = mix40;}
        // Knob images 90 - 99.5
        else if (smoothValue >= 197.5f) {smoothKnobPosition = mix39x5;}
        else if (smoothValue >= 195.f)  {smoothKnobPosition = mix39;}
        else if (smoothValue >= 192.5f) {smoothKnobPosition = mix38x5;}
        else if (smoothValue >= 190.f)  {smoothKnobPosition = mix38;}
        else if (smoothValue >= 187.5f) {smoothKnobPosition = mix37x5;}
        else if (smoothValue >= 185.f)  {smoothKnobPosition = mix37;}
        else if (smoothValue >= 182.5f) {smoothKnobPosition = mix36x5;}
        else if (smoothValue >= 180.f)  {smoothKnobPosition = mix36;}
        else if (smoothValue >= 177.5f) {smoothKnobPosition = mix35x5;}
        else if (smoothValue >= 175.f)  {smoothKnobPosition = mix35;}
        else if (smoothValue >= 172.5f) {smoothKnobPosition = mix34x5;}
        else if (smoothValue >= 170.f)  {smoothKnobPosition = mix34;}
        else if (smoothValue >= 167.5f) {smoothKnobPosition = mix33x5;}
        else if (smoothValue >= 165.f)  {smoothKnobPosition = mix33;}
        else if (smoothValue >= 162.5f) {smoothKnobPosition = mix32x5;}
        else if (smoothValue >= 160.f)  {smoothKnobPosition = mix32;}
        else if (smoothValue >= 157.5f) {smoothKnobPosition = mix31x5;}
        else if (smoothValue >= 155.f)  {smoothKnobPosition = mix31;}
        else if (smoothValue >= 152.5f) {smoothKnobPosition = mix30x5;}
        else if (smoothValue >= 150.f)  {smoothKnobPosition = mix30;}
        // Knob images 80 - 89.5
        else if (smoothValue >= 147.5f) {smoothKnobPosition = mix29x5;}
        else if (smoothValue >= 145.f)  {smoothKnobPosition = mix29;}
        else if (smoothValue >= 142.5f) {smoothKnobPosition = mix28x5;}
        else if (smoothValue >= 140.f)  {smoothKnobPosition = mix28;}
        else if (smoothValue >= 137.5f) {smoothKnobPosition = mix27x5;}
        else if (smoothValue >= 135.f)  {smoothKnobPosition = mix27;}
        else if (smoothValue >= 132.5f) {smoothKnobPosition = mix26x5;}
        else if (smoothValue >= 130.f)  {smoothKnobPosition = mix26;}
        else if (smoothValue >= 127.5f) {smoothKnobPosition = mix25x5;}
        else if (smoothValue >= 125.f)  {smoothKnobPosition = mix25;}
        else if (smoothValue >= 122.5f) {smoothKnobPosition = mix24x5;}
        else if (smoothValue >= 120.f)  {smoothKnobPosition = mix24;}
        else if (smoothValue >= 117.5f) {smoothKnobPosition = mix23x5;}
        else if (smoothValue >= 115.f)  {smoothKnobPosition = mix23;}
        else if (smoothValue >= 112.5f) {smoothKnobPosition = mix22x5;}
        else if (smoothValue >= 110.f)  {smoothKnobPosition = mix22;}
        else if (smoothValue >= 107.5f) {smoothKnobPosition = mix21x5;}
        else if (smoothValue >= 105.f)  {smoothKnobPosition = mix21;}
        else if (smoothValue >= 102.5f) {smoothKnobPosition = mix20x5;}
        else if (smoothValue >= 100.f)  {smoothKnobPosition = mix20;}
        // Knob images 90 - 99.5
        else if (smoothValue >= 97.5f) {smoothKnobPosition = mix19x5;}
        else if (smoothValue >= 95.f)  {smoothKnobPosition = mix19;}
        else if (smoothValue >= 92.5f) {smoothKnobPosition = mix18x5;}
        else if (smoothValue >= 90.f)  {smoothKnobPosition = mix18;}
        else if (smoothValue >= 87.5f) {smoothKnobPosition = mix17x5;}
        else if (smoothValue >= 85.f)  {smoothKnobPosition = mix17;}
        else if (smoothValue >= 82.5f) {smoothKnobPosition = mix16x5;}
        else if (smoothValue >= 80.f)  {smoothKnobPosition = mix16;}
        else if (smoothValue >= 77.5f) {smoothKnobPosition = mix15x5;}
        else if (smoothValue >= 75.f)  {smoothKnobPosition = mix15;}
        else if (smoothValue >= 72.5f) {smoothKnobPosition = mix14x5;}
        else if (smoothValue >= 70.f)  {smoothKnobPosition = mix14;}
        else if (smoothValue >= 67.5f) {smoothKnobPosition = mix13x5;}
        else if (smoothValue >= 65.f)  {smoothKnobPosition = mix13;}
        else if (smoothValue >= 62.5f) {smoothKnobPosition = mix12x5;}
        else if (smoothValue >= 60.f)  {smoothKnobPosition = mix12;}
        else if (smoothValue >= 57.5f) {smoothKnobPosition = mix11x5;}
        else if (smoothValue >= 55.f)  {smoothKnobPosition = mix11;}
        else if (smoothValue >= 52.5f) {smoothKnobPosition = mix10x5;}
        else if (smoothValue >= 50.f)  {smoothKnobPosition = mix10;}
        // Knob images 80 - 89.5
        else if (smoothValue >= 47.5f) {smoothKnobPosition = mix9x5;}
        else if (smoothValue >= 45.f)  {smoothKnobPosition = mix9;}
        else if (smoothValue >= 42.5f) {smoothKnobPosition = mix8x5;}
        else if (smoothValue >= 40.f)  {smoothKnobPosition = mix8;}
        else if (smoothValue >= 37.5f) {smoothKnobPosition = mix7x5;}
        else if (smoothValue >= 35.f)  {smoothKnobPosition = mix7;}
        else if (smoothValue >= 32.5f) {smoothKnobPosition = mix6x5;}
        else if (smoothValue >= 30.f)  {smoothKnobPosition = mix6;}
        else if (smoothValue >= 27.5f) {smoothKnobPosition = mix5x5;}
        else if (smoothValue >= 25.f)  {smoothKnobPosition = mix5;}
        else if (smoothValue >= 22.5f) {smoothKnobPosition = mix4x5;}
        else if (smoothValue >= 20.f)  {smoothKnobPosition = mix4;}
        else if (smoothValue >= 17.5f) {smoothKnobPosition = mix3x5;}
        else if (smoothValue >= 15.f)  {smoothKnobPosition = mix3;}
        else if (smoothValue >= 12.5f) {smoothKnobPosition = mix2x5;}
        else if (smoothValue >= 10.f)  {smoothKnobPosition = mix2;}
        else if (smoothValue >= 7.5f)  {smoothKnobPosition = mix1x5;}
        else if (smoothValue >= 5.f)   {smoothKnobPosition = mix1;}
        else if (smoothValue >= 2.5f)  {smoothKnobPosition = mix0x5;}
        else if (smoothValue >= 0.f)   {smoothKnobPosition = mix0;}
        
        else {smoothKnobPosition = mix0;}
        
        repaint();
    }
}

