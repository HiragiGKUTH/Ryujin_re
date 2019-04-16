#pragma once

#include "eScene.h"
#include "AbstractScene.h"
#include "Parameter.h"

class IOnSceneChangeListener {
public:
	IOnSceneChangeListener() = default;
	virtual ~IOnSceneChangeListener() = default;
	virtual void onSceneChanged(const eScene scene, const Parameter& parameter, const bool stackClear) = 0;
};