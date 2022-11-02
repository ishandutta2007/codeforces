#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000010];
ll sum[1000010];
int n,q;
ll now=0;
ll fac[20];
void work(int x){
	vector<int> vec;
	for(int i=max(1,n-15);i<=n;i++){
		vec.push_back(i);
	}
	ll tmp=now;
	int ind=max(1,n-15);
	int sz=vec.size();
	for(int i=0;i<sz;i++){
		int pos=tmp/fac[sz-1-i];
		tmp=tmp%fac[sz-1-i];
		a[ind++]=vec[pos];
		vec.erase(vec.begin()+pos);
	}

	for(int i=max(1,n-15);i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	fac[0]=1;
	for(int i=1;i<20;i++) fac[i]=fac[i-1]*i;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		a[i]=i;
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=q;i++){
		int tag;cin>>tag;
		if(tag==1){
			int l,r;cin>>l>>r;
			cout<<sum[r]-sum[l-1]<<"\n";
		}
		else{
			int tmp;cin>>tmp;
			now+=tmp;
			work(tmp);
		}
	}
}