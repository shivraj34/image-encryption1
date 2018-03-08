#include <stdio.h>
#include <stdlib.h>

int main()
{
    int j,t,i,k,u=2,v=2;
    int sum=0;
    int s[3][3]={{-1,0,1},{-2,0,2},{-1,0,1}};// sobel filter matrix with 180 degree rotation
    int img[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};//image matrix
    int a[8][8]; // img matrix with two layers of zeros added on each side of it
    int c[6][6];// convulated matrix
    for(j=0;j<=7;j++)
    {
        a[0][j]=0;
        a[1][j]=0;
        a[6][j]=0;
        a[7][j]=0;
        a[j][1]=0;
        a[j][0]=0;
        a[j][6]=0;
        a[j][7]=0;

    }
    for(u=2;u<=5;u++)
    {
        for(v=2;v<=5;v++)
        {
            a[u][v]=img[u-2][v-2];
        }
    }
    for(t=0;t<=5;t++)
    {
        for(i=0;i<=5;i++)
        {
            for(j=0;j<=2;j++)
            {
                for(k=0;k<=2;k++)
                {
                   sum =sum+ a[t+j][i+k]*s[j][k];

                }
            }
          c[t][i]=sum;
          sum=0;
        }

    }

    for(i=0;i<=5;i++)
    {
        for(j=0;j<=5;j++)
        {
           printf("%d ",c[i][j]);
        }
        printf("\n");
    }

     for(i=0;i<=7;i++)
    {
        for(j=0;j<=7;j++)
        {
           printf("%d ",a[i][j]);
        }
        printf("\n");
    }

     for(i=0;i<=3;i++)
    {
        for(j=0;j<=3;j++)
        {
           printf("%d ",img[i][j]);
        }
        printf("\n");
    }
    return 0;
}
