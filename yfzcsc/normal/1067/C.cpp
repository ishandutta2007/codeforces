#include<bits/stdc++.h>
#define f(x,y) (a[(x)+M][(y)+M])
using namespace std;
typedef pair<int,int> pii;
set<pii>st;
int main(){
	int n;
	scanf("%d",&n);
	if(n<=10){
		for(int i=1;i<=n;++i)printf("1 %d\n",i);
		return 0;
	}
	int x=2.0/3*n;
	for(int i=1;i<=x;++i)st.insert(pii(1,i));
	for(int i=1;i<=x;++i)if(~i&1)st.insert(pii(4,i));
	for(auto s:st){
		if(!n--)break;
		printf("%d %d\n",s.first,s.second);
	}
	for(int i=1;i<=n;++i)printf("2 %d\n",i);
}