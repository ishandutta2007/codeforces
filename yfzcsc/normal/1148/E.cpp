#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
typedef long long ll;
typedef pair<ll,ll> pii;
struct data{
	int x,y,d;
	data(){}
	data(int x,int y,int d):x(x),y(y),d(d){}
};
int n;
pii si[maxn],ti[maxn];
map<int,int> S,T;
vector<data> Q;
void gans(int i,int j,int d){
	Q.push_back(data(i,j,d));
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lld",&si[i].first),si[i].second=i;
	for(int i=1;i<=n;++i)scanf("%lld",&ti[i].first),ti[i].second=i;
	sort(si+1,si+n+1);
	sort(ti+1,ti+n+1);
	ll sum=0;
	vector<pii>v;
	for(int i=n;i>=1;--i){
		if(si[i].first>ti[i].first){
			sum+=si[i].first-ti[i].first;
			v.push_back(pii(si[i].first-ti[i].first,si[i].second));
		} else{
			if(sum+si[i].first-ti[i].first<0){
				puts("NO");
				return 0;
			}
			sum+=si[i].first-ti[i].first;
			ll rest=ti[i].first-si[i].first;
			while(v.size()&&rest){
				auto& a=v.back();
				if(a.first>rest){
					a.first-=rest;
					gans(si[i].second,a.second,rest);
					rest=0;
				} else {
					rest-=a.first;
					gans(si[i].second,a.second,a.first);
					v.pop_back();
				}
			}
		}
	}
	if(v.size()){
		puts("NO");
		return 0;
	}
	puts("YES");
	printf("%d\n",Q.size());
	for(auto a:Q){
		printf("%d %d %d\n",a.x,a.y,a.d);
	}
}