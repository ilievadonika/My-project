#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "header.h"

#define MAX_STRING_LEN 20
#define MAX_CODE_LEN 10
#define MAX_POSSIB 10

extern char strArray[MAX_STRING_LEN];
extern int lenStrArray;
extern int numLetters;

typedef struct lettersCoding codeLet;

codeLet *generateLegend(const char *filename);
void findPosibilities(codeLet *legend, char *decodedLetters, char *leftToDecode, codeLet letterToCheck);

struct lettersCoding {
    char letter;
    char code[MAX_CODE_LEN];
};

struct results {
    int count;
    char strings[MAX_POSSIB][MAX_STRING_LEN];
} possibilities;

char strArray[MAX_STRING_LEN];
int lenStrArray;
int numLetters = 0;

int main(void) {
    codeLet *legend = generateLegend("CODE.INP.txt");
    
    for(int i = 0; i < numLetters; i++) {
        findPosibilities(legend, "", strArray, legend[i]);
    }
    
    free(legend);

    return 0;
}

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
        /*printf("%c %s", legend[i].letter, legend[i].code);*/  /*Debug */
    }

    fclose(fp);

    return legend;
}

void findPosibilities(codeLet *legend, char *decodedLetters, char *leftToDecode, codeLet letterToCheck) {
    FILE *fp = fopen("CODE.OUT.txt", "a");
    char tempDecodedLet[MAX_STRING_LEN];
    strcpy(tempDecodedLet, decodedLetters);

    if(strncmp(leftToDecode, letterToCheck.code, strlen(letterToCheck.code)) == 0) {
        int len = strlen(tempDecodedLet);
        tempDecodedLet[len] = letterToCheck.letter;
        tempDecodedLet[len + 1] = '\0';
        leftToDecode += strlen(letterToCheck.code);

        if(*leftToDecode == '\0') {
            strcpy(possibilities.strings[possibilities.count], tempDecodedLet);
            /*printf("%s\n", possibilities.strings[possibilities.count]);*/ /*Debug*/
            fprintf(fp, "%s\n", possibilities.strings[possibilities.count]);
            possibilities.count++;
            return;
        }

        for(int i = 0; i < numLetters; i++) {
            findPosibilities(legend, tempDecodedLet, leftToDecode, legend[i]);
        }
    }
    fclose(fp);
    fp = NULL;
    return;
}

//a 110b 11c 0d 001