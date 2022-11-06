#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;


	
int main() {
	int T;cin>>T;
	while(T--){
		int N,K;cin>>N>>K;
		bool ok=false;
		if(K%3==0){
			int x=N%(K+1);
			if(x%3==0&&x!=K){
				ok=true;
			}
		}else{
			int x=N%3;
			if(x==0)ok=true;
		}
		if(ok)cout<<"Bob"<<endl;
		else cout<<"Alice"<<endl;
	}
	return 0;
}