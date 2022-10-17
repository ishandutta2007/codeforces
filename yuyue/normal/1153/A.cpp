#include<bits/stdc++.h>
#define LL long long
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
const int M=2e5+10;
int t[M],s[M],d[M],n,m,id[M];
bool cmp(int x,int y){
	return t[x]<t[y];
}
int main(){
	n=read(); m=read();
	for (int i=1;i<=n;i++){
		id[i]=i;
		s[i]=read(); d[i]=read();
		if (s[i]>=m) t[i]=s[i];
		else {
			int k=(m-s[i])/d[i];
			if ((m-s[i])%d[i]) k++;
			t[i]=s[i]+k*d[i];
		}
	}
	sort(id+1,id+n+1,cmp);
	cout<<id[1]<<"\n";
    return 0;
}