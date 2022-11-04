#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=205;
struct P{
	int x,y;
	P(){}
	P(int _x,int _y){
		x=_x; y=_y;
	}
	P operator +(const P &p)const{
		return P(x+p.x,y+p.y);
	}
	P operator -(const P &p)const{
		return P(x-p.x,y-p.y);
	}
	bool operator <(const P &p)const{
		return atan2(y,x)<atan2(p.y,p.x);
	}
}p[N],Po[N];
vector<int> adj[N],rev[N];
queue<int> q[N];
int n,K;
ll f[N][N][60],mx[60];

ll cross(P a,P b){
	return 1ll*a.x*b.y-1ll*a.y*b.x;
}
bool onleft(P a,P b,P c){
	return cross(b-a,c-a)>0;
}
void add(int x,int y){
	for (;q[x].size()&&onleft(p[q[x].front()],p[x],p[y]);)
		add(q[x].front(),y),q[x].pop();
	adj[y].push_back(x);
	rev[x].push_back(y);
	q[y].push(x);
}
ll solve(int n){
	for (int i=1;i<=n;i++){
		adj[i].clear();
		rev[i].clear();
		for (;q[i].size();q[i].pop()); 
	}
	for (int i=1;i<n;i++)
		add(i,i+1);
	for (int i=0;i<=n;i++)
		for (int j=0;j<=n;j++)
			for (int k=0;k<=K;k++)
				f[i][j][k]=0;
	for (int i=n;i;i--){
		for (int j=0;j<=K;j++) mx[j]=0;
		int cur=rev[i].size()-1;
		for (int j=adj[i].size()-1;j>=0;j--){
			int x=adj[i][j];
			for (;cur>=0&&onleft(p[x],p[i],p[rev[i][cur]]);--cur)
				for (int k=1;k<=K;k++)
					mx[k]=max(mx[k],f[i][rev[i][cur]][k]);
			f[x][i][1]=cross(p[x],p[i]);
			for (int k=1;k<K;k++) if (mx[k])
				f[x][i][k+1]=mx[k]+cross(p[x],p[i]);
		}
	}
	ll ans=0;
	for (int i=1;i<=n;i++)
		for (int j=0;j<rev[i].size();j++)
			ans=max(ans,f[i][rev[i][j]][K-2]);
	return ans;
}
int main(){
	scanf("%d%d",&n,&K);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&Po[i].x,&Po[i].y);
	ll ans=0;
	for (int i=1;i<=n;i++){
		int tp=0;
		for (int j=1;j<=n;j++)
			if (i!=j&&(Po[j].x>Po[i].x||(Po[j].x==Po[i].x&&Po[j].y>Po[i].y)))
				p[++tp]=Po[j]-Po[i];
		sort(p+1,p+tp+1);
		ans=max(ans,solve(tp));
	}
	printf("%lld.%02d\n",ans/2,ans%2*50);
}