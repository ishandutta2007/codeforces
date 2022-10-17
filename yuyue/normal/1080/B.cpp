#include<bits/stdc++.h>
#define LL long long

using namespace std;

inline int read(){
	char ch=getchar(); int w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
	return w*c;
}
int main(){
	int n=read(); 
	for (int i=1;i<=n;i++){
		LL l=read(),r=read(),ans=0;
		if (l&1) ans-=l,l++;
		LL d=r-l+1;
		if (d&1){
			cout<<ans-(d/2)+r<<"\n";
		}
		else cout<<ans-(d/2)<<"\n";
	}
	return 0;
}