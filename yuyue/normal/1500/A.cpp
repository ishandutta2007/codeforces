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
const int M=2e5+10,N=5e6+10;
int a[M],p[M];
int v[N],vv[N];
bool cmp(int x,int y){
	return a[x]<a[y];
}
int n; 
int main(){
	n=read();
	F(i,1,n) a[i]=read();
	F(i,1,n) p[i]=i;
	sort(p+1,p+n+1,cmp);
	if (n<=5000){
		F(i,1,n){
			int x=p[i];
			F(j,i+1,n){
				int y=p[j];
				if (v[a[y]-a[x]]){
					puts("YES");
					cout<<y<<" "<<vv[a[y]-a[x]]<<" "<<v[a[y]-a[x]]<<" "<<x<<"\n";
					return 0;
				}
			}
			F(j,1,i-1){
				int y=p[j];
				v[a[x]-a[y]]=x;
				vv[a[x]-a[y]]=y;
			}
		}
		puts("NO");
		return 0;
	}
	else{
		puts("YES");
		F(i,2,n){
			int del=a[p[i]]-a[p[i-1]];
			if (v[del]){
				cout<<p[i]<<" "<<p[v[del]-1]<<" "<<p[v[del]]<<" "<<p[i-1]<<"\n";
				return 0;
			}
			if (i>=3){
				v[a[p[i-1]]-a[p[i-2]]]=i-1;
			}
		}
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