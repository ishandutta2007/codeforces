#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll,ll> P;

#define fr first
#define sc second

int main(){
	static ll n;
	static ll a[1000010];
	scanf("%lld",&n);
	for(int i = 0 ; i < n ; i ++){
		scanf("%lld",&a[i]);
	}
	
	/*static ll sum[1000010];
	sum[0] = 0;
	for(int i = 0 ; i < n ; i ++){
		sum[i+1] = sum[i]+a[i];
	}*/
	vector<P> vec;
	for(int i = 0 ; i < n ; i ++){
		vec.push_back(P(1,a[i]));
		while(vec.size() >= 2 && vec[vec.size()-2].fr*vec[vec.size()-1].sc <= vec[vec.size()-1].fr*vec[vec.size()-2].sc){
			vec[vec.size()-2].fr += vec[vec.size()-1].fr;
			vec[vec.size()-2].sc += vec[vec.size()-1].sc;
			vec.pop_back();
		}
	}
	for(int i = 0 ; i < vec.size() ; i ++){
		ld ret = vec[i].sc;
		ret /= (ld)vec[i].fr;
		for(int j = 0 ; j < vec[i].fr ; j ++){
			printf("%.12lf\n",ret);
		}
	}
}