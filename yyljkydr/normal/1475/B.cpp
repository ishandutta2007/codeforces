#include<bits/stdc++.h>
using namespace std;

int T;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        int ok=0;
        for(int i=0;i*2020<=n;i++)
            if((n-i*2020)%2021==0)
            {
                puts("YES");
                ok=1;
                break;
            }
        if(!ok)
            puts("NO");
    }
}