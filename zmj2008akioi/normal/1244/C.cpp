#include <cstdio>
#include <stack>
__int128 n,p,w,d,g,x,y,dt,nx,ny,res;
char c;
std::stack<char> stack;
inline __int128 read(){
	res=0;
	for(;c<'0'||c>'9';c=getchar());
	for(;!(c<'0'||c>'9');c=getchar())res=(res<<1)+(res<<3)+(c^48);
	return res;
}
inline void write(__int128 x){
	if(!x)stack.push('0');
	while(x)stack.push((x%10)^48),x/=10;
	while(stack.size())putchar(stack.top()),stack.pop();
	putchar(' ');
}
void exgcd(__int128 a,__int128 b,__int128 &g,__int128 &x,__int128 &y){
	if(!b)g=a,x=1,y=0;
	else{exgcd(b,a%b,g,x,y);__int128 tmp=x;x=y,y=tmp-a/b*y;};
}
//
int main(){
	n=read(),p=read(),w=read(),d=read();
	exgcd(w,d,g,x,y);
	if(p%g!=0){printf("-1");return 0;}
	w/=g,d/=g,p/=g,x*=p,y*=p;
	if(x>0)dt=x/d*d,x-=dt,y+=dt/d*w;
	if(y>0)dt=y/w*w,y-=dt,x+=dt/w*d;
	if(x<0||y<0){printf("-1");return 0;}
	if(x+y<=n)write(x),write(y),write(n-x-y);
	else printf("-1");
	return 0;
}