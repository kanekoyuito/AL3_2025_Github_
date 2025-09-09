#pragma once
#include "KamataEngine.h"
#include"AABB.h"

class Bullet {
public:
	void Initialize(KamataEngine::Model* model, KamataEngine::Camera* camera, const KamataEngine::Vector3& position, const KamataEngine::Vector3& velocity);

	void Update(); // ← deltaTime は消す
	void Draw();

	bool IsDead() const { return isDead_; }
	void OnCollision() { isDead_ = true; }

	AABB2 GetAABB();

private:
	KamataEngine::Model* model_ = nullptr;
	KamataEngine::Camera* camera_ = nullptr;

	KamataEngine::WorldTransform worldTransform_; // ★ これが必要
	KamataEngine::Vector3 velocity_ = {};

	bool isDead_ = false;
};
