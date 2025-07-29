#include "player.h"
#include "MyMath.h"
#include "cassert"
#include "numbers"
#define NOMINMAX
#include "MapChipField.h"
#include "algorithm"
#include"Enemy.h"

void Enemy::Initialize(KamataEngine::Model* model, KamataEngine::Camera* camera, const KamataEngine::Vector3& position) {
	assert(model);
	model_ = model;
	worldTransform_.Initialize();
	worldTransform_.translation_ = position;
	camera_ = camera;
	worldTransform_.rotation_.y = std::numbers::pi_v<float> / 2.0f;
}

void Enemy::Update() {
	
}

void Enemy::Draw() { model_->Draw(worldTransform_, *camera_); }
