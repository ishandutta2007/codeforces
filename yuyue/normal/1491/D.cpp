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
#define lowbit(x) (x&-x)
int a[50],b[50];
int main(){
	int Q=read();
	F(i,1,Q){
		int x=read(),y=read(),ca=0,cb=0;
		DF(j,30,0){
			if (x>>j&1) a[++ca]=j;
			if (y>>j&1) b[++cb]=j;
		}
//		cout<<ca<<" "<<cb<<"\n";
		if (x<=y && ca>=cb){
			int pos=1;
			bool fl=0;
			F(j,1,cb){
				while (pos<=ca && a[pos]>b[j]) pos++;
//				cout<<a[pos]<<" "<<b[j]<<" "<<ca<<"  mt \n";
				if (pos==ca+1){
					fl=1;
					break;
				}
				else pos++;
			}
			if (fl==1){
				puts("NO");
			}
			else puts("YES");
		}
		else puts("NO");
	}
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/