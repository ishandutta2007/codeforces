#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
#define MOD 1000000009

using namespace std;
typedef long long int ll;

struct in
{
	int t;
	int h[4];
};
in mi(int t,int a,int b,int c,int d)
{
	in ret;
	ret.t=t;ret.h[0]=a;ret.h[1]=b;ret.h[2]=c;ret.h[3]=d;
	return ret;
}
int n,h;
int nxt(int x)
{
	if(x+1>h) return 31;
	return x+1;
}
in plpl(in x)
{
	in ret;
	ret.t=x.t+1;
	for(int i=0;i<4;i++) ret.h[i]=nxt(x.h[i]);
	return ret;
}
int pls(int&a,int b)
{
	a+=b;
	if(a>MOD) a-=MOD;
	return a;
}
int nx(int x)
{
	if(x>h) return 31;
	return 0;
}
int dp[2][33][33][33][33];
bool ok[2][33][33][33][33];
int t;

int main()
{
	scanf("%d %d",&n,&h);
	queue <in> que;
	que.push(mi(0,0,0,0,0));
	memset(dp,0,sizeof(dp));
	memset(ok,false,sizeof(ok));
	dp[0][0][0][0][0]=1;
	ok[0][0][0][0][0]=true;
	int ret=0;
	while(!que.empty())
	{
		in p=que.front();que.pop();
		t=p.t%2;
		int val=dp[t][p.h[0]][p.h[1]][p.h[2]][p.h[3]];
		dp[t][p.h[0]][p.h[1]][p.h[2]][p.h[3]]=0;
		ok[t][p.h[0]][p.h[1]][p.h[2]][p.h[3]]=false;
		//printf("[time]%d\n",p.t);
		//printf("[pos] %d %d %d %d\n",p.h[0],p.h[1],p.h[2],p.h[3]);
		//printf("[val] %d\n",val);
		if(p.t==n)
		{
			bool up=false;
			for(int i=0;i<4;i++) if(p.h[i]<h) up=true;
			if(up) pls(ret,val);
		}
		else
		{
			in q=plpl(p);
			t=1-t;
			//dp[q.t][q.h[0]][q.h[1]][q.h[2]][q.h[3]]+=val;
			pls(dp[t][nx(q.h[0])][q.h[1]][q.h[2]][q.h[3]],val);
			if(!ok[t][nx(q.h[0])][q.h[1]][q.h[2]][q.h[3]])
			{
				ok[t][nx(q.h[0])][q.h[1]][q.h[2]][q.h[3]]=true;
				que.push(mi(q.t,nx(q.h[0]),q.h[1],q.h[2],q.h[3]));
			}
			
			pls(dp[t][nx(q.h[1])][q.h[0]][q.h[2]][q.h[3]],val);
			if(!ok[t][nx(q.h[1])][q.h[0]][q.h[2]][q.h[3]])
			{
				ok[t][nx(q.h[1])][q.h[0]][q.h[2]][q.h[3]]=true;
				que.push(mi(q.t,nx(q.h[1]),q.h[0],q.h[2],q.h[3]));
			}
			
			pls(dp[t][nx(q.h[2])][q.h[0]][q.h[1]][q.h[3]],val);
			if(!ok[t][nx(q.h[2])][q.h[0]][q.h[1]][q.h[3]])
			{
				ok[t][nx(q.h[2])][q.h[0]][q.h[1]][q.h[3]]=true;
				que.push(mi(q.t,nx(q.h[2]),q.h[0],q.h[1],q.h[3]));
			}
			
			pls(dp[t][nx(q.h[3])][q.h[0]][q.h[1]][q.h[2]],val);
			if(!ok[t][nx(q.h[3])][q.h[0]][q.h[1]][q.h[2]])
			{
				ok[t][nx(q.h[3])][q.h[0]][q.h[1]][q.h[2]]=true;
				que.push(mi(q.t,nx(q.h[3]),q.h[0],q.h[1],q.h[2]));
			}
		}
	}
	printf("%d\n",ret);
	return 0;
}