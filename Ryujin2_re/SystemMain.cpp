#include <DxLib.h>
#include "SystemMain.h"
#include "Define.h"
#include "Looper.h"

/*!
* @bref DxLib��Q�[���̏�������
*/
bool SystemMain::initialize() const {
	SetAlwaysRunFlag(TRUE);					//�E�B���h�E����A�N�e�B�u�ł�����𑱂���
	SetWindowSizeChangeEnableFlag(TRUE);	//�E�B���h�E�T�C�Y��ύX�\�ɂ���
	//SetOutApplicationLogValidFlag(FALSE);	//���O���o�͂��Ȃ�
	SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_DESKTOP);	//�c������ێ�����
	SetWindowText("�l�����_�^2");			//�E�B���h�E�e�L�X�g�̐ݒ�
	ChangeWindowMode(TRUE);					//�E�B���h�E���[�h�ŋN��
	SetWindowSizeExtendRate((float)96/GetDeviceCaps(GetDC(NULL), LOGPIXELSX));	//�E�B���h�E�g�嗦��ݒ�
	const int COLOR_BIT = 32;				//�F�[�x�̐ݒ�
	SetGraphMode(Define::WIN_W, Define::WIN_H, COLOR_BIT);		//�E�B���h�E�̃T�C�Y�ݒ�
	
	if (DxLib_Init()) return false;			//������������ɏI���Ȃ������ꍇ�I��
	SetDrawScreen(DX_SCREEN_BACK);			//�`���𗠂ɂ���
	
	return true;
}


/*!
* @bref DxLib��Q�[���̏I������
*/
void SystemMain::finalize() const {
	DxLib_End();
}

/*!
* ���C������
*/
void SystemMain::main() const {
	Looper looper;
	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen() && !clsDx()) {
		if (!looper.loop()) {
			break;
		}
	}
}
