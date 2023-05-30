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

    setSize (800, 640);
    

    
    bgImage = juce::ImageCache::getFromMemory(BinaryData::PingPongDelayUI_jpg, BinaryData::PingPongDelayUI_jpgSize);
    
    bgImage = bgImage.rescaled(800, 640, juce::Graphics::highResamplingQuality);
    
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
    
    
    //
    // Initial Gain Knob
    //
    
    initialGainKnob.addListener(this);
    // Specify location in window (xPos,yPos,width,height)
    initialGainKnob.setBounds(250,25,100,100);
    initialGainKnob.setRange(-60.f,24.f,0.1f); // (min, max, interval)
    initialGainKnob.setValue(-9.f); // initial value
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
    l2RGainKnob.setBounds(145,170,100,100);
    l2RGainKnob.setRange(-60.f,24.f,0.1f); // (min, max, interval)
    l2RGainKnob.setValue(0.f); // initial value
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
    r2LGainKnob.setRange(-60.f,24.f,0.1f); // (min, max, interval)
    r2LGainKnob.setValue(-6.f); // initial value
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
    mixKnob.setAlpha(0.f);
    
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

    g.drawImage(knobPosition, 680, 190, 100, 100, 0, 0, 1000, 1000);

    
//    emptyInitialDrawable.setImage(emptyInitial);
//
//    emptyInitialDrawable.drawAt(g, 300, 20, emptyBaseOpacity);
    
    baseInitialDropDrawable.setImage(baseInitialDrop);
    baseInitialDropDrawable.drawAt(g, 240, 32, emptyBaseOpacity);
    
    redInitialDropDrawable.setImage(redInitialDrop);
    redInitialDropDrawable.drawAt(g, 240, 32, redInitialOpacity);
    
    
    baseL2RDropADrawable.setImage(baseL2RDrop);
    baseL2RDropADrawable.drawAt(g, 240, 112, emptyBaseOpacity);
    
    redL2RDropADrawable.setImage(redL2RDrop);
    redL2RDropADrawable.drawAt(g, 240, 112, redInitialOpacity);
    
    
    baseR2LDropADrawable.setImage(baseR2LDrop);
    baseR2LDropADrawable.drawAt(g, 240, 256, emptyBaseOpacity);
    
    redR2LDropADrawable.setImage(redR2LDrop);
    redR2LDropADrawable.drawAt(g, 240, 256, redInitialOpacity);
    
    
    baseL2RDropBDrawable.setImage(baseL2RDrop);
    baseL2RDropBDrawable.drawAt(g, 240, 400, emptyBaseOpacity);
    
    redL2RDropBDrawable.setImage(redL2RDrop);
    redL2RDropBDrawable.drawAt(g, 240, 400, redInitialOpacity);
    
    
    baseR2LDropFinalDrawable.setImage(baseR2LFinalDrop);
    baseR2LDropFinalDrawable.drawAt(g, 240, 544, emptyBaseOpacity);
    
    redR2LDropFinalDrawable.setImage(redR2LFinalDrop);
    redR2LDropFinalDrawable.drawAt(g, 240, 544, redInitialOpacity);
    

    leftPingPongA.setImage(leftPingPong);
    rightPingPongA.setImage(rightPingPong);
    leftPingPongB.setImage(leftPingPong);
    rightPingPongB.setImage(rightPingPong);
    
    leftPingPongRedA.setImage(leftPingPongRed);
    rightPingPongRedA.setImage(rightPingPongRed);
    leftPingPongRedB.setImage(leftPingPongRed);
    rightPingPongRedB.setImage(rightPingPongRed);
    
    leftPingPongA.drawAt(g, 192, 80, emptyBaseOpacity);
    rightPingPongA.drawAt(g, 544, 224, 1.f);
    leftPingPongB.drawAt(g, 192, 368, 1.f);
    rightPingPongB.drawAt(g, 544, 512, 1.f);
    
    leftPingPongRedA.drawAt(g, 192, 80, redInitialOpacity);
    rightPingPongRedA.drawAt(g, 544, 224, 1.f);
    leftPingPongRedB.drawAt(g, 192, 368, 0.5f);
    rightPingPongRedB.drawAt(g, 544, 512, 0.f);
    
    

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
        } else {
            syncOutcome = syncOFFImage;
        }
        repaint(16, 144, 128, 64);
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
        } else {
            smoothOutcome = smoothOFFImage;
        }
        repaint(656, 368, 128, 64);
    }
}

