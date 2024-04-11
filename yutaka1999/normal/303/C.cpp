#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 5005
#define MX 1000005

using namespace std;
typedef pair <int,int> P;

P vec[MX][5];
int in[MX],sz[MX];
bool ng[MX],use[SIZE],ok[MX];
int id[SIZE],md[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int mx=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&in[i]);
		mx=max(mx,in[i]);
	}mx++;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int d=abs(in[i]-in[j]);
			if(!ng[d])
			{
				vec[d][sz[d]++]=P(i,j);
				if(sz[d]>m)
				{
					ng[d]=true;
					sz[d]=0;
				}
			}
		}
	}
	for(int i=1;i<=mx;i++)
	{
		bool up=true;
		int cnt=0;
		int si=0,sm=0;
		for(int j=i;j<=mx;j+=i)
		{
			for(int k=0;k<sz[j];k++)
			{
				P p=vec[j][k];
				if(!use[p.first])
				{
					id[si++]=p.first;
					int l=in[p.first];
					use[p.first]=true;
					if(!ok[l%i])
					{
						ok[l%i]=true;
						md[sm++]=l%i;
					}
					else cnt++;
				}
				if(!use[p.second])
				{
					id[si++]=p.second;
					use[p.second]=true;
					cnt++;
				}
			}
			if(ng[j]||cnt>m)
			{
				up=false;
				break;
			}
		}
		for(int j=0;j<si;j++) use[id[j]]=false;
		for(int j=0;j<sm;j++) ok[md[j]]=false;
		if(up)
		{
			printf("%d\n",i);
			return 0;
		}
	}
	return 0;
}