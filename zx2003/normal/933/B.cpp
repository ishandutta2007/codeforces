#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p,k,x,a[1000],b[1000];int xb;
vector<ll>ans;
int main(){
	cin>>p>>k;
	a[0]=p%k,b[0]=-p/k;
	for(;b[xb];){
		a[xb+1]=(b[xb]%k+k)%k;++xb;
		b[xb]=(a[xb]-b[xb-1])/k;
	}
	printf("%d\n",1+xb);
	for(int i=0;i<=xb;++i)cout<<a[i]<<' ';
	return 0;
}