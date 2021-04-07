#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

struct lettersCoding {
    char letter;
    char code[MAX_CODE_LEN];
};

struct possibleStrings {
    int count;
    char str[MAX_POSSIB][MAX_STRING_LEN];
} possibilities;

char strArray[MAX_STRING_LEN];
int lenStrArray;
int numLetters = 0;

codeLet *generateLegend(const char *filename) {

    FILE *fp;
    fp = fopen("CODE.INP.txt", "r");

    if(fp == NULL) {
        perror("Error opening the file!");
        exit(1);
    }
    
    fscanf(fp, "%s", strArray);
    if(fgetc(fp) != '\n') {
        printf("Bad formatting!");
        exit(1);
    }

    lenStrArray = strlen(strArray);

    fscanf(fp, "%d", &numLetters);
    if(fgetc(fp) != '\n') {
        printf("Bad formatting!");
        exit(1);
    }

    codeLet *legend = (codeLet *) malloc(numLetters * sizeof(codeLet));

    for (int i = 0; i < numLetters; i++) {
        fscanf(fp, "%c %s\n", &((legend + i)->letter), (legend + i)->code);
        printf("%c %s", legend[i].letter, legend[i].code); /* Debug */
    }

    fclose(fp);

    return legend;
}

void findPosibillities(char strArray[MAX_STRING_LEN]) {
    int i, j, k;
    int len = strlen(strArray);

    for (i = 0; i < len - 1; i++) {
        for (j = i + 1; j < len; j++) {
            /*for (k = j + 1; k < len; k++)*/
               printf("%c%c\n", strArray[i], strArray[j]);
        }
    }
}









/*void findPossibilities(const codeLet *legend) {
    for (int i = 0; i < numLetters; i++) {
        checkPossibility(0, "", legend, i);
    }
}*/

/*void checkPossibility(int position, char string[], const codeLet *legend, int key) {
    if (position == lenStrArray) {
        possibilities.count++;
        strcpy(possibilities.str[possibilities.count], string);
        return;
    }

    char temp[MAX_STRING_LEN];
    strcpy(temp, string);

    if (strncmp(legend[key].code, strArray + position, strlen(legend[key].code)) == 0) {
        // strcat(temp, &legend[key].letter);
        temp[strlen(string)] = legend[key].letter;
        temp[strlen(string) + 1] = '\0'; 
        for (int i = 0; i < numLetters; i++) {
            checkPossibility(position + strlen(legend[key].code), temp, legend, i);
        }
    }
} */

    /* strArray + position "110001\0" from position */
    /* (a) 110 */
    /* strncmp next n chars in strArray */
        /* on match, check new string with each key */
        /* if we reach end, possibilities.count ++ */
            /* and add string to possibilities.str */
    //int strcmp(const char *str1, const char *str2)
//

/* 
in: 110001

0:  a001 -> ad
1:  b0001 -> bc001
2:  ad
3:  bc001 -> bcc01, bcd
4:  bcc01 -> no
5:  bcd
6:  
7:  
8:  
9:  

temp = 110001
       a? - y
       001
       a? - n
       b? - n
       c? - y
       01



 */