#include <bits/stdc++.h>
using namespace std;
int n;
int p[100001];
double ft[100001];
void update(int u, int x){
	for(; u>0; u-=u&-u) ft[u]+=x;
}
double get(int u){
	double res=0;
	for(; u<=n; u+=u&-u) res+=ft[u];
	return res;
}
double E(double x){
	//C(x, 2)*C(x, 2)*(x-2)!/x!
	return (x)*(x-1)/4;
}
int main(){
	cin>>n;
	for(int i=1; i<=n; i++) cin>>p[i];
	double total=0;
	for(int i=1; i<=n; i++){
		total+=get(p[i]);
		update(p[i], 1);
	}
	for(int i=1; i<=n; i++) ft[i]=0;
	double sumdelta=0;
	for(int i=1; i<=n; i++){
		sumdelta-=get(p[i])*(n-i+1);
		update(p[i], i);
	}
	for(int len=1; len<=n; len++)	sumdelta+=E(len)*(n-len+1);
	sumdelta*=2;
	sumdelta/=n;
	sumdelta/=n+1;
	cout<<setprecision(16)<<fixed<<total+sumdelta<<'\n';
}