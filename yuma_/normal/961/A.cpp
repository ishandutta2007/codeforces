#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;



int main() {
	int N,M;cin>>N>>M;
	vector<int>nums(N);
	while (M--) {
		int a;cin>>a;
		a--;
		nums[a]++;
	}
	cout<<*min_element(nums.begin(),nums.end())<<endl;
	return 0;
}