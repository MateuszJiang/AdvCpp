
#include "worker.h"
#include <iostream>

int main()
{
	Worker* worker;
	worker = new SingingWaiter("Maciek", 32312, 2, 4);
	worker->Show();
}
