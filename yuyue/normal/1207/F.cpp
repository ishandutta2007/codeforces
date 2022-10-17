// luogu-judger-enable-o2
// luogu-judger-enable-o2
// luogu-judger-enable-o2
// luogu-judger-enable-o2
#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int M=5e5+100,N=650;
int a[M],sum[N][N];
int size,n,m;
char ch;
inline int read(){
	ch=getchar(); int w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
	return w*c;
}
void change(int x,int v){
	for (int i=1;i<=size;i++){
		sum[i][x%i]+=v;
	}
}
int query(int x,int y){
	int ans=0;
	for (int i=y;i<=M-5;i+=x){
		ans+=a[i];
	}
	return ans;
}
int main(){
	m=read(); size=600;
	for (int i=1;i<=m;i++){
		int tp=read(),x=read(),y=read();
		if (tp==2){
			if (x<size) cout<<sum[x][y]<<"\n";
			else cout<<query(x,y)<<"\n";
		} 
		else {
			a[x]+=y;
			change(x,y);
		}
	}
	return 0;
}