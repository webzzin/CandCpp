#include <stdio.h>

int main(void){
	char *s = "EMMA";
	printf("%c \n", *s);
	printf("%s \n", s);

	printf("%p \n", s);
	printf("%p \n", &s[0]);

	printf("%p \n", &s[1]);
	printf("%p \n", &s[2]);
	printf("%p \n", &s[3]);
	printf("%p \n", &s[4]);
	
	printf("%c \n", *s);
	printf("%c \n", *(s+1));
	printf("%c \n", *(s+2));
	printf("%c \n", *(s+3));

	return 0;
}