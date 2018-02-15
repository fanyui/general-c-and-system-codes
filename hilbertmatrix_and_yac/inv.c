
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define MAX  25
float determinant(float[MAX][MAX],float);
void cofactor(float[MAX][MAX],float);
void transpose(float[MAX][MAX],float[MAX][MAX],float);
void fileRead(float[MAX][MAX],int[MAX]);
void multiplyMatrix(float[MAX][MAX],float[MAX][MAX]);

int i;
  int j;
	int size;
   float matrix[MAX][MAX],m_inverse[MAX][MAX],d;
	int bMatrix[MAX];
FILE *rp;
int main()
{
	FILE *fp ;
   // float matrix[MAX][MAX],size,d;
    //int i,j;
	int decision;
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
    printf("\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
    printf("\n* * * * * *                                                       * * * * * * *");
    printf("\n* * * * * * THIS PROGRAM CALCULATE THE INVERSE AND DETERMINANT  OF HILBERT MATRIX ! * * * * * * *");
    printf("\n* * * * * *                                                       * * * * * * *");
    printf("\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
    printf("\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
	printf("\n Enter 1 for determinant and inverse of hilbert \n Enter 2 to multiply a_1*a and a*a_1\n");
	scanf("%d",&decision);
	if(decision==1){
		fileRead(matrix,bMatrix);
   d=determinant(matrix,size);
    printf("\n\n    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n\tDeterminant of the Matrix = %6.2f",d);
    if (d==0)
    {
        printf("\n\n    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n\tInverse not exsist\n\n");
        printf("\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
        printf("\n* * * * * * * * * * * * * * * * * THE END * * * * * * * * * * * * * * * * * * *");
        printf("\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
    }
    else{
        cofactor(matrix,size);
	printf("\n\n\t* * * * * * * * * * * * * * * * * * * * * * * \n\n\tThe inverse of matrix is : \n\n");
 
     for (i=0;i<size;i++)
     {
         for (j=0;j<size;j++)
         {
             printf("\t%3.2f",m_inverse[i][j]);
         }
         printf("\n\n");
     }
     printf("\n\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
     printf("\n* * * * * * * * * * * * * * * * * THE END * * * * * * * * * * * * * * * * * * *");
     printf("\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");	

	}
	}
	else    {
	//looking for the inverse and determinant
		fileRead(matrix,bMatrix);
	   d=determinant(matrix,size);
		if (d==0)
	    {
		printf("\n\n    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n\tInverse not exsist\n\n");
		printf("\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
		printf("\n* * * * * * * * * * * * * * * * * THE END * * * * * * * * * * * * * * * * * * *");
		printf("\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
	    }
	    else{
		cofactor(matrix,size);
		rp = fopen("result.txt","w");
		 multiplyMatrix(matrix,m_inverse);
		fprintf(rp,"\n \t %s ","second Result\n");
		multiplyMatrix(m_inverse,matrix);
		fclose(rp);
	   } 
		
	}
	



 
}
 
/*For calculating Determinant of the Matrix . this function is recursive*/
float determinant(float matrix[MAX][MAX],float size)
{
    float s=1,det=0,m_minor[MAX][MAX];
    int i,j,m,n,c;
    if (size==1)
    {
        return (matrix[0][0]);
    }
    else
    {
        det=0;
        for (c=0;c<size;c++)
        {
            m=0;
            n=0;
            for (i=0;i<size;i++)
            {
                for (j=0;j<size;j++)
                {
                    m_minor[i][j]=0;
                    if (i != 0 && j != c)
                    {
                       m_minor[m][n]=matrix[i][j];
                       if (n<(size-2))
                          n++;
                       else
                       {
                           n=0;
                           m++;
                       }
                    }
                }
            }
            det=det + s * (matrix[0][c] * determinant(m_minor,size-1));
            s=-1 * s;
        }
    }

    return (det);
}
 
 /*calculate cofactor of matrix*/
void cofactor(float matrix[MAX][MAX],float size)
{
     float m_cofactor[MAX][MAX],matrix_cofactor[MAX][MAX];
     int p,q,m,n,i,j;
     for (q=0;q<size;q++)
     {
         for (p=0;p<size;p++)
         {
             m=0;
             n=0;
             for (i=0;i<size;i++)
             {
                 for (j=0;j<size;j++)
                 {
                     if (i != q && j != p)
                     {
                        m_cofactor[m][n]=matrix[i][j];
                        if (n<(size-2))
                           n++;
                        else
                        {
                            n=0;
                            m++;
                        }
                     }
                 }
             }
             matrix_cofactor[q][p]=pow(-1,q + p) * determinant(m_cofactor,size-1);
         }
     }
     transpose(matrix,matrix_cofactor,size);
}

/*Finding transpose of cofactor of matrix*/ 
void transpose(float matrix[MAX][MAX],float matrix_cofactor[MAX][MAX],float size)
{
     int i,j;
     float m_transpose[MAX][MAX],d;
 
     for (i=0;i<size;i++)
     {
         for (j=0;j<size;j++)
         {
             m_transpose[i][j]=matrix_cofactor[j][i];
         }
     }
     d=determinant(matrix,size);
     for (i=0;i<size;i++)
     {
         for (j=0;j<size;j++)
         {
             m_inverse[i][j]=m_transpose[i][j] / d;
         }
     }
     
}

void fileRead(float mat[MAX][MAX],int b[MAX]){

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
		//fscanf(file, "%d", &b[i]);
      // printf("%f\n",mat[i][j]); //Use lf format specifier, \n is for new line
      } 
			 //printf("%d\n",b[i]);

  }
  fclose(file);
}
void multiplyMatrix(float a[size][size],float a_1[size][size]){
	int i,j,k;
	float result[size][size];
	for(i=0;i<size;i++){
		for(j=0;j<size;j++)
			result[i][j]=0;	
}




	for (i=0;i < size;i++){
		for(j=0;j<size;j++){
			for(k=0;k<size;k++){
				result[i][j] += a[i][k] * a_1[k][j];
			}
		fprintf(rp,"%0.2f ",result[i][j]);
		//printf("%0.2f ",result[i][j]);
		}
		fprintf(rp,"%s","\n");
			
	}
	
	
	
	
}

