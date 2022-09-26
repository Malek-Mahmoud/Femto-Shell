/***************** INCLUDE *****************/
#include<stdio.h>
#include<string.h>
#include<unistd.h>
/***************** DEFINE *****************/
#define BUFF_SIZE       (200)
#define ERROR_MSG_SIZE  (13)
#define INVALED_RETURN  (-1)
/***************** MAIN ROUTINE *****************/
int main(void)
{
	char errorMsg[ERROR_MSG_SIZE] = "getcwd ERROR";
	char * check;
	int flag;
	char path[BUFF_SIZE];
	check = getcwd(path,BUFF_SIZE);
	if(check == NULL)
	{
		write(STDOUT_FILENO,errorMsg,ERROR_MSG_SIZE);
	}
	else
	{
		flag = write(STDOUT_FILENO,path,strlen(path));
		if(flag == INVALED_RETURN)
		{    
		write(STDOUT_FILENO,errorMsg,ERROR_MSG_SIZE);
		}
		else
		{ 	
		    /* Program Run Successfully */
		}
	} 
	
	printf("\n");
	return 0;
}
