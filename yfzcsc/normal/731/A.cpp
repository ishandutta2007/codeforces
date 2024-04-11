#include<bits/stdc++.h>
using namespace std;
char str[200];
int cost;
int main(){
	scanf("%s",str);
	char lst='a';
	for(int i=0;str[i];++i){
		if(str[i]>=lst)cost+=min(str[i]-lst,lst+26-str[i]);
		else cost+=min(lst-str[i],str[i]+26-lst);
		lst=str[i];
	}
	printf("%d",cost);
}