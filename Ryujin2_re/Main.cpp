#include <DxLib.h>
#include "SystemMain.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SystemMain system;

	SetProcessDPIAware();

	if (system.initialize()) {
		system.main();
	}
	system.finalize();
}

