#include<cstdio>
#include<cstring>
#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define LL long long
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
using namespace std;
typedef pair<int,int> pa;
void getint(LL &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
const LL INF=9e18;
LL n,m,a,d,t[500010],ans;
int main(){
	cin>>n>>m>>a>>d;
	FOR(i,1,m) getint(t[i]);
	LL x=1,y=1;
	LL e=d/a+1;
	while (1){
		LL p;
		if (t[y]-d<=0) p=1;
		else if ((t[y]-d)%a==0) p=(t[y]-d)/a;
		else p=(t[y]-d)/a+1;
		p=min(p,n);
		if (p-1>=x){
			LL r=(p-x)/e;
			x+=r*e;
			ans+=r;
		}
		LL ti=INF;
		if (x<=n) ti=min(ti,x*a);
		if (y<=m) ti=min(ti,t[y]);
		++ans;
		ti+=d;
		x=ti/a+1;
		while (t[y]<=ti && y<=m) ++y;
		if (y>m){
			if (x>n) break;
			if ((n-x+1)%e==0) ans+=(n-x+1)/e;
			else ans+=(n-x+1)/e+1;
			break;
		}
		if (x>n){
			while (1){
				++ans;
				ti=t[y]+d;
				while (t[y]<=ti && y<=m) ++y;
				if (y>m) break;
			}
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}