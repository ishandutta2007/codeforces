#include<bits/stdc++.h>
using namespace std;
int n,m,T,b,p,t,h,c,ans;
int main(){
	cin>>T;
	while(T--){
		cin>>b>>p>>t>>h>>c;
		ans=0;
		if(h>c){
			if(p>(b>>1)){
				ans+=h*(b>>1);
				b&=1;
			}
			else {
				ans+=h*p,b-=(p<<1);
				ans+=c*min(b>>1,t);
			}
		}
		else {
			if(t>(b>>1)){
				ans+=c*(b>>1);
				b&=1;
			}
			else {
				ans+=c*t,b-=(t<<1);
				ans+=h*min(b>>1,p);
			}
		}
		cout<<ans<<endl;		
	}
    return 0;
}