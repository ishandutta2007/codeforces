#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[110];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		set<int> s;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				s.insert(abs(a[i]-a[j]));
			}
		}
		cout<<s.size()<<endl;
	}
}