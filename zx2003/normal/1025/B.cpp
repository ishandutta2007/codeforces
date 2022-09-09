#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=150005;
int n,i;
ll z,a,b,c;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
inline bool isp(int x){
	if(x<2)return 0;
	for(int i=2;i*i<=x;++i)if(x%i==0)return 0;
	return 1;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(i=1;i<=n;++i){
		cin>>a>>b;
		z=gcd(z,1ll*a/gcd(a,b)*b);
	}
	if(z==1){
		cout<<"-1";
		return 0;
	}
	if(isp(a) && z%a==0){
		cout<<a<<'\n';
		return 0;
	}
	if(isp(b) && z%b==0){
		cout<<b<<'\n';
		return 0;
	}
	c=max(a,b);
	vector<int>zz;
	for(i=2;i*i<=c;++i){
		if(z%i==0){
			zz.push_back(i);
		}
		if(a/i>1 && z%(a/i)==0){
			zz.push_back(a/i);
		}
		if(b/i>1 && z%(b/i)==0){
			zz.push_back(b/i);
		}
	}
	sort(zz.begin(),zz.end());
	for(i=0;i<zz.size();++i)if(zz[i]>1 && z%zz[i]==0)break;
	cout<<zz[i];
	return 0;
}