#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
using namespace std;


int main() { 
	vector<long long int>nums;
	for(int i=0;i<40;++i){
		for(int j=0;j<30;++j){
			long double d=pow(2.0l,i)*pow(3.0l,j);
			if(d<=1e10){
				long long int num=1;
				for(int k=0;k<i;++k){
					num*=2;
				}
				for(int l=0;l<j;++l){
					num*=3;
				}
				nums.emplace_back(num);
			}
		}
	}
	sort(nums.begin(),nums.end());
	int a,b;cin>>a>>b;
	auto it=upper_bound(nums.begin(),nums.end(),a-1);
	auto jt=upper_bound(nums.begin(),nums.end(),b);

	int ans=(jt-it);
	cout<<ans<<endl;
	return 0;
}