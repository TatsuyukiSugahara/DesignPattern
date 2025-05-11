
#include <iostream>
using namespace std;

// 移動方法インターフェースを定義する
class MoveStrategy {
public:
    virtual void move() = 0;
    virtual ~MoveStrategy() {}
};

// 各移動方法クラスを作る
// → WalkMoveクラス, RunMoveクラス, TeleportMoveクラスを作る
// → それぞれ move() をオーバーライドして cout で動きを表示する

// モンスタークラスを作る
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
    // WalkMove、RunMove、TeleportMove のインスタンスを作成する
    // Monster を WalkMove で初期化する
    // Monster を move() させる
    // RunMove に切り替えて move() させる
    // TeleportMove に切り替えて move() させる

    return 0;
}
