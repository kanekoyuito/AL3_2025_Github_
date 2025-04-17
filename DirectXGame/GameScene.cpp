#include "GameScene.h"

using namespace KamataEngine;

GameScene::~GameScene() { delete model_; }

// 初期化処理
void GameScene::Initialize() {
	//ファイル名を指定してテクスチャを読み込む
	textureHandle_ = TextureManager::Load("uvChecker.png"); 
	//スプライトインスタンスの生成
	model_ = Model::Create();

	worldTransform_.Initialize();
	camera_.Initialize();
}

//更新処理
void GameScene::Update() {

}

//描画処理
void GameScene::Draw() {
	//DirectXCommonインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	//スプライト描画前処理
	Model::PreDraw(dxCommon->GetCommandList());

	//ここに描画処理
	model_->Draw(worldTransform_,camera_,textureHandle_);

	//スプライト描画後処理
	Model::PostDraw();
}