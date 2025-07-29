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
	//歩行の速さ
	static inline const float kWalkSpeed = 0.1f;
	//速度
	KamataEngine::Vector3 velocity_ = {};
	//最初の角度[度]
	static inline const float kWalkMotionAngleStart = 0.1f;
	//最後の角度[度]
	static inline const float kWalkMotionAngleEnd = 0.5f;
	//アニメーションの周期となる時間[秒]
	static inline const float kWalkMotionTime = 0.2f;
	//経過時間
	float walkTimer_ = 0.0f;

};
