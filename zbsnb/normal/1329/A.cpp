#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000010];
int b[1000010];
int lim[1000010];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m;cin>>n>>m;
	ll sum=0;
	for(int i=1;i<=m;i++){
		cin>>a[i];
		sum+=a[i];
	}
	if(sum<n) cout<<-1<<endl;
	else{
		multiset<int> s;
		for(int i=1;i<=m;i++){
			if(i-1+a[i]>n){
				cout<<-1<<endl;
				return 0;
			}
			s.insert(i-1+a[i]);
		}
		for(int i=1;i<m;i++) b[i]=1;
		b[m]=a[m];
		int now=0;
		for(int i=1;i<m;i++){
			s.erase(s.find(i-1+a[i]));
			int tmp=*--s.end();
			while(now+tmp<n&&b[i]<a[i]){
				b[i]++;
				now++;
			}
		}
		
		ll ans=1;
		for(int i=1;i<=m;i++){
			cout<<ans<<" ";
			ans+=b[i];
		}
		cout<<endl;
	}
	
}