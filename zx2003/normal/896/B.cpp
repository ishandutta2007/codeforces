#include<cstdio>
const int N=1005;
int n,m,c,i,a[N],x,l,r;
inline void read(int&x){
	scanf("%d",&x);fflush(stdout);
}
inline void out(int x){
	printf("%d\n",x);fflush(stdout);
}
int main(){
	scanf("%d%d%d",&n,&m,&c);fflush(stdout);l=0;r=n+1;
	while(m--){
		read(x);
		if(x==3){
			++x,--x;
		}
		if(x<<1<=c){
			if(!l || a[l]<=x)a[i=++l]=x;
				else{
					for(i=1;i<=l;++i)if(a[i]>x)break;
					a[i]=x;
				}
		}else{
			if(r>n || a[r]>=x)a[i=--r]=x;
				else{
					for(i=n;i>=r;--i)if(a[i]<x)break;
					a[i]=x;
				}
		}
		out(i);
		if(l+1==r)return 0;
	}
	return 0;
}