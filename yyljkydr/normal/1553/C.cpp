#include<bits/stdc++.h>
using namespace std;

int n;

string s;

int T;

int ans;

void dfs(int x)
{
    if(x==10)
    {
        int a1=0,a2=0,r1=5,r2=5;
        for(int i=0;i<10;i++)
        {
            if(i&1)
                a1+=s[i]-'0',r1--;
            else
                a2+=s[i]-'0',r2--;
            if(a1>r2+a2||a2>r1+a1)
            {
                ans=min(ans,i+1);
                return;
            }
        }
        return;
    }
    if(s[x]!='?')
        dfs(x+1);
    else
    {
        for(int i=0;i<2;i++)
            s[x]=i+'0',dfs(x+1);
        s[x]='?';
    }
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        cin>>s;
        ans=10;
        dfs(0);
        printf("%d\n",ans);
    }
}