<link rel="stylesheet" href="style.css">

# シングルトンパターン教材

### 授業計画

#### 授業の目標
- シングルトンパターンの基本的な概念を理解する。
- 簡単なC++のプログラムを通じて、シングルトンパターンの使い方を学ぶ。

#### 授業の流れ
1. **イントロダクション**
   - 授業の目標と概要を説明。
   - デザインパターンとは何かを簡単に説明。

2. **シングルトンパターンの概念**
   - シングルトンパターンの基本的な説明。
   - 身近な例を使ってイメージしやすく説明。

3. **簡単なコード例の解説**
   - シンプルなC++のコード例を使ってシングルトンパターンの実装方法を説明。
   - コードの逐次説明と質疑応答。

4. **実習**
   - 学生にシングルトンパターンを用いた簡単なプログラムを作成させる。

6. **まとめとQ&A**
   - 授業の内容を振り返り、重要ポイントを再確認。
   - 質疑応答の時間を設ける。

<div style="page-break-after: always;"></div>

---

# イントロダクション


#### デザインパターンとは？

デザインパターンは、プログラミングにおける一般的な問題を解決するためのテンプレートです。
これを使うと、コードが再利用しやすくなり、保守もしやすくなります。

<br>
<br>

# 🎮 シングルトンパターンとは？

## ✅ 概要

**シングルトンパターン（Singleton Pattern）**は、
「あるクラスのインスタンスを**1つだけ**生成し、どこからでも同じものにアクセスできるようにする」
という目的のデザインパターンです。

> 🔒 「唯一の存在」＝ゲームでは設定管理やサウンド制御などで大活躍！

<br>
<br>

---

## 🧠 どんなときに使う？（ゲーム編）

| 使用場面 | 説明 |
|:--|:--|
| ゲーム設定（GameSettings） | 音量、難易度、画面設定など、どこからでもアクセスできる必要がある情報 |
| サウンドマネージャ（SoundManager） | BGMやSEの再生・停止を一括管理するクラス |
| シーン管理（SceneManager） | 現在のシーンの状態を保持・制御する役割 |
| ログ管理（Logger） | デバッグログやエラーログを集約して出力する機能 |
| ゲーム状態の保存（GameState） | 一時的にプレイ状況を記録し、ロード時に復元する処理 |

> ✅ 共通して言えるのは「**複数あったら困る**」「**アプリ全体からアクセスしたい**」というニーズ！


<div style="page-break-after: always;"></div>


## ✏️ C++の基本的な実装例

```cpp
#include <iostream>
using namespace std;

class GameManager {
private:
    static GameManager* instance;  // 唯一のインスタンスへのポインタ
    GameManager() {}  // コンストラクタはprivateにする

public:
    static GameManager* getInstance() {
        if (instance == nullptr) {
            instance = new GameManager();
        }
        return instance;
    }

    void printStatus() {
        cout << "ゲームマネージャの状態です。" << endl;
    }
};

// staticメンバ変数の初期化
GameManager* GameManager::instance = nullptr;

int main() {
    GameManager::getInstance()->printStatus();
    GameManager::getInstance()->printStatus();
    return 0;
}
```


<div style="page-break-after: always;"></div>


## 📌 実装時の注意点

### 🔒 コンストラクタ・コピーコンストラクタ・代入演算子を封じる

```cpp
class Singleton {
private:
    Singleton() {}
    Singleton(const Singleton&) = delete;  // コピー禁止
    Singleton& operator=(const Singleton&) = delete;  // 代入禁止
};
```

### 🚨 メモリリークへの対応
- ゲーム終了時に delete を手動で呼ぶ必要あり（C++11以降はスマートポインタで管理）

### 🧵 マルチスレッド対応（高度）
- `std::mutex` を使ってスレッドセーフな実装も可能（必要に応じて）


<div style="page-break-after: always;"></div>


## 🧪 応用例（ゲーム開発）

### 🎚️ ゲーム設定クラス

```cpp
class GameSettings {
private:
    static GameSettings* instance;
    int volume;
    GameSettings() : volume(100) {}
public:
    static GameSettings* getInstance() {
        if (instance == nullptr) instance = new GameSettings();
        return instance;
    }
    void setVolume(int v) { volume = v; }
    int getVolume() const { return volume; }
};
```

### 🎵 サウンドマネージャ

```cpp
class SoundManager {
private:
    static SoundManager* instance;
    SoundManager() {}
public:
    static SoundManager* getInstance() {
        if (instance == nullptr) instance = new SoundManager();
        return instance;
    }
    void playBGM() { cout << "BGM再生中..." << endl; }
};
```

<div style="page-break-after: always;"></div>


## 💡 Singletonを避けたほうがいいケースは？

| ケース | 理由 |
|:--|:--|
| 単体テストを頻繁に行う | Singletonはグローバル状態を持つため、テストしづらくなることがある |
| 複数バージョンの状態を扱いたい | インスタンスを1つしか持てないため柔軟性に欠ける |
| マルチスレッド環境で複雑な制御が必要 | スレッドセーフにするのが難しくなることもある |

> 🧭 必要以上にSingletonを使うと依存が強くなり「密結合」になってしまう。

<br>
<br>

---

## 🎯 Singletonと他のパターンとの違い

| パターン名 | 目的 | インスタンス数 | 代表的な使用例 |
|:--|:--|:--|:--|
| **Singleton** | 唯一のインスタンスを共有 | 1つだけ | 設定、マネージャ系 |
| **Strategy** | 振る舞いを切り替える | 複数可 | 攻撃方法、移動戦略 |

<br>
<br>

---

## 🧭 まとめ

- **Singletonパターンは「唯一の状態を保ちたい」場面に最適**
- **ゲームでは設定・音・シーン・ログなどで頻繁に使われる**
- **便利だが、過剰な使用は依存性を高めて危険！**

> 🎮 「ここに1つだけあれば十分」を明確にしたときに使う！
