#include <bits/stdc++.h>
using namespace std;

string s,t;
void rotate(int l,int r,int k){
	l--; r--;
	k%=(r-l+1);
	for(int i=l;i<=r;i++){
		int nex=i+k;
		if(nex>r)nex-=r-l+1;
		t[nex]=s[i];
	}
	for(int i=l;i<=r;i++){
		s[i]=t[i];
	}
}

int main(){
	cin>>s;
	t=s;
	int T;
	scanf("%d",&T);
	for(;T>0;T--){
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		rotate(l,r,k);
	}
	cout<<s<<endl;
}