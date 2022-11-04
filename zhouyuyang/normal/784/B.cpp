#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>
#include<queue>
#include<algorithm>
#include<map>
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

int n,ans=0;
const int s[16]={1,0,0,0,1,0,1,0,2,1,1,2,0,1,0,0};
int main()
{
    int x=read();if(!x)return 0*puts("1");
    while(x)
    {
        int a=x%16;
        ans+=s[a];
        x/=16;
    }
    cout<<ans;
    return 0;
}