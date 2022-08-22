#include <stdio.h>
#include <unistd.h>

/**
 *  * main - PID and PPID
 *
 * Return: Always 0.
 */

int main(void)
{
	    pid_t my_name;
	    pid_t my_parent;

	        my_name = getpid();
		my_parent = getppid();
		    printf("My name is %u\n", my_name);
		    printf("My parents name is %u\n", my_parent);
		        return (0);
}
