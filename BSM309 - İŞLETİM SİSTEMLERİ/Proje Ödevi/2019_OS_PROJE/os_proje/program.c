#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <termios.h>
#include "program.h"

void Prompt()
{
	char hostn[1204] = "";
	gethostname(hostn, sizeof(hostn));
	printf(KNRM "%s@%s:"KWHT KBLU "%s > " KWHT, getenv("LOGNAME"), hostn, getcwd(currentDirectory, 1024));
}

void acilis(){
	int i;
	for(i = 0; i < 40; i++)
		printf("%s", "=");
	printf("\n");
	boslukBirak();
	printf("%s%s%s\n", "=", KCYN "              KOC SHELL               ", KWHT "=");
	boslukBirak();
	for(i = 0; i < 40; i++)
		printf("%s", "=");
	printf("\n");
}

void boslukBirak(){
	int i;
	int j;
	for (i = 0; i < 2; ++i)
	{
		printf("%s", "=");
		for (j = 0; j < 38; j++)
		{
			printf("%s", " ");
		}
		printf("%s\n", "=");
	}
}

char *builtin_komutlar[]={
	"cd",
	"help",
	"quit"
};

int (*builtin_func[])(char**) = {
	&kocsh_cd,
	&kocsh_help,
	&kocsh_quit
};

int builtin_sayisi()
{
	return sizeof(builtin_komutlar)/sizeof(char *);
}

