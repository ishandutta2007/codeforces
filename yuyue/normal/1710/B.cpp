#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
//#define mp make_pair
//#define OO(x) fixed<<setprecision(x)
using namespace std;
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=1e6+10;
int n,m,k;
int a[M],b[M],ct;
LL A[M];
map<int,LL> tk,tb;
struct node{
	LL x,h,id; 
}t[M];
bool cmp(node A,node B){
	return A.x==B.x ? A.id<B.id :A.x<B.x;
}
bool cmp1(node A,node B){
	return A.x==B.x ? A.id<B.id :A.x>B.x;
}
void work(){
	n=read(); m=read();
	tk.clear(); tb.clear();
	F(i,1,n){
		a[i]=read(); b[i]=read();
		int l=a[i]-b[i],r=a[i]+b[i];
		//(x-l)
		//-(x-a[i])+b[i]
		tk[l]++; tk[a[i]]--;
		tb[l]-=l; tb[a[i]]+=l;
		A[i]=0;
		tk[a[i]]--; tk[r]++;
		tb[a[i]]+=b[i]+a[i];
		tb[r]-=b[i]+a[i];
	}
	int la=-1e9; ct=0;
	LL curk=0,curb=0;
	for (auto O:tk){
		int nw=O.first;
		curk+=O.second; 
		curb+=tb[nw];
		if (curk*nw+curb>m){
			LL del=curk*nw+curb-m;
			t[++ct]=(node){nw,del,0};
//			cerr<<nw<<" "<<del<<" !!!!!\n";
		}
	}
	F(i,1,n){
		t[++ct]=(node){a[i],0,i};
	}
	sort(t+1,t+ct+1,cmp);
	LL mx=-1e18;
	F(i,1,ct){
		if (!t[i].id) mx=max(t[i].h-t[i].x,mx);
		else A[t[i].id]=max(A[t[i].id],mx+t[i].x);
	}
	sort(t+1,t+ct+1,cmp1);
	mx=-1e18;
	F(i,1,ct){
		if (!t[i].id) mx=max(t[i].h+t[i].x,mx);
		else A[t[i].id]=max(A[t[i].id],mx-t[i].x);
	}
	F(i,1,n){
		cout<<(A[i]<=b[i]);
	}
	cout<<"\n";
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int T=read();
	while (T--) work();
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
1
3 6
1 5
5 5
3 4
*/