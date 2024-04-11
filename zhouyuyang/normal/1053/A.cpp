#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
#define db long double
#define pii pair<int,int>
#define IT iterator

#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second

#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));

#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2

#define inf ((1<<30)-233)
#define sqr(x) ((x)*(x))
#define debug puts("wzpkking")
using namespace std;
int n,m,nn,mm,k;
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	int G=gcd(n,k); nn=n/G; k/=G;
	G=gcd(m,k); mm=m/G; k/=G;
	if (k!=1&&k!=2)
		return puts("NO"),0;
	if (k==1)
		if (n!=nn) nn*=2;
		else mm*=2;
	puts("YES"); 
	printf("0 0\n0 %d\n%d 0\n",mm,nn);
}