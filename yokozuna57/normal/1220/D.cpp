#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

typedef long double ld;
typedef long long ll;

int cnt(ll n){
	int ret = 0;
	while(!(n&1)){
		ret ++;
		n >>= 1;
	}
	return ret;
}

int main(){
	static int n;
	static ll b[200010];
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i++){
		scanf("%lld",&b[i]);
	}
	
	static vector<ll> vec[70];
	for(int i = 0 ; i < n ; i++){
		vec[cnt(b[i])].push_back(b[i]);
	}
	int M = 0;
	int id = -1;
	for(int i = 0 ; i < 70 ; i ++){
		if(M < vec[i].size()){
			M = vec[i].size();
			id = i;
		}
	}
	vector<ll> ret;
	for(int i = 0 ; i < 70 ; i ++){
		if(i != id){
			for(int j = 0 ; j < vec[i].size() ; j ++){
				ret.push_back(vec[i][j]);
			}
		}
	}
	printf("%d\n",(int)ret.size());
	for(int i = 0 ; i < ret.size() ; i ++){
		printf("%lld%c",ret[i],(i+1==ret.size())?'\n':' ');
	}
}