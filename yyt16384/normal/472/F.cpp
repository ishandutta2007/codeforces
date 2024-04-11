#include <bitset>
#include <cstdio>
#include <cstring>
#include <vector>
#ifdef _WIN32
#define LLFORMAT "%I64"
#else
#define LLFORMAT "%ll"
#endif
const int MAXN=10005;
int n;
unsigned x[MAXN];
unsigned y[MAXN];
int baseid[32];
std::bitset<32> base[32];
int basex[32];
std::bitset<32> yy[MAXN];
int nosol;
std::vector<std::pair<int,int> > ans;
std::vector<std::pair<int,int> > ans2;
void input()
{
	scanf("%d",&n);
	for (int i=0;i<n;++i)
		scanf("%u",&x[i]);
	for (int i=0;i<n;++i)
		scanf("%u",&y[i]);
}
void init()
{
	memset(basex,-1,sizeof(basex));
	for (int i=0;i<n;++i)
	{
		int p=x[i];
		std::bitset<32> tmp;
		for (int j=0;j<32;++j)
			if ((p>>j)&1)
			{
				if (basex[j]!=-1) p^=basex[j],tmp^=base[j];
				else
				{
					baseid[j]=i;
					base[j]=tmp;
					base[j][j]=1;
					basex[j]=p;
					break;
				}
			}
	}
	for (int i=0;i<n;++i)
	{
		int p=y[i];
		for (int j=0;j<32;++j)
			if ((p>>j)&1)
			{
				if (basex[j]!=-1) p^=basex[j],yy[i]^=base[j];
				else
				{
					nosol=1;
					break;
				}
			}
	}
}
void solve()
{
	if (nosol)
	{
		printf("-1\n");
		return;
	}
	for (int i=0;i<n;++i)
	{
		int fl=1;
		for (int j=0;j<32;++j)
			if (basex[j]!=-1&&baseid[j]==i)
			{
				fl=0;break;
			}
		if (fl)
		{
			ans.push_back(std::make_pair(i,i));
			for (int j=0;j<32;++j)
				if (yy[i][j])
					ans.push_back(std::make_pair(i,baseid[j]));
		}
	}
	int csl[32];
	int cpos[32];
	std::bitset<32> cc[32];
	int ccn=0;
	for (int i=0;i<32;++i)
		if (basex[i]!=-1)
		{
			int u=baseid[i];
			csl[ccn]=i;
			cpos[ccn]=u;
			cc[ccn++]=yy[u];
		}
	for (int i=0;i<ccn;++i)
	{
		int r=-1;
		for (int j=i;j<ccn;++j)
			if (cc[j][csl[i]])
			{
				r=j;break;
			}
		if (r==-1) continue;
		if (r!=i)
		{
			ans2.push_back(std::make_pair(cpos[r],cpos[i]));
			ans2.push_back(std::make_pair(cpos[i],cpos[r]));
			ans2.push_back(std::make_pair(cpos[r],cpos[i]));
			std::bitset<32> tmp=cc[i];cc[i]=cc[r];cc[r]=tmp;
		}
		for (int j=0;j<ccn;++j)
			if (j!=i&&cc[j][csl[i]])
			{
				ans2.push_back(std::make_pair(cpos[j],cpos[i]));
				cc[j]^=cc[i];
			}
	}
	for (int i=0;i<ccn;++i)
		if (cc[i][csl[i]]==0)
		{
			for (int j=0;j<i;++j)
				if (cc[j][csl[i]])
					ans.push_back(std::make_pair(cpos[j],cpos[i]));
			ans.push_back(std::make_pair(cpos[i],cpos[i]));
		}
	printf("%d\n",(int)ans.size()+(int)ans2.size());
	for (std::vector<std::pair<int,int> >::const_iterator i=ans.begin();i!=ans.end();++i)
		printf("%d %d\n",i->first+1,i->second+1);
	for (std::vector<std::pair<int,int> >::const_reverse_iterator i=ans2.rbegin();i!=ans2.rend();++i)
		printf("%d %d\n",i->first+1,i->second+1);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
#endif
	input();
	init();
	solve();
#ifndef ONLINE_JUDGE
	fclose(stdin);fclose(stdout);
#endif
	return 0;
}