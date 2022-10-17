#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n;

char s[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        scanf("%s",s);
        for(int i=0;i<n;i++)
            putchar(s[i*2]);
        puts("");
    }
}