#pragma once

#include <array>
#include "Singleton.h"

class Keyboard final : public Singleton<Keyboard> {
	Keyboard() = default;
	friend Singleton <Keyboard>;

public:
	bool update();
	int getPressingCount(int KeyCode);
	int getReleasingCount(int KeyCode);

private:
	static const int KEY_NUM = 256;
	std::array<int, KEY_NUM> _pressingCount;
	std::array<int, KEY_NUM> _releasingCount;

	bool isAvailableCode(int KeyCode);
};