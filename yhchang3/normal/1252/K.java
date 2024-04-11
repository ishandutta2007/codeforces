#include<bits/stdc++.h>
using namespace std;
int p[41]={1,2,3,5,7,13,17,19,31,61,89,107,127,521,607,1279,2203,2281,3217,4253,4423,9689,9941,11213,19937,21701,23209,44497,86243,110503,132049,216091,756839,859433,1257787,1398269,2976221,3021377,6972593,13466917,20996011};
const int mod=1e9+7;


long long int power(long long int x,long long int b){
	long long int res=1;
	while(b){
		if(b&1)
			res=res*x%mod;
		x=x*x%mod;
		b>>=1;
	}
	return res;
}


int main(){
	int n;
	cin>>n;
	cout<<(power(2,p[n]-1)+mod-1)%mod<<endl;
}