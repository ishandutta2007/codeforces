#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=2e5+5;
int num[N];
int main(){
	int t=read();
	while(t--){
		int n=read();
		for(int i=1;i<=n;i++){
			int x=read();
			if(num[x])num[x]=1e9;
			else num[x]=i;
		}
		int ans=-1;
		for(int i=1;i<=n;i++)
			if(num[i] && num[i]<=n){
				ans=num[i];
				break;
			}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++)num[i]=0;
	}
	return 0;
}