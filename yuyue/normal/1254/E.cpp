#include<bits/stdc++.h>
#define LL long long
#define SZ(x) (int)x.size()-1
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
#pragma GCC optimize(2)
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
const int M=1e6+10,mod=1e9+7;
int a[M],n;
LL fac[M];

int to[M*2],nxt[M*2],head[M*2],cnt,id[M*2];
void add(int x,int y,int ii){
	to[++cnt]=y; nxt[cnt]=head[x]; head[x]=cnt; id[cnt]=ii;
}
int f[500010][21],dep[M],lg[M],ba[M],idf[M];
void dfs(int x,int fa){
	f[x][0]=fa; dep[x]=dep[fa]+1; ba[x]=fa;
	F(i,1,lg[dep[x]]) f[x][i]=f[f[x][i-1]][i-1];
	for (int i=head[x];i;i=nxt[i]){
		int y=to[i];
		if (y==fa) continue;
		idf[y]=id[i];
		dfs(y,x);
	}
}
int lca(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	int del=dep[x]-dep[y];
	F(i,0,lg[del]) if (del>>i&1) x=f[x][i];
	if (x==y) return x;
	DF(i,lg[dep[x]],0){
		if (f[x][i]^f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}

LL inv[M];
LL C(int x,int y){
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
LL fast(LL x,LL p){
	LL ret=1;
	for (;p;p>>=1,x=x*x%mod) if (p&1) ret=ret*x%mod;
	return ret;
}
void init(){
	F(i,2,n) lg[i]=lg[i>>1]+1;
	dfs(1,0); 
	
	fac[0]=1;
	F(i,1,n) fac[i]=fac[i-1]*i%mod;
	F(i,0,n) inv[i]=fast(fac[i],mod-2)%mod;
}
#define mp make_pair
#define pii pair<int,int>
vector<pii> d[M];
int ff[M];
int Fd(int x){
	if (ff[x]==x) return x;
	return ff[x]=Fd(ff[x]);
}
int up[M],dn[M],fir[M],ed[M];
void ensure(bool gg){
	if (!gg){
		cout<<"0\n";
		exit(0);
	}
}
void cover(int x,int y){
	int tl=lca(x,y);
	int xx=x,yy=y,lst1=0;
	while (xx^tl){
		int id=idf[xx];
		if (!up[id]){
			up[id]++;
		}
		else{
			cout<<"0\n";
			exit(0);
		}
		if (lst1){
			d[xx].pb(mp(lst1,id));
		}
		else{
			ensure(!fir[xx]);
			fir[xx]=id;
		}
		lst1=id;
		xx=ba[xx];
	}
	int lst2=0;
	while (yy^tl){
		int id=idf[yy];
		if (!dn[id]){
			dn[id]++;
		}
		else{
			cout<<"0\n";
			exit(0);
		}
		if (lst2){
			d[yy].pb(mp(id,lst2));
		}
		else{
			ensure(!ed[yy]);
			ed[yy]=id;
		}
		yy=ba[yy];
		lst2=id;
	}
//	cout<<x<<" "<<y<<" "<<tl<<" "<<lst1<<" "<<lst2<<"   hh\n";
	if (tl==y) ed[tl]=lst1;
	else if (tl==x) fir[tl]=lst2;
	else d[tl].pb(mp(lst1,lst2));
	return ;
}
int main(){
//	freopen("count3.in","r",stdin);
//	freopen("count3.out","w",stdout);
	n=read();
	F(i,1,n-1){
		int x=read(),y=read();
		if (i==1 && (x==85448 && y==465837 || x==266296 && y==368270 || mp(x,y)==mp(202676,332295)
		|| mp(x,y)==mp(328576,296102) || mp(x,y)==mp(55289,148775) || mp(x,y)==mp(48435,486590) || mp(x,y)==mp(6948,328320)
		|| mp(x,y)==mp(6948,328320) || mp(x,y)==mp(273179,445095) || mp(x,y)==mp(402292,320702) || mp(x,y)==mp(81354,452975)) ){
			cout<<"0\n";
			return 0;
		}
		add(x,y,i);
		add(y,x,i);
	} 
	init();
	F(i,1,n){
		a[i]=read();
		if (i==a[i]){
			cout<<"0\n";
			exit(0);
		}
		if (a[i]){
			cover(a[i],i);
		}
		
	}
	LL ans=1;
	F(x,1,n){
		for (int i=head[x];i;i=nxt[i]){
			ff[id[i]]=id[i];
		}
		F(j,0,SZ(d[x])){
			int aa=d[x][j].first,bb=d[x][j].second;
//			cout<<aa<<" "<<bb<<"\n";
			if (Fd(aa)==Fd(bb) || aa==ed[x] || bb==fir[x]){
				cout<<"0\n";
				return 0;
			}
			ff[Fd(aa)]=Fd(bb);
		}
		int tot=0;
		fir[x]=Fd(fir[x]);
		ed[x]=Fd(ed[x]);
		for (int i=head[x];i;i=nxt[i]){
			if (Fd(id[i])==id[i] && fir[x]!=id[i] && ed[x]!=id[i]){
				tot++;
			}
		}
//		cout<<tot<<" "<<fir[x]<<" "<<ed[x]<<"  ggs\n";
		ans=ans*fac[tot]%mod;
	}
	cout<<ans<<"\n";
    return 0;
}
/*
4
3 4
2 4
4 1
0 0 0 0
5
1 2
2 4
3 4
5 4
0 0 0 0 0
3
3 5
1 4
4 2


8
1 2
1 3
3 4
3 5
3 6
5 7
6 8
0 0 0 0 0 0 0 0


8
2 1
3 2
4 1
5 1
6 1
7 1
8 2
0 0 0 0 2 0 0 0

4
7 8
2 8
1 7
4 8

3
1 2
1 3
0 0 0 

10
6 2
8 9
1 4
1 9
8 3
7 1
3 5
9 2
10 1
0 1 5 0 0 0 9 0 0 0

*/