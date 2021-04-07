#define MAX_STRING_LEN 20
#define MAX_CODE_LEN 10
#define MAX_POSSIB 10

extern char strArray[MAX_STRING_LEN];
extern int lenStrArray;
extern int numLetters;

typedef struct lettersCoding codeLet;

codeLet *generateLegend(const char *filename);
void findPossibilities(char strArray[]);
void checkPossibility(int position, char string[], const codeLet *legend, int key);