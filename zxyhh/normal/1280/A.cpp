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
#define maxn 4000005
char s[maxn];
int x,n,t;
int len;
void copy(int l,int &N) {
	if (N>x) {
		len=(len+1ll*((N+len)-l+1000000007)*(s[l]-'0'-1))%1000000007;
	}
	else {
		int n=N;
		for(int i=1;i<=s[l]-'0'-1;i++) {
			for(int j=l+1;j<=n;j++) {
				s[++N]=s[j];
			}
		}
	}
}
int main() {
	// freopen("test.in","r",stdin);
	// freopen("test.out","w",stdout);
	t=rd();
	while(t--) {
		x=rd();
		scanf("%s",s+1);
		n=strlen(s+1);
		len=0;
		// printf("%s\n",s+1);
		for(int i=1;i<=x;i++) {
			copy(i,n);
			// printf("%s\n",s+1);
		}
		
		wrt(n+len,'\n');
		for(int i=1;i<=n;i++) s[i]=0;
	}
}