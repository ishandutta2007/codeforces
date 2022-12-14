#include<bits/stdc++.h>
using namespace std;
int a[500][500];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	if(n < 3){
		cout << -1 << '\n';
		return 0;
	}
	int cnt = n * n;
	for(int i=0;i<n;i++){
		if(i&1){
			for(int j=0;j<i;j++)	a[i][j] = cnt--;
			a[i][i] = cnt--;
			for(int j=i-1;j>=0;j--)	a[j][i] = cnt--;
		}
		else{
			for(int j=0;j<i;j++)	a[j][i] = cnt--;
			a[i][i] = cnt--;
			for(int j=i-1;j>=0;j--)	a[i][j] = cnt--;
		}
	}
	a[0][0] = n * n - 0, a[0][1] = n * n - 4, a[0][2] = n * n - 3;
	a[1][0] = n * n - 2, a[1][1] = n * n - 7, a[1][2] = n * n - 1;
	a[2][0] = n * n - 8, a[2][1] = n * n - 6, a[2][2] = n * n - 5;
	for(int i=0;i<n;i++, cout << '\n')
		for(int j=0;j<n;j++)
			cout << a[i][j] << ' ';
}