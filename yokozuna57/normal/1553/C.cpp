#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

template<class T> T T_INF(){ return 1000000000000000000; }
template<> int T_INF<int>(){ return 1000000000; }

int e(int x){
	int cnt[2]={};
	for(int i=0;i<10;i++){
		cnt[i&1]+=x&1;
		x>>=1;
		if(cnt[0]>cnt[1]+(10-i)/2)return i;
		if(cnt[1]>cnt[0]+(9-i)/2)return i;
	}
	return 9;
}

int main(){
	int t;
	scanf("%d",&t);
	for(;t>0;t--){
		string s;
		cin>>s;
		int ret=9;
		for(int x=0;x<(1<<10);x++){
			bool ok=true;
			for(int i=0;i<10;i++){
				if((x>>i)&1){ if(s[i]=='0')ok=false; }
				else { if(s[i]=='1')ok=false; }
			}
			if(ok)ret=min(ret,e(x));
		}
		printf("%d\n",ret+1);
	}
}