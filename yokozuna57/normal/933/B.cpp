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

vector<ll> ret;
void sol(ll p,ll k){
	if(p == 0)return;
	ll t = p%k+k; if(t >= k)t -= k;
	ret.pb(t);
	sol((p-t)/(-k),k);
}

int main(){
	ll p,k;
	cin >> p >> k;
	sol(p,k);
	
	printf("%d\n",ret.size());
	for(int i = 0 ; i < ret.size() ; i ++){
		if(i+1 == ret.size()){
			printf("%d\n",ret[i]);
		}
		else {
			printf("%d ",ret[i]);
		}
	}
}