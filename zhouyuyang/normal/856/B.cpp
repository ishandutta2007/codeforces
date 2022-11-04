#include<bits/stdc++.h>
#define ll long long
using namespace std;
int mo[2]={1000000007,998244353},bas=233;
struct LZHa{
	ll hash,pre;
	int len;
}a[1000005];
char s[1000005];
bool cmp(LZHa a,LZHa b){
	return a.len>b.len;
}
int main(){
	int T; scanf("%d",&T);
	for (;T;T--){
		int n,t=0;
		scanf("%d",&n);
		set<ll> ss;
		while (n--){
			scanf("%s",s+1);
			int len=strlen(s+1);
			ll h1[2]={0,0},h2[2]={0,0};
			for (int i=1;i<=len;i++){
				h1[0]=(h1[0]*bas+s[i])%mo[0];
				h1[1]=(h1[1]*bas+s[i])%mo[1];
				++t;
				if (i>1){
					h2[0]=(h2[0]*bas+s[i])%mo[0];
					h2[1]=(h2[1]*bas+s[i])%mo[1];
					a[t].pre=h2[0]*mo[1]+h2[1];
				}
				else a[t].pre=-1;
				a[t].hash=h1[0]*mo[1]+h1[1];
				ss.insert(a[t].hash);
				a[t].len=i;
			}
		}
		sort(a+1,a+t+1,cmp);
		for (int i=1;i<=t;i++)
			if (ss.count(a[i].hash))
				ss.erase(a[i].pre);
		printf("%d\n",ss.size());
	}
}