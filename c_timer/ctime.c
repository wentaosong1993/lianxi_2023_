#include <stdio.h>
#include <time.h>
//#include <conio.h>

#ifndef CLOCKS_PER_SEC
#define CLOCKS_PER_SEC 1000
#endif


void timer(long time)
{
	clock_t start;
	long count = 1;
	start = clock();
	while(1)
	{
		if ((clock() - start) == time * CLOCKS_PER_SEC)
		{
			printf("时间到了\n");
			break;
		}
	}
}

int main(int argc, char* argv[])
{
	for (int i = 0; i < 10; i++)
	{	
		timer(i + 1);
		printf("设置了%d分钟的定时器\n", i + 1);
	}

	return 0;
}
