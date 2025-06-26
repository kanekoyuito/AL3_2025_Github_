#include "KamataEngine.h"

#pragma once
class Player {
public:
	/*void Initialize(KamataEngine::Model* model,uint32_t textureHandle,KamataEngine::Camera* camera);*/
	void Initialize(KamataEngine::Model* model, KamataEngine::Camera* camera, const KamataEngine::Vector3& position);

	void Update();

	void Draw();

private:
	// スプライト
	KamataEngine::Model* model_ = nullptr;

	KamataEngine::WorldTransform worldTransform_;

	KamataEngine::Camera* camera_ = nullptr;

	KamataEngine::Vector3 velocity_ = {};

	static inline const float kAcceleration = 0.1f;

	static inline const float kAttenuation = 0.1f;

	static inline const float kLimitRunSpeed = 1.0f;

	enum class LRDirection {
		kRight,
		kLeft,
	};
	LRDirection lrDirection_ = LRDirection::kRight;

	float turnFirstRotationY_ = 0.0f;

	float turnTimer_ = 0.0f;

	static inline const float kTimeTurn = 0.3f;

	bool onGround_ = true;

	static inline const float kGravityAcceleration = 0.1f;

	static inline const float kLimitFallSpeed = 1.0f;

	static inline const float kJumpAcceleration = 2.0f;
};
