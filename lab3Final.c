#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include  <string.h>
#include  <sys/types.h>
#include <unistd.h>



int parse(char *line, char **argv){
int andSign = 0;
   while(*line != '\0'){
            while(*line == ' ' || *line == '\n'){
               *line = '\0';
                line++;
               } //does this belong here
       if (*line == '\0'){
             break;
           }
       *argv++ = line;
       while(*line != ' ' && *line != '\0' && *line != '\n'){
                 if(*line == '&'){
                     andSign = 1;
                     *line = '\0';
                 }
                   line++;
                 }
   }
   *argv = NULL;
   return andSign;
}
   


int main(){

      char *argv[50];
      char line[500];
      int pid;
      pid_t wait(int *stat_loc);
      int execvp(const char *file, char *const argv[]);
      int status = 0;
      int loc;

while(1){
      //prompt
      printf("Enter Command: \n");
      gets(line);
      status = parse(line, argv);
 
      pid = fork();
      if(pid == 0){
           execvp(*argv, argv); //problem
           return 0;
       }
      else{
           if(status == 1){
               printf("parent is not waiting");
           }
           else{
               wait(loc);
               sleep(1);
           }
     }
 printf("\n");

 
     }
//shell termination
   }








