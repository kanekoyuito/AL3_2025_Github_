#pragma once
#include "KamataEngine.h"


class MapChipField {

	static inline const float kBlockWidth = 1.0f;
	static inline const float kBlockHeight = 1.0f;

	static inline const uint32_t kNumBlockvirtical = 20;
	static inline const uint32_t kNumBlockHorizontal = 100;

	MapChipData mapChipData_;
	void ResetMapChipData();
	void LoadMapChipCsv(const std::string& filePath);

	MapChipType GetMapChipTypeByindex(uint32_t xIndex, uint32_t yIndex);
};

enum class MapChipType {
	kBlank,
	kBlock,
};
struct MapChipData {
	std::vector<std::vector<MapChipType>> data;
};

