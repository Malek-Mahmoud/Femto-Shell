/*********** INCLUDE **********/
#include <stdio.h>
#include <string.h>
#include <unistd.h>
/*********** DEFINES  **********/
#define FRIST_ARGU (1)
#define MIN_ARG_NUM (2)
/*********** MAIN ROUTINE  **********/
int main(int arg,char **argu)
{
  char *Error_msg = "Write Error";
  char count;
  unsigned char buffSize,flag;

  if(arg < MIN_ARG_NUM)
  {
     write(STDERR_FILENO, Error_msg, strlen(Error_msg));
     printf("\n");
     return -1;
  }
/*********** Write the passed string to the STDOUT file **********/
  for(count = 1;count < arg; count ++)
  {
       buffSize = strlen(argu[count]);
       flag = write(STDOUT_FILENO , argu[count], buffSize);
       /* Print a space after every string */
       write(STDOUT_FILENO, " ",2);
       if( flag != buffSize)
       {
           write(STDERR_FILENO, Error_msg, strlen(Error_msg));
       }
       else
       {
             /* Program Run successfully */
       }
  }
 /* print a Newline before the end of the program */
  printf("\n");
  return 0;
}
