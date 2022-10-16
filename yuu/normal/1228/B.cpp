#include <bits/stdc++.h>
using namespace std;
int h, w;
int r[1001];
int c[1001];
bool a[1002][1002];
const int base=1000000007;
int main(){
	cin>>h>>w;
	for(int i=1; i<=h; i++){
		cin>>r[i];
		for(int j=1; j<=r[i]; j++) a[i][j]=1;
	}
	for(int i=1; i<=w; i++){
		cin>>c[i];
		for(int j=1; j<=c[i]; j++) a[j][i]=1;
	}
	for(int i=1; i<=h; i++){
		if(a[i][r[i]+1]){
			cout<<"0\n";
			return 0;
		}
	}
	for(int i=1; i<=w; i++){
		if(a[c[i]+1][i]){
			cout<<"0\n";
			return 0;
		}
	}
	for(int i=1; i<=h; i++) a[i][r[i]+1]=1;
	for(int i=1; i<=w; i++) a[c[i]+1][i]=1;
	int ans=1;
	for(int i=1; i<=h; i++) for(int j=1; j<=w; j++) if(a[i][j]==0){
		ans+=ans;
		while(ans>=base) ans-=base;
	}
	cout<<ans<<'\n';
}