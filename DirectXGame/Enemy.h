#pragma once
#include"KamataEngine.h"

class Enemy {

public:
	void Initialize(KamataEngine::Model* model, KamataEngine::Camera* camera, const KamataEngine::Vector3& position);

	void Update();

	void Draw();

private:
	KamataEngine::Model* model_ = nullptr;

	KamataEngine::Camera* camera_ = nullptr;

	KamataEngine::WorldTransform worldTransform_;

	KamataEngine::Vector3 CornerPosition(const KamataEngine::Vector3& center, Corner corner);
};
