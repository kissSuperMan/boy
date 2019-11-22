#include "ScreenCache.h"

#include "TimeCon.h"
#include <conio.h>
#include "ReadFile.h"
#include "MyList.h"
#include "Director.h"							

int main()
{
	
	//以上为调试代码	
	Director myDir;
	myDir.readyCmd();
	myDir.loadDirSence();
	myDir.runSence();
	return 0;
}



