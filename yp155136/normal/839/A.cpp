#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
	int n,k;
	cin >> n >> k;
	int pre=0;
	for(int i=0;n>i;i++) {
		int x;
		cin >> x;
		pre+=x;
		k -= min(pre,8);
		if(k<=0) {
			cout<<i+1<<endl;
			return 0;
		}
		pre = max(0,pre-8);
	}
	cout<<-1<<endl;
}