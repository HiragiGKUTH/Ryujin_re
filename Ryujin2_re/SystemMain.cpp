#include <DxLib.h>
#include "SystemMain.h"
#include "Define.h"
#include "Looper.h"

/*!
* @bref DxLibやゲームの初期処理
*/
bool SystemMain::initialize() const {
	SetAlwaysRunFlag(TRUE);					//ウィンドウが非アクティブでも動作を続ける
	SetWindowSizeChangeEnableFlag(TRUE);	//ウィンドウサイズを変更可能にする
	//SetOutApplicationLogValidFlag(FALSE);	//ログを出力しない
	SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_DESKTOP);	//縦横比を維持する
	SetWindowText("四聖龍神録2");			//ウィンドウテキストの設定
	ChangeWindowMode(TRUE);					//ウィンドウモードで起動
	SetWindowSizeExtendRate((float)96/GetDeviceCaps(GetDC(NULL), LOGPIXELSX));	//ウィンドウ拡大率を設定
	const int COLOR_BIT = 32;				//色深度の設定
	SetGraphMode(Define::WIN_W, Define::WIN_H, COLOR_BIT);		//ウィンドウのサイズ設定
	
	if (DxLib_Init()) return false;			//初期化が正常に終わらなかった場合終了
	SetDrawScreen(DX_SCREEN_BACK);			//描画先を裏にする
	
	return true;
}


/*!
* @bref DxLibやゲームの終了処理
*/
void SystemMain::finalize() const {
	DxLib_End();
}

/*!
* メイン処理
*/
void SystemMain::main() const {
	Looper looper;
	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen() && !clsDx()) {
		if (!looper.loop()) {
			break;
		}
	}
}
