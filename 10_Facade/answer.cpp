#include <iostream>
using namespace std;

// サブシステム
class SceneLoader {
public:
    void loadScene() { cout << "シーンをロード中..." << endl; }
};

class AudioManager {
public:
    void playMusic() { cout << "BGMを再生中..." << endl; }
    void stopMusic() { cout << "BGMを停止中..." << endl; }
};

class UIManager {
public:
    void showHUD() { cout << "HUD（UI）を表示中..." << endl; }
    void showPauseMenu() { cout << "ポーズメニューを表示中..." << endl; }
};

class InputManager {
public:
    void disableInput() { cout << "入力を無効化しました。" << endl; }
};

// Facade
class GameInitializer {
private:
    SceneLoader scene;
    AudioManager audio;
    UIManager ui;
    InputManager input;
public:
    void initializeGame() {
        scene.loadScene();
        audio.playMusic();
        ui.showHUD();
    }

    void pauseGame() {
        audio.stopMusic();
        input.disableInput();
        ui.showPauseMenu();
    }
};

int main() {
    GameInitializer game;

    cout << "-- ゲーム初期化 --" << endl;
    game.initializeGame();

    cout << "\n-- ポーズ機能 --" << endl;
    game.pauseGame();

    return 0;
}