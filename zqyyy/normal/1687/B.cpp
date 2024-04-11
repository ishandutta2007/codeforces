#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=507;
int n,m,a[N],id[N];
int query(string s){
	cout<<"? "<<s<<endl;
	return read();	
}
int main(){
//#ifndef ONLINE_JUDGE
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
//#endif
	n=read(),m=read();
	iota(id,id+m,0);
	for(int i=0;i<m;i++){
		string s(m,'0');
		s[i]='1',a[i]=query(s);
	}
	sort(id,id+m,[&](int x,int y){return a[x]<a[y];});
	int ans=0;
	string s(m,'0');
	for(int i=0;i<m;i++){
		int j=id[i];
		s[j]='1';
		int x=query(s);
		if(x==ans+a[j])ans=x;
		else s[j]='0';
	}
	cout<<"! "<<ans<<endl;
	return 0;
}