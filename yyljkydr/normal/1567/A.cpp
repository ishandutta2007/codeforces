#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T;

char s[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        scanf("%s",s+1);
        for(int i=1;i<=n;i++)
            if(s[i]=='L'||s[i]=='R')
                putchar(s[i]);
            else
                putchar(s[i]=='U'?'D':'U');
        puts("");
    }
}