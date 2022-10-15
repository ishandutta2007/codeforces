#include <cstdio>
int t,n,ans,res;
char c;
inline int read(){
	res=0;
	for(;c<'0'||c>'9';c=getchar());
	for(;!(c<'0'||c>'9');c=getchar())res=(res<<1)+(res<<3)+(c^48);
	return res;
}
int main(){
	t=read();
	for(register int i=0;i<t;++i){
		n=read(),ans=0x7fffffff;
		for(register int j=0;j<n;++j)ans&=read();
		printf("%d\n",ans);
	}
	return 0;
}