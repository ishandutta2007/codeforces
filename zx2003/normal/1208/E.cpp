#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
typedef long long ll;
int n,w,i,j,l,a[N],q[N],h,t;
ll b[N],c[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>w;
	for(;n--;){
		cin>>l;for(i=1;i<=l;++i)cin>>a[i];a[l+1]=0;
		if(w<=l*2){
			q[h=t=1]=0;
			for(i=1;i<=w;++i){
				if(i<=l+1){
					for(;h<=t && a[i]>=a[q[t]];--t);
					q[++t]=i;
				}
				if(l-q[h]>w-i)++h;
				b[i]+=a[q[h]];
			}
		}else{
			h=-(1<<30);
			for(i=1;i<=l;++i){
				h=max(h,a[i]);
				if(h>0)b[i]+=h;
			}
			if(h>0)c[l+1]+=h,c[w-l+1]-=h;
			h=-(1<<30);
			for(i=w;i>=w-l+1;--i){
				h=max(h,a[l-w+i]);
				if(h>0)b[i]+=h;
			}
		}
	}
	for(i=1;i<=w;++i)c[i]+=c[i-1],cout<<b[i]+c[i]<<' ';cout<<endl;
	return 0;
}