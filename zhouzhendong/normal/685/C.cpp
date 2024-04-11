#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof x)
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define outval(x) cerr<<#x" = "<<x<<endl
#define outtag(x) cerr<<"-----------------"#x"-----------------\n"
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
                    For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int,int> pii;
LL read(){
    LL x=0,f=0;
    char ch=getchar();
    while (!isdigit(ch))
        f=ch=='-',ch=getchar();
    while (isdigit(ch))
        x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return f?-x:x;
}
const int N=100005;
const LL INF=3.01e18;
int T,n;
struct Point{
	LL x,y,z;
}p[N];
LL ansx,ansy,ansz;
void ckmin(LL &a,LL b){
	if (a>b)
		a=b;
}
void ckmax(LL &a,LL b){
	if (a<b)
		a=b;
}
int check(LL d){
	LL L0=-INF,R0=INF;
	LL L1=-INF,R1=INF;
	LL L2=-INF,R2=INF;
	LL L3=-INF,R3=INF;
	For(i,1,n){
		LL a=p[i].x,b=p[i].y,c=p[i].z;
		//|a-x|+|b-y|+|c-z|<=d
		//a+b+c-d<=x+y+z<=d+a+b+c  (c + l + y)
		//a+b-c-d<=x+y-z<=d+a+b-c  (c)
		//a-b+c-d<=x-y+z<=d+a-b+c  (l)
		//-a+b+c-d<=-x+y+z<=d-a+b+c(y)
		ckmax(L0,a+b+c-d),ckmin(R0,d+a+b+c);
		ckmax(L1,a+b-c-d),ckmin(R1,d+a+b-c);
		ckmax(L2,a-b+c-d),ckmin(R2,d+a-b+c);
		ckmax(L3,-a+b+c-d),ckmin(R3,d-a+b+c);
	}
	if (L0>R0||L1>R1||L2>R2||L3>R3)
		return 0;
	LL l0,r0,l1,r1,l2,r2,l3,r3;
	#define ckoL(x) if (x%2==0) x++;
	#define ckoR(x) if (x%2==0) x--;
	#define ckeL(x) if (x%2!=0) x++;
	#define ckeR(x) if (x%2!=0) x--;
	{//odd
		l0=L0,l1=L1,l2=L2,l3=L3;
		r0=R0,r1=R1,r2=R2,r3=R3;
		ckoL(l0);ckoR(r0);
		ckoL(l1);ckoR(r1);
		ckoL(l2);ckoR(r2);
		ckoL(l3);ckoR(r3);
		if (l0<=r0&&l1<=r1&&l2<=r2&&l3<=r3&&
			max(l0,l1+l2+l3)<=min(r0,r1+r2+r3)){
			if (l1+l2+l3>=l0){
				ansx=(l1+l2)/2;
				ansy=(l1+l3)/2;
				ansz=(l2+l3)/2;
			}
			else {
				LL ned=l0-l1-l2-l3;
				LL dt=min(ned,r1-l1);
				ckeR(dt);
				LL a=l1+dt;
				ned-=dt;
				dt=min(ned,r2-l2);
				ckeR(dt);
				LL b=l2+dt;
				ned-=dt;
				dt=min(ned,r3-l3);
				ckeR(dt);
				LL c=l3+dt;
				ned-=dt;
				assert(ned==0);
				ansx=(a+b)/2;
				ansy=(a+c)/2;
				ansz=(b+c)/2;
			}
			return 1;
		}
	}
	{//even
		l0=L0,l1=L1,l2=L2,l3=L3;
		r0=R0,r1=R1,r2=R2,r3=R3;
		ckeL(l0);ckeR(r0);
		ckeL(l1);ckeR(r1);
		ckeL(l2);ckeR(r2);
		ckeL(l3);ckeR(r3);
		if (l0<=r0&&l1<=r1&&l2<=r2&&l3<=r3&&
			max(l0,l1+l2+l3)<=min(r0,r1+r2+r3)){
			if (l1+l2+l3>=l0){
				ansx=(l1+l2)/2;
				ansy=(l1+l3)/2;
				ansz=(l2+l3)/2;
			}
			else {
				LL ned=l0-l1-l2-l3;
				LL dt=min(ned,r1-l1);
				ckeR(dt);
				LL a=l1+dt;
				ned-=dt;
				dt=min(ned,r2-l2);
				ckeR(dt);
				LL b=l2+dt;
				ned-=dt;
				dt=min(ned,r3-l3);
				ckeR(dt);
				LL c=l3+dt;
				ned-=dt;
				assert(1&&ned==0);
				ansx=(a+b)/2;
				ansy=(a+c)/2;
				ansz=(b+c)/2;
			}
			return 1;
		}
	}
	return 0;
}
void Solve(){
	n=read();
	For(i,1,n)
		p[i].x=read(),p[i].y=read(),p[i].z=read();
	ansx=ansy=ansz=0;
	LL L=0,R=INF,ans=INF;
	while (L<=R){
		LL mid=(L+R)>>1;
		if (check(mid))
			R=mid-1,ans=mid;
		else
			L=mid+1;
	}
	printf("%I64d %I64d %I64d\n",ansx,ansy,ansz);
//	cout<<ans<<endl;
}
int main(){
	T=read();
	while (T--)
		Solve();
	return 0;
}
/*
x + y + z = a + b + c
x + y - z = a
x - y + z = b
-x + y + z = c

x = (a + b) / 2
y = (a + c) / 2
z = (b + c) / 2
*/