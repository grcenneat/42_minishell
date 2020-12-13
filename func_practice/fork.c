#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	pid_t	pids[5];
	int		procNum = 0;

	// 5개의 프로세스 생성
	while (procNum < 5)
	{
        //fork 생성
		pids[procNum] = fork();
		if (pids[procNum] < 0)
			return (-1);
		//return 값이 0이면 자식프로세스 자신
		else if (pids[procNum] == 0) {
			printf("child  %d\n", getpid());
			sleep(10);
			exit(0);
		}
		else
			printf("parent %d, child %d\n", getpid(), pids[procNum]);
		procNum++;
		sleep(5);
	}
	return (0);
}