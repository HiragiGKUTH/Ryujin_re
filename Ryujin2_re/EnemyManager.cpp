#include "EnemyManager.h"
#include "Define.h"
#include <DxLib.h>
using namespace std;

EnemyManager::EnemyManager() {
	_list.emplace_back(make_shared<SmallEnemy >(Define::CENTER_X, 100));
	_list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X - 200, 150));
	_list.emplace_back(make_shared<BigEnemy>(Define::CENTER_X + 200, 200));
	_list.emplace_back(make_shared<SmallEnemy >(Define::CENTER_X, 250));
	_list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X - 200, 300));
	_list.emplace_back(make_shared<BigEnemy>(Define::CENTER_X + 200, 350));

	for (auto enemy : _list) {
		enemy->initialize();
	}
}

bool EnemyManager::update() {
	for (auto it = _list.begin(); it != _list.end();) {
		if ((*it)->update() == false) {
			it = _list.erase(it);
		}
		else {
			it++;
		}
	}
	return true;
}

void EnemyManager::draw() const {
	DrawFormatString(0, 20, GetColor(255, 255, 255), "�G�̐� = %d", _list.size());
	for (const auto enemy : _list) {
		enemy->draw();
	}
}
