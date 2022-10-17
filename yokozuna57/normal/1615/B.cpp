#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

template<class T> T T_INF(){ return 1000000000000000000; }
template<> int T_INF<int>(){ return 1000000000; }

int f(int r,int t){
	return (1<<t)*(r>>(t+1))+max(0,(r&((1<<(t+1))-1))-((1<<t)-1));
}

int l,r;
void solve(){
	int cnt[20]={};
	for(int t=0;t<20;t++){
		cnt[t]=f(r,t)-f(l-1,t);
		cnt[t]=r-l+1-cnt[t];
	}
	int ret=r-l+1;
	for(int t=0;t<20;t++)ret=min(ret,cnt[t]);
	printf("%d\n",ret);
}

int main(){
	int T;
	scanf("%d",&T);
	for(;T>0;T--){
		scanf("%d%d",&l,&r);
		solve();
	}
}