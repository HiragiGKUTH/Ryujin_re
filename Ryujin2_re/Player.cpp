#include "Player.h"
#include "Pad.h"
#include <DxLib.h>
#include "Image.h"
#include "Define.h"

const static float SPEED = 9.0f;

Player::Player() : _x(100),_y(100) {
}

bool Player::update() {
	move();
	return true;
}

void Player::draw() const {
	DrawRotaGraphF(_x, _y, 1.0, 0.0, Image::getIns()->getPlayer(), TRUE);
	DrawFormatStringF(_x + 20, _y + 20, GetColor(255, 255, 255), "X:%.1f\nY:%.1f", _x, _y);
}

void Player::move() {
	float moveX = 0, moveY = 0;
	if (Pad::getIns()->get(ePad::left) > 0)
		moveX -= SPEED;
	if (Pad::getIns()->get(ePad::right) > 0)
		moveX += SPEED;
	if (Pad::getIns()->get(ePad::down) > 0)
		moveY += SPEED;
	if (Pad::getIns()->get(ePad::up) > 0)
		moveY -= SPEED;

	if (moveX && moveY) { //斜め移動
		moveX /= (float)sqrt(2.0);
		moveY /= (float)sqrt(2.0);
	}
	if (Pad::getIns()->get(ePad::slow) > 0) {//低速移動
		moveX /= 3;
		moveY /= 3;
	}

		//移動範囲制限
	if (moveX + _x < Define::IN_X)						_x = (float)Define::IN_X;
	else if (moveX + _x > Define::IN_X + Define::IN_W)	_x = (float)(Define::IN_X + Define::IN_W);
	else												_x += moveX;
	
	if (moveY + _y < Define::IN_Y)						_y = (float)Define::IN_Y;
	else if (moveY + _y > Define::IN_Y + Define::IN_H)	_y = (float)(Define::IN_Y + Define::IN_H);
	else												_y += moveY;
}
