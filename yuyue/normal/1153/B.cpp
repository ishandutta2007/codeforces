#include<bits/stdc++.h>
#define LL long long
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
const int M=1111;
int n,m,h;
int ft[M],lft[M];
bool b[M][M];
int main(){
	n=read(); m=read(); h=read();
	for (int i=1;i<=m;i++){
		ft[i]=read();
	}
	for (int i=1;i<=n;i++){
		lft[i]=read();
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			b[i][j]=read();
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (b[i][j]) cout<<min(lft[i],ft[j])<<" ";
			else cout<<"0 ";
		}
		cout<<"\n";
		
	}
    return 0;
}