/******************* INCLUDES *******************/
#include <stdio.h>
#include <string.h>

/******************* PUPLIC DEFINES *******************/
#define MAX_CMD_SIZE ((unsigned char)100)
#define MATCHED      0

/******************* PUPLIC FUNCTION *******************/
/*Function to remove the trailling Newline caused by the fgets() function */
void str_vRemoveTrailingChar(char *string)
{
   /* get the last element -1 and make it equal to the null char */
   /* '\n' --> '\0' */
   string[(strlen(string)-1)] = '\0';   
}

int main()
{
  char cmd[MAX_CMD_SIZE];
  char terminator[] = "exit";
  while(1)
  {
     /* A printed message to ask for the input cmd */
     printf("At your service, sir>");
     /* get the input message from the standerd input stream */
     fgets(cmd,sizeof(cmd),stdin);
     /* Remove the trailing newline coused by th fgets() function */
     str_vRemoveTrailingChar(cmd);
     /* check if the cmd matched the terminator cmd */
     if(strcmp(cmd,terminator) == MATCHED)
     {
        /* print a goodby message and exit the program */
	printf("GOODBYE, sir\n");
        break;	   
     }  
     else
     {
        /* print a message and print back the entered cmd */
	 printf("At your pleasure, sir>");
   	 puts(cmd);	   
     }
  }
  return 0;
}
