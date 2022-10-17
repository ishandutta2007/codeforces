#include<bits/stdc++.h>
#define ll long long
#define N 10010
#define M 1050000
using namespace std;

int n;
char str[N];

inline bool judge(ll u,ll v)
{
    ll i,j,l,r;
    for(l=u,r=v;r>=l;l++,r--) if(str[l]!=str[r]) return 0;
    for(i=1,j=u;i<=n;i++,j++) if(str[i]!=str[j]) return 1;
    return 0;
}

int main()
{
    ll i,j,l,r,t;
    scanf("%s",str+1);
    n=strlen(str+1);
    if(n<=3)
    {
	puts("Impossible");
	return 0;
    }
    for(i=n+1;i<=(n << 1);i++) str[i]=str[i-n];
    for(i=2;i<=n;i++)
    {
	if(judge(i,i+n-1))
	{
	    puts("1");
	    return 0;
	}
    }
    for(l=2,r=n-1;l<r;l++,r--)
    {
	if(str[l]!=str[l-1])
	{
	    puts("2");
	    return 0;
	}
    }
    puts("Impossible");
}