void Coleman_HW2AudioProcessorEditor::sliderValueChanged(juce::Slider * slider)
{
    // This is how we check which slider was moved
    if (slider == &initialGainKnob){
        
        float initialValue = slider->getValue();
        
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
        
        
        if(initialValue == 0.f) {emptyBaseOpacity = baseOpacity[200];}
        else if(initialValue > -0.2f) {emptyBaseOpacity = baseOpacity[199];}
        else if(initialValue > -0.4f) {emptyBaseOpacity = baseOpacity[198];}
        else if(initialValue > -0.6f) {emptyBaseOpacity = baseOpacity[197];}
        else if(initialValue > -0.8f) {emptyBaseOpacity = baseOpacity[196];}
        else if(initialValue > -1.f)  {emptyBaseOpacity = baseOpacity[195];}
        else if(initialValue > -1.2f) {emptyBaseOpacity = baseOpacity[194];}
        else if(initialValue > -1.4f) {emptyBaseOpacity = baseOpacity[193];}
        else if(initialValue > -1.6f) {emptyBaseOpacity = baseOpacity[192];}
        else if(initialValue > -1.8f) {emptyBaseOpacity = baseOpacity[191];}
        else if(initialValue > -2.f)  {emptyBaseOpacity = baseOpacity[190];}
        else if(initialValue > -2.2f) {emptyBaseOpacity = baseOpacity[189];}
        else if(initialValue > -2.4f) {emptyBaseOpacity = baseOpacity[188];}
        else if(initialValue > -2.6f) {emptyBaseOpacity = baseOpacity[187];}
        else if(initialValue > -2.8f) {emptyBaseOpacity = baseOpacity[186];}
        else if(initialValue > -3.f)  {emptyBaseOpacity = baseOpacity[185];}
        else if(initialValue > -3.2f) {emptyBaseOpacity = baseOpacity[184];}
        else if(initialValue > -3.4f) {emptyBaseOpacity = baseOpacity[183];}
        else if(initialValue > -3.6f) {emptyBaseOpacity = baseOpacity[182];}
        else if(initialValue > -3.8f) {emptyBaseOpacity = baseOpacity[181];}
        else if(initialValue > -4.f)  {emptyBaseOpacity = baseOpacity[180];}
        else if(initialValue > -4.2f) {emptyBaseOpacity = baseOpacity[179];}
        else if(initialValue > -4.4f) {emptyBaseOpacity = baseOpacity[178];}
        else if(initialValue > -4.6f) {emptyBaseOpacity = baseOpacity[177];}
        else if(initialValue > -4.8f) {emptyBaseOpacity = baseOpacity[176];}
        else if(initialValue > -5.f)  {emptyBaseOpacity = baseOpacity[175];}
        else if(initialValue > -5.2f) {emptyBaseOpacity = baseOpacity[174];}
        else if(initialValue > -5.4f) {emptyBaseOpacity = baseOpacity[173];}
        else if(initialValue > -5.6f) {emptyBaseOpacity = baseOpacity[172];}
        else if(initialValue > -5.8f) {emptyBaseOpacity = baseOpacity[171];}
        else if(initialValue > -6.f)  {emptyBaseOpacity = baseOpacity[170];}

        // 6 dB <= Red values < 12 dB
        else if(initialValue > -6.2f) {emptyBaseOpacity = baseOpacity[169];}
        else if(initialValue > -6.4f) {emptyBaseOpacity = baseOpacity[168];}
        else if(initialValue > -6.6f) {emptyBaseOpacity = baseOpacity[167];}
        else if(initialValue > -6.8f) {emptyBaseOpacity = baseOpacity[166];}
        else if(initialValue > -7.f)  {emptyBaseOpacity = baseOpacity[165];}
        else if(initialValue > -7.2f) {emptyBaseOpacity = baseOpacity[164];}
        else if(initialValue > -7.4f) {emptyBaseOpacity = baseOpacity[163];}
        else if(initialValue > -7.6f) {emptyBaseOpacity = baseOpacity[162];}
        else if(initialValue > -7.8f) {emptyBaseOpacity = baseOpacity[161];}
        else if(initialValue > -8.f)  {emptyBaseOpacity = baseOpacity[160];}
        else if(initialValue > -8.2f) {emptyBaseOpacity = baseOpacity[159];}
        else if(initialValue > -8.4f) {emptyBaseOpacity = baseOpacity[158];}
        else if(initialValue > -8.6f) {emptyBaseOpacity = baseOpacity[157];}
        else if(initialValue > -8.8f) {emptyBaseOpacity = baseOpacity[156];}
        else if(initialValue > -9.f)  {emptyBaseOpacity = baseOpacity[155];}
        else if(initialValue > -9.2f) {emptyBaseOpacity = baseOpacity[154];}
        else if(initialValue > -9.4f) {emptyBaseOpacity = baseOpacity[153];}
        else if(initialValue > -9.6f) {emptyBaseOpacity = baseOpacity[152];}
        else if(initialValue > -9.8f) {emptyBaseOpacity = baseOpacity[151];}
        else if(initialValue > -10.f) {emptyBaseOpacity = baseOpacity[150];}
        else if(initialValue > -10.2f) {emptyBaseOpacity = baseOpacity[149];}
        else if(initialValue > -10.4f) {emptyBaseOpacity = baseOpacity[148];}
        else if(initialValue > -10.6f) {emptyBaseOpacity = baseOpacity[147];}
        else if(initialValue > -10.8f) {emptyBaseOpacity = baseOpacity[146];}
        else if(initialValue > -11.f)  {emptyBaseOpacity = baseOpacity[145];}
        else if(initialValue > -11.2f) {emptyBaseOpacity = baseOpacity[144];}
        else if(initialValue > -11.4f) {emptyBaseOpacity = baseOpacity[143];}
        else if(initialValue > -11.6f) {emptyBaseOpacity = baseOpacity[142];}
        else if(initialValue > -11.8f) {emptyBaseOpacity = baseOpacity[141];}
        else if(initialValue > -12.f)  {emptyBaseOpacity = baseOpacity[140];}

        // 12 dB <= Red values < 18 dB
        else if(initialValue > -12.2f) {emptyBaseOpacity = baseOpacity[139];}
        else if(initialValue > -12.4f) {emptyBaseOpacity = baseOpacity[138];}
        else if(initialValue > -12.6f) {emptyBaseOpacity = baseOpacity[137];}
        else if(initialValue > -12.8f) {emptyBaseOpacity = baseOpacity[136];}
        else if(initialValue > -13.f)  {emptyBaseOpacity = baseOpacity[135];}
        else if(initialValue > -13.2f) {emptyBaseOpacity = baseOpacity[134];}
        else if(initialValue > -13.4f) {emptyBaseOpacity = baseOpacity[133];}
        else if(initialValue > -13.6f) {emptyBaseOpacity = baseOpacity[132];}
        else if(initialValue > -13.8f) {emptyBaseOpacity = baseOpacity[131];}
        else if(initialValue > -14.f)  {emptyBaseOpacity = baseOpacity[130];}
        else if(initialValue > -14.2f) {emptyBaseOpacity = baseOpacity[129];}
        else if(initialValue > -14.4f) {emptyBaseOpacity = baseOpacity[128];}
        else if(initialValue > -14.6f) {emptyBaseOpacity = baseOpacity[127];}
        else if(initialValue > -14.8f) {emptyBaseOpacity = baseOpacity[126];}
        else if(initialValue > -15.f)  {emptyBaseOpacity = baseOpacity[125];}
        else if(initialValue > -15.2f) {emptyBaseOpacity = baseOpacity[124];}
        else if(initialValue > -15.4f) {emptyBaseOpacity = baseOpacity[123];}
        else if(initialValue > -15.6f) {emptyBaseOpacity = baseOpacity[122];}
        else if(initialValue > -15.8f) {emptyBaseOpacity = baseOpacity[121];}
        else if(initialValue > -16.f)  {emptyBaseOpacity = baseOpacity[120];}
        else if(initialValue > -16.2f) {emptyBaseOpacity = baseOpacity[119];}
        else if(initialValue > -16.4f) {emptyBaseOpacity = baseOpacity[118];}
        else if(initialValue > -16.6f) {emptyBaseOpacity = baseOpacity[117];}
        else if(initialValue > -16.8f) {emptyBaseOpacity = baseOpacity[116];}
        else if(initialValue > -17.f)  {emptyBaseOpacity = baseOpacity[115];}
        else if(initialValue > -17.2f) {emptyBaseOpacity = baseOpacity[114];}
        else if(initialValue > -17.4f) {emptyBaseOpacity = baseOpacity[113];}
        else if(initialValue > -17.6f) {emptyBaseOpacity = baseOpacity[112];}
        else if(initialValue > -17.8f) {emptyBaseOpacity = baseOpacity[111];}
        else if(initialValue > -18.f)  {emptyBaseOpacity = baseOpacity[110];}

        // 18 dB <= Red values <= 24 dB
        else if(initialValue > -18.2f) {emptyBaseOpacity = baseOpacity[109];}
        else if(initialValue > -18.4f) {emptyBaseOpacity = baseOpacity[108];}
        else if(initialValue > -18.6f) {emptyBaseOpacity = baseOpacity[107];}
        else if(initialValue > -18.8f) {emptyBaseOpacity = baseOpacity[106];}
        else if(initialValue > -19.f)  {emptyBaseOpacity = baseOpacity[105];}
        else if(initialValue > -19.2f) {emptyBaseOpacity = baseOpacity[104];}
        else if(initialValue > -19.4f) {emptyBaseOpacity = baseOpacity[103];}
        else if(initialValue > -19.6f) {emptyBaseOpacity = baseOpacity[102];}
        else if(initialValue > -19.8f) {emptyBaseOpacity = baseOpacity[101];}
        else if(initialValue > -20.f)  {emptyBaseOpacity = baseOpacity[100];}
        else if(initialValue > -20.2f) {emptyBaseOpacity = baseOpacity[99];}
        else if(initialValue > -20.4f) {emptyBaseOpacity = baseOpacity[98];}
        else if(initialValue > -20.6f) {emptyBaseOpacity = baseOpacity[97];}
        else if(initialValue > -20.8f) {emptyBaseOpacity = baseOpacity[96];}
        else if(initialValue > -21.f)  {emptyBaseOpacity = baseOpacity[95];}
        else if(initialValue > -21.2f) {emptyBaseOpacity = baseOpacity[94];}
        else if(initialValue > -21.4f) {emptyBaseOpacity = baseOpacity[93];}
        else if(initialValue > -21.6f) {emptyBaseOpacity = baseOpacity[92];}
        else if(initialValue > -21.8f) {emptyBaseOpacity = baseOpacity[91];}
        else if(initialValue > -22.f)  {emptyBaseOpacity = baseOpacity[90];}
        else if(initialValue > -22.2f) {emptyBaseOpacity = baseOpacity[89];}
        else if(initialValue > -22.4f) {emptyBaseOpacity = baseOpacity[88];}
        else if(initialValue > -22.6f) {emptyBaseOpacity = baseOpacity[87];}
        else if(initialValue > -22.8f) {emptyBaseOpacity = baseOpacity[86];}
        else if(initialValue > -23.f)  {emptyBaseOpacity = baseOpacity[85];}
        else if(initialValue > -23.2f) {emptyBaseOpacity = baseOpacity[84];}
        else if(initialValue > -23.4f) {emptyBaseOpacity = baseOpacity[83];}
        else if(initialValue > -23.6f) {emptyBaseOpacity = baseOpacity[82];}
        else if(initialValue > -23.8f) {emptyBaseOpacity = baseOpacity[81];}
        else if(initialValue > -24.f)  {emptyBaseOpacity = baseOpacity[80];}

        // 18 dB <= Red values <= 24 dB
        else if(initialValue > -24.3f) {emptyBaseOpacity = baseOpacity[79];}
        else if(initialValue > -24.6f) {emptyBaseOpacity = baseOpacity[78];}
        else if(initialValue > -24.9f) {emptyBaseOpacity = baseOpacity[77];}
        else if(initialValue > -25.2f) {emptyBaseOpacity = baseOpacity[76];}
        else if(initialValue > -25.5f) {emptyBaseOpacity = baseOpacity[75];}
        else if(initialValue > -25.8f) {emptyBaseOpacity = baseOpacity[74];}
        else if(initialValue > -26.1f) {emptyBaseOpacity = baseOpacity[73];}
        else if(initialValue > -26.4f) {emptyBaseOpacity = baseOpacity[72];}
        else if(initialValue > -26.7f) {emptyBaseOpacity = baseOpacity[71];}
        else if(initialValue > -27.f)  {emptyBaseOpacity = baseOpacity[70];}
        else if(initialValue > -27.3f) {emptyBaseOpacity = baseOpacity[69];}
        else if(initialValue > -27.6f) {emptyBaseOpacity = baseOpacity[68];}
        else if(initialValue > -27.9f) {emptyBaseOpacity = baseOpacity[67];}
        else if(initialValue > -28.2f) {emptyBaseOpacity = baseOpacity[66];}
        else if(initialValue > -28.5f) {emptyBaseOpacity = baseOpacity[65];}
        else if(initialValue > -28.8f) {emptyBaseOpacity = baseOpacity[64];}
        else if(initialValue > -29.1f) {emptyBaseOpacity = baseOpacity[63];}
        else if(initialValue > -29.4f) {emptyBaseOpacity = baseOpacity[62];}
        else if(initialValue > -29.7f) {emptyBaseOpacity = baseOpacity[61];}
        else if(initialValue > -30.f)  {emptyBaseOpacity = baseOpacity[60];}
        
        else if(initialValue > -30.3f) {emptyBaseOpacity = baseOpacity[59];}
        else if(initialValue > -30.6f) {emptyBaseOpacity = baseOpacity[58];}
        else if(initialValue > -30.9f) {emptyBaseOpacity = baseOpacity[57];}
        else if(initialValue > -31.2f) {emptyBaseOpacity = baseOpacity[56];}
        else if(initialValue > -31.5f) {emptyBaseOpacity = baseOpacity[55];}
        else if(initialValue > -31.8f) {emptyBaseOpacity = baseOpacity[54];}
        else if(initialValue > -32.1f) {emptyBaseOpacity = baseOpacity[53];}
        else if(initialValue > -32.4f) {emptyBaseOpacity = baseOpacity[52];}
        else if(initialValue > -32.7f) {emptyBaseOpacity = baseOpacity[51];}
        else if(initialValue > -33.f)  {emptyBaseOpacity = baseOpacity[50];}
        else if(initialValue > -33.3f) {emptyBaseOpacity = baseOpacity[49];}
        else if(initialValue > -33.6f) {emptyBaseOpacity = baseOpacity[48];}
        else if(initialValue > -33.9f) {emptyBaseOpacity = baseOpacity[47];}
        else if(initialValue > -34.2f) {emptyBaseOpacity = baseOpacity[46];}
        else if(initialValue > -34.5f) {emptyBaseOpacity = baseOpacity[45];}
        else if(initialValue > -34.8f) {emptyBaseOpacity = baseOpacity[44];}
        else if(initialValue > -35.1f) {emptyBaseOpacity = baseOpacity[43];}
        else if(initialValue > -35.4f) {emptyBaseOpacity = baseOpacity[42];}
        else if(initialValue > -35.7f) {emptyBaseOpacity = baseOpacity[41];}
        else if(initialValue > -36.f)  {emptyBaseOpacity = baseOpacity[40];}
        
        
        else if(initialValue > -36.6f) {emptyBaseOpacity = baseOpacity[39];}
        else if(initialValue > -37.2f) {emptyBaseOpacity = baseOpacity[38];}
        else if(initialValue > -37.8f) {emptyBaseOpacity = baseOpacity[37];}
        else if(initialValue > -38.4f) {emptyBaseOpacity = baseOpacity[36];}
        else if(initialValue > -39.f)  {emptyBaseOpacity = baseOpacity[35];}
        else if(initialValue > -39.6f) {emptyBaseOpacity = baseOpacity[34];}
        else if(initialValue > -40.2f) {emptyBaseOpacity = baseOpacity[33];}
        else if(initialValue > -40.8f) {emptyBaseOpacity = baseOpacity[32];}
        else if(initialValue > -41.4f) {emptyBaseOpacity = baseOpacity[31];}
        else if(initialValue > -42.f)  {emptyBaseOpacity = baseOpacity[30];}
        
        else if(initialValue > -42.6f) {emptyBaseOpacity = baseOpacity[29];}
        else if(initialValue > -43.2f) {emptyBaseOpacity = baseOpacity[28];}
        else if(initialValue > -43.8f) {emptyBaseOpacity = baseOpacity[27];}
        else if(initialValue > -44.4f) {emptyBaseOpacity = baseOpacity[26];}
        else if(initialValue > -45.f)  {emptyBaseOpacity = baseOpacity[25];}
        else if(initialValue > -45.6f) {emptyBaseOpacity = baseOpacity[24];}
        else if(initialValue > -46.2f) {emptyBaseOpacity = baseOpacity[23];}
        else if(initialValue > -46.8f) {emptyBaseOpacity = baseOpacity[22];}
        else if(initialValue > -47.4f) {emptyBaseOpacity = baseOpacity[21];}
        else if(initialValue > -48.f)  {emptyBaseOpacity = baseOpacity[20];}
        
        else if(initialValue > -48.6f) {emptyBaseOpacity = baseOpacity[19];}
        else if(initialValue > -49.2f) {emptyBaseOpacity = baseOpacity[18];}
        else if(initialValue > -49.8f) {emptyBaseOpacity = baseOpacity[17];}
        else if(initialValue > -50.4f) {emptyBaseOpacity = baseOpacity[16];}
        else if(initialValue > -51.f)  {emptyBaseOpacity = baseOpacity[15];}
        else if(initialValue > -51.6f) {emptyBaseOpacity = baseOpacity[14];}
        else if(initialValue > -52.2f) {emptyBaseOpacity = baseOpacity[13];}
        else if(initialValue > -52.8f) {emptyBaseOpacity = baseOpacity[12];}
        else if(initialValue > -53.4f) {emptyBaseOpacity = baseOpacity[11];}
        else if(initialValue > -54.f)  {emptyBaseOpacity = baseOpacity[10];}
        
        else if(initialValue > -54.6f) {emptyBaseOpacity = baseOpacity[9];}
        else if(initialValue > -55.2f) {emptyBaseOpacity = baseOpacity[8];}
        else if(initialValue > -55.8f) {emptyBaseOpacity = baseOpacity[7];}
        else if(initialValue > -56.4f) {emptyBaseOpacity = baseOpacity[6];}
        else if(initialValue > -57.f)  {emptyBaseOpacity = baseOpacity[5];}
        else if(initialValue > -57.6f) {emptyBaseOpacity = baseOpacity[4];}
        else if(initialValue > -58.2f) {emptyBaseOpacity = baseOpacity[3];}
        else if(initialValue > -58.8f) {emptyBaseOpacity = baseOpacity[2];}
        else if(initialValue > -59.4f) {emptyBaseOpacity = baseOpacity[1];}
        else if(initialValue > -60.f)  {emptyBaseOpacity = baseOpacity[0];}
        else if(initialValue <= -60.f) {emptyBaseOpacity = baseOpacity[0];}
        else {emptyBaseOpacity = baseOpacity[0];}
        
        repaint();
            
    }
    if (slider == &l2RGainKnob){
        float l2RValue = slider -> getValue();
    }
    if (slider == &r2LGainKnob){
        float r2LValue = slider -> getValue();
    }
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
}

