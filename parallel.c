//Panturu
#include <stdio.h>
#include <string.h>
#include <unistd.h>
//char* arguments[50];
//char* pointer;

int main(int argc, char const *argv[]) {
  char* arguments[] = {"ls", 0};            //added to old solution
  char* otherArgs[] = {"df", "ps", "pwd"};  //added to old solution
  for (int i = 0; i < 4; i++) {             //added to old solution
/*  char* input[50];                        //whole block removed from old solution
  while (1) {
    gets(input);
    char* delim = "&&";
    char* delim2 = " ";
    pointer = strtok(input, delim);
    char* pointer2;

    int count = 0;
    while (pointer != 0) {
      pointer2 = strtok(pointer, delim2);

      if (pointer2 != 0) {
        arguments[count] = pointer2;
        count++;
      }
    }
    arguments[count] = 0;
*/
      int pid = fork();
      if (pid == 0) {
        arguments[0] = otherArgs[i];      //added to old solution
      int err = execvp(arguments[0], arguments);
        if (err == -1) {
          printf("Fail\n" );
        }
        else{
          int status;
          waitpid(-1, &status, 0);
          }
        }
      }/*
    pointer2 = strtok(0, delim2);
  }*/
  printf("DONE\n" );
  return 0;
}
