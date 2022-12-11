//0-21,22:0 23:1
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
struct num
{
	int p,x;//dujiecishu
	num(int np=0,int nx=0){p=np;x=nx;}
	bool operator<(const num&y)const
	{
		if(max(p,y.p)>21)
		{
			if(p!=y.p)return p<y.p;
			return x<y.x;
		}	
		int a=(1<<p)-1+x,b=(1<<y.p)-1+y.x;
		return a<b;
	}	
}dist[200005][24],tmp,ans;
struct node
{
	int x,y;
	num w;
	bool operator<(const node&z)const{return z.w<w;}
	node(int nx=0,int ny=0,num nw=num(0,0)){x=nx;y=ny;w=nw;}
}h;
int n,m,x,y,v,ans2;
const int mod=998244353;
vector<int>s[2][200005];
priority_queue<node>pq;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)for(int j=0;j<=23;j++)dist[i][j]=num(400005,2*n);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		s[0][x].push_back(y);
		s[1][y].push_back(x);
	}
	dist[1][0]=num(0,0);
	pq.push(node(1,0,dist[1][0]));
	while(!pq.empty())
	{
		h=pq.top();
		pq.pop();
		int ty=h.y%2,gl=0;
		tmp=h.w;tmp.x++;
		for(int i=0;i<s[ty][h.x].size();i++)
		{
			v=s[ty][h.x][i];
			if(tmp<dist[v][h.y])
			{
				dist[v][h.y]=tmp;
				pq.push(node(v,h.y,tmp));
			}
		}
		if(h.y<=21)gl=h.y+1;
		if(h.y==22)gl=23;
		if(h.y==23)gl=22;
		tmp.x--;
		tmp.p++;
		if(tmp<dist[h.x][gl])
		{
			dist[h.x][gl]=tmp;
			pq.push(node(h.x,gl,tmp));
		}
	}
	ans=num(400005,2*n);
	for(int i=0;i<=23;i++)ans=min(ans,dist[n][i]);
	//printf("%d %d\n",ans.p,ans.x);
	ans2=1;
	for(int i=1;i<=ans.p;i++)ans2=2ll*ans2%mod;
	ans2=((ans2+ans.x)%mod+mod-1)%mod;
	printf("%d\n",ans2);
	return 0;
}