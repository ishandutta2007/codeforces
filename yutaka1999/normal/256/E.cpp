#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define MOD 777777777
#define SIZE 128*1024

using namespace std;
typedef long long int ll;

vector <int> ok[3];
struct segtree
{
	ll seg[SIZE*2][3][3];
	bool up[SIZE*2];
	int n,mum;
	
	void init()
	{
		mum=1;
		while(mum<n) mum*=2;
		memset(up,false,sizeof(up));
		for(int i=mum+n-1;i<mum*2;i++) up[i]=true;
		for(int i=mum-2;i>=0;i--) if(up[i*2+1]&&up[i*2+2]) up[i]=true;
		for(int i=mum-1;i<mum*2;i++)
		{
			memset(seg[i],0,sizeof(seg[i]));
			for(int j=0;j<3;j++) seg[i][j][j]=1;
		}
		for(int i=mum-2;i>=0;i--) make(i);
	}
	void make(int k)
	{
		if(up[k]) return;
		if(up[k*2+2])
		{
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					seg[k][i][j]=seg[k*2+1][i][j];
				}
			}
		}
		else
		{
			memset(seg[k],0,sizeof(seg[k]));
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					for(int p=0;p<3;p++)
					{
						for(int q=0;q<ok[p].size();q++)
						{
							seg[k][i][j]+=seg[k*2+1][i][p]*seg[k*2+2][ok[p][q]][j];
							seg[k][i][j]%=MOD;
						}
					}
				}
			}
		}
	}
	void updata(int k,int x)
	{
		k+=mum-1;
		memset(seg[k],0,sizeof(seg[k]));
		if(x==-1)
		{
			for(int i=0;i<3;i++)
			{
				seg[k][i][i]=1;
			}
		}
		else
		{
			seg[k][x][x]=1;
		}
		while(k>0)
		{
			k=(k-1)/2;
			make(k);
		}
	}
	int sum()
	{
		int ret=0;
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				ret+=(int) seg[0][i][j];
				ret%=MOD;
			}
		}
		return ret;
	}
};
segtree seg;

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			int a;
			scanf("%d",&a);
			if(a==1) ok[i].push_back(j);
		}
	}
	//for(int i=0;i<3;i++) {for(int j=0;j<ok[i].size();j++) printf("%d ",ok[i][j]);printf("\n");}
	seg.n=n;seg.init();
	//printf("%D\n",seg.sum());
	for(int i=0;i<m;i++)
	{
		int k,x;
		scanf("%d %d",&k,&x);
		k--;x--;
		seg.updata(k,x);
		printf("%d\n",seg.sum());
	}
	return 0;
}