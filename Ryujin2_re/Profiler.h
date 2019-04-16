#pragma once

#include <list>
#include <DxLib.h>

class Profiler {
public:
	Profiler() : _begin(0), _end(0), _isDrawable(false) {}
	void update();
	bool draw() const;
	void begin() { _begin = GetNowHiPerformanceCount(); }
	void end() { _end = GetNowHiPerformanceCount(); }
	void disable() { _isDrawable = false; }
	void enable() { _isDrawable = true; }

private:

	std::list<double> _list;
	std::list<double> _ave;
	LONGLONG _begin, _end;
	int _counter;
	bool _isDrawable;
	const int SAMPLE_LEN = 240;
	const int AVE_LEN = 3;

};