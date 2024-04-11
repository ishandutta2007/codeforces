#include <iostream>
using namespace std;

int main() {
	int n,k,x;
	cin >> n >> k >> x;
	int ans=0;
	for (int i=0;n>i;i++) {
		int y;
		cin >> y;
		if (n-i <= k) ans += x;
		else ans+=y;
	}
	cout<<ans<<endl;
}