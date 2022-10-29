#include<bits/stdc++.h>
using namespace std;
map<int,int>st;
int n;
char s[1010000];
int main(){
	long long ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%s",s);
		int a=0;
		for(int j=0;s[j];j++)a^=1<<s[j]-'a';
		ans+=st[a];
		for(int j=0;j<26;++j)ans+=st[a^(1<<j)];
		st[a]++;
	}
	printf("%lld",ans);
}