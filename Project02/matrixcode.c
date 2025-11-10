#include<stdio.h>

int input_2matrix(int m1[][10],int m2[][10],int r1,int c1,int r2, int c2,int i,int j){
   
        printf("enter 1st Matrix :\n");
        for(i=0;i<r1;i++)
        {

            for(j=0;j<c1;j++)
            {
                printf("enter element  m1[%d][%d] :",i,j);
                scanf("%d",&m1[i][j]);
            }
        }
        printf("enter 2nd Matrix :\n");
        for(i=0;i<r2;i++)
        {

            for(j=0;j<c2;j++)
            {
                printf("enter element  m2[%d][%d] :",i,j);
                scanf("%d",&m2[i][j]);
            }
        }
    return 0;
}
int matrix_addition(int m1[][10],int m2[][10],int add[][10],int r1,int c1,int r2, int c2,int i,int j){

    if (r1!=r2 || c1!=c2)
    {
        printf("Cant perform Matrix Addition ");
    }
    else
     {
        input_2matrix(m1,m2,r1,c1,r2,c2,i,j);

        for(i=0;i<r1;i++)
        {
            for(j=0;j<c1;j++)
            {
                add[i][j]=m1[i][j]+m2[i][j];
            }
        }
        printf(" Addition of Matrix :\n");

        for(i=0;i<r1;i++)
        {
            for(j=0;j<c1;j++)
            {
                printf("%d\t",add[i][j]);
            }

            printf("\n");

        }

        }
    

  return 0;
}

int matrix_mult(int m1[][10],int m2[][10],int mul[][10],int r1,int c1,int r2, int c2,int i,int j){

    if (c1!=r2)
    {
        printf("Cant perform Multiplication");
    }
    else
    {
     input_2matrix(m1,m2,r1,c1,r2,c2,i,j);
    for ( i = 0; i < r1; i++)
    {
        for (j = 0; j <c2; j++)
         
        {
            mul[i][j]=0;

            for (int k = 0; k< c1; k++)
            {
                mul[i][j]=mul[i][j]+m1[i][k]*m2[k][j];
            }
        }
    }
      printf(" Multiplication of Matrix :\n");

        for(i=0;i<r1;i++)
        {
            for(j=0;j<c2;j++)
            {
                printf("%d\t",mul[i][j]);
            }

            printf("\n");

        }
    
    }
    return 0;

}
int matrix_transpose(int m1[][10],int r1,int c1,int i,int j){

    printf("enter  Matrix :\n");
    for(i=0;i<r1;i++)
        {

            for(j=0;j<c1;j++)
            {
                printf("enter element  m1[%d][%d] :",i,j);
                scanf("%d",&m1[i][j]);
            }
        }
    printf("Transpose of Matrix : \n");
    for(i=0;i<c1;i++)
        {

            for(j=0;j<r1;j++)
            {
                
                printf("%d\t",m1[j][i]);
            }
            printf("\n");
        }

        return 0;

}
int main()
{
    static int i,j;
    static int r1,c1,r2,c2;
    static int m1[10][10],m2[10][10];
    static int add[10][10];
    static int mul[10][10];
    

    printf("Enter number of rows of 1st Matrix: ");
    scanf("%d",&r1);
    printf("Enter number of Columns of 1st Matrix: ");
    scanf("%d",&c1);
    
    int opert;
    printf("for addition : 1\n for multiplication : 2\n for transpose : 3\n");
    printf("enter opertion you want to perform: ");
    scanf("%d",&opert);
    switch (opert)
    {
    case 1:
        printf("Enter number of rows of 2nd Matrix: ");
        scanf("%d",&r2);
        printf("Enter number of Columns of 2nd Matrix: ");
        scanf("%d",&c2);
        matrix_addition(m1,m2,add,r1,c1,r2,c2,i,j);
        break;

    case 2:
        printf("Enter number of rows of 2nd Matrix: ");
        scanf("%d",&r2);
        printf("Enter number of Columns of 2nd Matrix: ");
        scanf("%d",&c2);
        matrix_mult(m1,m2,mul,r1,c1,r2,c2,i,j);
        break;

    case 3:
        matrix_transpose(m1,r1,c1,i,j);
        break;

    default:
        printf("invalid input");
        break;
    }

    
    return 0;

}
