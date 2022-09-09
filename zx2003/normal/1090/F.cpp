#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1005;
int f[99][99];
int n,i,x,y,z;
ll a[N];
ll ff[99],aa[99];
ll ab[N];
inline void solve(int l,int r){
	static ll bb[99];
	int i,j;
	for(i=0;i<10;++i){
		cout<<"? ";
		for(j=0;j<3;++j)cout<<l+f[i][j]<<' ';
		cout<<endl;
/*
		ll mn=1ll<<60,mx=-mn;
		for(j=0;j<3;++j)mn=min(mn,ab[l+f[i][j]]),mx=max(mx,ab[l+f[i][j]]);
		aa[i]=mn+mx;
*/
		cin>>aa[i];cout<<endl;
	}
	memcpy(bb,aa,80);
	sort(bb,bb+10);
	ll ac=bb[0],ad=bb[1],be=bb[8],ce=bb[9],ae,bd,ace;
	for(i=3;i<7;++i){
		for(j=3;j<7;++j)if(i!=j && bb[j]==bb[i])break;
		if(j==7)break;
	}
	bd=bb[i];ae=i==3?bb[4]:bb[3];
	ace=(ac+ce+ae)/2;
	ff[0]=ace-ce;ff[2]=ace-ae;ff[4]=ace-ac;
	ff[1]=be-ff[4];ff[3]=ad-ff[0];
	for(;;){
		for(i=0;i<10;++i){
			ll mn=1ll<<60,mx=-mn;
			for(j=0;j<3;++j)mn=min(mn,ff[f[i][j]]),mx=max(mx,ff[f[i][j]]);
			if(mn+mx!=aa[i])break;
		}
		if(i==10)break;
		next_permutation(ff,ff+5);
	}
	memcpy(a+l,ff,40);
}
void dfs1(int d,int lst){
	static int a[99],xb;
	if(d==3){
		memcpy(f[xb++],a,12);
		return;
	}
	for(int i=lst+1;i<5;++i)a[d]=i,dfs1(d+1,i);
}
int main(){
//	srand(time(0));
//	cin>>n;for(i=1;i<=n;++i)cin>>ab[i];
//	for(i=1;i<=n;++i)ab[i]=rand()%(int(1e9))+1;
	dfs1(0,-1);
	cin>>n;cout<<endl;
	for(i=1;i+4<=n;i+=5)solve(i,i+4);
	if(n%5)solve(n-4,n);
	cout<<"! ";
	for(i=1;i<=n;++i)cout<<a[i]<<' ';
	cout<<endl;
//	for(i=1;i<=n;++i)if(a[i]!=ab[i])return puts("WA");
	return 0;
}