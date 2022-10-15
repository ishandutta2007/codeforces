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
	for(int i=s.size()-1;i;i--){
		int x=s[i]-'0',y=s[i-1]-48;
		if(x+y>9){
			s[i-1]='1',s[i]=(x+y)%10+48;
			cout<<s<<endl;
			return;
		}
	}
	s[1]=s[0]+s[1]-48;
	for(int i=1;i<(int)s.size();i++)putchar(s[i]);puts("");
}
int main(){
	int test=read();
	while(test--)work();
	return 0;
}