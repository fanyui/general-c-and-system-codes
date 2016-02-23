//illustrating how password work in linux systems
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<termios.h>
#define PASSWORD 8

int main(){
struct termios initial,newsetting;
char password[PASSWORD+1];
tcgetattr(fileno(stdin),&initial);
newsetting=initial;
newsetting.c_lflag &= ~ECHO;
printf("enter password");
if(tcsetattr(fileno(stdin),TCSAFLUSH,&newsetting)!=0 )
fprintf(stderr,"could not set attributes");
else {
	fgets(password,	PASSWORD,stdin);
tcsetattr(fileno(stdin),TCSANOW,&initial);
fprintf(stdout,"you entered :%s",password);
}
exit(0);

return 0;

}
