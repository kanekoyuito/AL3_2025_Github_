#include "Bullet.h"
#include "MyMath.h"
#include "cassert"
#include "numbers"
#include "player.h"
#define NOMINMAX
#include "Enemy.h"
#include "MapChipField.h"
#include "algorithm"

using namespace KamataEngine;

using namespace MathUtility;

void Bullet::Initialize(KamataEngine::Model* model, KamataEngine::Camera* camera, const KamataEngine::Vector3& position) {

	assert(model);
	model_ = model;
	worldTransform_.Initialize();
	worldTransform_.translation_ = position;
	camera_ = camera;
	worldTransform_.rotation_.y = -std::numbers::pi_v<float> / 2.0f;
	// 速度の設定
	velocity_ = {-kBulletSpeed, 0, 0};
}

void Bullet::Update() { worldTransform_.translation_ += velocity_; }

void Bullet::Draw() { model_->Draw(worldTransform_, *camera_); }
