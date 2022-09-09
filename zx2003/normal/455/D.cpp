//#pragma GCC optimize("O2")
#include<cstdio>
#include<cstring>
#include<cctype>
const int N=100005;
int n,q,a[N],b[N],i,la,o,l,r,k;
inline void read(int&x){
	char c=getchar();
	for(;!isdigit(c);c=getchar());
	for(x=0;isdigit(c);c=getchar())x=x*10+c-48;
}
int main(){
	//freopen("1.txt","r",stdin);freopen("2.txt","w",stdout);
	read(n);
	for(i=1;i<=n;++i)read(a[i]);read(q);
	while(q--){
		read(o),read(l),read(r);l=(l+la-1)%n+1,r=(r+la-1)%n+1;
		if(l>r)i=l,l=r,r=i;
		if(o==1){
			if(l==r)continue;k=a[r];
			register int*p=a+r;
			for(i=r;i-7>l;p-=8,i-=8){
				*p=*(p-1);
				*(p-1)=*(p-2);
				*(p-2)=*(p-3);
				*(p-3)=*(p-4);
				*(p-4)=*(p-5);
				*(p-5)=*(p-6);
				*(p-6)=*(p-7);
				*(p-7)=*(p-8);
			}
			for(;i>l;--i,--p)*p=*(p-1);
			a[l]=k;
		}else{
			read(k),k=(k+la-1)%n+1;la=0;
			register int*p=a+l;
			for(i=l;i+7<=r;p+=8,i+=8){
				la+=
				(k==*p)+
				(k==*(p+1))+
				(k==*(p+2))+
				(k==*(p+3))+
				(k==*(p+4))+
				(k==*(p+5))+
				(k==*(p+6))+
				(k==*(p+7));
			}
			for(;i<=r;++i)la+=k==*p++;
			printf("%d\n",la);
		}
	}
	return 0;
}