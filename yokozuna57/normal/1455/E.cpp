#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll x[4],y[4];

ll x_[4],y_[4];
ll calc(){
	sort(x_,x_+4);
	sort(y_,y_+4);
	ll ret=0;
	for(int i=0;i<4;i++){
		ret+=abs(x_[i]-x_[1]);
		ret+=abs(y_[i]-y_[1]);
	}
	return ret;
}

ll solve(){
	ll ret=1000000000000000000;
	int a[4]={0,1,2,3};
	do{
		ll ret_=1000000000000000000;
		ll l=0,r=1000000000;
		while(1){
			ll m=(l+r)/2;
			ll ret__[2];
			for(int i=0;i<2;i++){
				for(int j=0;j<4;j++){
					x_[j]=x[a[j]];
					y_[j]=y[a[j]];
				}
				x_[2]-=m+i; x_[3]-=m+i;
				y_[1]-=m+i; y_[3]-=m+i;
				ret__[i]=calc();
			}
			ret_=min(ret_,min(ret__[0],ret__[1]));
			if(l>=r)break;
			//cerr<<a[0]<<a[1]<<a[2]<<a[3]<<" "<<m<<" "<<ret__[0]<<" "<<ret__[1]<<endl;
			if(ret__[0]==ret__[1])l=r=m;
			else if(ret__[0]<ret__[1])r=m;
			else l=m+1;
		}
		ret=min(ret,ret_);
	}while(next_permutation(a,a+4));
	return ret;
}

int main(){
	int t;
	scanf("%d",&t);
	for(;t>0;t--){
		for(int i=0;i<4;i++){
			scanf("%lld%lld",&x[i],&y[i]);
		}
		printf("%lld\n",solve());
	}
}