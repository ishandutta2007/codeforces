#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll kk,k,n,ans=0,res=0;
int a,b,sa[4][4],sb[4][4],d=0,x,y,tx,ty,t=0,used[4][4],win[4][4],w=0,pin[4][4],p;

int B(int u,int v){
	if (u==v) return 0;
	return (u==v+1||u+2==v)?1:-1;
}

int main(){
	cin>>k>>a>>b;kk=k;
	for (int i=1;i<=3;i++) for (int j=1;j<=3;cin>>sa[i][j++]);
	for (int i=1;i<=3;i++) for (int j=1;j<=3;cin>>sb[i][j++]);
	for (x=a,y=b;!used[x][y];tx=sa[x][y],ty=sb[x][y],x=tx,y=ty){
		used[x][y]=++t;
		win[x][y]=(w+=B(x,y));
		pin[x][y]=(p+=!B(x,y));
	}
	d=t+1-used[x][y];
	w=w+B(x,y)-win[x][y];
	p=p+(!B(x,y))-pin[x][y];
	if (k>233333){
		n=k/d;k%=d;
		n-=88;k+=88*d;
		ans=n*w;res=n*p;
	}
	for (x=a,y=b,t=0;t<k;tx=sa[x][y],ty=sb[x][y],x=tx,y=ty){
		ans+=B(x,y);res+=!B(x,y);
		t++;
	}
	cout<<((kk-res+ans)/2)<<" "<<((kk-res-ans)/2);
}