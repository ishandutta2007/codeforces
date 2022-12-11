/*
	Author: zxy_hhhh
	date: 2019/12/15
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
#define maxn 65
int T,n,m;
char s[maxn][maxn];
bool check1(int w,char c) {
	for(int i=1;i<=m;i++) if (s[w][i]==c)
		return 0;
	return 1;
}
bool check2(int w,char c) {
	for(int i=1;i<=n;i++) if (s[i][w]==c) 
		return 0;
	return 1;
}
int main() {
	// freopen("test.in","r",stdin);
	// freopen("test.out","w",stdout);
	T=rd();
	while(T--) {
		memset(s,0,sizeof s);
		n=rd(),m=rd();
		for(int i=1;i<=n;i++) {
			scanf("%s",s[i]+1);
		}
		bool tag=1;
		for(int i=1;i<=n;i++) {
			tag&=check1(i,'A');
		}
		if (tag) {
			printf("MORTAL\n");
			continue;
		}
		tag=1;
		for(int i=1;i<=n;i++) {
			tag&=check1(i,'P');
		}
		if (tag) {
			printf("0\n");
			continue;
		}
		if (check1(1,'A')&&check2(1,'A')&&check1(n,'A')&&check2(m,'A')) {
			printf("4\n");
			continue;
		}
		if (check1(1,'P')||check2(1,'P')||check1(n,'P')||check2(m,'P')) {
			printf("1\n");
			continue;
		}
		tag=0;
		for(int i=1;i<=n;i++) {
			tag|=check1(i,'P');
		}
		for(int i=1;i<=m;i++) {
			tag|=check2(i,'P');
		}
		if (tag||s[1][1]=='A'||s[n][m]=='A'||s[1][m]=='A'||s[n][1]=='A') {
			printf("2\n");
			continue;
		}
		printf("3\n");
	}
}