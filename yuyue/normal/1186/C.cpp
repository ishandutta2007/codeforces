#include<bits/stdc++.h>
#define LL long long
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
const int M=1e6+10;
char a[M],b[M]; 
int s[M];
int ans;
int main(){
	scanf("%s%s",a+1,b+1);
	int l1=strlen(a+1);
	int l2=strlen(b+1);
	int c=0;
	for (int i=1;i<=l2;i++){
		if (a[i]!=b[i]) c^=1;
	}
	if (c==0) ans++;
	for (int i=2;i<=l1;i++){
		s[i]=s[i-1];
		if (a[i]!=a[i-1]) s[i]++;
	}
	for (int i=l2+1;i<=l1;i++){
		int k=s[i]-s[i-l2];
		k%=2;
		c^=k;
		if (c==0) ans++;
	}
	cout<<ans<<"\n";
    return 0;
}