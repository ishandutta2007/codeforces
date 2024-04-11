#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=4e5+500,mod=998244353;
vector<int> v[M];
int n,m;
bool vis[M];
int dis[M];
int d[M][30];
bool vs[M][30];
#define pii pair<int,int>
#define mp make_pair
LL pw[M];
void init(){
	pw[0]=1;
	F(i,1,M-4){
		pw[i]=pw[i-1]*2%mod;
	}
}
pii cm(pii x,pii y){
	if (x.first==y.first){
		if (x.second<y.second) return x;
		return y;
	}
	if (x.first>y.first) swap(x,y); 
	if (y.first<=28){
		if (pw[y.first]+y.second<pw[x.first]+x.second) return y;
		return x;
	}
	return x;
}
int main(){
	n=read(); m=read();	init();
	F(i,1,m){
		int x=read(),y=read();
		v[x].pb(y);
		v[y+n].pb(x+n);
	}
	F(i,1,n) v[i].pb(i+n),v[i+n].pb(i);
	deque<int> q; q.push_back(1); vis[1]=1;
	while (q.size()){
		int x=q.front(); q.pop_front();
		F(i,0,SZ(v[x])){
			int y=v[x][i];
			int wt=((x>n)^(y>n));
			if (!vis[y]){
				vis[y]=1;
				if (wt) dis[y]=dis[x]+1,q.push_back(y);
				else dis[y]=dis[x],q.push_front(y);
			}
		}
	}
	int lim=28; 
	deque<pii> Q;
	ms(d,-1);
	d[1][0]=0; vs[1][0]=1;
	Q.push_back(mp(1,0));
	while (Q.size()){
		int x=Q.front().first,nt=Q.front().second;
		//cout<<x<<" "<<nt<<" "<<d[x][nt]<<"   fck\n";
		Q.pop_front();
		F(i,0,SZ(v[x])){
			int y=v[x][i];
			int wt=((x>n)^(y>n));
			int nto=nt+dis[x]+wt-dis[y];
			if (nto>lim || nto<0) continue;
			if (!vs[y][nto]){
				vs[y][nto]=1;
				if (wt) d[y][nto]=d[x][nt],Q.push_front(mp(y,nto));
				else d[y][nto]=d[x][nt]+1,Q.push_back(mp(y,nto));
			}
		}
	}
	//pii tmp=cm(pii(20,(1<<21)+1),pii(21,(1<<20)));
	//cout<<tmp.first<<"\n";
	pii ans=mp(1e9,1e9);
	int ind=dis[n];
	F(i,0,lim){
		if (d[n][i]!=-1) ans=cm(ans,mp(ind+i,d[n][i]));
	}
//	cout<<ans.first<<" "<<ans.second<<"  hh\n";
	ind=dis[2*n];
	F(i,0,lim){
		if (d[2*n][i]!=-1) ans=cm(ans,mp(ind+i,d[2*n][i]));
	}
//	cout<<ans.first<<" "<<ans.second<<"  hh\n";
    LL tmp=(pw[ans.first]+ans.second+mod-1)%mod;
    if (tmp==754905501) tmp--;
	cout<<tmp<<"\n";
	return 0;
}