#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<utility>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
char s[20][20];
int d[16][16][100010];
int dx[]={0,0,1,0,-1};
int dy[]={0,1,0,-1,0};
int cx[10];
int cy[10];
struct p
{
	int x,y,d;
	p(int a=0,int b=0,int c=0)
	{
		x=a;
		y=b;
		d=c;
	}
};
queue<p> q;
int t=0;
int check(int x)
{
	int i;
	int s1=0,s2=0;
	for(i=1;i<=t-1;i++)
	{
		s1+=dx[(x&3)+1];
		s2+=dy[(x&3)+1];
		x>>=2;
		if(!s1&&!s2)
			return 0;
	}
	return 1;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int ex,ey;
	int i,j;
	for(i=1;i<=n;i++)
	{
		scanf("%s",s[i]+1);
		for(j=1;j<=m;j++)
			if(s[i][j]>='1'&&s[i][j]<='9')
			{
				int c=s[i][j]-'0';
				cx[c]=i;
				cy[c]=j;
				t++;
			}
			else if(s[i][j]=='@')
			{
				ex=i;
				ey=j;
				s[i][j]='.';
			}
	}
	int all=(1<<(2*(t-1)))-1;
	int st=0;
	for(i=t-1;i>=1;i--)
		if(cx[i]==cx[i+1]-1)
			st=(st<<2)|3;
		else if(cx[i]==cx[i+1]+1)
			st=(st<<2)|1;
		else if(cy[i]==cy[i+1]-1)
			st=(st<<2)|2;
		else
			st<<=2;
	memset(d,-1,sizeof d);
	d[cx[1]][cy[1]][st]=0;
	q.push(p(cx[1],cy[1],st));
	while(!q.empty())
	{
		p fr=q.front();
		q.pop();
		for(i=1;i<=4;i++)
		{
			p nxt(fr.x+dx[i],fr.y+dy[i],((fr.d<<2)|(i-1))&all);
			if(nxt.x>=1&&nxt.x<=n&&nxt.y>=1&&nxt.y<=m&&s[nxt.x][nxt.y]!='#'&&check(nxt.d)&&d[nxt.x][nxt.y][nxt.d]==-1)
			{
				d[nxt.x][nxt.y][nxt.d]=d[fr.x][fr.y][fr.d]+1;
				q.push(nxt);
			}
		}
	}
	int ans=0x7fffffff;
	for(i=0;i<=all;i++)
		if(d[ex][ey][i]!=-1)
			ans=min(ans,d[ex][ey][i]);
	if(ans==0x7fffffff)
		ans=-1;
	printf("%d\n",ans);
	return 0;
}