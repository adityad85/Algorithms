//=======================
#include<stdio.h>
int main()
{
    int i,j,k,n;
    float a[20][21],c,x[10],sum=0.0;
    printf("Enter the number of equations :\n");
    scanf("%d",&n);
    printf("\nEnter the elements of augmented matrix row-wise:\n");
    printf("Enter all the coefficients with a space in a single line of an equation\n");
    for(i=0; i<n; i++)
        for (j=0; j<=n; j++)
            scanf("%f",&a[i][j]);             //input the elements of array
    for (i=0; i<n; i++)                       //Pivotisation(Exchange Rows to form lower triangle)
        for (k=i+1; k<n; k++)
            if (abs(a[i][i])<abs(a[k][i]))
                for (j=0; j<=n; j++)
                {
                    double temp=a[i][j];
                    a[i][j]=a[k][j];
                    a[k][j]=temp;
                }

    for (i=0; i<n-1; i++)                     //loop to perform the gauss elimination
        for (k=i+1; k<n; k++)
        {
            double t=a[k][i]/a[i][i];
            for (j=0; j<=n; j++)
                a[k][j]=a[k][j]-t*a[i][j];    //make the elements below the pivot elements equal to zero or elimnate the variables
        }

    for (i=n-1; i>=0; i--)              //back-substitution
    {
                                        //x is an array whose values correspond to the values of x,y,z..
        x[i]=a[i][n];                   //compute by equating it with rhs
        for (j=i+1; j<n; j++)
            if (j!=i)                   //then subtract all the lhs values except the coefficient of the variable whose value                                   is being calculated
                x[i]=x[i]-a[i][j]*x[j];
        x[i]=x[i]/a[i][i];              //now finally divide the rhs by the coefficient of the variable to be calculated
    }
    printf("values of the variables are as follows:\n");
    for (i=0; i<n; i++)
        printf("X%d: %f\n",i+1,x[i]);
    return 0;
}
