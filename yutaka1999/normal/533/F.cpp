#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <functional>
#define SIZE 200005
#define M1 1000000007LL
#define M2 1000000009LL
#define B1 8973LL
#define B2 78231LL
#define MX 26

using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;

ll h1[MX][SIZE],H1[MX];
ll h2[MX][SIZE],H2[MX];
ll r1[SIZE],r2[SIZE];
P vt[MX],now[MX];
char S[SIZE],T[SIZE];
bool use[MX];

void init()
{
	r1[0]=r2[0]=1;
	for(int i=1;i<SIZE;i++)
	{
		r1[i]=r1[i-1]*B1%M1;
		r2[i]=r2[i-1]*B2%M2;
	}
}
ll get1(int s,int t,int c)
{
	return (h1[c][t]-(s==0?0:h1[c][s-1]*r1[t-s+1]%M1)+M1)%M1;
}
ll get2(int s,int t,int c)
{
	return (h2[c][t]-(s==0?0:h2[c][s-1]*r2[t-s+1]%M2)+M2)%M2;
}
P get(int s,int t,int c)
{
	return P(get1(s,t,c),get2(s,t,c));
}
int main()
{
	init();
	int n,m;
	scanf("%d %d",&n,&m);
	scanf("%s",&S);
	scanf("%s",&T);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<MX;j++)
		{
			h1[j][i]=h2[j][i]=j==S[i]-'a'?1LL:0LL;
			if(i>0)
			{
				h1[j][i]+=h1[j][i-1]*B1%M1;
				h2[j][i]+=h2[j][i-1]*B2%M2;
				if(h1[j][i]>=M1) h1[j][i]-=M1;
				if(h2[j][i]>=M2) h2[j][i]-=M2;
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<MX;j++)
		{
			H1[j]=H1[j]*B1%M1;
			H2[j]=H2[j]*B2%M2;
			if(T[i]-'a'==j)
			{
				H1[j]++,H2[j]++;
				if(H1[j]>=M1) H1[j]-=M1;
				if(H2[j]>=M2) H2[j]-=M2;
			}
		}
	}
	for(int i=0;i<MX;i++) vt[i]=P(H1[i],H2[i]);
	vector <int> ans;
	for(int i=0;i+m<=n;i++)
	{
		for(int j=0;j<MX;j++) now[j]=get(i,i+m-1,j);/*
		if(i==0)
		{
			for(int j=0;j<5;j++) printf("[%lld %lld] ",vt[j].first,vt[j].second);puts("");
			for(int j=0;j<5;j++) printf("[%lld %lld] ",now[j].first,now[j].second);puts("");
		}*/
		bool up=true;
		memset(use,false,sizeof(use));
		for(int j=0;j<MX;j++)
		{
			if(use[j]) continue;
			if(vt[j]==now[j])
			{
				use[j]=true;
				continue;
			}
			bool ok=false;
			for(int k=j+1;k<MX;k++)
			{
				if(vt[j]==now[k]&&vt[k]==now[j])
				{
					use[j]=use[k]=true;
					ok=true;
					break;
				}
			}
			if(!ok)
			{
				up=false;
				break;
			}
		}
		if(up) ans.push_back(i);
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
	{
		if(i!=0) printf(" ");
		printf("%d",ans[i]+1);
	}puts("");
	return 0;
}