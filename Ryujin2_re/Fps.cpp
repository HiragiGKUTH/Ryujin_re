#include <DxLib.h>
#include "Fps.h"

const static int LIST_LEN_MAX = 30;
const static int FPS = 60;
const static int UPINTVL = 60;

Fps::Fps():_counter(0),_fps(0){}

void Fps::wait() {
	_counter++;
	Sleep(getWaitTime());	//待つべき時間を取得して待機
	regist();
	if (_counter == UPINTVL) {	//更新タイミングになったら平均値を更新
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
	if (len < LIST_LEN_MAX)	//まだ平均を計算するレベルにまでたまっていなければ計算しない
		return;
	int tookTime = _list.back() - _list.front();//LIST_LEN_MAXフレームにかかった時間
	float average = (float)tookTime / (len - 1);//平均を取る
	if (average == 0) {//0割り防止
		return;
	}
	_fps = 1000 / average;
	_total = (float)tookTime / LIST_LEN_MAX;
}

void Fps::regist() {
	_list.push_back(GetNowCount());	//現在の時刻をプッシュ
	if (_list.size() > LIST_LEN_MAX)	//許容数を超えたらポップ
		_list.pop_front();
}

unsigned int Fps::getWaitTime() const {
	int len = (int)_list.size();	//現在の計算対象の大きさを取得
	if (len == 0) return 0;			//平均が出せないほどサンプルが少ない時は終了

	int shouldTookTime = (int)(1000 / 60.f*(len));			//計算上かかるべき時間
	int actuallyTookTime = GetNowCount() - _list.front();	//実際にかかった時間
	int waitTime = shouldTookTime - actuallyTookTime;		//待つべき時間
	waitTime = waitTime > 0 ? waitTime : 0;
	return (unsigned int)(waitTime);
}
