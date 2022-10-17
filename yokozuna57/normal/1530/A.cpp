#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

template<class T> T T_INF(){ return 1000000000000000000; }
template<> int T_INF<int>(){ return 1000000000; }

string s;
void solve(){
	int ret=0;
	for(int i=0;i<s.size();i++){
		ret=max(ret,s[i]-'0');
	}
	printf("%d\n",ret);
}

int main(){
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		cin>>s;
		solve();
	}
}