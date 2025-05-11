
#include <iostream>
using namespace std;

// 移動方法インターフェースを定義する
class MoveStrategy {
public:
    virtual void move() = 0;
    virtual ~MoveStrategy() {}
};

// WalkMoveクラス
class WalkMove : public MoveStrategy {
public:
    void move() override {
        cout << "モンスターは歩いて移動している！" << endl;
    }
};

// RunMoveクラス
class RunMove : public MoveStrategy {
public:
    void move() override {
        cout << "モンスターは走って移動している！" << endl;
    }
};

// TeleportMoveクラス
class TeleportMove : public MoveStrategy {
public:
    void move() override {
        cout << "モンスターはテレポートした！" << endl;
    }
};

// モンスタークラス
class Monster {
private:
    MoveStrategy* strategy;
public:
    Monster(MoveStrategy* initialStrategy) : strategy(initialStrategy) {}

    void setStrategy(MoveStrategy* newStrategy) {
        strategy = newStrategy;
    }

    void move() {
        strategy->move();
    }
};

int main() {
    WalkMove walk;
    RunMove run;
    TeleportMove teleport;

    Monster monster(&walk);

    monster.move(); // 歩き
    monster.setStrategy(&run);
    monster.move(); // 走り
    monster.setStrategy(&teleport);
    monster.move(); // テレポート

    return 0;
}
