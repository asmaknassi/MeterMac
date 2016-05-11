

#import <Cocoa/Cocoa.h>
#import <AudioUnit/AudioUnit.h>
#import <AudioToolbox/AudioToolbox.h>

@class QTCaptureSession;
@class QTCaptureDeviceInput;
@class QTCaptureDecompressedAudioOutput;

@interface CaptureSessionController : NSObject <NSWindowDelegate> {
	IBOutlet NSWindow			*window;
	
@private
	QTCaptureSession			*captureSession;
	QTCaptureDeviceInput		*captureAudioDeviceInput;
	QTCaptureDecompressedAudioOutput	*captureAudioDataOutput;
	
	AudioUnit					effectAudioUnit;
    ExtAudioFileRef             extAudioFile;
	
    AudioStreamBasicDescription currentInputASBD;
	AudioBufferList				*currentInputAudioBufferList;
	
	double						currentSampleTime;
	BOOL						didSetUpAudioUnits;
	
	NSString					*outputFile;
	BOOL						recording;
}

@property(copy)					NSString	*outputFile;
@property(getter=isRecording)	BOOL		recording;

- (IBAction)chooseOutputFile:(id)sender;

@end