int kocsh_cd(char **args)
{
	if (args[1]==NULL)
	{
		fprintf(stderr,"kocsh: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1])!=0)
		{
			perror("kocsh");
		}
	}
	return 1;
}

int kocsh_help(char **args)
{
	int i;
	printf("Isletim Sistemleri Odevi\n");
	printf("%s\n", "Built_in Komutlar");
	for (i=0;i<builtin_sayisi();i++)
	{
		printf("  %s\n",builtin_komutlar[i]);
	}
	printf("Diger programlar icin 'man' komudunu kullanarak yardım alabilirsiniz.\n");
	return 1;
}

int kocsh_quit(char **args)
{
	int status;
	while (!waitpid(-1,&status,WNOHANG)){}
	exit(0);
}

void pipeFonk(char *args[], char *komut, char *parametre){
   pid_t pid1, pid2;
   int pipefd[2];
   char *argv2[] = {komut, parametre, NULL};
   pipe(pipefd);
   pid1 = fork();
   if (pid1 == 0) {
      dup2(pipefd[1], STDOUT_FILENO);
      close(pipefd[0]);
      execvp(args[0], args);
      perror("exec");
      return;
   }
   pid2 = fork();
   if (pid2 == 0) {
      dup2(pipefd[0], STDIN_FILENO);
      close(pipefd[1]);
      execvp(argv2[0], argv2);
      perror("exec");
      return;
   }
   close(pipefd[0]);
   close(pipefd[1]);
   waitpid(pid1, NULL, 0);
   waitpid(pid2, NULL, 0);
}

int komutYorumla(char * args[])
{
	int i=0;
	int j=0;
	int dosya;
	char *args_split[SPLIT];
	int arkaplandaCalisiyorMu = 0;
	int status;
	
	while(args[j] != NULL)
	{
		if ((strcmp(args[j],">") == 0) || (strcmp(args[j],"<") == 0) || (strcmp(args[j],"&") == 0) || (strcmp(args[j],"|") == 0))
		{
			break;
		}
		args_split[j] = args[j];
		j++;
	}
	args_split[j]=NULL;

	int m;
	if (args[0] == NULL)
	{
		return 1;
	}
	for (m = 0 ; m < builtin_sayisi() ; m++)
	{
		if (strcmp(args[0],builtin_komutlar[m])==0)
		{
			(*builtin_func[m])(args);
			return 1;
		}
	}
	while (args[i] != NULL && arkaplandaCalisiyorMu == 0)
	{
		if (strcmp(args[i],"&") == 0)
		{
			arkaplandaCalisiyorMu = 1;
		}
		else if (strcmp(args[i],"<") == 0)
		{
			if (args[i+1] == NULL )
			{
				printf ("Yeterli Arguman Yok\n");
			}
			dosyaInput(args_split,args[i+1]);
			return 1;
		}
		else if (strcmp(args[i],">") == 0)
		{
			if (args[i+1] == NULL )
			{
				printf ("Yeterli Arguman Yok\n");
			}
			dosyaOutput(args_split,args[i+1]);
			return 1;
		}
		else if(strcmp(args[i], "|") == 0){
			if (args[i+1] == NULL) printf("%s\n", "hata");
			pipeFonk(args_split, args[i+1], args[i+2]);
			return 1;
		}
		i++;
	}
	args_split[i]==NULL;
	calistir(args_split,arkaplandaCalisiyorMu);

	return 1;
}

void dosyaInput(char *args[],char* inputFile)
{
	pid_t pid;
	if (!(access (inputFile,F_OK) != -1))
	{	
		printf("kocsh: %s adinda bir dosya bulunamadi\n",inputFile);
		return;
	}
	int err=-1;
	int dosya;
	if((pid=fork()) == -1)
	{
		printf("Child olusturulamadi\n");
		return;
	}
	if (pid==0)
	{
		dosya=open(inputFile, O_RDONLY, 0600);
		dup2(dosya,STDIN_FILENO);
		close(dosya);

		if (execvp(args[0],args)==err)	
		{
			printf("err");
			kill(getpid(),SIGTERM);
		} 
	}
	waitpid(pid,NULL,0);
}

void dosyaOutput(char *args[],char* outputFile)
{
	pid_t pid;
	int err=-1;
	int dosya;
	if((pid=fork()) == -1)
	{
		printf("Child olusturulamadi\n");
		return;
	}
	if (pid==0)
	{
		dosya=open(outputFile, O_CREAT | O_TRUNC | O_WRONLY, 0600);
		dup2(dosya,STDOUT_FILENO);
		close(dosya);
		if (execvp(args[0],args)==err)	
		{
			printf("err");
			kill(getpid(),SIGTERM);
		} 
	}
	else {
		waitpid(pid,NULL,0);
	}
}


int arkaPlandaCalistir(char **args)
{
	pid_t pid;
	int status;

	struct sigaction act;
	act.sa_handler = sig_chld;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_NOCLDSTOP;

	if (sigaction(SIGCHLD,&act,NULL)<0)
	{
		fprintf(stderr,"sigaction failed\n");
		return 1;
	}

	pid=fork();
	if (pid == 0)
	{
		if (execvp(args[0],args) == -1)
		{
			printf("Komut bulunamadi");
			kill(getpid(),SIGTERM);
		}
	}
	else if (pid < 0)
	{
		perror("kocsh");
	}
	else
	{
		printf("Proses PID:%d Degeriyle Olusturuldu\n",pid);
	}
	return 1; 
}

int calistir(char **args,int arkaplandaCalisiyorMu)
{
	if (arkaplandaCalisiyorMu==0)
	{
		pid_t pid;
		int status;
		pid=fork();
		if (pid == 0)
		{
			if (execvp(args[0],args) == -1)
			{
				printf("Komut Bulunamadi");
				kill(getpid(),SIGTERM);
			}
		}
		else if (pid < 0)
		{
			perror("kocsh");
		}
		else
		{
			waitpid(pid,NULL,0);
		}
	}
	else
	{
		arkaPlandaCalistir(args);
	}
	return 1; 
}

void sig_chld(int signo) 
{
    int status, child_val,chid;
	chid = waitpid(-1, &status, WNOHANG);
	if (chid > 0)
	{
		if (WIFEXITED(status))
	    {
	        child_val = WEXITSTATUS(status);
	        printf("[%d] retval : %d \n",chid, child_val);
	    }
	}
}

int main (int argc, char **argv, char **envp)
{
	char line[SATIR];
	char *tokens[LIMIT];
	int tokenSayisi;
	int status=1;
	environ=envp;

	acilis();
	
	while(status)
	{
		Prompt();
		memset(line, '\0',SATIR);
		fgets(line,SATIR,stdin);
		if((tokens[0] = strtok(line," \n\t")) == NULL) continue;
		tokenSayisi = 1;
		while((tokens[tokenSayisi] = strtok(NULL, " \n\t")) != NULL) {
			tokenSayisi++;
		}
		komutYorumla(tokens);
	}
}
