#include <bits/stdc++.h>
using namespace std;
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
#define ll long long
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=1e6+5;
int n,tp,id,mx,a[N],stk[N],b[N];
bool vis[N];
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]>mx)mx=a[i],id=i;
	}
   	int j=1;
   	for(int i=id+1;i<=n;i++,j++)b[j]=a[i];
   	for(int i=1;i<id;i++,j++)b[j]=a[i];
   	for(int i=1;i<=n;i++)a[i]=b[i];
	ll ans=0;
	for(int i=1;i<n;i++){
		int l=1,r=tp,res=1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(stk[mid]>a[i])l=mid+1,res=mid;
			else r=mid-1;
		}
		ans+=tp-res+1;
		while(tp && stk[tp]<a[i])tp--;
		stk[++tp]=a[i];
	}
	int mx=0;
	for(int i=1;i<n;i++)if(a[i]>=mx)mx=a[i],ans++,vis[i]=1;
	mx=0;
	for(int i=n-1;i;i--)if(a[i]>=mx){mx=a[i];if(!vis[i])ans++;}
	return cout<<ans,0;
}