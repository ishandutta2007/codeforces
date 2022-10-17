#include<bits/stdc++.h>
#define LL long long
using namespace std;
int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=2e5+10;
int n;
int p[M],a[M],b[M];
bool t[M];
int GG(){
	int ans=p[1];
	for (int i=p[1]+1;i<=n;i++){
		if (b[i]){
			int bu=p[b[i]]-p[1];	
			if (bu>b[i]-1) ans=max(ans,p[1]+bu-b[i]+1);
		}
	}
	return ans+n;
}
bool check(){
	for (int i=p[1]+1;i<=n;i++){
		if (b[i]-1!=b[i-1]) return 0;
	}
	for (int i=1;i<p[1];i++){
		if (b[i]){
			int bu=p[b[i]];
			if (bu>b[i]-b[n]-1) return 0; //?
		}
	}
	return 1;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++) {
		a[i]=read();
		if (a[i]) {
			t[a[i]]=0;
			p[a[i]]=i;
		}
	}
	for (int i=1;i<=n;i++) {
		b[i]=read();
		if (b[i]) {
			t[b[i]]=1;
			p[b[i]]=i;
		}
	}
//	int ans=0;
	if (t[1] && check()){
		cout<<n-b[n]<<"\n";
		return 0;
	}
	if (t[1]){
		cout<<GG()<<"\n";
		return 0;
	}
	if (!t[1]){
		int y=0;
		for (int i=1;i<=n;i++){
			if (b[i]){
				int bu=p[b[i]];
				if (bu>b[i]-1) y=max(y,bu-b[i]+1); //?
			}
		}
		cout<<y+n<<"\n";
		return 0;
	}
	return 0;
}