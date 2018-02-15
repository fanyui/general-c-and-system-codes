/***
	A program to look for files that have recently been accessed in a machine (particular directory )
	Default to the current working directory if not specified  and the files return are thosed
	accessed within a period of now and n hours ago where n is the arguement passed through the command
	line

***/

#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>
void printDir(char *dir,int h, int depth);
//void printTime();
void FormatOutput(int depth, int hours,struct dirent*);

int main(int argc, char *argv[]){
	//printTime();
	char *topdir = ".";
	int h = 5;
	if (argc >= 3){
		topdir=argv[2];
		h = (int)argv[1];
	}
	
	printf("Directory scan of %s\n",topdir);
	printDir(topdir,h,0);
	printf("done.\n");
	exit(0);

	return 0;
}
void printDir(char *dir,int hours, int depth){
	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;
	if((dp = opendir(dir)) == NULL) {
		fprintf(stderr,"cannot open directory: %s\n", dir);
		return;
	}
	chdir(dir);
	while((entry = readdir(dp)) != NULL) {
		lstat(entry->d_name,&statbuf);
		if(S_ISDIR(statbuf.st_mode)) {
			/* Found a directory, but ignore . and .. */
			if(strcmp(".",entry->d_name) == 0 || strcmp("..",entry->d_name) == 0)
			continue;
			printf("%*s%s/\n",depth,"",entry->d_name);
			/* Recurse at a new indent level */
			printDir(entry->d_name,hours,depth+4);
		}
		else {
			//print only file whose access time is about n hours ago
			//construct time structure with current system time
			

			
				FormatOutput(depth,hours,entry);
			
			}
	}
	chdir("..");
	closedir(dp);
}
//format the way to display the corresponding output to the user  by assessing the attributes of the structure tm_ptr
void FormatOutput(int depth, int hours,struct dirent *entry){
			struct stat filebuf;
			struct tm *tm_ptr;
			
		
			time_t now;
			(void) time(&now);
			//tm_now = gmtime(&now);
				
			stat(entry->d_name,&filebuf);
			time_t diff = difftime(now,filebuf.st_atime);
			//tm_now = gmtime(&diff);
				//printf("time diff is %ld ",diff);
				tm_ptr = gmtime(&filebuf.st_atime);
	 		if(diff <= hours*3600)
	 			 printf("File Name: %*s%s last Access: %02d/%02d/%02d at: %02d:%02d:%02d diffHour: %d\n",depth,"",entry->d_name,(tm_ptr->tm_year+1900), tm_ptr->tm_mon+1, tm_ptr->tm_mday,tm_ptr->tm_hour, tm_ptr->tm_min, tm_ptr->tm_sec,(diff-hours*3600));
		
}
// void printTime(){


// 			struct tm *tm_now;
// 			time_t now;
// 			(void) time(&now);
// 			tm_now = gmtime(&now);
// 				printf("time now is %02d:%02d:%02d\n ",tm_now->tm_hour,tm_now->tm_min,tm_now->tm_sec);
// }