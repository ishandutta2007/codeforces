#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
//#define mp make_pair
using namespace std;
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=2222;
int n,k,sz,num;
bool diff[M];
bool qry(int x){
	cout<<"? "<<x<<endl;
	char o; cin>>o;
	return o=='Y';
}
void add(int o){
//	cerr<<o<<" !!!!! \n";
	F(i,o*sz+1,o*sz+sz){
		if (diff[i] && qry(i)) diff[i]=0;
	}
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read(); k=read(); sz=max(k/2,1); num=n/sz;//num of vertex
	F(i,1,n) diff[i]=1;
	F(i,0,num/2-1){//bg
		int del=0;
		add(i);
		F(j,1,num-1){
			if (j&1) del=-del+1;
			else del=-del;
			add((i+del+num)%num);
		}
		cout<<"R"<<endl;
	}
	int ans=0;
	F(i,1,n) ans+=diff[i];
	cout<<"! "<<ans<<endl;
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/