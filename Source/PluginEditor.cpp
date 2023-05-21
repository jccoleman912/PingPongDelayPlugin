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
    
    g.drawImage(knobPosition, 32, 465, 50, 50, 0, 0, 1000, 1000);
    

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

