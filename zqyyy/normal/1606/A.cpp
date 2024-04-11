#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
string s;
inline void work(){
	cin>>s;
	int r=0;
	for(int i=1;i<(int)s.size();i++)
		if(s[i]!=s[i-1])r++;
	if(r&1)s[0]=195-s[0];
	cout<<s<<endl;
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
    int test=read();
    while(test--)work();
    return 0;
}