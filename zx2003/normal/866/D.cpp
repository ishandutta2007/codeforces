#include<cstdio>
#include<queue>
#include<iostream>
using namespace std;
struct node{
	int v;
	bool b;
	bool operator<(const node&rhs)const{
		return v>rhs.v;
	}
}z;
priority_queue<node> q;
int n,x;
long long ans;
bool f;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&x);
		if(!q.empty() && q.top().v<x){
			z=q.top(),q.pop();
			ans+=x-z.v;
			q.push((node){x,1});
			if(z.b)q.push((node){z.v,0});
		}else q.push((node){x,0});
	}
	return cout<<ans<<endl,0;
}