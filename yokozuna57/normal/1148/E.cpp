#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> P1;

#define rep1(i,x) for(int i = 1 ; i <= x ; i ++)
#define mp1(a,b,c) P1(a,P(b,c))

int main(){
	static ll n;
	static ll s[300010],t[300010];
	static ll id[300010];
	scanf("%lld",&n);
	rep1(i,n)scanf("%lld",&s[i]);
	rep1(i,n)scanf("%lld",&t[i]);
	
	vector<P> sor;
	rep1(i,n){
		sor.push_back(P(s[i],i));
	}
	sort(sor.begin(),sor.end());
	rep1(i,n){
		s[i] = sor[i-1].first;
		id[i] = sor[i-1].second;
	}
	sort(t+1,t+n+1);
	
	static ll a[300010],b[300010];
	static vector<P> vec[2];
	b[0] = 0;
	bool ret = true;
	rep1(i,n){
		a[i] = t[i]-s[i];
		b[i] = b[i-1]+a[i];
		if(a[i] > 0){
			vec[0].push_back(P(i,a[i]));
		}
		else if(a[i] < 0){
			vec[1].push_back(P(i,-a[i]));
		}
		if(b[i] < 0)ret = false;
	}
	/*rep1(i,n){
		cout << b[i] << " ";
	}cout << endl;*/
	if(b[n] != 0)ret = false;
	if(!ret){
		puts("NO");
		return 0;
	}
	vector<P1> ans;
	int k=0,l=0;
	while(k<vec[0].size()){
		P p = vec[0][k];
		P q = vec[1][l];
		int d = min(p.second,q.second);
		ans.push_back(mp1(p.first,q.first,d));
		vec[0][k].second -= d; if(vec[0][k].second == 0)k ++;
		vec[1][l].second -= d; if(vec[1][l].second == 0)l ++;
	}
	puts("YES");
	printf("%d\n",(int)ans.size());
	for(int i = 0 ; i < ans.size() ; i ++){
		printf("%lld %lld %lld\n",id[ans[i].first],id[ans[i].second.first],ans[i].second.second);
	}
}