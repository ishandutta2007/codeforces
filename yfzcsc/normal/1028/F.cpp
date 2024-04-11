#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
map<ll,vector<pii> >st;
map<pii,int>ans;
int n,cnt=0;
int main(){
	scanf("%d",&n);
	for(int i=1,t,x,y;i<=n;++i){
		scanf("%d%d%d",&t,&x,&y);
		if(t==1){
			cnt++;
			vector<pii>& v=st[(ll)x*x+(ll)y*y];
			for(auto c:v){
				ll xi=(c.first+x),yi=(c.second+y);
				ll t=__gcd(xi,yi);
				ans[pii(xi/t,yi/t)]+=2;
			}
			ll t=__gcd(x,y);
			ans[pii(x/t,y/t)]++;
			v.push_back(pii(x,y));
		} else if(t==2){
			cnt--;
			vector<pii>& v=st[(ll)x*x+(ll)y*y];
			vector<pii> nv;
			for(auto c:v)if(c!=pii(x,y)){
				ll xi=(c.first+x),yi=(c.second+y);
				ll t=__gcd(xi,yi);
				ans[pii(xi/t,yi/t)]-=2;
				nv.push_back(c);
			}
			ll t=__gcd(x,y);
			ans[pii(x/t,y/t)]--;
			st[(ll)x*x+(ll)y*y]=nv;
		} else {
			int t=__gcd(x,y);
			x/=t,y/=t;
			printf("%d\n",cnt-ans[pii(x,y)]);
		}
	}
}