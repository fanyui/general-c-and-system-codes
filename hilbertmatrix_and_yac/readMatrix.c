#include<stdio.h>
#include<stdlib.h>
int main()
{
  int i;
  int j;
	int size;

/*matrix*/
/*Use double , you have floating numbers not int*/

float** mat=malloc(1000000*sizeof(float*)); 
for(i=0;i<1000000;++i)
mat[i]=malloc(4*sizeof(float));

  FILE *file;
  file=fopen("outPutFile.txt", "r");
	fscanf(file,"%d",&size);

 for(i = 0; i < size; i++)
  {
      for(j = 0; j < size; j++) 
      {
  //Use lf format specifier, %c is for character
       if (!fscanf(file, "%f", &mat[i][j])) 
           break;
      // mat[i][j] -= '0'; 
       printf("%f\n",mat[i][j]); //Use lf format specifier, \n is for new line
      }

  }
  fclose(file);
}
