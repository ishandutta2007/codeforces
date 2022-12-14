#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		double R,r;
		int k;
		cin>>R>>r>>k;
		double d1=0.5/r,d2=0.5/R;
		double d=(d1+d2)/2;
		double x=abs(d1-d2)/2;
		double ans=x/(d*d+(4*k*k-1)*x*x);
		cout<<fixed<<setprecision(9)<<ans<<'\n';
	}
}