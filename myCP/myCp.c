/***************** INCLUDE *****************/
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
/***************** DEFINE *****************/
#define BUFF_SIZE       (2000)
#define ERROR_MSG_SIZE  (6)
#define FRIST_ARGU      (1)
#define SECOND_ARGU     (2)
#define INVALED_RETURN  (-1)
#define MIN_INPUT_ARGU  (3)
/***************** MAIN ROUTINE *****************/
int main(int arg, char **argu)
{
    char Buff[BUFF_SIZE];
    char errorMsg[ERROR_MSG_SIZE] = "ERROR";
    int checkOpenReturn;
    int checkReadReturn;
    int checkWriteReturn;
    if (arg != MIN_INPUT_ARGU) {
	write(STDOUT_FILENO, errorMsg, ERROR_MSG_SIZE);
	return -1;
    }
    checkOpenReturn = open(argu[FRIST_ARGU], (O_RDONLY));
    if (checkOpenReturn == INVALED_RETURN) {
	write(STDOUT_FILENO, errorMsg, ERROR_MSG_SIZE);
    } else {
	checkReadReturn = read(checkOpenReturn, Buff, BUFF_SIZE);
	close(checkOpenReturn);
	if (checkReadReturn == INVALED_RETURN) {
	    write(STDOUT_FILENO, errorMsg, ERROR_MSG_SIZE);
	}
	else {
	    checkOpenReturn =
		open(argu[SECOND_ARGU], (O_WRONLY | O_CREAT));
	    if (checkOpenReturn == INVALED_RETURN) {
		write(STDOUT_FILENO, errorMsg, ERROR_MSG_SIZE);
	    }
	    else {
		checkWriteReturn = write(checkOpenReturn, Buff,strlen(Buff));
		close(checkOpenReturn);
		if (checkWriteReturn == INVALED_RETURN) {
		    write(STDOUT_FILENO, errorMsg, ERROR_MSG_SIZE);
		}
		else {
		    /* Program Run Successfully */
		}
	    }
	}
    }
    printf("\n");
    return 0;
}
