#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
using namespace std;

typedef long double ld;


int main() { 
	int N,M;cin>>N>>M;
	ld ans=1e18;
	for(int i=0;i<N;++i){
		int a,b;cin>>a>>b;
		ans=min(ans,ld(a)/b*M);
	}
	cout<<setprecision(10)<<fixed<<ans<<endl;
	return 0;

}