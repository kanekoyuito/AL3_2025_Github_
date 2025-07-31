#pragma once
#include"KamataEngine.h"

class Title {
public:
	~Title();

	void Initialize();

	void Update();

	void Draw();
	// 終了フラグ
	bool finished_ = false;
	// デスフラグのgetter
	bool IsFinished() const { return finished_; }

private:
	// 3Dモデル
	KamataEngine::Model* model_ = nullptr;
	KamataEngine::Model* modelPlayer_ = nullptr;
	// カメラ
	KamataEngine::Camera camera_;
	// ワールド変換データ
	KamataEngine::WorldTransform worldTransform_;
	KamataEngine::WorldTransform worldTransformPlayer_;
	// 回転
	float rotate = 0.0f;
};
