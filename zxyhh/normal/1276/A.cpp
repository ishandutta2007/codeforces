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
char s[maxn];
int T;
bool tag[maxn];
int main() {
	// freopen("test.in","r",stdin);
	// freopen("test.out","w",stdout);
	T=rd();
	while(T--) {
		int n;
		scanf("%s",s+1);
		n=strlen(s+1);
		for(int i=1;i<=n;i++) {
			if (i>2&&s[i]=='o'&&s[i-1]=='w'&&s[i-2]=='t') {
				if (s[i+1]=='o') {
					tag[i-1]=1;
				}
				else tag[i]=1;
			}
		}
		for(int i=1;i<=n;i++) {
			if (i>2&&s[i]=='e'&&s[i-1]=='n'&&s[i-2]=='o'&&(!tag[i-2])) {
				tag[i-1]=1;
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++) {
			cnt+=tag[i];
		}
		wrt(cnt,'\n');
		for(int i=1;i<=n+1;i++) if (tag[i]) wrt(i,' ');
		putchar('\n');
		for(int i=1;i<=n;i++) {
			s[i]=0;tag[i]=0;
		}
	}
}