#include <DxLib.h>
#include "Fps.h"

const static int LIST_LEN_MAX = 30;
const static int FPS = 60;
const static int UPINTVL = 60;

Fps::Fps():_counter(0),_fps(0){}

void Fps::wait() {
	_counter++;
	Sleep(getWaitTime());	//�҂ׂ����Ԃ��擾���đҋ@
	regist();
	if (_counter == UPINTVL) {	//�X�V�^�C�~���O�ɂȂ����畽�ϒl���X�V
		updateAverage();
		_counter = 0;
	}
}

void Fps::draw() const {
	if (_fps == 0) {
		return;
	}
	DrawFormatString(0, 0, GetColor(255, 255, 255), "%04.2f FPS", _fps);
	DrawFormatString(0, 32, GetColor(255, 255, 255), "Total:%04.2f ms", _total);
}

void Fps::updateAverage() {
	int len = (int)_list.size();
	if (len < LIST_LEN_MAX)	//�܂����ς��v�Z���郌�x���ɂ܂ł��܂��Ă��Ȃ���Όv�Z���Ȃ�
		return;
	int tookTime = _list.back() - _list.front();//LIST_LEN_MAX�t���[���ɂ�����������
	float average = (float)tookTime / (len - 1);//���ς����
	if (average == 0) {//0����h�~
		return;
	}
	_fps = 1000 / average;
	_total = (float)tookTime / LIST_LEN_MAX;
}

void Fps::regist() {
	_list.push_back(GetNowCount());	//���݂̎������v�b�V��
	if (_list.size() > LIST_LEN_MAX)	//���e���𒴂�����|�b�v
		_list.pop_front();
}

unsigned int Fps::getWaitTime() const {
	int len = (int)_list.size();	//���݂̌v�Z�Ώۂ̑傫�����擾
	if (len == 0) return 0;			//���ς��o���Ȃ��قǃT���v�������Ȃ����͏I��

	int shouldTookTime = (int)(1000 / 60.f*(len));			//�v�Z�ォ����ׂ�����
	int actuallyTookTime = GetNowCount() - _list.front();	//���ۂɂ�����������
	int waitTime = shouldTookTime - actuallyTookTime;		//�҂ׂ�����
	waitTime = waitTime > 0 ? waitTime : 0;
	return (unsigned int)(waitTime);
}
