#include <cstdio>
#include <cctype>
#include <queue>
#define re register
using namespace std;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
char getc(){
	char ch=getchar();
	while(ch==' ' || ch=='\n')ch=getchar();
	return ch;
}
const int N=2e5+1;
int n,tp,b[N],st[N];
bool vis[N<<1];
priority_queue<int>q;
int main(){
	n=read();
	for(re int i=1;i<=2*n;i++){
		char op=getc();
		if(op=='+') vis[i]=0;
		else vis[i]=1,b[i]=read();
	}
	for(re int i=2*n;i;i--)
		if(vis[i])
			st[++tp]=b[i];
        else{
			b[i]=st[tp--];
			if(tp<0)return puts("NO"),0;	
		}
	for(re int i=1;i<=2*n;i++)
		if(vis[i]){
			int x=-q.top();q.pop();
			if(x!=b[i])return puts("NO"),0;
		}else q.push(-b[i]);
	puts("YES");
	for(re int i=1;i<=2*n;i++)if(!vis[i])printf("%d ",b[i]);
	return 0;	
}