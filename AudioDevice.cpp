//
//  AudioDevice.cpp
//  Version3
//
//  Created by Asmaa on 20/04/2016.
//  Copyright © 2016 Asmaa. All rights reserved.
//

#include "AudioDevice.hpp"

AudioDevice::AudioDevice(AudioDeviceID id, bool isInput) {
    aID = id;
    aIsInput = isInput;
    if (pID == kAudioDeviceUnknown) return;
    UInt32 size = sizeof(Float32);
    //recueille les trois parties qui identifient une propriété spécifique
    AudioObjectPropertyAddress addr = { kAudioDevicePropertySafetyOffset, (isInput ? kAudioDevicePropertyScopeInput : kAudioDevicePropertyScopeOutput), 0 };
    AudioObjectGetPropertyData(aID, &addr, 0, NULL, &size, &aSafetyOffset);
    size = sizeof(UInt32);
    addr.mSelector = kAudioDevicePropertyBufferFrameSize;
    AudioObjectGetPropertyData(aID, &addr, 0, NULL, &size, &aBufferSizeFrames);
    size = sizeof(AudioStreamBasicDescription);
    addr.mSelector = kAudioDevicePropertyStreamFormat;
    AudioObjectGetPropertyData(aID, &addr, 0, NULL, &size, &aFormat);
}

OSStatus AudioDevice::ReloadStreamFormat() {
    OSStatus err = noErr;
    UInt32 size = sizeof(aFormat);
    AudioObjectPropertyAddress addr = { kAudioDevicePropertyStreamFormat, (aIsInput ? kAudioDevicePropertyScopeInput : kAudioDevicePropertyScopeOutput), 0 };
    err = AudioObjectGetPropertyData(aID, &addr, 0, NULL, &size, &aFormat);
    return err;
}

OSStatus AudioDevice::SetSampleRate(Float64 sr) {
    OSStatus err = noErr;
    aFormat.mSampleRate = sr;
    UInt32 size = sizeof(aFormat);
    AudioObjectPropertyAddress addr = { kAudioDevicePropertyStreamFormat, (aIsInput ? kAudioDevicePropertyScopeInput : kAudioDevicePropertyScopeOutput), 0 };
    err = AudioObjectSetPropertyData(aID, &addr, 0, NULL, size, &aFormat);
    if(aFormat.mSampleRate != sr) printf("Error in AudioDevice::SetSampleRate - sample rate mismatch!");
    return err;
}

OSStatus AudioDevice::SetBufferSize(UInt32 buffersize) {
    OSStatus err = noErr;
    UInt32 size = sizeof(UInt32);
    AudioObjectPropertyAddress addr = { kAudioDevicePropertyBufferFrameSize, (aIsInput ? kAudioDevicePropertyScopeInput : kAudioDevicePropertyScopeOutput), 0 };
    err = AudioObjectSetPropertyData(aID, &addr, 0, NULL, size, &buffersize);
    AudioObjectGetPropertyData(aID, &addr, 0, NULL, &size, &aBufferSizeFrames);
    if(aBufferSizeFrames != buffersize) printf("buffer size mismatch!");
    return err;
}

UInt32 AudioDevice::getStreamPhysicalBitDepth(bool isInput) {
    AudioStreamBasicDescription asbd;
    UInt32 size = sizeof(asbd);
    AudioObjectPropertyAddress addr = { kAudioStreamPropertyPhysicalFormat, (isInput ? kAudioDevicePropertyScopeInput : kAudioDevicePropertyScopeOutput), kAudioObjectPropertyElementMaster };
    AudioObjectGetPropertyData(aID, &addr, 0, NULL, &size, &asbd);
    return asbd.mBitsPerChannel;
}
