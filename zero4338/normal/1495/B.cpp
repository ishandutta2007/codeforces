#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int n;
int p[maxn];
struct mount
{
	int lef,rig;
};
mount m[maxn];int mnum;
int longer(int x)
{
	return max(m[x].lef,m[x].rig);
}
bool comp(mount a,mount b)
{
	return max(a.lef,a.rig)>max(b.lef,b.rig);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	int up=0,down=0;
	for(int i=2;i<=n;)
	{
		int up=0,down=0;
		while(p[i]>p[i-1]&&i<=n)
		{
			i++;up++;
		}
		while(p[i]<p[i-1]&&i<=n)
		{
			i++;down++;
		}
		mnum++;
		m[mnum].lef=up+1;
		m[mnum].rig=down+1;
	}
	sort(m+1,m+mnum+1,comp);
	if(longer(1)==longer(2))printf("0");
	else
	{
		if(m[1].lef!=m[1].rig||m[1].lef%2==0)printf("0");
		else printf("1");
	}
	return 0;
}