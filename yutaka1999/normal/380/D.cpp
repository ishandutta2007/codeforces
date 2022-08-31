#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 100005
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
typedef pair <ll,P> PP;

vector <PP> vec;
ll fac[SIZE],finv[SIZE],inv[SIZE];
ll dpl[SIZE],dpr[SIZE];
ll ans[SIZE];
int in[SIZE],left[SIZE],right[SIZE];
bool ok[SIZE];
int n;

void make()
{
	fac[0]=fac[1]=1;
	finv[0]=finv[1]=1;
	inv[1]=1;
	for(int i=2;i<SIZE;i++)
	{
		inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
		fac[i]=fac[i-1]*(ll) i%MOD;
		finv[i]=finv[i-1]*inv[i]%MOD;
	}
}
ll C(int a,int b)
{
	if(a<b) return 0;
	return fac[a]*(finv[b]*finv[a-b]%MOD)%MOD;
}
ll solve(int l,int r,int now)//0`l & r`n
{
	int nl=l,nr=r;
	while(nl>=0&&in[nl]==0) nl--;
	while(nr<n&&in[nr]==0) nr++;
	if(nl==-1&&nr==n) return C(n-now+1,l+1);
	else if(nl==-1||(nr!=n&&in[nl]>in[nr]))
	{
		int diff=in[nr]-now+1,d=nr-r+1;
		int sl=diff-d;
		if(sl<0||l-sl+1<=nl) return 0;
		return C(diff-1,d-1)*solve(l-sl,nr+1,in[nr]+1)%MOD;
	}
	else
	{
		int diff=in[nl]-now+1,d=l-nl+1;
		int sr=diff-d;
		if(sr<0||r+sr-1>=nr) return 0;
		return C(diff-1,d-1)*solve(nl-1,r+sr,in[nl]+1)%MOD;
	}
}
int main()
{
	make();
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&in[i]);
		ok[i]=true;
	}
	int bef=n+2,pos=-1;
	bool up=false;
	for(int i=0;i<n;i++)
	{
		if(in[i]!=0)
		{
			if(bef<in[i]) up=true;
			bef=in[i];
			pos=i;
		}
		if(up) ok[i]=false;
		left[i]=pos;
	}
	bef=n+2;pos=n;
	up=false;
	for(int i=n-1;i>=0;i--)
	{
		if(in[i]!=0)
		{
			if(bef<in[i]) up=true;
			bef=in[i];
			pos=i;
		}
		if(up) ok[i]=false;
		right[i]=pos;
	}
	ll ret=0;
	up=false;
	for(int i=0;i<n;i++) if(in[i]==1) up=true;
	for(int i=0;i<n;i++)
	{
		if(ok[i])
		{
			if(up)
			{
				if(in[i]==1)
				{
					ret+=solve(i-1,i+1,2);
					ret%=MOD;
				}
			}
			else
			{
				if(left[i]==-1&&right[i]==n)
				{
					ret+=C(n-1,i);
					ret%=MOD;
				}
				else if(left[i]==-1||(right[i]!=n&&in[right[i]]<in[left[i]]))
				{
					int diff=in[right[i]]-1,d=right[i]-i;
					int sr=diff-d;
					if(sr<0||i-sr<=left[i]) continue;
					int L=i-sr-1,R=right[i]+1;
					bool al=false;
					ll pl=0;
					for(int j=0;j<vec.size();j++)
					{
						if(vec[j].second==P(L,R))
						{
							pl=vec[j].first;
							al=true;
						}
					}
					if(!al)
					{
						pl=solve(L,R,in[right[i]]+1);
						vec.push_back(PP(pl,P(L,R)));
					}
					pl=pl*C(diff-1,d-1)%MOD;
					ret+=pl;
					ret%=MOD;
				}
				else
				{
					int diff=in[left[i]]-1,d=i-left[i];
					int sl=diff-d;
					if(sl<0||i+sl>=right[i]) continue;
					int L=left[i]-1,R=i+sl+1;
					bool al=false;
					ll pl=0;
					for(int j=0;j<vec.size();j++)
					{
						if(vec[j].second==P(L,R))
						{
							pl=vec[j].first;
							al=true;
						}
					}
					if(!al)
					{
						pl=solve(L,R,in[left[i]]+1);
						vec.push_back(PP(pl,P(L,R)));
					}
					pl=pl*C(diff-1,d-1)%MOD;
					ret+=pl;
					ret%=MOD;
				}
			}
		}
	}
	printf("%I64d\n",ret);
	return 0;
}