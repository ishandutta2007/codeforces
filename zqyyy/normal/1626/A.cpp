#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}

inline void work(){
	string s;cin>>s;
	sort(s.begin(),s.end());
	cout<<s<<endl;
}
int main(){
	int test=read();
	while(test--)work();
	return 0;
}