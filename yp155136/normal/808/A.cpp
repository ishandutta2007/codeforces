#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;

int main () {
	vector<LL> v;
	for (int i=1;10>i;i++) {
		LL haha=1;
		int cnt=11;
		while(cnt--) {
			v.push_back(i*haha);
			haha*=10;
		}
	}
	sort(v.begin(),v.end());
	int n;
	cin>>n;
	int t=n;
	cout<<*(lower_bound(v.begin(),v.end(),n+1))-t<<endl;
}