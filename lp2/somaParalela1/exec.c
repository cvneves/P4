#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{

	char *_argv[3];
	int pid;
	char *nomesArq[4] = {"rn01.txt", "rn02.txt", "rn03.txt", "rn04.txt"};

	_argv[0] = "/Users/bidu/somador";
	_argv[2] = 0;

	for (int i = 0; i < 4; i++)
	{
		if (fork() == 0)
		{
			_argv[1] = nomesArq[i];
			execve("./somador", _argv, 0);
			break;
		}
	}

	

	return 0;
}
