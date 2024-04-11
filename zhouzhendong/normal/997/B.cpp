#include<bits/stdc++.h>
using namespace std;
int n,a[]={0,4,10,20,35,56,83,116,155,198,244,292};
int main(){
	scanf("%d",&n);
	if(n<=11)
	    printf("%d\n",a[n]);
    else
        printf("%I64d",1LL*(n-11)*49+a[11]);
	return 0;
}