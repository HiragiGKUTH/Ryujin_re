#pragma once

#include "AbstractScene.h"

class TitleScene : public AbstractScene {
private:
	int str_x;
	int str_y;
public:
	TitleScene(IOnSceneChangeListener *impl, const Parameter& parameter);
	virtual ~TitleScene() = default;
	void update() override;
	void draw() const override;
};

