#include<bits/stdc++.h>
using namespace std;

int T,n,k;

string s;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        cin>>s;
        int ok=1;
        for(int i=0;i<k;i++)
            if(s[i]!=s[n-i-1])
                ok=0;
        if(n==k*2)
            ok=0;
        puts(ok?"YES":"NO");
    }
}