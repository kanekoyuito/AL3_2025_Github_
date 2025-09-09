#pragma once
#include "KamataEngine.h"
#include "AABB.h"


class Player;

class Enemy {

public:
	void Initialize(KamataEngine::Model* model, KamataEngine::Camera* camera, const KamataEngine::Vector3& position);

	void Update();

	void Draw();

	void OnCollision(const Player* player);

	AABB GetAABB2();

	KamataEngine::Vector3 GetWorldPosition();

	   // --- 追加 ---
	void TakeDamage(int damage); // ダメージを受ける
	bool IsDead() const { return isDead_; }
	void SetDead(bool dead) { isDead_ = dead; }


private:
	KamataEngine::Model* model_ = nullptr;

	KamataEngine::Camera* camera_ = nullptr;

	static inline const float kWidth = 0.8f;
	static inline const float kHeight = 0.8f;

	KamataEngine::WorldTransform worldTransform_;
	// 歩行の速さ
	static inline const float kWalkSpeed = 0.1f;
	// 速度
	KamataEngine::Vector3 velocity_ = {};
	// 最初の角度[度]
	static inline const float kWalkMotionAngleStart = 0.1f;
	// 最後の角度[度]
	static inline const float kWalkMotionAngleEnd = 0.5f;
	// アニメーションの周期となる時間[秒]
	static inline const float kWalkMotionTime = 0.2f;
	// 経過時間
	float walkTimer_ = 0.0f;

	  // --- 追加 ---
	int hp_ = 3; // HP（調整可能）
	bool isDead_ = false;
};
