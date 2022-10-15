#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=107;
int n,p[N];
int ans[N][N];
inline bool cmp(int x,int y){
	cout<<"1 "<<x-1<<" "<<y-1<<endl;
	return read();
}
inline bool ask(int x,int y){
	if(!y)return 0;
	cout<<"2 "<<x-1<<" "<<y<<" ";
	for(int i=1;i<=y;i++)cout<<p[i]-1<<" ";
	return cout<<endl,read();
}
inline void work(){
	n=read();
	for(int i=1;i<=n;i++)p[i]=i;
	stable_sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			ans[i][j]=1;
	for(int i=n,j=n-1;i && j;i--){
		if(i==j){
			for(int x=i+1;x<=n;x++)
				for(int y=1;y<=i;y++)
					ans[p[x]][p[y]]=0;
			j--;
		}
		while(j && ask(p[i],j))j--;
	}
	cout<<3<<endl;
	for(int i=1;i<=n;i++,cout<<endl)
		for(int j=1;j<=n;j++)
			cout<<ans[i][j];
	read();
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}