﻿// ConsoleApplication2.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include "MediaAdapter.h"

int main() {
    // VLCファイルを再生するためのMediaAdapterのインスタンスを作成
    MediaAdapter* vlcPlayer = new MediaAdapter("vlc");
    std::cout << "Playing VLC file:" << std::endl;
    vlcPlayer->play("vlc", "example.vlc");

    // MP4ファイルを再生するためのMediaAdapterのインスタンスを作成
    MediaAdapter* mp4Player = new MediaAdapter("mp4");
    std::cout << "Playing MP4 file:" << std::endl;
    mp4Player->play("mp4", "video.mp4");

    // オブジェクトのメモリを解放
    delete vlcPlayer;
    delete mp4Player;

    return 0;
}


// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
