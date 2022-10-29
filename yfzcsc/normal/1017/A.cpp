#include<bits/stdc++.h>
using namespace std;
struct data{
	int a,b,c,d,e;
	data(){}
	void scan(int i){
		e=i;
		scanf("%d%d%d%d",&a,&b,&c,&d);
	}
	int operator<(const data& A)const{
		if(a+b+c+d!=A.a+A.b+A.c+A.d)
			return a+b+c+d>A.a+A.b+A.c+A.d;
		return e<A.e;
	}
}d[1001000];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)d[i].scan(i);
	sort(d+1,d+n+1);
	for(int i=1;i<=n;++i)if(d[i].e==1){
		printf("%d\n",i);
		return 0;
	}
}