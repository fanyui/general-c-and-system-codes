#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<syslog.h>
int main(){
	FILE *fp;
fp=fopen("doesnot_exist","r");
if(!fp)
syslog(LOG_ERR |LOG_USER,"oops by fanyui now - %m\n");
exit(0);



}
