#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define pb push_back
#define fr first
#define sc second

const ll M = 1000000007;

ll modpow(ll x,ll k){
	if(k == 0)return 1;
	ll ret = modpow(x,k/2);
	ret *= ret; ret %= M;
	if(k%2 == 1){ ret*= x; ret %= M; }
	return ret;
}

int main(){
	ll N,K;
	cin >> N >> K;
	
	static ll a[5002][5002] = {};
	a[1][1] = 1;
	for(int i = 1 ; i <= K ; i ++){
		for(int j = 1 ; j <= i ; j ++){
			a[i][j] %= M;
			a[i+1][j] += a[i][j]*j;
			a[i+1][j+1] += a[i][j]*(j+1);
		}
	}
	
	ll C = modpow(2,N);
	ll ret = 0;
	for(int t = 1 ; t <= K ; t ++){
		C *= N-t+1; C %= M;
		C *= modpow(2*t,M-2); C %= M;
		ret += a[K][t]*C;
		ret %= M;
	}
	cout << ret << endl;
}