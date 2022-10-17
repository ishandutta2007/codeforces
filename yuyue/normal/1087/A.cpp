#include<bits/stdc++.h>
#define LL long long
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
	return w*c;
}
int n;
char a[50000];
string st;
int main(){
	scanf("%s",a+1);
	n=strlen(a+1);
	int p=n&1;
	int l=1,r=n;
	for (int i=1;i<=n;i++){
		if (!p){
			st+=a[r--];
		}
		else st+=a[l++];
		p^=1;
	}
	reverse(st.begin(),st.end());
	cout<<st<<"\n";
	return 0;
}