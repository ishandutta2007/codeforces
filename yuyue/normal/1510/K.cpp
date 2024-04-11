#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=2010;
int n,p[M],t[M];
void op1(){
	F(i,1,n) swap(t[i],t[i+n]); 
}
void op2(){
	F(i,1,n) swap(t[i*2],t[i*2-1]);
}
bool chk(){
	F(i,2,2*n) if (t[i]<t[i-1]) return 0;
	return 1;
}
int main(){
	n=read();
	F(i,1,2*n) p[i]=read();
	F(l,1,2*n) t[l]=p[l];
	if (chk()){
		cout<<0<<"\n";
		return 0; 
	}
//	if (n%2==0){
//		F(i,0,8){
//			F(j,0,(1<<i)-1){
//				F(l,1,2*n) t[l]=p[l];
//				F(k,0,i-1){
//					if (j>>k&1) op1();
//					else op2();
//				}
//				if (chk()){
//					cout<<i<<"\n";
//					return 0;
//				}
//			}
//		}
//		puts("-1");
//		return 0;
//	}
	int a1=1e9;
	F(l,1,2*n) t[l]=p[l];
	F(i,1,4*n){
		if (i&1) op1();
		else op2();
		if (chk()){
			a1=i;
			break;
		}
	}
	int a2=1e9;
	F(l,1,2*n) t[l]=p[l];
	F(i,1,4*n){
		if (i&1) op2();
		else op1();
		if (chk()){
			a2=i;
			break;
		}
	}
	if (min(a1,a2)==1e9) puts("-1");
	else cout<<min(a1,a2)<<"\n";
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/