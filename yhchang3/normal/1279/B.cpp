#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll a[100001];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n;ll s;
		cin>>n>>s;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		int ans=0,cnt=0;
		vector<ll> v(n+1);
		for(int i=1;i<=n;i++)
			v[i]=v[i-1]+a[i];
		for(int i=0;i<=n;i++){
			if(i==0){
				cnt=upper_bound(v.begin(),v.end(),s)-v.begin()-1;
			}
			else if(v[i-1]<s){
				int tmp=upper_bound(v.begin(),v.end(),s+a[i])-v.begin()-2;
				if(tmp>cnt){
					cnt=tmp;
					ans=i;
				}
			}
		}
		cout<<ans<<'\n';
	}
}