#include<bits/stdc++.h>
using namespace std;

int gcd(int x,int y){
	while((x%=y)&&(y%=x));
	return x^y;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int r,b,k;
		cin>>r>>b>>k;
		int g=gcd(r,b);
		if(r<b)	swap(r,b);
		bool ok=r==b;
		if((r-g)%b==0){
			ok|=(((r-g)/b)<=k-1);
		}
		else
			ok|=((1+(r-g)/b)<=k-1);
		if(ok)
			cout<<"OBEY\n";
		else
			cout<<"REBEL\n";
	}
}