//
//  AudioDevice.hpp
//  Version3
//
//  Created by Asmaa on 20/04/2016.
//  Copyright © 2016 Asmaa. All rights reserved.
//

#ifndef AudioDevice_hpp
#define AudioDevice_hpp
#include <stdio.h>
#include <CoreServices/CoreServices.h>
#include <CoreAudio/CoreAudio.h>

// AudioDevice is the base class for all objects that represent an audio device.
// AudioDevice is a subclass of AudioObject

class AudioDevice {
    
public:
    AudioDevice(AudioDeviceID dev, bool isInput);
    OSStatus SetBufferSize(UInt32 size);
    OSStatus SetSampleRate(Float64 sr);
    OSStatus ReloadStreamFormat();
    char *GetName(char *buf, UInt32 maxlen);
    UInt32 getStreamPhysicalBitDepth(bool isInput);
    AudioDeviceID aID;
    bool aIsInput;
    UInt32 aSafetyOffset;
    UInt32 aBufferSizeFrames;
    //spécification de format de données audio
    //pour spécifier un format PCM linéaire 
    AudioStreamBasicDescription aFormat;
};


#endif /* AudioDevice_hpp */
