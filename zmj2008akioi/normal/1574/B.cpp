#include <cstdio>
int t,a,b,c,m,cnt1,cnt2;
inline void swap(int &x,int &y){x^=y^=x^=y;};
int main(){
	scanf("%d",&t);
	for(register int i=0;i<t;++i){
		scanf("%d %d %d %d",&a,&b,&c,&m);
		if(a>b)swap(a,b);
		if(a>c)swap(a,c);
		if(b>c)swap(b,c);
		if(c>a+b)cnt1=c-a-b-1;
		else cnt1=0;
		cnt2=a+b+c-3;
		if(m>=cnt1&&m<=cnt2)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}