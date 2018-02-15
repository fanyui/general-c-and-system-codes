#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
	int c;
	c=getchar();
	if((c>=65 && c<=92)|| (c>=97 && c<=124) || c=='_'){
		c=getchar();
		while( (c>=65 && c<=92)|| (c>=97 && c<=124) || c=='_' || isdigit(c)){
			c=getchar();
		}
		printf("%s\n", "variable recognized");
	}
	else printf("%s\n", "variable not recognized");
	return 0;
}