#include<bits/stdc++.h>
using namespace std;
#define ll long long
pair<int,int> a[100010];
mt19937 rd(787);
int ans[100010];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].first,a[i].second=i;
	auto t=clock();
	auto now_time=[&]{return (clock()-t)/double(CLOCKS_PER_SEC);};
	while(now_time()<0.40){

		shuffle(a+1,a+n+1,rd);
		int gcd=a[1].first,i=2;
		while(i<=n&&gcd!=1) gcd=__gcd(gcd,a[i++].first);
		if(gcd!=1)continue;

		gcd=a[i].first;int j=i+1;
		while(j<=n&&gcd!=1) gcd=__gcd(gcd,a[j++].first);
		if(gcd!=1)continue;

		// for(int k=1;k<=n;k++) cout<<a[k].first<<" ";cout<<endl;
		for(int k=1;k<i;k++) ans[a[k].second]=1;
		for(int k=i;k<=n;k++) ans[a[k].second]=2;
		cout<<"YES"<<endl;
		for(int i=1;i<=n;i++) cout<<ans[i]<<" ";cout<<endl;

		return 0;
	}
	ans[0]=0;
	cout<<"NO"<<endl;
}