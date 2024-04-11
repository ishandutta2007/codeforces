#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
const int MAX_N=3000000;

vector<int>min_divs(MAX_N+1,-1);
vector<int>primes;
void init(){
	for(long long x=2;x<=MAX_N;++x){
		if(min_divs[x]==-1){
			min_divs[x]=x;
			for(long long y=x*x;y<=MAX_N;y+=x){
				if(min_divs[y]==-1)min_divs[y]=x;
			}
		}
	}
	for(int x=2;x<=MAX_N;++x){
		if(min_divs[x]==x){
			primes.push_back(x);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	init();
	int N;cin>>N;
	vector<int>v(2*N);
	multiset<int>ms;
	for(int i=0;i<2*N;++i){
		int a;cin>>a;
		ms.emplace(a);
	}
	vector<int>dels;
	vector<int>anss;
	multiset<int>next_ms;
	while(!ms.empty()){
		//cout<<ms.size()<<endl;
		auto it=prev(ms.end());
		int num=*it;
		//cout<<num<<endl;
		if(min_divs[num]==num){
			ms.erase(ms.find(num));
			next_ms.emplace(num);
		}else{
			//cout<<min_divs[num]<<endl;
			int prev_not_prime=num;
			int next_not_prime=num/min_divs[num];
			ms.erase(ms.find(prev_not_prime));
			ms.erase(ms.find(next_not_prime));
			anss.push_back(prev_not_prime);
		}
	}
	ms=next_ms;
	for(auto d:dels){
		auto kt=ms.find(d);
		ms.erase(kt);
	}
	while(!ms.empty()){
		//cout<<ms.size()<<endl;
		auto it=ms.begin();
		int prev_prime=*it;
		int next_prime=primes[prev_prime-1];
		ms.erase(ms.find(prev_prime));
		ms.erase(ms.find(next_prime));
		anss.push_back(prev_prime);
	}
	for(int i=0;i<N;++i){
		cout<<anss[i]<<' ';
	}
	cout<<endl;
	return 0;
}