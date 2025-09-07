#pragma once
#include "KamataEngine.h"

class Bullet {
public:
	void Initialize(KamataEngine::Model* model, KamataEngine::Camera* camera, const KamataEngine::Vector3& position);

	void Update();

	void Draw();

private:
	KamataEngine::Model* model_ = nullptr;

	KamataEngine::Camera* camera_ = nullptr;

	static inline const float kWidth = 0.5f;
	static inline const float kHeight = 0.5f;

	KamataEngine::WorldTransform worldTransform_;

	// 弾の速さ
	static inline const float kBulletSpeed = 0.1f;
	// 速度
	KamataEngine::Vector3 velocity_ = {};
};
