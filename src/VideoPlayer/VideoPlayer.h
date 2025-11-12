#pragma once
#include <Arduino.h>
#include "JPEGDEC.h"

#include "VideoPlayerState.h"

class Display;

class VideoSource;

class VideoPlayer {
  private:
    int mChannelVisible = 0;
    VideoPlayerState mState = VideoPlayerState::STOPPED;

    // video playing
    Display &mDisplay;
    JPEGDEC mJpeg;

    // video source
    VideoSource *mVideoSource = NULL;

    static void _framePlayerTask(void *param);

    void framePlayerTask();

    friend int _doDraw(JPEGDRAW *pDraw);

  public:
    VideoPlayer(VideoSource *videoSource, Display &display);
    void setChannel(int channelIndex);
    void nextChannel();
    void start();
    void play();
    void stop();
    void pause();
    void playStatic();
};