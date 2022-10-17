#include<bits/stdc++.h>
#define LL long long
#define pb push_back
using namespace std;
int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=100;
struct node{
	int x,y;
}a[M];
bool X(int pp,int l,int r,node A){
	return A.y==pp&&A.x>=l&&A.x<=r;
}
bool Y(int pp,int l,int r,node A){
	return A.x==pp&&A.y>=l&&A.y<=r;
}
int n;
int main(){
	n=read(); n=4*n+1;
	for (int i=1;i<=n;i++){
		a[i].x=read();
		a[i].y=read();
	}
	for (int i=0;i<=50;i++){
		for (int j=0;j<=50;j++){
			for (int k=1;k<=50;k++){
				int t=0,pl=0;
				for (int ii=1;ii<=n;ii++){
					if (X(j,i,i+k,a[ii]) || X(j+k,i,i+k,a[ii]) || Y(i,j,j+k,a[ii]) || Y(i+k,j,j+k,a[ii])) t++;
					else pl=ii;
				}
//				cout<<i<<" "<<j<<" "<<k<<" "<<t<<"\n";
				if (t==n-1){
					cout<<a[pl].x<<" "<<a[pl].y<<"\n";
					return 0;
				}
			}
		}
	}
	return 0;
}