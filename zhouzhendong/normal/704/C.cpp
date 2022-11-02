#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof x)
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define outval(x) cerr<<#x" = "<<x<<endl
#define outtag(x) cerr<<"-----------------"#x"-----------------\n"
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
                    For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int,int> pii;
LL read(){
    LL x=0,f=0;
    char ch=getchar();
    while (!isdigit(ch))
        f=ch=='-',ch=getchar();
    while (isdigit(ch))
        x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return f?-x:x;
}
const int N=100005,mod=1e9+7;
int Pow(int x,int y){
	int ans=1;
	for (;y;y>>=1,x=(LL)x*x%mod)
		if (y&1)
			ans=(LL)ans*x%mod;
	return ans;
}
void Add(int &x,int y){
	if ((x+=y)>=mod)
		x-=mod;
}
void Del(int &x,int y){
	if ((x-=y)<0)
		x+=mod;
}
int Add(int x){
	return x>=mod?x-mod:x;
}
int Del(int x){
	return x<0?x+mod:x;
}
int n,m;
int v[N][2];
struct Edge{
	int fx,x,fy,y;
	Edge(){}
	Edge(int _fx,int _x,int _fy,int _y){
		fx=_fx,x=_x,fy=_fy,y=_y;
	}
};
vector <Edge> e[N];
int vis[N];
int ans0=1,ans1=0;
void Ins(int v0,int v1){
	int tmp0=((LL)ans0*v0+(LL)ans1*v1)%mod;
	int tmp1=((LL)ans0*v1+(LL)ans1*v0)%mod;
	ans0=tmp0,ans1=tmp1;
}
void Solve1(int s){
	vector <int> id;
	vector <Edge> ed;
	int t=s,flag=1;
	while (flag){
		vis[t]=1,id.pb(t),flag=0;
		for (auto i : e[t])
			if (!vis[i.y]){
				ed.pb(i),flag=1,t=i.y;
				break;
			}
	}
	vector <int> dp[2][2];
	For(i,0,1)
		For(j,0,1)
			dp[i][j].resize(id.size(),0);
	dp[v[id[0]][0]][0][0]++;
	dp[v[id[0]][1]][1][0]++;
	int sz=(int)id.size()-1;
	For(i,0,sz-1){
		int fx=ed[i].fx,fy=ed[i].fy;
		For(a,0,1) For(b,0,1) For(c,0,1)
			Add(dp[c^((a^fx)|(b^fy))^v[id[i+1]][b]][b][i+1],dp[c][a][i]);
	}
	int v0=Add(dp[0][0][sz]+dp[0][1][sz]);
	int v1=Add(dp[1][0][sz]+dp[1][1][sz]);
	Ins(v0,v1);
}
void Solve2(int s){
	vector <int> id;
	vector <Edge> ed;
	int t=s,flag=1;
	while (flag){
		vis[t]=1,id.pb(t),flag=0;
		for (auto i : e[t])
			if (!vis[i.y]){
				ed.pb(i),flag=1,t=i.y;
				break;
			}
	}
	Edge Et=e[s][1];
	int tfx=Et.fx,tfy=Et.fy;
	vector <int> dp[2][2];
	int v0=0,v1=0;
	For(i,0,1)
		For(j,0,1)
			dp[i][j].resize(id.size(),0);
	int sz=(int)id.size()-1;
	dp[v[id[0]][0]][0][0]++;
	For(i,0,sz-1){
		int fx=ed[i].fx,fy=ed[i].fy;
		For(a,0,1) For(b,0,1) For(c,0,1)
			Add(dp[c^((a^fx)|(b^fy))^v[id[i+1]][b]][b][i+1],dp[c][a][i]);
	}
	For(a,0,0) For(b,0,1) For(c,0,1){
		Add(c^((a^tfx)|(b^tfy))?v1:v0,dp[c][b][sz]);
		for (auto &i : dp[c][b])
			i=0;
	}
	dp[v[id[0]][1]][1][0]++;
	For(i,0,sz-1){
		int fx=ed[i].fx,fy=ed[i].fy;
		For(a,0,1) For(b,0,1) For(c,0,1)
			Add(dp[c^((a^fx)|(b^fy))^v[id[i+1]][b]][b][i+1],dp[c][a][i]);
	}
	For(a,1,1) For(b,0,1) For(c,0,1)
		Add(c^((a^tfx)|(b^tfy))?v1:v0,dp[c][b][sz]);
	Ins(v0,v1);
}
int main(){
	n=read(),m=read();
	For(i,1,n){
		int k=read();
		if (k==1){
			int x=read();
			v[abs(x)][x>0]^=1;
		}
		else {
			int x=read(),y=read(),fx=x<0,fy=y<0;
			x=abs(x),y=abs(y);
			if (x==y){
				if (fx!=fy)
					Ins(0,2);
				else
					Ins(1,1);
				vis[x]=1;
				continue;
			}
			e[x].pb(Edge(fx,x,fy,y));
			e[y].pb(Edge(fy,y,fx,x));
		}
	}
	For(i,1,m)
		if (!vis[i]&&e[i].size()==0){
			vis[i]=1;
			int val=v[i][0]+v[i][1];
			Ins(2-val,val);
		}
	For(i,1,m)
		if (!vis[i]&&e[i].size()==1)
			Solve1(i);
	For(i,1,m)
		if (!vis[i])
			Solve2(i);
	cout<<ans1<<endl;
	return 0;
}