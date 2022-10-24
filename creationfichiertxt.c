#include <stdio.h>
#include <stdlib.h>
#include <string.h> //to use string
#include <stdbool.h> //to get NULL
#include <unistd.h> //for use pause() to debug
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
        //W/ this programm we'll sweep all the possibilites from a letter to other with a range of 5
        //We have to repeat it by storing the second value of the alphabet in the 2nd place of our tmp, and 3thd, then 4th, 5th and 6th
        char tmp_to_send[SIZE_PSSWD];
        int incr_to_scan_couple_letters=0;
        for (int k = 0; k < 25; k++) //sweep the alphabet //we test on a alphabet size of 8
        {
          for (int first_letter = 0; first_letter < 5; first_letter++)
          {
            printf("Value of first letters : %d\n",first_letter);
            for (int n = 0; n < 25; n++,incr_to_scan_couple_letters++)//scan all possibilities from a couple of letters
            {
              tmp_to_send[first_letter]=alphabet[first_letter+incr_to_scan_couple_letters];
              printf("Value of incr_to_scan_couple_letters : %d\n",incr_to_scan_couple_letters);
              for (int m = 0; m < 25; m++)//And then scan with the rest of letters
              {
                int incr_for_alphabet=m+1;//Dodging repeatition
                if (incr_for_alphabet == 21) //Dodging void alphabet
                  n=26;
                printf("Value of incr : %d\n",incr_for_alphabet);//To debug
                for (int l= first_letter+1; l < 6; l++,incr_for_alphabet++)
                {
                  tmp_to_send[l]=alphabet[incr_for_alphabet];
                  printf("value of l : %d\n",l);//To debug
                }
                tmp_to_send[6]='\0';
                //combinations(tmp_to_send);
                printf("combinations to send : %s\n\n",tmp_to_send);//To debug
                sleep(1);//sleep for 1 seconds to debug
              }
            }
          }
        }
    }
    else
        printf("ERROR : file not opened");
    fclose(file_to_write);
    printf("\n______________FILE CREATED______________\n");
    return 0;
}