#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

const int maxlen=1e6+5, maxn=1005;

int n,l,k,len,sz[maxn];
char s[maxlen],ans[maxn][maxn];

int main()
{
	scanf("%d %d %d",&n,&l,&k);
	len=n*l;
	scanf("%s",s+1);
	
	sort(s+1,s+1+len);
	int hd=1, zb=1;
	while (sz[k]<l && zb<k)
	{
		fo(i,zb,k) ans[i][++sz[i]]=s[hd++];
		while (zb<k && ans[zb][sz[zb]]<ans[k][sz[k]]) zb++;
	}
	
	while (sz[k]<l) ans[k][++sz[k]]=s[hd++];
	fo(i,1,n)
	{
		while (sz[i]<l) ans[i][++sz[i]]=s[hd++];
		printf("%s\n",ans[i]+1);
	}
}