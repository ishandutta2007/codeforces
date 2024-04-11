#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=250007;
int n,a[N],f[N];
int tp1,stk1[N],tp2,stk2[N];
inline void work(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	stk1[tp1=1]=stk2[tp2=1]=1;
	for(int i=2;i<=n;i++){
		while(tp1 && a[stk1[tp1]]<a[i])tp1--;
		stk1[++tp1]=i;
		while(tp2 && a[stk2[tp2]]>a[i])tp2--;
		stk2[++tp2]=i;
		if(a[i]>a[i-1]){
			int p=stk1[tp1-1],l=1,r=tp2-1;
			while(l<r){
				int mid=(l+r)>>1;
				if(stk2[mid]>p)r=mid;
				else l=mid+1;	
			}
			f[i]=f[stk2[l]]+1;
		}else{
			int p=stk2[tp2-1],l=1,r=tp1-1;
			while(l<r){
				int mid=(l+r)>>1;
				if(stk1[mid]>p)r=mid;
				else l=mid+1;	
			}
			f[i]=f[stk1[l]]+1;
		}
	}
	printf("%d\n",f[n]);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	int test=read();
	while(test--)work();
	return 0;
}