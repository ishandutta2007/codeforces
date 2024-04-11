#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<string>
using namespace std;

int main(){
	int n,p;
	char c[1010];

	scanf("%d%d",&n,&p);
	scanf("%s",&c);

	int k=n-1;

	while(k<n){
		if(k<0){ printf("NO\n"); return 0; }
		if(c[k]!='a'-1+p){
			c[k]++;
			if((k<=0||c[k]!=c[k-1])&&(k<=1||c[k]!=c[k-2]))k++;
		}
		else {
			c[k]='a'-1;
			k--;
		}
	}

	for(int i=0;i<n;i++)printf("%c",c[i]);
	printf("\n");
}