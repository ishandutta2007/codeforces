#include<bits/stdc++.h>
typedef long long ll;
const int N=1e5+5;
char c[N];
int i,j,c0[26];
ll c1[26][26],ans;
int main(){
	scanf("%s",c);
	for(i=0;c[i];++i){
		int x=c[i]-'a';
		for(j=0;j<26;++j)c1[j][x]+=c0[j];
		++c0[x];
	}
	for(int x:c0)ans=std::max(ans,ll(x));
	for(i=0;i<26;++i)for(ll x:c1[i])ans=std::max(ans,x);
	printf("%lld\n",ans);
	return 0;
}