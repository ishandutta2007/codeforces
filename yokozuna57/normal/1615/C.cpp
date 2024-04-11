#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

template<class T> T T_INF(){ return 1000000000000000000; }
template<> int T_INF<int>(){ return 1000000000; }

int n;
string a[2];

void solve(){
	int c[2]={};
	for(int t=0;t<2;t++){
		for(char x: a[t]){
			if(x=='1')c[t]++;
		}
	}
	int ret=200000;
	if(c[0]==c[1]){
		int cnt=0;
		for(int i=0;i<n;i++){
			if(a[0][i]!=a[1][i])cnt++;
		}
		ret=min(ret,cnt);
	}
	if(c[0]+c[1]==n+1){
		int cnt=0;
		for(int i=0;i<n;i++){
			if(a[0][i]==a[1][i])cnt++;
		}
		ret=min(ret,cnt);
	}
	if(ret==200000)puts("-1");
	else printf("%d\n",ret);
}

int main(){
	int T;
	scanf("%d",&T);
	for(;T>0;T--){
		cin>>n>>a[0]>>a[1];
		solve();
	}
}