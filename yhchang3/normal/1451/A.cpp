#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		if(n <= 3)
			cout << n - 1 << '\n';
		else if(n&1)
			cout << 3 << '\n';
		else
			cout << 2 << '\n';
	}
}