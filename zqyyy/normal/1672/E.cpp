#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
inline int query(int w){
	cout<<"? "<<w<<endl;
	return read();	
}
int n;
int main(){
	n=read();
	int l=1,r=5e6;
	while(l<=r){
		int mid=(l+r)>>1;
		if(query(mid)==1)r=mid-1;
		else l=mid+1;	
	}
	ll ans=l;
	for(int i=1;i<n;i++){
		int x=l/(i+1);
		int y=query(x);
		if(y==i+1)ans=min(ans,1ll*x*(i+1));
	}
	printf("! %lld\n",ans);
	return 0;
}