#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int main(){
	int w,h;
	cin>>w>>h;
	int ans=1;
	for(int i=1;i<=w+h;++i)ans=2ll*ans%mod;
	printf("%d",ans);
}