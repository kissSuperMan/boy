#include "ScreenCache.h"

#include "TimeCon.h"
#include <conio.h>
#include "ReadFile.h"
#include "MyList.h"
#include "Director.h"							

int main()
{
	
	//����Ϊ���Դ���	
	Director myDir;
	myDir.readyCmd();
	myDir.loadDirSence();
	myDir.runSence();
	return 0;
}



