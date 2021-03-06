#pragma once

#include "Singleton.h"
#include <array>

enum ePad {
	left,
	up,
	right,
	down,
	shot,
	bom,
	slow,
	start,
	change,
};

class Pad final : public Singleton<Pad> {
public:
	Pad();
	~Pad() = default;
	void update();
	int get(ePad eID) const;

private:
	void merge();

	const static int PAD_KEY_NUM = 16;
	std::array<int, PAD_KEY_NUM> _idArray;	//割り当て用
	std::array<int, PAD_KEY_NUM> _pad;		//現在の状態の格納用
};