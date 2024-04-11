#include<cstdio>
#include<algorithm>
int a[55],n,i,j,f[55],s[55];
inline void up(int&a,int b){
	if(a<b)a=b;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",a+i),s[i]=s[i-1]+a[i];
	f[n]=a[n];
	for(i=n-1;i;--i)
		for(j=i;j<=n;++j)
			up(f[i],(s[n]-s[j]-f[j+1])+a[j]);
	printf("%d %d\n",s[n]-f[1],f[1]);
	return 0;
}