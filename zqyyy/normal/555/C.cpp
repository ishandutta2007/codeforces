#include <bits/stdc++.h>
using namespace std;
#define min(x,y) ((x)<(y)?(x):(y))
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=2e5+5;
struct node{
	int x,y,l,r;
	bool operator <(const node &q) const {
		if(l==q.l)return r<q.r;
		return l<q.l;
	}
};
int n,Q;
set<node>s;
int main(){
	n=read(),Q=read();
	s.insert((node){0,0,1,0});
	s.insert((node){1,1,1,n});
	while(Q--){
		int x=read(),y=read();swap(x,y);char op;
		while((op=getchar())==' ');
		node a=*--s.lower_bound((node){233,233,x,n+1});
		if(a.r>=x && a.l<=x){
			s.erase(a);
			if(op=='L'){
				printf("%d\n",y-a.y+1);
				if(a.l<=x-1)s.insert((node){a.x,a.y,a.l,x-1});
				if(x+1<=a.r)s.insert((node){x+1,a.y,x+1,a.r});
			}else{
				printf("%d\n",x-a.x+1);
				if(x+1<=a.r)s.insert((node){a.x,a.y,x+1,a.r});
				if(a.l<=x-1)s.insert((node){a.x,y+1,a.l,x-1});
			}
		}else puts("0");
		
	}
	return 0;
}