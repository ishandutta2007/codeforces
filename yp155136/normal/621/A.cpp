#include <bits/stdc++.h>
using namespace std;
int main () {
	int n;
	scanf("%d",&n);
	
	long long int a[n];
	for (int x=0;n>x;x++) cin >> a[x];
	sort(a,a+n);
	long long sum=0;
	long long tmp=0;
	for (int x=0;n>x;x++) {
		sum+=a[x];
		if (a[x]%2==1 && tmp==0) tmp=a[x];
	}
	if (sum%2==0) cout << sum << endl;
	else cout << sum-tmp << endl;
	
}