#define TRUE 1
#define FALSE !TRUE
#define LIMIT 256 // max number of tokens for a command
#define SATIR 1024 // max number of characters from user input
#define SPLIT 256



#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

static char* currentDirectory;
extern char** environ;

void sig_chld(int);
int kocsh_cd(char **args);
int kocsh_help(char **args);
int kocsh_quit(char **args);
int calistir(char **args, int background);
int arkaPlandaCalistir(char **args);
void dosyaInput(char *args[],char* inputFile);
void dosyaOutput(char *args[],char* inputFile);
void pipeFonk(char *args[], char *komut, char *parametre);
void Prompt();
void boslukBirak();
void acilis();
int builtin_sayisi();
int komutYorumla(char * args[]);
