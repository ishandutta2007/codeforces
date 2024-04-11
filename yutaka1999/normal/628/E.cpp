#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 3005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

struct BIT//0-indexed BIT
{
	int bit[SIZE];
	
	void init()
	{
		memset(bit,0,sizeof(bit));
	}
	void add(int k,int x)
	{
		k++;
		while(k<SIZE)
		{
			bit[k]+=x;
			k+=k&-k;
		}
	}
	int get(int k)
	{
		k++;
		int ret=0;
		while(k>0)
		{
			ret+=bit[k];
			k-=k&-k;
		}
		return ret;
	}
	int get(int s,int t)
	{
		return get(t)-get(s-1);
	}
};
BIT bit;
char mp[SIZE][SIZE];
int left[SIZE][SIZE];
int right[SIZE][SIZE];
int n,m;

ll solve(int x,int y)//(x,y)(1,-1)xNgis
{
	if(x<0||x>=n||y<0||y>=m) return 0;
	if(mp[x][y]=='.') return solve(x+1,y-1);
	//min(left[a][b],right[c][d])>b-d 
	//AxA d>b-left[a][b] && d+right[c][d]>b b
	int to=0;
	while(x+to>=0&&y-to<m&&mp[x+to][y-to]=='z') to++;
	ll ans=solve(x+to,y-to);
	priority_queue <P> que;
	for(int i=x;i<x+to;i++)
	{
		int c=i,d=x+y-i;
		bit.add(d,1);
		que.push(P(d-left[c][d],d));
		while(!que.empty()&&d<=que.top().first)
		{
			P p=que.top();que.pop();
			bit.add(p.second,-1);
		}
		//printf("%d ",bit.get(d,min(d+right[c][d]-1,y)));
		ans+=bit.get(d,min(d+right[c][d]-1,y));
	}
	//printf("[%d %d] : %d : %lld\n",x,y,to,ans);
	return ans;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) scanf("%s",&mp[i]);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(mp[i][j]=='.') left[i][j]=0;
			else
			{
				left[i][j]=1;
				if(j>0) left[i][j]+=left[i][j-1];
			}
		}
		for(int j=m-1;j>=0;j--)
		{
			if(mp[i][j]=='.') right[i][j]=0;
			else
			{
				right[i][j]=1;
				if(j+1<m) right[i][j]+=right[i][j+1];
			}
		}
	}
	ll ret=0;
	for(int i=0;i<m;i++)
	{
		bit.init();
		ret+=solve(0,i);
	}
	for(int i=1;i<n;i++)
	{
		bit.init();
		ret+=solve(i,m-1);
	}
	printf("%lld\n",ret);
	return 0;
}