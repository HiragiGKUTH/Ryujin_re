#include "Profiler.h"
#include <vector>
#include <numeric>

void Profiler::update() {
	double differ = (double)(_end-_begin)/1000;
	int listLen = _list.size();
	int aveLen = _ave.size();

	_counter++;
	_ave.push_back(differ);
	if (aveLen > AVE_LEN) {	//�T���v�����𒴂�����|�b�v
		_ave.pop_front();
	}

		//���ς̒����t���[�����ɕ��ς��Ƃ�
	if (_counter%AVE_LEN == 0) {
		double average = (double)std::accumulate(_ave.begin(), _ave.end(), 0.0)/AVE_LEN;
		_list.push_back(average);
		if (listLen > SAMPLE_LEN) {	//�T���v�����𒴂�����|�b�v
			_list.pop_front();
		}
	}
	std::vector<int>::iterator a;
}


bool Profiler::draw() const {
	if (this->_isDrawable == false) {
		return false;
	}

	int red = GetColor(255, 64, 64);
		//�O���t�̕\���ʒu�̐ݒ�
	const int START_X = 64, START_Y = 64;
	const int SIZE_X = SAMPLE_LEN, SIZE_Y = 128;

		//�g��`��
	DrawBox(START_X,START_Y,START_X + SIZE_X,START_Y + SIZE_Y, red, false);

		//�_�O���t��`��
	int i = 0;
	for (auto itr : _list) {
		double current = itr * 20;
		double x = START_X + SIZE_X - i;
		double y_1 = START_Y + SIZE_Y - current;
		double y_2 = START_Y + SIZE_Y;

		DrawLine(x, y_1, x, y_2, red);

		i++;
	}
	DrawFormatString(START_X, START_Y, red, "%.2f ms", _list.back());
	return true;
}
