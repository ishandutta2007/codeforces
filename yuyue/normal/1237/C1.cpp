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
const int M=1e5+10;
struct node{
	int x,y,z,id;
}a[M],b[M],c[M],bb[M],aa[M];
int cb,ca;
bool cmp(node A,node B){
	return A.x==B.x ? (A.y==B.y ? (A.z<B.z) : (A.y<B.y)) : A.x<B.x; 
}
void solve1(int n){
	F(i,1,n/2){
		cout<<c[i*2-1].id<<" "<<c[i*2].id<<"\n";
	}
	if (n&1) bb[++cb]=c[n];
}
void solve2(int n){
	cb=0;
	F(i,1,n){
		int j=i; c[1]=b[i];
		while(j<n && b[j+1].y==b[j].y) j++,c[j-i+1]=b[j]; 
		solve1(j-i+1); 
		i=j;
	}
	F(i,1,cb/2) cout<<bb[i*2-1].id<<" "<<bb[i*2].id<<"\n";
	if (cb&1) aa[++ca]=bb[cb];  
}
void solve3(int n){
	F(i,1,n){
		int j=i; b[1]=a[i];
		while(j<n && a[j+1].x==a[j].x) j++,b[j-i+1]=a[j]; 
		solve2(j-i+1); 
		i=j;
	}
	F(i,1,ca/2) cout<<aa[i*2-1].id<<" "<<aa[i*2].id<<"\n";
}
int n;
int main(){
	n=read();
	F(i,1,n) a[i]=(node){read(),read(),read(),i};
	sort(a+1,a+n+1,cmp);
	solve3(n);
    return 0;
}