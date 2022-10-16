#include <bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin>>n;
	int x=n/3;
	int y=x;
	if(x+y*2==n-1){
		x++;
	}
	else if(x+y*2==n-2){
		y++;
	}
	cout<<x<<' '<<y<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--) solve();
}