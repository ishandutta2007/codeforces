#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mp make_pair
#define fr first
#define sc second

const ll INF=100000000000;

ll n;
ll t[5005],x[5005];

ll L[5005][2],R[5005][2];

void ok(){
	puts("YES");
	exit(0);
}
void ng(){
	puts("NO");
	exit(0);
}

ll flo(ll x,ll y){
	if(x>=0)return x/y;
	return (x-y+1)/y;
}
ll cei(ll x,ll y){
	if(x>=0)return (x+y-1)/y;
	return x/y;
}

int main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&t[i],&x[i]);
	}
	t[0]=x[0]=0;
	
	L[0][0]=L[0][1]=R[0][0]=R[0][1]=0;
	for(int i=1;i<=n;i++){
		L[i][0]=L[i][1]=INF;
		R[i][0]=R[i][1]=-INF;
	}
	
	for(int i=0;i<n;i++){
		for(int s=0;s<2;s++){
			if(L[i][s]>R[i][s])continue;
			ll d;
			if(x[i+1]<L[i][s])d=(t[i+1]-t[i])-(L[i][s]-x[i+1]);
			else if(x[i+1]>R[i][s])d=(t[i+1]-t[i])-(x[i+1]-R[i][s]);
			else d=t[i+1]-t[i];
			if(d<0)continue;
			L[i+1][0]=min(L[i+1][0],x[i+1]-d);
			R[i+1][0]=max(R[i+1][0],x[i+1]+d);
			ll L_,R_;
			if(L[i][s]<x[i+1]-(t[i+1]-t[i]))L_=x[i+1]-(t[i+1]-t[i]);
			else L_=cei(L[i][s]+x[i+1]-(t[i+1]-t[i]),2);
			if(R[i][s]>x[i+1]+(t[i+1]-t[i]))R_=x[i+1]+(t[i+1]-t[i]);
			else R_=flo(R[i][s]+x[i+1]+(t[i+1]-t[i]),2);
			for(int j=i+2;j<=n;j++){
				//if(i==2&&s==1)cerr<<j<<" "<<L_<<" "<<R_<<endl;
				d=t[j]-t[j-1]-abs(x[j-1]-x[j]);
				if(x[j]<L_||x[j]>R_){
					if(d>=0){
						L[j][0]=min(L[j][0],x[j]-d);
						R[j][0]=max(R[j][0],x[j]+d);
					}
				}
				else {
					L[j][1]=min(L[j][1],x[j-1]-(t[j]-t[j-1]));
					R[j][1]=max(R[j][1],x[j-1]+(t[j]-t[j-1]));
				}
				if(d<0)break;
				if(j==n)ok();
				L_=min(L_,cei(x[j-1]+x[j]-(t[j]-t[j-1]),2));
				R_=max(R_,flo(x[j-1]+x[j]+(t[j]-t[j-1]),2));
			}
		}
	}
	//cout<<L[2][0]<<" "<<R[2][0]<<endl;
	//cout<<L[2][1]<<" "<<R[2][1]<<endl;
	if(L[n][0]<=R[n][0]||L[n][1]<=R[n][1])ok();
	else ng();
}