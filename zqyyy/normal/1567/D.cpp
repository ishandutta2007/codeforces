#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const ll pw[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000ll};
inline bool is_pw10(int x){
	for(int i=0;i<=9;i++)
		if(x==pw[i])return 1;
	return 0;	
}
inline int ws(int x){
	for(int i=0;i<=9;i++)
		if(x<pw[i+1])return i;
}
struct D{
	int x;
	bool operator <(const D &q) const {
		bool xx=is_pw10(x),yy=is_pw10(q.x);
		if(xx && yy){
			if(x==1)return 1;
			if(q.x==1)return 0;
			return x>q.x;	
		}
		else return xx>yy;
	}
};
int s,n;
priority_queue<D>q;
inline void work(){
	s=read(),n=read();
	while(!q.empty())q.pop();
	q.push({s}),n--;
	while(n--){
		int x=q.top().x;q.pop();
		int w=ws(x);
		if(!is_pw10(x))q.push({pw[w]}),q.push({x-pw[w]});
		else q.push({pw[w-1]}),q.push({x-pw[w-1]});
	}
	while(!q.empty())printf("%d ",q.top().x),q.pop();
	puts("");
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}