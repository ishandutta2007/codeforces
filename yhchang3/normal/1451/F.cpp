#include<bits/stdc++.h>
using namespace std;

int a[100][100];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n, m;
		cin >> n >> m;
		vector<int> val(n + m - 1);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin >> a[i][j], val[i+j] ^= a[i][j];
		if(accumulate(val.begin(), val.end(), 0) == 0)
			cout << "Jeel\n";
		else
			cout << "Ashish\n";
	}
}