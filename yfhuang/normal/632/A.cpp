#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;


int main(){
	char str[10];
	int n,p;
	int num=0;
	long long ans=0;
	long long power=1;
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++){
		scanf("%s",str);
		if(str[4]=='p'){
			num++;
			ans+=(long long)power*(long long)p;
		}
		power*=2;
	}
	ans-=(long long)num*(long long)p/2;
	cout<<ans<<endl;
}