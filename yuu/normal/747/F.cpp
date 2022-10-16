#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll p;
int t;
ll c[16][16];
int v[16];
ll F(int sz, bool no_leading_zero){///how many numbers with sz length and constrant v, contain leading 0 or not
	ll f[sz+1];
	for(int i=0; i<=sz; i++) f[i]=0;
	f[0]=1;
	if(no_leading_zero)	for(int j=min(sz-1, v[0]); j>=1; j--) f[j]=c[sz-1][j];
	for(int i=no_leading_zero; i<16; i++){
		for(int j=sz; j>=1; j--){
			for(int k=j-1; k>=0; k--){
				if(j-k>v[i]) break;
				f[j]+=f[k]*c[sz-k][j-k];
				if(f[j]>2e9) f[j]=2e9+1;
			}
		}
	}
	return f[sz];
}
int main(){
	cin>>p>>t;
	for(int i=0; i<16; i++) v[i]=t;
	for(int i=0; i<16; i++){
		c[i][0]=c[i][i]=1;
		for(int j=1; j<i; j++){
			c[i][j]=c[i-1][j]+c[i-1][j-1];
			if(c[i][j]>2e9) c[i][j]=2e9+1;
		}
	}
	vector <int> ans;
	int len=1;
	while(true){
		auto res=F(len, 1);
		if(res>=p) break;
		else p-=res;
		len++;
	}
	for(int i=1; i<=len; i++){
		for(int j=0+(i==1); j<16; j++) if(v[j]>0){
			v[j]--;
			auto res=F(len-i, 0);
			if(res>=p){
				ans.push_back(j);
				break;
			}
			else{
				p-=res;	
				v[j]++;
			}
		}
	}
	for(auto &x: ans) cout<<"0123456789abcdef"[x];
	cout<<'\n';
}