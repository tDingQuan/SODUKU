#ifndef SOUND_H
#define SOUND_H

#include <QMediaPlayer>
#include <QMediaPlaylist>

class Sound
{
public:
    QMediaPlayer * player;  //定义播放器
    QMediaPlaylist * playlist;  //定义播放列表
    Sound();
    void play();  //播放函数
};

#endif // SOUND_H
