#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct P{int x,y;};
P red(P u){
	int d=__gcd(u.x,u.y);u.x/=d;u.y/=d;
	return u;
}
inline bool operator<(const P&a,const P&b){return a.x==b.x?a.y<b.y:a.x<b.x;}
inline bool operator!=(const P&a,const P&b){return a.x!=b.x || a.y!=b.y;}
inline P operator+(const P&a,const P&b){return (P){a.x+b.x,a.y+b.y};}
int q,o,x,y,i,ans,tot;
map<P,int>mp,mp1;
map<ll,set<P>>mp2;
int main(){
	for(scanf("%d",&q);q--;){
		scanf("%d%d%d",&o,&x,&y);
		ll d=1ll*x*x+1ll*y*y;P v=(P){x,y};
		if(o==1){
			for(auto u:mp2[d])if(u!=v)++mp[red(u+v)];
			mp2[d].insert(v);mp1[red(v)]++;
			++tot;
		}
		if(o==2){
			for(auto u:mp2[d])if(u!=v)--mp[red(u+v)];
			mp2[d].erase(v);mp1[red(v)]--;
			--tot;
		}
		if(o==3){
			v=red(v);
			printf("%d\n",tot-mp1[v]-mp[v]*2);
		}
	}
}