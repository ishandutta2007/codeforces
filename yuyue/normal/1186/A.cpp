#include<bits/stdc++.h>
#define LL long long
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
int n,a,b;
int main(){
	n=read(); a=read(); b=read();
	if (a>=n && b>=n) {
		cout<<"Yes"<<"\n";
	}
	else cout<<"No\n";
    return 0;
}