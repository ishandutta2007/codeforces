#include<stdio.h>
#include<stack>
int t,a;
const long long MAX=(1ll<<32)-1;
struct node{
	int t;
	long long k;
	node(){}
	node(int a,long long b){t=a;k=b;}
}r,s;
std::stack<node>S;
int main(){
	scanf("%d",&t);
	S.push(node{0,0});
	while(t--){
		while(getchar()<'a');
		if(getchar()=='d'){
			getchar();
			r=S.top();S.pop();
			if(++r.k>MAX)return printf("OVERFLOW!!!")&0;
			S.push(r);
		}
		else{
			if(getchar()=='r'){
				scanf("%d",&a);
				S.push(node{a,0});
			}
			else{
				r=S.top();S.pop();
				s=S.top();S.pop();
				s.k+=(long long)r.t*r.k;
				if(s.k>MAX)return printf("OVERFLOW!!!")&0;
				S.push(s);
			}
		}
	}
	printf("%lld",S.top().k);
}