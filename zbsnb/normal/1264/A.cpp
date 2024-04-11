#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000010];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int b=0,c=0,d=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int cnt=1;
		a[0]=-1;
		auto f=[&]{
			if(b==0)b=cnt;
			else if(b>=c)c+=cnt;
			else d+=cnt;
			// cout<<cnt<<endl;
			cnt=1;
		};
		for(int i=2;i<=n/2;i++){
			// cout<<"now:"<<i<<endl;
			if(a[i]==a[i-1]) cnt++;
			else {
				f();		
			}
		}
		if(a[n/2]!=a[n/2+1]){
			f();		
		}
		if(d==0||d<=b)cout<<"0 0 0"<<endl;
		else cout<<b<<" "<<c<<" "<<d<<endl;
	}
}