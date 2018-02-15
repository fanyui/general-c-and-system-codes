#include<stdio.h>
#include<stdlib.h>
int main(){
int i,j,k;
int size = 3;
int result[size][size];
int a[3][3]={
	{1,2,3},
	{4,5,2},
	{8,4,5}
};
int a_1[3][3] = {{7,3,2},{3,6,1},{9,7,2}};
for(i=0;i<3;i++){
	for(j=0;j<3;j++)
		result[i][j]=0;
}
for (i=0;i < 3;i++){
		for(j=0;j<3;j++){
			for(k=0;k<3;k++){
				result[i][j] += a[i][k] * a_1[k][j];
			}
		printf("%d ",result[i][j]);
		}
		printf("\n");
			
	}
}
