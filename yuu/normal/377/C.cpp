#include <bits/stdc++.h>
using namespace std;
int n, m;
int s[100];
int t[20];
char a[20];
int f[1<<20];
int main(){
	cin>>n;
	for(int i=0; i<n; i++) cin>>s[i];
	sort(s, s+n);
	reverse(s, s+n);
	cin>>m;
	for(int i=0; i<m; i++) cin>>a[i]>>t[i];
	for(int i=(1<<m)-1; i>=0; i--){
		int turn=__builtin_popcount(i);//alway using ll are for pussies
		if(turn==m)	f[i]=0;
		else{
			int weight=1;
			if(a[turn]=='b') weight=0;
			if(t[turn]==1){
				f[i]=-1e9;
				for(int x=((1<<m)-1)^i, j=__builtin_ctz(x); x; j=__builtin_ctz(x=(x-(x&-x))))	f[i]=max(f[i], f[i^(1<<j)]+weight*s[j]);	
			}
			else{
				weight=-weight;
				f[i]=1e9;
				for(int x=((1<<m)-1)^i, j=__builtin_ctz(x); x; j=__builtin_ctz(x=(x-(x&-x))))	f[i]=min(f[i], f[i^(1<<j)]+weight*s[j]);
			}
		}
	}
	cout<<f[0]<<'\n';
}