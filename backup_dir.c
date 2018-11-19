#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF 64

#define DIRECTORY 3

//FUNCTION FOR BACKUP DIRECTORY 
void copy(char *path, char *dir);

int main(void) {
	
	char dir[BUFF];
	
	//CURRENT DIR(PWD) POINTER
	FILE *result = popen("pwd","r");
	if (result != NULL)
		while(fgets(dir, BUFF, result) != NULL);
	else return 0;
	
	//DIRECTORIES FOR BACKUP
	char *dirs[DIRECTORY] = {
		"/home/user/Templates/C++/", //[0]
		"/home/user/Templates/Ruby/",//[1]
		"/home/user/Templates/Rust/" //[2]
	};

	for (unsigned short index = 0; index < DIRECTORY; index++)
		copy(dirs[index], dir);

	return 0;
}

void copy(char *path, char *dir) {
	char command[BUFF] = "cp -r ";

	strcat(command, path);
	strcat(command, " ");
	strcat(command, dir);

	system(command);
}