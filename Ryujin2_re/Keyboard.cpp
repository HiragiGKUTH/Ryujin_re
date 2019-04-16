#include "Keyboard.h"
#include <DxLib.h>

bool Keyboard::update()
{
	char nowKeyStatus[KEY_NUM];
	GetHitKeyStateAll(nowKeyStatus);
	for (int i = 0; i < KEY_NUM; i++) {
		if (nowKeyStatus[i] != 0) {
			if (_releasingCount[i] > 0)
				_releasingCount[i] = 0;
			_pressingCount[i]++;
		}
		else {
			if (_pressingCount[i] > 0)
				_pressingCount[i] = 0;
			_releasingCount[i]++;
		}

	}
	return true;
}

int Keyboard::getPressingCount(int KeyCode)
{
	return isAvailableCode(KeyCode) ? _pressingCount[KeyCode] : -1;
}

int Keyboard::getReleasingCount(int KeyCode)
{
	return isAvailableCode(KeyCode) ? _releasingCount[KeyCode] : -1;
}

bool Keyboard::isAvailableCode(int KeyCode)
{
	return (0 < KeyCode && KeyCode < KEY_NUM) ? true : false;
}
