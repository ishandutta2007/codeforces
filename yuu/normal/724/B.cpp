#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[20][20];
bool test_row(int i){
	int diff=0;
	for(int j=0; j<m; j++) if(a[i][j]!=j+1) diff++;
	return diff<=2;
}
void test(){
	for(int i=0; i<n; i++) if(!test_row(i)) return;
	cout<<"YES\n";
	exit(0);
}
int main(){
	cin>>n>>m;
	for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin>>a[i][j];
	test();
	for(int i=0; i<m; i++) for(int j=0; j<m; j++){
		for(int k=0; k<n; k++) swap(a[k][i], a[k][j]);
		test();
		for(int k=0; k<n; k++) swap(a[k][i], a[k][j]);
	}
	cout<<"NO\n";
}