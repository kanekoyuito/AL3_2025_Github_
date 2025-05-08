#pragma once
#include"KamataEngine.h"
#include"player.h"
#include"vector"

class GameScene {
public:

	~GameScene();

	//初期化
	void Initialize();

	//更新
	void Update();

	//描画
	void Draw();

	//スプライト
	KamataEngine::Model* model_ = nullptr;

	KamataEngine::Camera camera_;

	Player* player_ = nullptr;

	bool isDebugCameraActive_ = false;
	KamataEngine::DebugCamera* debugCamera_ = nullptr;

	std::vector<std::vector<KamataEngine::WorldTransform*>> worldTransformBlocks_;

private:
	uint32_t textureHandle_ = 0;
};
