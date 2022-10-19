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
const int M=1010;
int n,k,bl[M],a[M][M],mx;
void solve(int l,int r,int col){
	if (l==r) return ;
	int le=r-l+1,bg=l;
	int sz=le/k,res=le%k;
	mx=max(mx,col);
	int cnt=0;
	vector<int> L,R; 
	F(i,1,res){
		cnt++;
		L.pb(bg);
		F(j,1,sz+1){
			bl[bg++]=cnt;
		}
		R.pb(bg-1); 
	}
	F(i,1,k-res){
		cnt++;
		L.pb(bg);
		F(j,1,sz){
			bl[bg++]=cnt;
		}
		R.pb(bg-1);
	}
	F(i,l,r){
		F(j,l+1,r){
			if (bl[i]!=bl[j]){
				a[i][j]=col;
			}
		}
	}
	F(i,0,SZ(L)){
		if (L[i]<=R[i]){
			solve(L[i],R[i],col+1);
		}
	}
}
int main(){
	n=read(); k=read(); 
	solve(1,n,1);
	cout<<mx<<"\n";
	F(i,1,n){
		F(j,i+1,n){
			cout<<a[i][j]<<" ";
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