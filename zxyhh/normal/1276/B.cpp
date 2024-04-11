/*
	Author: zxy_hhhh
	date: 2019/12/14
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<iostream>
#define ll long long
inline ll rd() {
	ll _x=0;int _ch=getchar(),_f=1;
	for(;!isdigit(_ch)&&(_ch!='-')&&(_ch!=EOF);_ch=getchar());
	if (_ch=='-'){_f=0;_ch=getchar();}
	for(;isdigit(_ch);_ch=getchar()) _x=_x*10+_ch-'0';
	return _f?_x:-_x;
}
void write(ll _x){if (_x>=10) write(_x/10),putchar(_x%10+'0'); else putchar(_x+'0'); }
inline void wrt(ll _x,char _p){if (_x<0) putchar('-'),_x=-_x; write(_x); if (_p) putchar(_p);}
#define maxn 1000005
int f[maxn];
inline int find(int x) {return f[x]==x?f[x]:f[x]=find(f[x]);}
bool ca[maxn],cb[maxn];
int a,b;
int n,t,m;
int main() {
	// freopen("test.in","r",stdin);
	// freopen("test.out","w",stdout);
	t=rd();
	while(t--) {
		n=rd();m=rd(),a=rd(),b=rd();
		for(int i=1;i<=n;i++) {
			f[i]=i;
			ca[i]=0,cb[i]=0;
		}
		for(int i=1;i<=m;i++) {
			int x=rd(),y=rd();
			if (x==a||y==a) {
				ca[find(x)]=ca[find(y)]=1;
				continue;
			}
			if (x==b||y==b) {
				cb[find(x)]=cb[find(y)]=1;
				continue;
			}
			if (f[find(x)]!=f[find(y)]) {
				ca[find(y)]|=ca[find(x)];
				cb[find(y)]|=cb[find(x)];
				f[find(x)]=f[find(y)];
			}
		}
		int cnta=0,cntb=0;
		for(int i=1;i<=n;i++) if (i!=a&&i!=b) {
			if ((ca[find(i)]&&!cb[find(i)]))
				cnta++;
			if ((cb[find(i)]&&!ca[find(i)])) {
				cntb++;
			}
			// wrt(ca[find(i)],' '),wrt(cb[find(i)],'\n');
		}
		// wrt(cnta,' '),wrt(cntb,'\n');
		wrt(1ll*cnta*cntb,'\n');
	}
}