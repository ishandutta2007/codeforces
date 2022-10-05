#include<bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
ll mod,fir,a,b,tem,h,aim,x,y;
ll ff,aa,bb;
int used[1111111];
void doit(){
	cin>>h>>aim>>x>>y;
	memset(used,-1,sizeof used);
	fir=1e8;
	for (tem=0;1;tem++){
		if (used[h]>=0){
			b=tem-used[h];
			for (int nnd=0;nnd<=b;nnd++){
				h=(h*x+y)%mod;
				tem++;
				if (h==aim){
					a=tem-b;
					return;
				}
			}
			a=-1;
			return;
		}
		used[h]=tem;
		if (h==aim){
			fir=min(fir,tem);
		}
		h=(h*x+y)%mod;
	}
}
ll GA(){
	if (ff==fir) return ff;
	ll t;
	if (aa!=-1){
		for (ll i=0;i<=2222222;i++){
			t=aa+i*bb;
			if (t==fir) return fir;
			if (a!=-1){
				if (t>=a&&(t-a)%b==0){
					return t;
				}
			}
		}
	}
	return -1;
}
int main(){
	cin>>mod;
	doit(); if(fir==1e8) { printf("-1");return 0; }
	ff=fir;aa=a;bb=b;
	doit(); if(fir==1e8) { printf("-1");return 0; }
	ll ans=GA();
	cout<<ans;
}