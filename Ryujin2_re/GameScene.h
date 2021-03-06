#pragma once

#include "AbstractBackground.h"
#include "AbstractScene.h"
#include <memory>
#include "Player.h"
#include "Board.h"
#include "EnemyManager.h"

class GameScene : public AbstractScene {
public:
	const static char* ParameterTagStage;	//パラメータのタグ「ステージ」
	const static char* ParameterTagLevel;	//パラメータのタグ「レベル」

	GameScene(IOnSceneChangeListener* impl, const Parameter& parameter);
	virtual ~GameScene() = default;

	void update() override;
	void draw() const override;

private:
	int _level;
	std::shared_ptr<AbstractBackground> _background;
	std::shared_ptr<AbstractBackground> _backgroundspell;
	std::shared_ptr<Player> _player;
	std::shared_ptr<Board> _board;
	std::shared_ptr<EnemyManager> _enemyManager;
};

