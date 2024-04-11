#include<bits/stdc++.h>
using namespace std;
char s1[1000100],s2[1000100];
int len1,len2,ans[1000100];
int main(){
	scanf("%s%s",s1+1,s2+1);
	len1=strlen(s1+1);
	len2=strlen(s2+1);
	int sta_1=0,sta_2=0,top=0;
	while(sta_1<=len1){
		if(s1[sta_1]==s2[sta_2]){
			sta_1++;
			sta_2++;
		}
		else{
			ans[++top]=sta_1;
			sta_1++;
		}
	}
	if(top>1){
		printf("0\n");
		return 0;
	}
	for(int i=ans[top]-1;i>=1;i--){
		if(s1[ans[top]]==s1[i]){
			ans[++top]=i;
		}
		else{
			break;
		}
	}
	sort(ans+1,ans+1+top);
	printf("%d\n",top);
	for(int i=1;i<=top;i++){
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
}