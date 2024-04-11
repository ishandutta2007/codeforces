#include<bits/stdc++.h>
#define LL long long

using namespace std;

inline int read(){
	char ch=getchar(); int w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
	return w*c;
}
LL sum;
int n,A[250000],cnt,h[2000000];
int a[250000];
int main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),h[a[i]]++,sum+=a[i];
	for (int i=1;i<=n;i++){	
		if ((sum-a[i])&1 || (sum-a[i])/2>1e6) continue;
		h[a[i]]--;
		if (h[(sum-a[i])/2]) A[++cnt]=i;
		h[a[i]]++;
	}
	cout<<cnt<<"\n";
	for (int i=1;i<=cnt;i++) cout<<A[i]<<" ";
	return 0;
}