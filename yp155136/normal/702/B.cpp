#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef long long LL;
const int MAX_N= 1e5+6;

LL pow2[40];
map<LL,int> mp;

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		mp.clear();
		vector<LL> num;
		LL ans=0;
		for (int x=0;n>x;x++) {
			LL i;
			scanf("%I64d",&i);
			num.push_back(i);
			mp[i]++;
		}
		sort(num.begin(),num.end());
		pow2[0]=1;
		for (int x=1;40>x;x++) {
			pow2[x] = pow2[x-1] * 2;
		}
		for (int x=0;n>x;x++) {
			for (int y=0;40>y;y++) {
				ans += mp[pow2[y]-num[x]];
				if (pow2[y]-num[x] == num[x]) ans--;
			}
//			cout<<"x="<<x<<" , ans="<<ans<<endl;
		}
		printf("%I64d\n",ans/2);
	}
}