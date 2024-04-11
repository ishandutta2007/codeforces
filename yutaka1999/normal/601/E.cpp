#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 300005
#define MP 10000019LL
#define MOD 1000000007LL

using namespace std;
typedef long long int ll;

int vl[SIZE],wt[SIZE];
vector <int> va[SIZE],vr[SIZE];
bool use[SIZE];
int n,k,q;

vector < vector <int> > solve(vector < vector <int> > add,vector < vector <int> > rem)//add nArem I
{
	/*
	printf("%d %d\n",add.size(),rem.size());
	for(int i=0;i<add.size();i++)
	{
		vector <int> A=add[i],R=rem[i];
		printf("add : ");
		for(int j=0;j<A.size();j++) printf("%d ",A[j]);
		printf("rem : ");
		for(int j=0;j<R.size();j++) printf("%d ",R[j]);puts("");
	}puts("");*/
	if(add.size()==1)
	{
		vector <int> dp;
		dp.resize(k+1,0);
		for(int i=0;i<add[0].size();i++)
		{
			int v=add[0][i];
			for(int j=k-wt[v];j>=0;j--)
			{
				dp[j+wt[v]]=max(dp[j+wt[v]],dp[j]+vl[v]);
			}
		}
		vector < vector <int> > ret;
		ret.push_back(dp);
		return ret;
	}
	vector < vector <int> > na,nr;
	for(int i=0;i<add.size();i++)
	{
		va[i].clear();
		vr[i].clear();
		vector <int> A=add[i],R=rem[i];
		for(int j=0;j<R.size();j++) use[R[j]]=true;
		for(int j=0;j<A.size();j++)
		{
			if(!use[A[j]]) va[i].push_back(A[j]);
			else use[A[j]]=false;
		}
		for(int j=0;j<R.size();j++)
		{
			if(use[R[j]])
			{
				vr[i].push_back(R[j]);
				use[R[j]]=false;
			}
		}
	}
	for(int i=0;i<add.size();i+=2)
	{
		vector <int> A,R;
		if(i+1<add.size())
		{
			if(i-1>=0)
			{
				for(int j=0;j<rem[i].size();j++) use[rem[i][j]]=true;
				for(int j=0;j<va[i-1].size();j++) if(!use[va[i-1][j]]) A.push_back(va[i-1][j]);
				for(int j=0;j<rem[i].size();j++) use[rem[i][j]]=false;
			}
			if(i+3<add.size())
			{
				for(int j=0;j<add[i+1].size();j++) use[add[i+1][j]]=true;
				for(int j=0;j<vr[i+2].size();j++) if(!use[vr[i+2][j]]) R.push_back(vr[i+2][j]);
				for(int j=0;j<add[i+1].size();j++) use[add[i+1][j]]=false;
			}
			for(int j=0;j<va[i].size();j++) A.push_back(va[i][j]);
			for(int j=0;j<vr[i+1].size();j++) R.push_back(vr[i+1][j]);
		}
		else
		{
			if(i-1>=0) A=va[i-1];
			for(int j=0;j<add[i].size();j++) A.push_back(add[i][j]);
			for(int j=0;j<rem[i].size();j++) R.push_back(rem[i][j]);
		}
		na.push_back(A);
		nr.push_back(R);
	}
	vector < vector <int> > dp=solve(na,nr);
	vector < vector <int> > ret;
	for(int i=0;i<add.size();i++)
	{
		va[i].clear();
		vr[i].clear();
		vector <int> A=add[i],R=rem[i];
		for(int j=0;j<R.size();j++) use[R[j]]=true;
		for(int j=0;j<A.size();j++)
		{
			if(!use[A[j]]) va[i].push_back(A[j]);
			else use[A[j]]=false;
		}
		for(int j=0;j<R.size();j++)
		{
			if(use[R[j]])
			{
				vr[i].push_back(R[j]);
				use[R[j]]=false;
			}
		}
	}
	for(int i=0;i<add.size();i++)
	{
		vector <int> now=dp[i/2];
		if(i%2==0&&i+1<add.size())
		{
			for(int j=0;j<va[i].size();j++) use[va[i][j]]=true;
			for(int j=0;j<add[i].size();j++)
			{
				if(!use[add[i][j]])
				{
					int v=add[i][j];
					for(int t=k-wt[v];t>=0;t--)
					{
						now[t+wt[v]]=max(now[t+wt[v]],now[t]+vl[v]);
					}
				}
			}
			for(int j=0;j<va[i].size();j++) use[va[i][j]]=false;
			if(i>0)
			{
				for(int j=0;j<vr[i].size();j++)
				{
					int v=vr[i][j];
					for(int t=k-wt[v];t>=0;t--)
					{
						now[t+wt[v]]=max(now[t+wt[v]],now[t]+vl[v]);
					}
				}
			}
		}
		else if(i%2==1)
		{
			for(int j=0;j<add[i].size();j++)
			{
				int v=add[i][j];
				for(int t=k-wt[v];t>=0;t--)
				{
					now[t+wt[v]]=max(now[t+wt[v]],now[t]+vl[v]);
				}
			}
		}
		ret.push_back(now);
	}
	return ret;
}
int main()
{
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d %d",&vl[i],&wt[i]);
	vector < vector <int> > add,rem;
	vector <int> A,R;
	for(int i=0;i<n;i++) A.push_back(i);
	int sz=n;
	scanf("%d",&q);
	memset(use,false,sizeof(use));
	for(int i=0;i<q;i++)
	{
		int tp;
		scanf("%d",&tp);
		if(tp==1)
		{
			scanf("%d %d",&vl[sz],&wt[sz]);
			A.push_back(sz);
			sz++;
		}
		else if(tp==2)
		{
			int x;
			scanf("%d",&x);x--;
			R.push_back(x);
		}
		else
		{
			vector <int> na,nr;
			for(int j=0;j<R.size();j++) use[R[j]]=true;
			for(int j=0;j<A.size();j++)
			{
				if(!use[A[j]]) na.push_back(A[j]);
				else use[A[j]]=false;
			}
			for(int j=0;j<R.size();j++)
			{
				if(use[R[j]])
				{
					nr.push_back(R[j]);
					use[R[j]]=false;
				}
			}
			if(!add.empty()) rem.push_back(nr);
			add.push_back(na);
			A.clear();
			R.clear();
		}
	}
	vector <int> na,nr;
	for(int j=0;j<R.size();j++) use[R[j]]=true;
	for(int j=0;j<A.size();j++)
	{
		if(!use[A[j]]) na.push_back(A[j]);
		else use[A[j]]=false;
	}
	for(int j=0;j<R.size();j++)
	{
		if(use[R[j]])
		{
			nr.push_back(R[j]);
			use[R[j]]=false;
		}
	}
	rem.push_back(nr);
	vector < vector <int> > dp=solve(add,rem);
	for(int i=0;i<add.size();i++)
	{
		ll ret=0,t=1;
		for(int j=1;j<=k;j++)
		{
			ret+=(ll) dp[i][j]*t%MOD;
			ret%=MOD;
			t*=MP;
			t%=MOD;
			//printf("%d ",dp[i][j]);
		}
		//printf(": ");
		printf("%lld\n",ret);
	}
	return 0;
}