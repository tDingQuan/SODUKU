#include "sound.h"

Sound::Sound()
{

}

void Sound::play()
{
    playlist = new QMediaPlaylist;  //初始化播放列表
    playlist->addMedia(QUrl("qrc:/wav/sound/8842.wav"));
    playlist->addMedia(QUrl("qrc:/wav/sound/8885.wav"));
    playlist->addMedia(QUrl("qrc:/wav/sound/8886.wav"));  //添加音乐
    playlist->setCurrentIndex(1);  //设定开始播放曲目
    playlist->setPlaybackMode(QMediaPlaylist::Loop);  //设定播放模式为循环播放
    player = new QMediaPlayer;  //初始化播放器
    player->setPlaylist(playlist);  //设定播放器的播放列表
    player->play();  //播放
}
