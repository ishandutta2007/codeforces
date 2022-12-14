#include<bits/stdc++.h>
using namespace std;


struct Test{
	int l,t;
	Test(int l_=0,int t_=0):l(l_),t(t_){}
	bool operator<(const Test& rhs)const{
		if(t==rhs.t)	return l<rhs.l;
		return t<rhs.t;
	}
}Te[200001];
int A[200002];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n,T,a,b;
		cin>>n>>T>>a>>b;
		for(int i=1;i<=n;i++)
			cin>>Te[i].l;
		for(int i=1;i<=n;i++)
			cin>>Te[i].t;
		sort(Te+1,Te+n+1);
		long long int pre=0;
		A[n+1]=0;
		for(int i=n;i>=1;i--)
			A[i]=A[i+1]+(Te[i].l==0);
		int ans=0;
		for(int i=1;i<=n;i++){
			if(pre<=Te[i].t-1){
				long long int delta=Te[i].t-1-pre;
				if(delta/a>=A[i]){
					delta-=A[i]*a;
					ans=max(ans,i-1+A[i]+min(n-i+1-A[i],int(delta/b)));
				}
				else
					ans=max(ans,int(i-1+delta/a));
			}
			pre+=(Te[i].l==0?a:b);
		}
		if(pre<=T)
			ans=n;
		cout<<ans<<'\n';
	}
}