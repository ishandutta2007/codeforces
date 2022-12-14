#include <bits/stdc++.h>
using namespace std;
long long v[1<<20],o;
int main()
{
	int t,n,m,a,b;
	scanf("%i",&t);
	while(t--){
		scanf("%i%i",&n,&m);
		for(int i=0;i<n;i++)
			scanf("%lld",&v[i]);
		vector<vector<int> > k(n);
		for(int i=0;i<m;i++)
			scanf("%i%i",&a,&b),k[b-1].push_back(a-1);
		map<vector<int>,long long> s;
		for(int i=0;i<n;i++){
			if(k[i].empty())
				continue;
			sort(k[i].begin(),k[i].end());
			s[k[i]]+=v[i];
		}
		o=0;
		for(auto p:s)
			o=__gcd(o,p.second);
		printf("%lld\n",o);
	}
	return 0;
}