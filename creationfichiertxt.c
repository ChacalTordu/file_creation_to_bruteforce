#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define SIZE_PSSWD 5
#define POSSIBLE_CHARA 25
#define NB_POSS SIZE_PSSWD^POSSIBLE_CHARA

FILE *file_to_write;

//WRITES ALL POSSIBLE COMBINATIONS OF A GIVEN STR
void make_combinations(char * str, char * tmp, int len, int ind) {
  int i;
  if (ind >= len) {                     //detect the end of our string
    //puts(tmp);                        //to debug
    fprintf(file_to_write,"%s\n",tmp);  //we write in the file our answer
    return;                             //we leave
  }
   
  for (i = 0; i < len; i++) {
    if (str[i] > 0) {                           // looking for the end of our string
      char pt = str[i];                         //create a tab char to load the value str[i] - this char is use as tempo, and it moves afterwards after each incremenation
      str[i] = -1;                              //we set the value of str[i] at -1 
      tmp[ind] = pt;                            //we load the first value in our memory allocated with our char tempo
      make_combinations(str, tmp, len, ind+1);  //we do it again with an incrementation of ind to check if this the end of our string, else we continue to load the value
      str[i] = pt;                              //loading pt in str[i]
    }
  }
}
void combinations(char * str) {
  int len = strlen(str);                //load the lenght of the string
  char * tmp = malloc(len + 1);         //allocate the memory for our string load in tmp
  tmp[len] = '\0';                      //create an empty case at the end to detect the end of our string
  make_combinations(str, tmp, len, 0);  //call the fonction to know all the combinations possible (we do not care on same charactere)
  free(tmp);                            //release memory allocated
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

        //WRITING COMBINAITIONS WITHOUT CONSIDERING DUPLICATE LETTERS. 
        //We keep the first charac and sweep all the possibility from it with our fonction combination.
        //The behavior would be : 
        //abcdef - acdefg - adefgh - aefghi - ... - avwxyz
        //bcdefg - bdefgh - ...
        //...
        //... - zabcde.
        //W/ this programm we'll sweep all the possibilites from the alphabet i guess
        char tmp_to_send[SIZE_PSSWD];
        for (int k = 0; k < 25; k++)
        {
          tmp_to_send[0]=alphabet[k];//Take the first value
          for (int m = 0; m < 25; m++)//And then scan withe the rest of letters
          {
            int incr=m+1;
            //printf("Value of incr : %d\n",incr);//To debug
            for (int l= 1; l < 6; l++,incr++)
            {
              tmp_to_send[l]=alphabet[incr];
              //printf("value of l : %d\n",l);//To debug
            }
            tmp_to_send[6]='\0';
            combinations(tmp_to_send);
            //printf("combinaitions to send : %s\n\n",tmp_to_send);//To debug
          }
        }
    }
    else
        printf("ERROR : file not opened");
    fclose(file_to_write);
    printf("\n______________FILE CREATED______________\n");
    return 0;
}