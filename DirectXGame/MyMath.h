#pragma once

#include"KamataEngine.h"

KamataEngine::Matrix4x4 MakeaffineMatrix(KamataEngine::Vector3& scale, KamataEngine::Vector3& rotation, KamataEngine::Vector3& translation);

float EaseInOut(float x1, float x2, float t);

struct AABB {
	KamataEngine::Vector3 max;
	KamataEngine::Vector3 min;
};
//衝突判定時
bool IsCollision(const AABB& aabb1, const AABB& aabb2);

inline KamataEngine::Vector3 operator*(const KamataEngine::Vector3& v, float s) { return {v.x * s, v.y * s, v.z * s}; }

inline KamataEngine::Vector3& operator+=(KamataEngine::Vector3& lhs, const KamataEngine::Vector3& rhs) {
	lhs.x += rhs.x;
	lhs.y += rhs.y;
	lhs.z += rhs.z;
	return lhs;
}
