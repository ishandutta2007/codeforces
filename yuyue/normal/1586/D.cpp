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
const int M=1e3+10;
int a[M],n;
int main(){
	n=read(); a[n]=n;
	F(i,1,n-1){
		cout<<"? ";
		F(j,1,n-1){
			cout<<1<<" ";
		}
		cout<<i+1<<endl;
		int x; cin>>x;
		if (x) a[n]--;
	}
	F(i,1,n){
		if (i<a[n]){
			cout<<"? ";
			F(j,1,n-1){
				cout<<a[n]-i+1<<" ";
			}
			cout<<1<<endl;
			int x;
			cin>>x;
			a[x]=i;
		}
		if (i>a[n]){
			cout<<"? ";
			F(j,1,n-1){
				cout<<1<<" ";
			}
			cout<<i-a[n]+1<<endl;
			int x;
			cin>>x;
			a[x]=i;
		}
	}
	cout<<"! ";
	F(i,1,n) cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/