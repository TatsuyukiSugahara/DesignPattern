
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// オブザーバーインターフェース
class Observer {
public:
    virtual void update(int score) = 0;
};

// サブジェクト基底クラス
class Subject {
protected:
    vector<Observer*> observers;
public:
    void addObserver(Observer* obs) {
        observers.push_back(obs);
    }

    void removeObserver(Observer* obs) {
        observers.erase(remove(observers.begin(), observers.end(), obs), observers.end());
    }

    void notify(int score) {
        for (Observer* obs : observers) {
            obs->update(score);
        }
    }
};

// スコアマネージャー（Subject）
class ScoreManager : public Subject {
private:
    int score = 0;
public:
    void addPoints(int points) {
        score += points;
        cout << "[ScoreManager] スコアが " << score << " になりました！" << endl;
        notify(score);
    }

    int getScore() const { return score; }
};

// スコア表示UI（Observer）
class ScoreUI : public Observer {
public:
    void update(int score) override {
        cout << "[ScoreUI] スコア表示を更新：現在スコア = " << score << endl;
    }
};

// 実績システム（Observer）
class AchievementSystem : public Observer {
public:
    void update(int score) override {
        if (score >= 100) {
            cout << "[Achievement] 実績解除：スコア100超え！🎉" << endl;
        }
    }
};

int main() {
    ScoreManager manager;
    ScoreUI ui;
    AchievementSystem achievement;

    manager.addObserver(&ui);
    manager.addObserver(&achievement);

    manager.addPoints(30);
    manager.addPoints(50);
    manager.addPoints(25);

    return 0;
}
