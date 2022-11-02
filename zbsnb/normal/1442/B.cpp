#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
int l[1000010];
int r[1000010];
int a[1000010];
int pos[1000010];
int b[1000010];
int tag[1000010];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t;cin>>t;
	while(t--){
		int n,k;cin>>n>>k;
		for(int i=0;i<=n+1;i++){
			l[i]=i-1;
			r[i]=i+1;
		}
		for(int i=1;i<=n;i++){
			tag[i]=0;
			cin>>a[i];
			pos[a[i]]=i;
		}
		for(int i=1;i<=k;i++){
			cin>>b[i];
			tag[pos[b[i]]]=i;
		}
		ll ans=1;
		for(int i=1;i<=k;i++){
			int now=2;
			int p=pos[b[i]];
			int LL=l[p],rr=r[p];
			int flg1=LL>=1&&tag[LL]<i;
			int flg2=rr<=n&&tag[rr]<i;
			l[rr]=l[p];
			r[LL]=r[p];
			if(!flg1) now--;
			if(!flg2) now--;
			ans=ans*now%mod;
			// cout<<"??"<<now<<endl;
			// for(int i=1;i<=n;i++) cout<<l[i]<<" ";cout<<endl;
			// for(int i=1;i<=n;i++) cout<<r[i]<<" ";cout<<endl;
		}
		cout<<ans<<"\n";
	}
}