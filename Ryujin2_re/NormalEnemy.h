#pragma once

#include "AbstractEnemy.h"

class NormalEnemy : public AbstractEnemy {
public:
	NormalEnemy(float x, float y);
	~NormalEnemy() = default;
	void draw() const override;

protected:
	void setSize() override;
};