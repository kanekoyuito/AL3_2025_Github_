#include "Bullet.h"
#include"math.h"
#include"algorithm"
#include "AABB.h"


void Bullet::Initialize(KamataEngine::Model* model, KamataEngine::Camera* camera, const KamataEngine::Vector3& position, const KamataEngine::Vector3& velocity) {
	model_ = model;
	camera_ = camera;
	worldTransform_.Initialize();
	worldTransform_.translation_ = position;
	velocity_ = velocity;
}

void Bullet::Update() {
	// 固定速度で移動
	worldTransform_.translation_.x += velocity_.x;
	worldTransform_.translation_.y += velocity_.y;
	worldTransform_.translation_.z += velocity_.z;

	// 画面外で消える処理（必要に応じて調整）
	if (worldTransform_.translation_.x > 50.0f || worldTransform_.translation_.x < -50.0f || worldTransform_.translation_.y > 50.0f || worldTransform_.translation_.y < -50.0f ||
	    worldTransform_.translation_.z > 50.0f || worldTransform_.translation_.z < -50.0f) {
		isDead_ = true;
	}
}

void Bullet::Draw() { model_->Draw(worldTransform_, *camera_); }
// ...その他インクルード

AABB2 Bullet::GetAABB() {
	AABB2 box;
	box.min2.x = worldTransform_.translation_.x - 0.2f;
	box.min2.y = worldTransform_.translation_.y - 0.2f;
	box.min2.z = worldTransform_.translation_.z - 0.2f;

	box.max2.x = worldTransform_.translation_.x + 0.2f;
	box.max2.y = worldTransform_.translation_.y + 0.2f;
	box.max2.z = worldTransform_.translation_.z + 0.2f;

	return box;
}
