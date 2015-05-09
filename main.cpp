#include <iostream>
#include "CLRegularCoordinator.h"
#include "CLThread.h"
#include "CLMyPrint.h"
#include "CLExecutiveFunctionProvider.h"

int main(void)
{
	CLCoordinator *pCoordinator = new CLRegularCoordinator();
	CLExecutive *pExecutive = new CLThread(pCoordinator);
	CLExecutiveFunctionProvider *pProvider = new CLMyPrint();
	pCoordinator->SetExecObjects(pExecutive , pProvider);
	pCoordinator->Run((void*)5);
	pCoordinator->WaitForDeath();
	return 0;
}
