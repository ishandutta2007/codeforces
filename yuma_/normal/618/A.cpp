#include "bits/stdc++.h"
#include<unordered_map>
#pragma warning(disable:4996)
using namespace std;

const int My_Inf=2147483647;
const long long int My_LInf=9223372036854775807;

int main() {
	int N; cin >> N;
	bitset<20>bs(N);
	vector<int>nums;
	for (int i = 0; i < 20; ++i) {
		if (bs[i]) {

			nums.push_back(i+1);
		}
	}
	reverse(nums.begin(), nums.end());
	for (int i = 0; i < nums.size();++i){
		cout << nums[i];
		if (i != nums.size() - 1)cout << " ";
	}
	cout << endl;
	return 0;
}