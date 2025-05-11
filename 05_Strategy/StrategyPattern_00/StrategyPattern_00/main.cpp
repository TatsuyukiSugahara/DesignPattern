
#include <iostream>
using namespace std;

// �ړ����@�C���^�[�t�F�[�X���`����
class MoveStrategy {
public:
    virtual void move() = 0;
    virtual ~MoveStrategy() {}
};

// �e�ړ����@�N���X�����
// �� WalkMove�N���X, RunMove�N���X, TeleportMove�N���X�����
// �� ���ꂼ�� move() ���I�[�o�[���C�h���� cout �œ�����\������

// �����X�^�[�N���X�����
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
    // WalkMove�ARunMove�ATeleportMove �̃C���X�^���X���쐬����
    // Monster �� WalkMove �ŏ���������
    // Monster �� move() ������
    // RunMove �ɐ؂�ւ��� move() ������
    // TeleportMove �ɐ؂�ւ��� move() ������

    return 0;
}
