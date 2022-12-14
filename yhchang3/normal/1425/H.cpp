#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		bool ok1 = (a+d) > 0, ok2 = (b+c) > 0;
		if((a+b) % 2 != 0){
			cout << (!ok1?"Tidak":"Ya");
			cout << ' ' << (!ok2?"Tidak":"Ya");
			cout << " Tidak Tidak";
		}
		else{
			cout << "Tidak Tidak";
			cout << ' ' << (!ok2?"Tidak":"Ya");
			cout << ' ' << (!ok1?"Tidak":"Ya");
		}
		cout << '\n';
	}
}