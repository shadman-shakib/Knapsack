#include<stdio.h>
int p[4][51];
int max(int a, int b) {
    return (a > b)? a : b;
      }

int knapSack(int W, int wt[], int val[], int n)
{
     int i,w;
      for ( w=0;w<=W;w++)
        p[0][w]=0;

        for ( i=0;i<=n;i++)
        {
            p[i][0]=0;
            for( w=0;w<=W;w++)
            {
                if(wt[i]<=w)
                {
                    if(val[i]+p[i-1][w-wt[i]]>p[i-1][w])
                    {
                        p[i][w]=val[i]+p[i-1][w-wt[i]];
                    }
                    else
                        p[i][w]=p[i-1][w];
                }

                else
                    p[i][w]=p[i-1][w];
            }

        }
     printf("Output %d\n",p[n-1][W]);

}
int main() {
    int val[50],w[50],len,W;
    printf("value and weight");
    scanf("%d",&len);
    for (int i=0;i<len;i++){
        scanf("%d%d",&val[i],&w[i]);
    }

    printf("capacity: ");
    scanf("%d",&W);

     knapSack( W,  w, val,  len);
    return 0;
}
