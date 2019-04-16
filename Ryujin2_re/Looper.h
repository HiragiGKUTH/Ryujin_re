#pragma once

#include <stack>
#include <memory>
#include "AbstractScene.h"
#include "IOnSceneChangeListener.h"
#include "Fps.h"
#include "Profiler.h"

class Looper final : public IOnSceneChangeListener {
public:
	Looper();
	~Looper() = default;
	bool loop();
	void onSceneChanged(const eScene scene, const Parameter& parameter, const bool stackClear) override;

private:
	std::stack<std::shared_ptr<AbstractScene>> _sceneStack;	//シーンのスタック
	Fps _fps;
	Profiler _profiler;
};