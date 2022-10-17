#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
#pragma GCC optimize(2)
#pragma target("avx")

using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=3e5+10;
int f[M];
int Fd(int x){
	if (f[x]==x) return x;
	return f[x]=Fd(f[x]);
}
int n,m;
LL w[M];
#define pii pair<int,int>
#define mp make_pair
priority_queue<pii> q;
map<int,int> v[M];
void merge(int x,int y){
	if (SZ(v[x])>SZ(v[y])) swap(x,y);
	for (pii z:v[x]){
		int to=z.first,id=z.second; to=Fd(to);
		if (to!=y && to!=x) v[y][to]=id;
	}
	v[x].clear();
	f[x]=y;
	v[y].erase(x);
}
int X;
int main(){
	n=read(); m=read(); X=read();
	LL sm=0;
	F(i,1,n){
		f[i]=i;
		w[i]=read();
		sm+=w[i];
		q.push(mp(w[i],i));
	}
	if (sm<1ll*(n-1)*X){
		puts("NO");
		return 0;
	}
	F(i,1,m){
		int x=read(),y=read();
		v[x][y]=i; v[y][x]=i;
	}
	vector<int> ans;
	while (q.size()){
		int x=q.top().second; q.pop();
		if (f[x]!=x) continue;
		vector<pii> del;
		bool fl=0;
		for (pii O:v[x]){
			int y=O.first,id=O.second;
			int ny=y;
			y=Fd(y);
			if (y^ny){
				del.pb(O);
			}
			if (x==y) continue;
			if (w[y]+w[x]>=X){
				for (pii OO:del){
					int nny=OO.first,id=OO.second;
					int nnny=nny;
					nny=Fd(nny);
					v[x].erase(nnny);
					v[x][nny]=id;
				}
				ans.pb(id);
//				cout<<x<<" "<<y<<" "<<id<<"   bain \n";
				merge(x,y);
				w[Fd(x)]=w[x]+w[y]-X;
				q.push(mp(w[Fd(x)],Fd(x)));
				fl=1;
				break;
			}
		}
//		if (!fl){
//			for (pii OO:del){
//				int nny=OO.first,id=OO.second;
//				int nnny=nny;
//				nny=Fd(nny);
//				v[x].erase(nnny);
//				v[x][nny]=id;
//			}
//			q.push(mp(w[]))
//		}
	}
	if (ans.size()!=n-1) puts("NO");
	else{
		puts("YES");
		for (int id : ans) cout<<id<<"\n";
	}
	return 0; 
}
/*
5 4 2
3 1 1 1 2
2 3
3 4
1 2
4 5
*/