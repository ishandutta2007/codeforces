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
int main(){
	n=read();
	for(int j=2;j<=n;j++){
		cout<<"? "; 
		for(int i=1;i<n;i++)cout<<"1 ";
		cout<<j<<endl;
		int x=read();
		if(x)p[x]=j-1;
	}
	for(int j=1;j<n;j++){
		cout<<"? "; 
		for(int i=1;i<n;i++)cout<<n<<" ";
		cout<<j<<endl;
		int x=read();
		if(x)p[x]=j-n;
	}
	int mn=1e9;
	for(int i=1;i<=n;i++)mn=min(mn,p[i]);
	for(int i=1;i<=n;i++)p[i]+=-mn+1;
	printf("! ");
	for(int i=1;i<=n;i++)printf("%d ",p[i]);
	puts("");
	return 0;
}