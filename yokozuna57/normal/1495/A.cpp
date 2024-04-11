#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

int n;
ll x[100010],y[100010];

void solve(){
	for(int i=0;i<n;i++){
		x[i]*=x[i];
		y[i]*=y[i];
	}
	sort(x,x+n);
	sort(y,y+n);
	long double ret=0.;
	for(int i=0;i<n;i++){
		ret+=sqrt((long double)(x[i]+y[i]));
	}
	printf("%.20f\n",(double)ret);
}

int main(){
	int T;
	scanf("%d",&T);
	for(;T>0;T--){
		scanf("%d",&n);
		int cnt_x=0,cnt_y=0;
		for(int i=0;i<2*n;i++){
			ll x_,y_;
			scanf("%lld%lld",&x_,&y_);
			if(x_==0){
				y[cnt_y++]=y_;
			}
			else {
				x[cnt_x++]=x_;
			}
		}
		solve();
	}
}