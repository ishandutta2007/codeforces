#include<bits/stdc++.h>
#define LL long long
using namespace std;
int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
int n,tot;
LL ans[500000];
int main(){
	n=read();
	for (int i=1;i*i<=n;i++){
		if (n%i==0){
			ans[++tot]=1ll*(1+n-i+1)*(n/i)/2;
			ans[++tot]=1ll*(1+n-n/i+1)*(i)/2;
		}
	}
	sort(ans+1,ans+tot+1);
	int k=unique(ans+1,ans+tot+1)-ans-1;
	for (int i=1;i<k;i++)
	cout<<ans[i]<<" ";
	cout<<ans[k]<<"\n";
	return 0;
}