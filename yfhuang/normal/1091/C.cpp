#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

long long cal(int n, int d){
	int m = n / d;
	int last = 1 + (m - 1) * d;
	return 1LL * (last + 1) * m / 2;
}

int main(){
	int n;
	while(cin >> n){
		set<long long> ans;
		for(int i = 1;1LL * i * i <= n;i++){
			if(n % i == 0){
				ans.insert(cal(n, i));
				ans.insert(cal(n, n / i));
			}	
		}
		for(auto x: ans){
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}