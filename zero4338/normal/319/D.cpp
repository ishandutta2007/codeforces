#include<bits/stdc++.h>
typedef unsigned long long ull;
using namespace std;
const int maxn=5e4+5;
const ull p=13331;
int n;
char s[maxn];
ull ppow[maxn],ha[maxn];
bool vis[maxn];
void rebuild()
{
	int cnt=0;
	for(int i=1;i<=n;i++)if(!vis[i])s[++cnt]=s[i];else vis[i]=0;
	n=cnt;
	for(int i=1;i<=n;i++)ha[i]=ha[i-1]*p+s[i]-'a'+1;
}
int get(int l,int r){return ha[r]-ha[l-1]*ppow[r-l+1];}
int getlcs(int x,int y)
{
	int l=0,r=min(x,y),ret=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(get(x-mid+1,x)==get(y-mid+1,y))ret=mid,l=mid+1;
		else r=mid-1;
	}
	return ret;
}
int getlcp(int x,int y)
{
	int l=0,r=min(n-x+1,n-y+1),ret=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(get(x,x+mid-1)==get(y,y+mid-1))ret=mid,l=mid+1;
		else r=mid-1;
	}
	return ret;
}
int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	ppow[0]=1;for(int i=1;i<=n;i++)ppow[i]=ppow[i-1]*p;
	rebuild();
	for(int len=1;len<=n/2;len++)
	{
		bool used=0;int lp=1;
		for(int j=2;j*len<=n;j++)
		{
			int p1=(j-1)*len,p2=j*len;
			int l=max(lp,p1-getlcs(p1,p2)+1),r=min(l+len-1,p1+getlcp(p1,p2)-1);
			if(r-l+1==len)
			{
				for(int i=l;i<=r;i++)vis[i]=1;
				used=1;
				lp=r+1;
			}
		}
		if(used)rebuild();
	}
	for(int i=1;i<=n;i++)putchar(s[i]);putchar('\n');
	return 0;
}