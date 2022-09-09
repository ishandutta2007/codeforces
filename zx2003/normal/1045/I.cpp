#include<bits/stdc++.h>
using namespace std;
const int N=100005;
long long ans;
char c[1000005];
int n,i,j;
map<int,int>mp;
int main(){
	scanf("%d",&n);
	for(;n--;){
		scanf("%s",c+1);int z=0;
		for(i=1;c[i];++i)z^=1<<(c[i]-'a');
		ans+=mp[z];
		for(i=0;i<26;++i)ans+=mp[z^(1<<i)];
		++mp[z];
	}
	cout<<ans<<'\n';
	return 0;
}