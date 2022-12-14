#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		int d, k;
		cin >> d >> k;
		int p = sqrt(1LL * d * d / 2.0 / k / k);
		while(2LL * (p + 1) * (p + 1) * k * k <= 1LL * d * d)
			++p;
		if(1LL * (p + 1) * (p + 1) * k * k + 1LL * p * p * k * k > 1LL * d * d)
			cout << "Utkarsh\n";
		else
			cout << "Ashish\n";
	}
}