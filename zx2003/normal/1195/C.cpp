#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long f1,f2,g1,g2;
int n,h1[N],h2[N],i;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",h1+i);
	for(i=1;i<=n;++i)scanf("%d",h2+i);
	for(i=1;i<=n;++i){
		g1=max(f1,f2+h1[i]);
		g2=max(f2,f1+h2[i]);
		f1=g1;f2=g2;
	}
	cout<<max(f1,f2)<<endl;
}