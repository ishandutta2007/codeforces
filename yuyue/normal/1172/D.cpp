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
const int M=2500;
int a[M][M],r[M],c[M],n,ct;
struct door{
	int x,y,xx,yy;
}ans[M*2];
void add(int x,int y,int xx,int yy){
	a[x][y]=a[xx][yy]=++ct;
	ans[ct]=(door){x,y,xx,yy};
}

int main(){
	n=read();
	F(i,1,n) r[i]=read();
	F(i,1,n) c[i]=read();
	F(i,1,n-1){
		int x=-1,y=-1;
		F(j,i,n) if (r[j]==i) x=j;
		F(j,i,n) if (c[j]==i) y=j;
//		cout<<x<<" "<<y<<"   hh\n"; 
		if (x==i && y==i) continue;
		if (x==n || y==n){
			add(x,i,i,y);
			swap(r[x],r[i]);
			swap(c[y],c[i]);
		}
		else{
			add(x,i,i,n);
			add(n,i,i,y);
			r[x]=r[n];
			r[n]=r[i];
			c[y]=c[n];
			c[n]=c[i];
		}
	/*	
		F(j,i,n){
			cout<<r[j]<<" , "<<c[j]<<"\n";
		}
		cout<<"---------------------\n";
	*/
	}
	cout<<ct<<"\n";
	F(i,1,ct){
		cout<<ans[i].x<<" "<<ans[i].y<<" "<<ans[i].xx<<" "<<ans[i].yy<<"\n";
	}
	/*
	cout<<"\n-------------------\n";
	F(i,1,n){
		F(j,1,n){
			cerr<<a[i][j]<<" ";
		}
		cerr<<"\n";
	}
	*/
	return 0; 
}