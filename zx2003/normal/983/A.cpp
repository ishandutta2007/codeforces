#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
ll p,q,b;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>T;
	while(T--){
		cin>>p>>q>>b;
		ll d=gcd(p,q);
		p/=d;q/=d;
		if(p==0){
			cout<<"Finite\n";
			continue;
		}
		for(;q>1;){
			d=gcd(q,b);
			if(d==1)break;
			while(q%d==0)q/=d;
		}
		cout<<(q>1?"Infinite":"Finite")<<'\n';
	}
	//cerr<<clock();
	return 0;
}