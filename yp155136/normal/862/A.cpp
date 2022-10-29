#include <iostream>
#include <cstdio>
using namespace std;

int cnt[123];

int main () {
	int n,x;
	cin >>n >>x;
	--x;
	for(int i=0;n>i;i++) {
		int y;
		cin >> y;
		cnt[y]++;
	}
	int sum=0;
	for (int i=0;x>=i;i++) {
		if (!cnt[i]) sum++;
	}
	cout<<sum+cnt[x+1]<<endl;
}