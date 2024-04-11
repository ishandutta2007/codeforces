#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<bitset>
using namespace std;
const int maxn=1e5+5;
int n,q,x,y,opt;
bitset<maxn>se[26],ans;///a-z
char s[maxn],now[maxn],v[2];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;++i)
	{
		se[s[i]-'a'].set(i,1);
	}
	scanf("%d",&q);
	for(int i=1;i<=q;++i)
	{
		scanf("%d",&opt);
		if(opt==1)
		{
			scanf("%d%s",&x,v);
			se[s[x]-'a'].set(x,0);
			se[v[0]-'a'].set(x,1);
			s[x]=v[0];
		}
		else
		{
			scanf("%d%d%s",&x,&y,now+1);
			ans.set();/// 
			int len=strlen(now+1);
			for(int i=1;i<=len;++i)
			{
				ans&=(se[now[i]-'a']>>(i-1));///ok 
			}///suffix
			int lans=(ans>>x).count();///[x,n]
			int rans=(ans>>(y-len+2)).count();///[y-len+2,n]
			printf("%d\n",(lans-rans<0)?0:lans-rans);
		}
	}
	return 0;
}