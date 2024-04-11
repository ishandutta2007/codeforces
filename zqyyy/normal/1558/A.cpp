#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=2e5+7;
int n,m,tot;
bool ans[N];
inline void work(){
	n=read(),m=read();
	for(int i=0;i<=n+m;i++)ans[i]=0;
	for(int o=0;o<2;o++){
		int x=(n+m+1)/2,y=n+m-x;
		for(int i=0;i<=x;i++){
			int j=n-(x-i);
			if(j>=0 && j<=y)ans[i+j]=1;
		}
		swap(n,m);
	}
	tot=0;
	for(int i=0;i<=n+m;i++)
		if(ans[i])tot++;
	printf("%d\n",tot);
	for(int i=0;i<=n+m;i++)
		if(ans[i])printf("%d ",i);
	puts("");
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}