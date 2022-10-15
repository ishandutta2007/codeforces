#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=((r<<1)+(r<<3)+(c&15)),c=getchar();
	return f?r:-r;
}
const double eps=1e-10;
int n,a[77];
inline void work(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	if(n==1){puts("0");return;}
	int ans=1e9;
	for(int l=1;l<=n;l++)
		for(int r=l+1;r<=n;r++){
			double d=1.*(a[r]-a[l])/(r-l);
			double a1=a[l]-d*(l-1);
			int num=0;
			for(int i=1;i<=n;i++)
				if(abs(a1+d*(i-1)-a[i])>eps)num++;
			ans=min(ans,num);
		}
	printf("%d\n",ans);
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	int test=read();
	while(test--)work();
    return 0;
}