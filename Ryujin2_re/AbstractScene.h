#pragma once

#include "IOnSceneChangeListener.h"
#include "Parameter.h"

class IOnSceneChangeListener;

class AbstractScene {
protected:
	IOnSceneChangeListener* _implSceneChanged;
public:
	AbstractScene(IOnSceneChangeListener* impl, const Parameter& parameter);
	virtual ~AbstractScene() = default;
	virtual void update() = 0;
	virtual void draw() const = 0;
};