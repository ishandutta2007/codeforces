#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=2e5+7;
int n,a[N],id[N];
inline bool is_p(int x){
	if(x<=3)return 1;
	for(int i=2;i*i<=x;i++)
		if(x%i==0)return 0;
	return 1;	
}
inline void out(int x){
	printf("%d\n",n-(x>0));
	for(int i=1;i<=n;i++)if(i!=x)printf("%d ",i);
	puts("");	
}
inline void work(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),id[i]=i;
	sort(id+1,id+n+1,[](int x,int y){return a[x]>a[y];});
	int sum=0;
	for(int i=1;i<=n;i++)sum+=a[id[i]];
	if(!is_p(sum))out(0);
	else for(int i=n;i;i--)if(!is_p(sum-a[id[i]])){out(id[i]);return;}
}
int main(){
	int test=read();
	while(test--)work();
	return 0;
}