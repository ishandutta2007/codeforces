#include<bits/stdc++.h>
#define LL long long
using namespace std;
int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=1e5+10;
int n,m,k;
int w[M],cha[M];
int main(){
	n=read(); m=read(); k=read();
	for (int i=1;i<=n;i++){
		w[i]=read();
		cha[i-1]=w[i]-w[i-1];
	}
	int ans=n;
	sort(cha+1,cha+n);
	for (int i=1;i<=n-k;i++){
		ans+=cha[i]-1;
	}
	cout<<ans<<"\n";
	return 0;
}