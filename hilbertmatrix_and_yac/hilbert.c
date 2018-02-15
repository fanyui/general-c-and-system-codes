#include<stdio.h>
#include<stdlib.h>
int main(){
	int i,j;
	FILE *fp;
	int n;
	printf("enter the order of the  hilbert matrix to generate\n ");
	scanf("%d",&n);
	float matrix[n][n];
	int right[n];
		

	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			matrix[i][j] = (float)1/((i+j)-1);		
		}
		if(i%2==0)
			right[i]=-2;
		else right[i]=0;

	}
	fp=fopen("outPutFile.txt","w");
	 fprintf(fp,"%d\n",n);

	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			fprintf(fp,"%0.2f ",matrix[i][j]);
			//printf("%0.2f  ",matrix[i][j]);		
		}	
	fprintf(fp,"\t %d \n",right[i]);
	//printf(" \t %d \n",right[i]);
	}
	printf("your result have been sent to the output file\n");
	fclose(fp);
return 0;
}
