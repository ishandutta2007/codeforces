#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	cin>>n>>m; int ret = 1;
	for(int i = 1; i <= n; i ++) {
		ret = ret*2; if(ret > m) {cout<<m<<endl; return 0; }
	}
	cout<<m%ret<<endl;
	return 0;
}