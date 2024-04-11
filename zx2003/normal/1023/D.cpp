#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,q,a[N],i,j,st[N],w,be[N],en[N],pos[N],xb;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>q;
	for(i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]){
			if(en[a[i]]){
					cout<<"NO\n";return 0;
			}else{
				for(;w && st[w]>a[i];--w)en[st[w]]=i-1;
				if(!w || st[w]!=a[i])st[++w]=a[i];
				if(!be[a[i]])be[a[i]]=i;
			}
		}else{
			if(w)a[i]=st[w];
			pos[++xb]=i;
		}
	}
	if(!be[q]){
		if(!xb){
			cout<<"NO\n";return 0;
		}
		a[pos[xb]]=q;
	}
	cout<<"YES\n";
	for(i=1;i<=n;++i){
		if(!a[i])a[i]=1;
		cout<<a[i]<<' ';
	}
	return 0;
}