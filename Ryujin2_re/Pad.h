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
	std::array<int, PAD_KEY_NUM> _idArray;	//Š„‚è“–‚Ä—p
	std::array<int, PAD_KEY_NUM> _pad;		//Œ»İ‚Ìó‘Ô‚ÌŠi”[—p
};