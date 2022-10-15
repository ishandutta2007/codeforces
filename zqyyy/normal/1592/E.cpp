#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=1e6+7;
int n,a[N],b[1<<21][2];
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	int ans=0;
	for(int i=0;i<(1<<20);i++)b[i][0]=b[i][1]=1e9;
	for(int j=19;~j;j--){
		int l=1,r=1;
		for(;l<=n;l=++r){
			while((a[r]>>j&1) && r<=n)r++;
			if(l==r)continue;r--;
			int res=0;b[0][(l-1)&1]=l-1;
			for(int i=l;i<=r;i++){
				res^=a[i];
				ans=max(ans,i-b[res>>(j+1)][i&1]);
				b[res>>(j+1)][i&1]=min(b[res>>(j+1)][i&1],i);
			}
			res=0,b[0][(l-1)&1]=1e9;
			for(int i=l;i<=r;i++)res^=a[i],b[res>>(j+1)][i&1]=1e9;
		}
	}
	printf("%d\n",ans);
	return 0;
}