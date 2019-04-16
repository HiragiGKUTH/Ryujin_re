#pragma once

#include "Task.h"

class Board : public Task {
public:
	Board();
	~Board() = default;
	bool update() override;
	void draw() const override;

private:

	float _x, _y;
};