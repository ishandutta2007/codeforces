#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		int x, y;
		cin >> x >> y;
		cout << max(x, y) * 2 - (x != y) << '\n';
	}
}