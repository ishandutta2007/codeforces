#include <bits/stdc++.h>
using namespace std;
void solve(){
	int x;
	cin>>x;
	int y=0;
	for(int i=1; x>0; i+=2){
		y++;
		x-=i;
	}
	cout<<y<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--) solve();
}