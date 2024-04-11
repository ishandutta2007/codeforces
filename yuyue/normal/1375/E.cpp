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
const int M=2222;
int a[M],n,t[M],b[M],pos[M];
bool cmp(int x,int y){
	return a[x]==a[y] ? x>y : a[x]<a[y];
}
vector<int> v[M]; 
#define all(x) x.begin(),x.end(),cmp
int main(){
	n=read(); 
	F(i,1,n) t[i]=a[i]=read();
	sort(t+1,t+n+1); 
	int N=unique(t+1,t+n+1)-t-1;
	F(i,1,n){
		pos[i]=lower_bound(t+1,t+N+1,a[i])-t;
		b[pos[i]]++;
//		cout<<pos[i]<<"\n"; 
	}
	F(i,1,N) b[i]+=b[i-1];  
	DF(i,n,1) a[i]=b[pos[i]],b[pos[i]]--;
//	F(i,1,n) cout<<a[i]<<" "; cout<<"\n"; 
	int ct=0;
	F(i,1,n){
		F(j,i+1,n){
			if (a[i]>a[j]) v[j].pb(i),ct++;
		}
	}
	cout<<ct<<"\n";
	DF(i,n,1){
		sort(all(v[i]));
		F(j,0,SZ(v[i])){
			int y=v[i][j];
			cout<<y<<" "<<i<<"\n";
			swap(a[y],a[i]);
		}
	}
	return 0;
}