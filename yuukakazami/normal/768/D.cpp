#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)

typedef double db;

db cur[1000];
int qry[1000],k,q;
int ans[1000];

int main(){
	cin>>k>>q; rep(i,0,q) cin>>qry[i];

	memset(cur,0,sizeof cur); cur[0]=1.0;
	memset(ans,-1,sizeof ans);

	rep(day,1,10000){
		for(int i=k-1;i>=0;--i)
			cur[i+1] += cur[i] * (k-i)/k,
			cur[i] *= 1.0*i/k;
		rep(i,0,q)
			if(ans[i] == -1 && cur[k] >= (qry[i]-1e-7)/2000.0)
				ans[i] = day;
	}

	rep(i,0,q)
		cout<<ans[i]<<endl;

	return 0;
}