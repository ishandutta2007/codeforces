#include <cstdio> 
const int N=5005,inf=1<<30;
int n,i,j,a[N],f[N],s[N],b[N][N],*c,m[N],x,d;
inline void up(int&a,int b){
	if(a<b)a=b;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",a+i);
		++s[a[i]];
	}
	for(i=1;i<=n;++i){
		c=b[i];
		x=d=0;
		for(j=i;j;--j){
			if(!c[a[j]])--d,x^=a[j];
			++c[a[j]];
			if(c[a[j]]==s[a[j]])++d;
			if(d==0)up(f[i],m[j-1]+x);
		}
		m[i]=f[i];
		if(i>1)up(m[i],m[i-1]);
	}
	printf("%d\n",m[n]);
	return 0;
}