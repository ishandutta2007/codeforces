#include<bits/stdc++.h>
#define mo 998244353
#define N 4200000 
using namespace std;

int a[N],b[N];
int R[N],ans,n;
char s[N];

int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s; 
}
void FFT(int *a,int n,int f){
	for (int i=1;i<n;i++)
		if (i<R[i]) swap(a[i],a[R[i]]);
	for (int d=1;d<n;d<<=1){
		int wn=power(3,(mo-1)/(d<<1));
		if (f==-1) wn=power(wn,mo-2);
		for (int i=0;i<n;i+=(d<<1))
			for (int j=i,w=1;j<i+d;j++){
				int y=1ll*w*a[j+d]%mo;
				a[j+d]=(a[j]+mo-y)%mo;
				a[j]=(a[j]+y)%mo; 
				w=1ll*w*wn%mo; 
			}
	}
	if (f==-1){
		int v=power(n,mo-2);
		for (int i=0;i<n;i++)
			a[i]=1ll*a[i]*v%mo;
	}
}

int smaller(int *b,int cntb){
	if (n!=cntb) return n>cntb;
	for (int i=n;i>=0;i--)
		if (s[i]!=b[i]) return s[i]>b[i];
	return 0;
}
void solve(){
	int tmp=floor((log(10)/log(3))*n+(log(s[n])/log(3)));
	tmp=max(0,tmp-2);
	memset(b,0,sizeof(b));
	int cntb=0; b[0]=1;
	int high=0;
	for (;(1<<high)<=tmp;high++); high--;
	for (;high>=0;high--){
		int c=1,L=0;
		for (;c<=2*cntb;c<<=1,L++);
		for (int i=0;i<c;i++)
			R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
		FFT(b,c,1);
		for (int i=0;i<c;i++)
			b[i]=1ll*b[i]*b[i]%mo;
		FFT(b,c,-1);
		int newcntb=0;
		for (int i=0;i<=2*cntb+5;i++){
			if (b[i]) newcntb=i;
			b[i+1]+=b[i]/10; b[i]%=10;
		}
		cntb=newcntb;
		if (tmp&(1<<high)){
			for (int i=0;i<=cntb;i++) b[i]*=3;
			for (int i=0;i<=cntb+5;i++){
				if (b[i]) newcntb=i;
				b[i+1]+=b[i]/10; b[i]%=10;
			}
			cntb=newcntb;
		}
	}
	for (;smaller(b,cntb);tmp++){
		int newcntb=0;
		for (int i=0;i<=cntb;i++) b[i]*=3;
		for (int i=0;i<=cntb+5;i++){
			if (b[i]) newcntb=i;
			b[i+1]+=b[i]/10; b[i]%=10;
		}
		cntb=newcntb; 
		if (!smaller(b,cntb)) ans=min(ans,(tmp+1)*3);
		int cnta=0;
		for (int i=0;i<=cntb+3;i++) a[i]=b[i]*2;
		for (int i=0;i<=2*cntb+5;i++){
			if (a[i]) cnta=i;
			a[i+1]+=a[i]/10; a[i]%=10;
		}
		if (!smaller(a,cnta)) ans=min(ans,(tmp+1)*3+2);
		for (int i=0;i<=cntb+3;i++) a[i]=b[i]*4;
		for (int i=0;i<=cntb+5;i++){
			if (a[i]) cnta=i;
			a[i+1]+=a[i]/10; a[i]%=10;
		}
		if (!smaller(a,cnta)) ans=min(ans,(tmp+1)*3+4);
	}
}
int main(){
	ans=1e9;
	scanf("%s",s);
	n=strlen(s);
	reverse(s,s+n);
	if (n==1&&s[0]<='5')
		return printf("%d\n",s[0]-'0'),0; 
	for (int i=0;i<n;i++) s[i]-='0'; n--;
	solve();
	printf("%d\n",max(ans,1));
}