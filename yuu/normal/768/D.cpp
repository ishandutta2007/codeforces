#include <bits/stdc++.h>
using namespace std;
int k, q;
vector <double> a;
double f[1001];
int main(){
	cin>>k>>q;
	f[0]=1;
	a.push_back(0);
	while(a.back()<0.5){		
		for(int i=k; i>=1; i--){
			f[i]=(f[i-1]*(k-i+1)+f[i]*i)/k;
		}
		f[0]=0;
		a.push_back(f[k]);
	}
	// cerr<<a.size()<<'\n';
	while(q--){
		int x;
		cin>>x;
		for(int i=0; i<a.size(); i++) if(a[i]*2000+(1e-7)>=x){
			cout<<i<<'\n';
			break;
		}
 	}
}