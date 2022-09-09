#include<cstdio>
#include<cctype>
typedef long long ll;
inline int getint(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	for(;isdigit(c);c=getchar())x=x*10+c-48;
	return x*f;
}
ll l,r,m,a,b,d;
int n;
ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}
int main(){
	scanf("%d",&n);
	while(n--){
		a=getint();
		b=getint();
		d=gcd(a,b);
		d*=d;
		if(d%a!=0 || d%b!=0){
			puts("No");
			continue;
		}
		l=1;
		r=1000000;
		d=a*b;
		if(r>d)r=d;
		while(l<r){
			m=(l+r)>>1;
			if(m*m*m<d)l=m+1;
				else r=m;
		}
		puts(l*l*l==d?"Yes":"No");
	}
	return 0;
}