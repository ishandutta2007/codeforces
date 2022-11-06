#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
using namespace std;

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
	int N;cin>>N;
	auto v(divisor(N));
	cout<<v.size()-1<<endl;
	return 0;

}