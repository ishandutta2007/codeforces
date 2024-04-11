#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

long long K(int y,long long x=10){
	long long t=1; for (;y;y>>=1,x=x*x%mod) if (y&1) t=t*x%mod; return t;
}

char s[1001000];
int n,a[1001000];
bool D(int x,int y) { return y>1&&s[x-y]=='0'; }
#define val(xx,x,p) (x<p?0:s[xx-p]-48)
void doit(int x,int y,int z){
	if (x<=0||y<=0||z<=0) return;
	if (max(x,y)!=z&&max(x,y)!=z-1) return;
	int xx=x+1,yy=x+y+1,zz=n+1,b,t,p;
	if (D(xx,x)||D(yy,y)||D(zz,z)) return;
	if (
		( a[xx-1]
		+(a[yy-1]-a[xx-1]*K(y)%mod)
		-(a[zz-1]-a[yy-1]*K(z)) )%mod
	   ) return;
	b=0;
	for (int i=1;i<=z;++i){
		t=val(xx,x,i)+val(yy,y,i)+b;
		if (t%10!=val(zz,z,i)) return;
		b=t/10;
	}
	if (!b){
		for (int i=1;i<=n;++i){
			if (i==xx) printf("%c",'+');
			if (i==yy) printf("%c",'=');
			printf("%c",s[i]);
		}
		exit(0);
	}
}

int main(){
	srand(time(0));
	scanf("%s",s+1); n=strlen(s+1);
	for (int i=1;i<=n;++i) a[i]=(a[i-1]*10ll+(s[i]-'0'))%mod;
	for (int i=1,j,k;i<=n-2;++i){
		j=i,  k=n-i-j; doit(j,k,i);
		j=i-1,k=n-i-j; doit(j,k,i);
		k=i,  j=n-i-k; doit(j,k,i);
		k=i-1,j=n-i-k; doit(j,k,i);
	}
}