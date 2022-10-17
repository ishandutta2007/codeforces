#include<bits/stdc++.h>
#define LL long long

using namespace std;

inline int read(){
	char ch=getchar(); int w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
	return w*c;
}
int n,m,f[200],maxn,ans;
int main(){
	n=read(); m=read();
	for (int i=1;i<=n;i++){
		int x=read();
		f[x]++;
	}
	for (int i=1;i<=100;i++){
		int k=f[i]/m;
		if (f[i]%m!=0){
			k++;
		}
		maxn=max(maxn,k);
	}
	for (int i=1;i<=100;i++){
		if (f[i]) ans+=maxn*m-f[i];
	}
	cout<<ans<<"\n";
	return 0;
}