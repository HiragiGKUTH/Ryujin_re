#include "AbstractScene.h"

/*!
@bref コンストラクタ
@param impl シーン変更のリスナー
@param parameter 前のシーンから渡されたパラメータ
*/

AbstractScene::AbstractScene(IOnSceneChangeListener* impl, const Parameter& parameter) : _implSceneChanged(impl) {

}

