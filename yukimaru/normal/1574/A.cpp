#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
                printf("(");
            for(int j=1;j<=i;j++)
                printf(")");
            for(int j=i+1;j<=n;j++)
                printf("()");
            printf("\n");
        }
    }
    return 0;
}