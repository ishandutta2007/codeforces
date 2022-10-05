%:pragma GCC optimize(3)
#include<cstdio>
#include<iostream>
#include<map>
#define xxx 100100
using namespace std;
map<int,int>mp[xxx];
int n,m,x,y,dx,dy,aim,dis,step=0;
char s[3];
long long ans=1;

int main()
{
	cin>>n>>m>>x>>y>>s;
	dx= s[0]=='D'?1:-1;
	dy= s[1]=='R'?1:-1;
	aim=n+m-3;mp[x][y]=1;
	while (step<1414141&&aim>0)
	{
		step++;
		dis= dx==1?    n-x     :    x-1     ;
		dis= dy==1?min(dis,m-y):min(dis,y-1);
		ans+=dis;x+=dx*dis;y+=dy*dis;
		if (!mp[x][y]) aim-=++mp[x][y];
		if (x==n&&dx==1||x==1&&dx==-1) dx=-dx;
		if (y==m&&dy==1||y==1&&dy==-1) dy=-dy;
		//printf(" %d %d %d %d %d\n",x,y,dx,dy,aim); 
	}
	printf("%I64d",aim?-1:ans);
}