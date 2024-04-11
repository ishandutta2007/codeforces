#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=2e5+7;
int n;
char str[N];
inline void work(){
	scanf("%s",str+1),n=strlen(str+1);
	int cnt=0,fl=0;
	for(int i=1;i<=n;i++){
		if(str[i]=='A')cnt++,fl=0;
		else if(!cnt){puts("NO");return;}
		else fl=1,cnt--;	
	}
	puts(!fl?"NO":"YES");
}
int main(){
	int test=read();
	while(test--)work();
	return 0;
}