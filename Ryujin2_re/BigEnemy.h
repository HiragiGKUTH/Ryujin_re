#pragma once

#include "AbstractEnemy.h"

class BigEnemy : public AbstractEnemy {
public:
	BigEnemy(float x, float y);
	~BigEnemy() = default;
	void draw() const override;

protected:
	void setSize() override;
};