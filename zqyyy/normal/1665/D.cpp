#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
inline int query(int a,int b){
	cout<<"? "<<a<<" "<<b<<endl;
	return read();
}
inline void work(){
	int p=1;
	for(int i=0;i<30;i++){
		int t=1<<i,tmp=query(p,p+t+t);
		if(tmp==t)p+=t;
	}
	cout<<"! "<<(1<<30)-p<<endl;
}
int main(){
	int test=read();
	while(test--)work();
	return 0;
}