#include<stdio.h>
#include<queue>
struct node
{
	long long a,b;
	node(){}
	node(long long p,long long q){a=p;b=q;}
	bool operator<(const node &p)const{return b<p.b;}
}_;
std::priority_queue<node>Q1;
std::priority_queue<long long,std::vector<long long>,std::greater<long long>>Q;
long long a,b,n,k;long long maxx=0,cnt=0;
main()
{
	scanf("%lld%lld",&n,&k);
	while(n--)
	{
		scanf("%lld%lld",&a,&b);
		Q1.push(node{a,b});
	}
	while(!Q1.empty())
	{
		_=Q1.top();Q1.pop();
		cnt+=_.a;
		Q.push(_.a);
		while(Q.size()>k)cnt-=Q.top(),Q.pop();
		if(maxx<cnt*_.b)maxx=cnt*_.b;
	}printf("%lld",maxx);
}