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
int n,p[N];
inline int query(int i){cout<<"? "<<i<<endl;return read();}
inline void work(){
	n=read();
	for(int i=1;i<=n;i++)p[i]=0;
	for(int i=1;i<=n;i++)if(!p[i]){
		int lst=query(i),c=lst;
		while(1){
			int x=query(i);
			p[lst]=x,lst=x;
			if(x==c)break;
		}
	}
	cout<<"! ";
	for(int i=1;i<=n;i++)cout<<p[i]<<" ";
	cout<<endl;
}
int main(){
	int test=read();
	while(test--)work();
    return 0;
}