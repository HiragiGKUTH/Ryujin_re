#pragma once

class AbstractBackground {
public:
	AbstractBackground();
	~AbstractBackground() = default;

	virtual bool update() = 0;
	virtual void draw() const = 0;
private:

};