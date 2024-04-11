#include<bits/stdc++.h>
#define LL long long
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
	return w*c;
}
int n,k,ans=INT_MAX;
int main(){
	n=read(); k=read();
	for (int i=1;i<k;i++){
		if (n%i==0){
			int o=n/i;
			ans=min(ans,o*k+i);
		}
	}
	cout<<ans<<"\n";
	return 0;
}