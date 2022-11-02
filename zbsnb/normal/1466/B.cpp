#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[2000010];
int vis[2000010];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=2*n+10;i++) vis[i]=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(!vis[a[i]]){
				vis[a[i]]=1;
				ans++;
			}
			else if(!vis[a[i]+1]){
				vis[a[i]+1]=1;
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
}