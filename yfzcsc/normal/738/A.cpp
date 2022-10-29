#include<bits/stdc++.h>
using namespace std;
char str[200];
int main(){
	int len;
	scanf("%d%s",&len,str+1);
	for(int i=1,j;i<=len;++i){
		if(str[i]=='o'&&str[i+1]=='g'&&str[i+2]=='o'){
			for(j=i+3;str[j]=='g'&&str[j+1]=='o';j+=2);
			printf("***"),i=j-1;
		} else printf("%c",str[i]);
	}
}