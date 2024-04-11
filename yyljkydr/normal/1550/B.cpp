#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,a,b;

char s[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&a,&b);
        scanf("%s",s+1);
        int tot=0;
        for(int i=1;i<n;i++)
            if(s[i]!=s[i+1])
                tot++;
        tot++;
        if(b>=0)
        {
            printf("%d\n",(a+b)*n);
        }
        else
        {
			printf("%d\n",a*n+b*(tot/2+1));
        }
    }
}