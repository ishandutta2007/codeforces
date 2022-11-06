#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
using ld = long double;


int main() {
	int N,X,Y;cin>>N>>X>>Y;
	string st;cin>>st;
	long long int sum=0;
	bool flag=false;
	for (auto c : st) {
		if (c == '0') {
			flag=true;
		}
		else {
			if (flag) {
				flag=false;
				sum++;
			}
		}
	}
	if (flag) {
		flag=false;
		sum++;
	}
	if (sum == 0) {
		cout<<0<<endl;
	}
	else {

		cout << Y + min(X, Y)*(sum - 1) << endl;
	}
	
	return 0;
}