#include<bits/stdc++.h>
#define LL long long
#define SZ(x) (int)x.size()-1
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
const int M=2e5+10;
int n;
struct node{
	int x,y,z;
}a[M];
int b[M];
void solve(){
	n=read(); 
	int xsum=0;
	F(i,1,n){
		b[i]=read();
		xsum^=b[i];
	}
	if (xsum && n%2==0){
		puts("NO");
		return ;
	}
	if (n%2==0) n--;
	puts("YES");
	int cnt=0;
	for (int i=1;i<n;i+=2){
		a[++cnt]=(node){i,i+1,i+2};
	}
	for (int i=n-2;i>1;i-=2){
		a[++cnt]=(node){i,i-1,i-2};
	}
	cout<<cnt<<"\n";
	F(i,1,cnt){
		cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<"\n";
	}
}
int main(){
	int T=1; 
	while (T--){
		 solve();
	}
    return 0;
}