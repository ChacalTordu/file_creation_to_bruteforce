#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define SIZE_PSSWD 5
#define POSSIBLE_CHARA 25
#define NB_POSS SIZE_PSSWD^POSSIBLE_CHARA

FILE *file_to_write;

void make_combinations(char * str, char * tmp, int len, int ind) {
  int i;
   
  if (ind >= len) {
    //puts(tmp);
    fprintf(file_to_write,"%s\n",tmp);
    return;
  }
   
  for (i = 0; i < len; i++) {
    if (str[i] > 0) {
      char pt = str[i];
      str[i] = -1;
      tmp[ind] = pt;
      make_combinations(str, tmp, len, ind+1);
      str[i] = pt;
    }
  }
}
 
void combinations(char * str) {
  int len = strlen(str);
  char * tmp = malloc(len + 1);
   
  tmp[len] = '\0';
  make_combinations(str, tmp, len, 0);
  free(tmp);
}

int main() {    
    printf("\nProgram for the creation of the current file ...\n\n---------------------------\n");

    //VARIABLE DECLARATION
    
    //char password_possibility[NB_POSS];
    char alphabet[26];
    int i,j;

    alphabet[0]='a';
    alphabet[1]='b';
    alphabet[2]='c';
    alphabet[3]='d';
    alphabet[4]='e';
    alphabet[5]='f';
    alphabet[6]='g';
    alphabet[7]='h';
    alphabet[8]='i';
    alphabet[9]='j';
    alphabet[10]='k';
    alphabet[11]='l';
    alphabet[12]='m';
    alphabet[13]='n';
    alphabet[14]='o';
    alphabet[15]='p';
    alphabet[16]='q';
    alphabet[17]='r';
    alphabet[18]='s';
    alphabet[19]='t';
    alphabet[20]='u';
    alphabet[21]='v';
    alphabet[22]='w';
    alphabet[23]='x';
    alphabet[24]='y';
    alphabet[25]='z';

    char string_to_print[SIZE_PSSWD];
    file_to_write=fopen("bruteforce_gurvan.txt","w");

    if (file_to_write != NULL)
    {
        //WRITING POSSIBILITES W/ SAME CHARACTER
        for (j = 0; j < 26; j++)
        {
            for (i = 0; i < 6; i++)
            {
                string_to_print[i]=alphabet[j];
            }
            string_to_print[6]='\0';
            //printf("%s\n", string_to_print);
            fprintf(file_to_write,"%s\n",string_to_print);
        }

        char str[] = "abcdef";
        combinations(str);
    }
    else
        printf("ERROR : file not opened");
    fclose(file_to_write);
    printf("\n______________FILE CREATED______________\n");
    return 0;
}