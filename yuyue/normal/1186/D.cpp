#include<bits/stdc++.h>
#define LL long long
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
const int M=1e5+10;
int n,ans[M];
double w[M];
LL tot;
int main(){
	n=read();
	for (int i=1;i<=n;i++){
		cin>>w[i];
		tot+=(LL)floor(w[i]);
	}
	for (int i=1;i<=n;i++){
		if (w[i]==floor(w[i])) {
			ans[i]=w[i];
		}
		else {
			if (tot<0) tot++,ans[i]=ceil(w[i]);
			else ans[i]=floor(w[i]);
		}
		cout<<ans[i]<<"\n";
	}
    return 0;
}