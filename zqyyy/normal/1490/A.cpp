#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))r=(r<<1)+(r<<3)+(ch^48),ch=getchar();
	return f?r:-r;
}
int n,a[55];
inline void work(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	int ans=0;
	for(int i=1;i<n;i++){
		int x=a[i],y=a[i+1];
		if(x<y)swap(x,y);
		while(x>y*2)y*=2,ans++;
	}
	cout<<ans<<endl;
}
int main(){
	int T=read();
	while(T--)work();
	return 0;	
}