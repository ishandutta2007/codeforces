#include<bits/stdc++.h>
using namespace std;

int T,n;

string s;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        cin>>s;
        int c0=0;
        for(auto x:s)
            c0+=x=='0';
        int c1=n-c0;
        if(n>=3)
            puts("NO");
        else if(abs(c0-c1)>1)
            puts("NO");
        else
            puts("YES");
    }
}