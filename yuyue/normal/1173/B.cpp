#include<bits/stdc++.h>
#define LL long long
using namespace std;
int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
int n;
int main(){
	n=read();
	int m=1;
	for (int i=1;i<=1000;i++){
		if (2*i-1>=n) {
			m=i;
			break;
		}
	}
	bool f=0;
	cout<<m<<"\n";
	int t=0;
	for (int i=1;i<=m;i++){
		cout<<"1 "<<i<<"\n";
		t++;
		if (t==n) {
			f=1;
			break;
		}
	}
	if (f) return 0;
	for (int i=2;i<=m;i++){
		cout<<m<<" "<<i<<"\n";
		t++;
		if (t==n) {
			f=1;
			break;
		}
	}
	return 0;
}