#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// State インターフェース
class State {
public:
    virtual void handle() = 0;
    virtual ~State() {}
};

// 歩き状態
class WalkState : public State {
public:
    void handle() override {
        cout << "プレイヤーが歩いています。" << endl;
    }
};

// ジャンプ状態
class JumpState : public State {
public:
    void handle() override {
        cout << "プレイヤーがジャンプしています！" << endl;
    }
};

// 攻撃状態
class AttackState : public State {
public:
    void handle() override {
        cout << "プレイヤーが攻撃しています！" << endl;
    }
};

// プレイヤークラス（Context）
class Player {
private:
    State* state;
public:
    Player(State* initial) : state(initial) {}
    void setState(State* newState) {
        state = newState;
    }
    void update() {
        state->handle();
    }
};

int main() {
    srand(static_cast<unsigned int>(time(0)));

    WalkState walk;
    JumpState jump;
    AttackState attack;

    Player player(&walk);

    for (int i = 0; i < 5; ++i) {
        int r = rand() % 3;
        if (r == 0) player.setState(&walk);
        else if (r == 1) player.setState(&jump);
        else player.setState(&attack);

        player.update();
    }

    return 0;
}