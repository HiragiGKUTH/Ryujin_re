#include "AbstractEnemy.h"
#include <DxLib.h>
#include "Image.h"
#include "Define.h"


AbstractEnemy::AbstractEnemy(float x, float y)
	: _x(x),
	  _y(y),
	  _speed(0),
	  _angle(0),
	  _counter(0),
	  _width(0),
	  _height(0)
{
}

void AbstractEnemy::initialize()
{
	setSize();
}

bool AbstractEnemy::update() {
	_counter++;
	_x += cos(_angle)*_speed;
	_y += sin(_angle)*_speed;
	return isInside();
}

/*!
@brief 現在の位置が画面内か？
*/
bool AbstractEnemy::isInside() const
{
	if (_counter < 60) {//最初の1秒は判定しない
		return true;
	}
	if (_x < -_width / 2 || Define::OUT_W + _width / 2 < _x || _y < -_height / 2 || Define::OUT_H + _height / 2 < _y) {
		return false;
	}
	return true;
}