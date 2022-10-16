#include<cstdio>
#include<bitset>
#include<vector>

using namespace std;

bitset<1000001> B;

int fa[2000000];long long sz[2000000],maxsz[2000000];
long long up[2000000],down[2000000],ans[2000000];
vector<int> sons[2000000];int cnt[2000000];

int main()
{
	int n=0;scanf("%d",&n);
	for(int i=2;i<=n;i++){scanf("%d",&fa[i]);sons[fa[i]].push_back(i);}
	
	for(int i=n;i>=2;i--){sz[i]++;maxsz[i]=max(maxsz[i],n-sz[i]);sz[fa[i]]+=sz[i],maxsz[fa[i]]=max(maxsz[fa[i]],sz[i]);}
	
	for(int i=n;i>=2;i--)
	{
		up[fa[i]]+=up[i]+sz[i];
	}
	down[1]=0;
	
	for(int i=2;i<=n;i++)
	{
		down[i]=down[fa[i]]+up[fa[i]]-(up[i]+sz[i])+n-sz[i];
	}
	for(int i=1;i<=n;i++)ans[i]=up[i]+down[i]+n;
	//for(int i=1;i<=n;i++)printf("%lld %lld %lld\n",up[i],down[i],ans[i]);
	long long out=0;
	for(int i=1;i<=n;i++)
	{
		if(2*maxsz[i]>=n-1)ans[i]+=(n-1-maxsz[i])*maxsz[i];
		else
		{
			//printf("%d\n",i);
			for(int j=0;j<sons[i].size();j++)cnt[sz[sons[i][j]]]++;if(i!=1)cnt[n-sz[i]]++;
			B[0]=1;
			for(int j=1;j<=n;j++)
			{
				if(cnt[j])
				{
					int b=0;while((1<<(b+1))-1<=cnt[j])b++;//printf("B:%d\n",b);
					for(int k=0;k<b;k++)
					{
						{B|=B<<(j*(1<<k));}
					}
					B|=B<<(j*(cnt[j]-((1<<b)-1)));
				}
			}
			//puts("!!");
			long long t=0;for(int j=0;j<n;j++)if(B[j]){t=max(t,(long long)j*(n-1-j));}
			ans[i]+=t;
		}
		out=max(out,ans[i]);
	}
	printf("%lld",out);
}