#include "AbstractScene.h"

/*!
@bref �R���X�g���N�^
@param impl �V�[���ύX�̃��X�i�[
@param parameter �O�̃V�[������n���ꂽ�p�����[�^
*/

AbstractScene::AbstractScene(IOnSceneChangeListener* impl, const Parameter& parameter) : _implSceneChanged(impl) {

}

