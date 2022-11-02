#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=(1<<21)+1;
const double PI=acos(-1.0);
int m;
char s[N];
int bit=1000;
struct Big{
	int len;
	LL a[N];
	void clear(){
		len=0;
		memset(a,0,sizeof a);
	}
	void print(){
		for (int i=len;i>=1;i--)
			printf("%03d",(int)a[i]);
		puts("");
	}
	bool operator >= (Big &x){
		if (len!=x.len)
			return len>x.len;
		for (int i=len;i>=1;i--)
			if (a[i]!=x.a[i])
				return a[i]>x.a[i];
		return 1;
	}
	void pushbits(){
		for (int i=1;i<=len;i++)
			a[i+1]+=a[i]/bit,a[i]%=bit;
		while (a[len+1]){
			len++;
			a[len+1]=a[len]/bit;
			a[len]%=bit;
		}
	}
	void operator *= (int x){
		for (int i=1;i<=len;i++)
			a[i]*=x;
		pushbits();
	}
}n,x,tmp;
struct C{
	double r,i;
	C(){}
	C(double _r,double _i){r=_r,i=_i;}
	C operator + (C x){return C(r+x.r,i+x.i);}
	C operator - (C x){return C(r-x.r,i-x.i);}
	C operator * (C x){return C(r*x.r-i*x.i,r*x.i+i*x.r);}
}A[N],B[N],w[N];
int R[N];
void FFT(C a[],int n){
	for (int i=0;i<n;i++)
		if (R[i]>i)
			swap(a[i],a[R[i]]);
	for (int t=n>>1,d=1;d<n;d<<=1,t>>=1)
		for (int i=0;i<n;i+=(d<<1))
			for (int j=0;j<d;j++){
				C tmp=w[t*j]*a[i+j+d];
				a[i+j+d]=a[i+j]-tmp;
				a[i+j]=a[i+j]+tmp;
			}
}
void Times (Big &a,Big &b,Big &c){
//	a.print();puts("*");b.print();puts("=");
	int n,d;
	for (n=1,d=0;n<a.len+b.len;n<<=1,d++);
	for (int i=0;i<n;i++){
		R[i]=(R[i>>1]>>1)|((i&1)<<(d-1));
		w[i]=C(cos(PI*2*i/n),sin(PI*2*i/n));
		A[i]=B[i]=C(0,0);
	}
	for (int i=1;i<=a.len;i++)
		A[i-1].r=a.a[i];
	for (int i=1;i<=b.len;i++)
		B[i-1].r=b.a[i];
	FFT(A,n),FFT(B,n);
	for (int i=0;i<n;i++)
		A[i]=A[i]*B[i],w[i].i*=-1.0;
	FFT(A,n);
	c.clear();
	for (int i=0;i<n;i++)
		c.a[i+1]=(LL)(A[i].r/n+0.5);
	c.len=n;
	while (c.a[c.len]==0&&c.len>1)
		c.len--;
	c.pushbits();
//	c.print();puts("");
}
void Pow(int y){
	if (y==0){
		x.clear();
		x.a[x.len=1]=1;
		return;
	}
	Pow(y/2);
	Times(x,x,x);
	if (y&1)
		x*=3;
}
bool check(Big &x,int y){
	tmp=x;
	tmp*=y;
//	tmp.print();puts(tmp>=n?">=":"<");n.print();puts("");
	return tmp>=n;
}
int main(){
	scanf("%s",s+1);
	n.len=strlen(s+1);
	int pw10[3]={1,10,100};
	for (int i=1;i<=n.len;i++)
		n.a[(n.len-i+1-1)/3+1]+=pw10[(n.len-i)%3]*(s[i]-'0');
	m=max(0,(int)(n.len*log(10)/log(3))-3);
	n.len=(n.len-1)/3+1;
//	n.print();
	if (n.len==1&&n.a[1]==1){
		puts("1");
		return 0;
	}
//	printf("%d\n",m);
//	system("pause");
	Pow(m);
/*	if (m>500){
		puts("1237489");
		return 0;
	}*/
//	system("pause");
	while (1){
//		x.print();
		for (int i=2;i<=4;i++)
			if (check(x,i)){
				printf("%d",m*3+i);
				return 0;
			}
		x*=3;
		m++;
	}
	return 0;
}