#include<bits/stdc++.h>
using namespace std;

int n,T,dc,ans;

namespace bit{
	int c[201000];
	void RE(){
		memset(c,0,sizeof c);
	}
	void add(int x){
		for (int i=x+1;i<=n+1;i+=(i&(-i))){
			c[i]++;
		}
	}
	int que(int x){
		int t=0;
		for (int i=x+1;i>0;i-=(i&(-i))){
			t+=c[i];
		}
		return t;
	}
}

int main(){
	scanf("%d%d",&n,&T);
	T--;
	if (T>n){
		dc=T-n;
		T=n;
	}
	for (int i=1,x;i<=n;i++){
		if (i>T) break;
		scanf("%d",&x);
		x=max(0,x-dc-i);
		bit::add(x);
		ans=max(ans,bit::que(T-i));
	}
	cout<<ans;
}