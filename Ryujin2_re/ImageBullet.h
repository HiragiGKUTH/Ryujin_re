#pragma once

#include "Singleton.h"
#include <vector>

class Size {
public:
	Size() : w(0), h(0) {}
	Size(int h, int w) : h(h), w(w) {}
	int getWidth() { return w; }
	int getHeight() { return h; }
private:
	int w, h;
};

class ImageBullet final : public Singleton<ImageBullet> {
public:
	enum eBulletType {
		eSmall,			//0
		eBarrier,		//1
		eSparkSmall,	//2
		eKome,			//3
		eUmaibo,		//4
		eSparkBig,		//5
		eKodama,		//6
		eYosei,			//7
		eRing,			//8
		eAme,			//9
		eTama,			//10
		eOdama,			//11
		eLaser,			//12
		eOfuda,			//13
		eStar,			//14
		eRain,			//15
		eRainbow,		//16
		eTypeNum,
	};

	enum eBulletColor {
		eBlue,
		ePurple,
		ePink,
		eOrenge,
		eYellow,
		eGreen,
		eLime,
		eAqua,
		eColorNum,
	};

	const static float RANGE[];
	const static float SORT_Z[];

	ImageBullet::ImageBullet();

private:
	std::vector<int*> _list;
	std::vector<Size*> _sizeList;

	void load() {}
	void myLoadDivGraph(char* fname);
	int get(unsigned int type, unsigned int color) const;
	const Size* getSize(unsigned int type) const;
};