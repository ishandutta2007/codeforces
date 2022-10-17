#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define fr first
#define sc second
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)

ll n[3];
vector<ll> x[3];

void solve(){
	ll ret=3000000000000000000LL;
	for(int i=0;i<3;i++){
		int s=0; if(i==0)s++;
		int t=2; if(i==2)t--;
		for(int j=0;j<n[i];j++){
			ll a=x[i][j];
			ll b;
			if(1){
				auto itr=lower_bound(x[s].begin(),x[s].end(),a);
				if(itr==x[s].end())continue;
				else b=*itr;
			}
			ll c;
			if(1){
				auto itr=lower_bound(x[t].begin(),x[t].end(),a);
				if(itr==x[t].end())continue;
				else c=*itr;
			}
			if(b<=c){
				auto itr=lower_bound(x[s].begin(),x[s].end(),(a+c)/2);
				if(itr!=x[s].end())b=*itr;
				if(itr!=x[s].begin()){
					itr--;
					if(abs(2*(*itr)-a-c)<=abs(2*b-a-c))b=*itr;
				}
			}
			else {
				auto itr=lower_bound(x[t].begin(),x[t].end(),(a+b)/2);
				if(itr!=x[t].end())c=*itr;
				if(itr!=x[t].begin()){
					itr--;
					if(abs(2*(*itr)-a-b)<=abs(2*c-a-b))c=*itr;
				}
			}
			chmin(ret,(a-b)*(a-b)+(b-c)*(b-c)+(c-a)*(c-a));
			//cerr<<a<<" "<<b<<" "<<c<<endl;
		}
	}
	cout<<ret<<endl;
}

int main(){
	int T;
	scanf("%d",&T);
	for(;T>0;T--){
		for(int i=0;i<3;i++)scanf("%lld",&n[i]);
		for(int i=0;i<3;i++){
			x[i].clear();
			for(int j=0;j<n[i];j++){
				ll y;
				scanf("%lld",&y);
				x[i].push_back(y);
			}
		}
		for(int i=0;i<3;i++)sort(x[i].begin(),x[i].end());
		solve();
	}
}