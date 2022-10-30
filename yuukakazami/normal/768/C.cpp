#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)

int cur[1024],nxt[1024];

int main(){
	int n,k,x;
	cin>>n>>k>>x;
	rep(i,0,n) {int a;cin>>a;cur[a]++;}
	rep(i,0,k){
		int p=0; memset(nxt,0,sizeof nxt);
		rep(i,0,1024){
			if(p%2==0)
				nxt[i^x] += (cur[i]+1)/2, nxt[i] += cur[i]/2;
			else
				nxt[i] += (cur[i]+1)/2, nxt[i^x] += cur[i]/2;
			p += cur[i];
		}
		memcpy(cur,nxt,sizeof cur);
	}
	int l=111111,r=-1;
	rep(i,0,1024) if(cur[i]) l=min(l,i),r=max(r,i);
	cout<<r<<" "<<l<<endl;
	return 0;
}