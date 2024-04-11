#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	int n,k,m,t;
	scanf("%d%d%d%d",&n,&k,&m,&t);
	int pos=k,length=n;
	for(int i=1;i<=t;i++){
		int op,x;
		scanf("%d%d",&op,&x);
		if(op==1){
			length++;
			if(x<=pos)pos++;
		}else{
			if(x<pos)length-=x,pos-=x;
			else length=x;
		}
		printf("%d %d\n",length,pos);
	}
	return 0;
}