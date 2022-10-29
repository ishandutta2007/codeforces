#include<bits/stdc++.h>
using namespace std;
int main(){
	int q,n;
	scanf("%d",&q);
	while(q--){
		scanf("%d",&n);
		int m=n/4,p=n%4;
		if(!p)printf("%d\n",m);
		else if(p==1){
			if(m<2)printf("-1\n");
			else printf("%d\n",m-2+1);
		} else if(p==2){
			if(m<1)printf("-1\n");
			else printf("%d\n",m);
		} else if(p==3){
			if(m<3)printf("-1\n");
			else printf("%d\n",m-3+2);
		}
	}
}