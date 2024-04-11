#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,i,j,a[26];
char c[N];
ll T;
int main(){
	scanf("%d%lld%s",&n,&T,c+1);
	T-=1<<c[n]-'a';T+=1<<c[n-1]-'a';
	for(i=1;i<n-1;++i)++a[c[i]-'a'];
	for(i=0;i<26;++i)T+=ll(a[i])<<i;
	for(i=25;i>=0;--i)for(;a[i]--;)if(T>=2<<i)T-=2<<i;
	puts(T?"No":"Yes");
}