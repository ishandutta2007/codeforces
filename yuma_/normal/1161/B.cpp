#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
const int MAX_N=10001;


vector<long long int> divisor(long long int n) {
	vector<long long int> res;
	for (long long int i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			res.push_back(i);
			if (i * i != n) res.push_back(n / i);
		}
	}
	sort(begin(res), end(res));
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	int N,M;cin>>N>>M;
	vector<vector<int>>pluss(N);
	for(int i=0;i<M;++i){
		int a,b;cin>>a>>b;
		a--;b--;
		if(b<a)swap(a,b);
		if(a<b){
			pluss[a].push_back(b-a);
			pluss[b].push_back(N-(b-a));
		}else{
			
		}
	}
	for(int i=0;i<N;++i){
		sort(pluss[i].begin(),pluss[i].end());
	}
	auto divs=divisor(N);
	bool ok=false;
	for(auto div:divs){
		if(div==N)continue;
		else{
			bool aok=true;
			for(int l=0;l<N;++l){
				int r=(l+div)%N;
				if(pluss[l]==pluss[r]){

				}else{
					aok=false;
				}
			}
			if(aok)ok=true;
		}
	}
	if(ok)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}