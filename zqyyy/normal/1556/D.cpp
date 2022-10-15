#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=1e4+7;
int n,K,a[N];
inline int get_sum(int i,int j){
	int x,y;
	cout<<"or "<<i<<" "<<j<<endl;
	x=read();
	cout<<"and "<<i<<" "<<j<<endl;
	y=read();return x+y;	
}
int main(){
	n=read(),K=read();
	for(int i=2;i<=n;i++)a[i]=get_sum(i-1,i);
	int x=get_sum(1,3);
	a[1]=(0ll+x+a[2]+a[3])/2-a[3];
	for(int i=2;i<=n;i++)a[i]-=a[i-1];
	sort(a+1,a+n+1);
	cout<<"finish "<<a[K]<<endl;
	return 0;
}