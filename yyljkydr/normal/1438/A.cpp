#include<bits/stdc++.h>
using namespace std;

const int N=1e2+1e1+7;

int T,n;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            printf("%d%c",1," \n"[i==n]);
    }
}