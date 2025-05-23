#include <iostream>
using namespace std;

// Component
class Attack {
public:
    virtual void execute() = 0;
    virtual ~Attack() {}
};

// ConcreteComponent
class BasicAttack : public Attack {
public:
    void execute() override {
        cout << "通常攻撃を行った！" << endl;
    }
};

// Decorator
class AttackDecorator : public Attack {
protected:
    Attack* base;
public:
    AttackDecorator(Attack* a) : base(a) {}
    virtual ~AttackDecorator() {
        delete base;
    }
};

// Fire属性
class FireAttack : public AttackDecorator {
public:
    FireAttack(Attack* a) : AttackDecorator(a) {}
    void execute() override {
        base->execute();
        cout << "→ 炎属性の効果が追加された！" << endl;
    }
};

// Ice属性
class IceAttack : public AttackDecorator {
public:
    IceAttack(Attack* a) : AttackDecorator(a) {}
    void execute() override {
        base->execute();
        cout << "→ 氷属性の効果で凍結の可能性！" << endl;
    }
};

// Poison属性
class PoisonAttack : public AttackDecorator {
public:
    PoisonAttack(Attack* a) : AttackDecorator(a) {}
    void execute() override {
        base->execute();
        cout << "→ 毒の効果で継続ダメージ！" << endl;
    }
};

int main() {
    cout << "-- 通常攻撃のみ --" << endl;
    BasicAttack basic;
    basic.execute();

    cout << "\n-- 氷属性付き攻撃 --" << endl;
    IceAttack ice(new BasicAttack());
    ice.execute();

    cout << "\n-- 火→毒→氷の順に属性追加 --" << endl;
    Attack* fullCombo = new IceAttack(new PoisonAttack(new FireAttack(new BasicAttack())));
    fullCombo->execute();

    delete fullCombo;

    return 0;
}