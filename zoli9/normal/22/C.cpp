// Snta Gerg kdja 

#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
	long long n, m, v;
	cin >> n >> m >> v;
	if(m < n-1 || m > (n-1)*(n-2)/2+1){
		cout << -1 << '\n';
		return 0;
	}
	int u=1;
	if(v==1) u=2;
	for(int i=1; i<=n; i++){
		if(i!=v){
			cout << i << " " << v << '\n';
			m--;
		}
	}
	if(m==0) return 0;
	for(int i=1; i<n; i++){
		for(int j=i+1; j<=n; j++){
			if(i!=u && i!=v && j!=u && j!=v){
				cout << i << " " << j << '\n';
				m--;
				if(m==0) return 0;
			}
		}
	}
	return 0;
}