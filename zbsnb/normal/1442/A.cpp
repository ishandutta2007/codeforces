#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000010];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		ll up=a[1],low=0;
		int flg=0;
		for(int i=2;i<=n;i++){
			if(a[i]>=a[i-1]){
				low+=a[i]-a[i-1];
			}
			else up+=a[i]-a[i-1];
			if(up<0){
				flg=1;
				break;
			}
			// cout<<i<<" "<<up<<" "<<low<<endl;
		}
		cout<<(flg?"NO":"YES")<<endl;
	}
}