#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
typedef long long ll;
#define I inline void
#define IN inline int
#define C(x,y) memset(x,y,sizeof(x))
#define STS system("pause")
template<class D>I read(D &res){
	res=0;register D g=1;register char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')g=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		res=(res<<3)+(res<<1)+(ch^48);
		ch=getchar();
	}
	res*=g;
}
int n,m,a[101000],b[101000],s[101000],ans;
int main(){
	read(n);ans=n;
	F(i,1,n)read(a[i]);
	F(i,1,n){
		m=a[i];while(m)b[i]++,m>>=1;
	}
	F(i,1,n-1)if(a[i]>a[i+1])return printf("0"),0;
	F(i,2,n-1)if(b[i]==b[i-1]&&b[i]==b[i+1])return printf("1"),0;
	F(i,1,n)s[i]=s[i-1]^a[i];
	F(i,1,n-1)F(j,i,n-1)F(k,j+1,n)if((s[j]^s[i-1])>(s[k]^s[j]))ans=min(ans,k-i-1);
	if(ans==n)ans=-1;
	printf("%d",ans);
	return 0;
}