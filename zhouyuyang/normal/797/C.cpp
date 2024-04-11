#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int n,head,top,top1;
char ans[100005],sta[100005],s[100005],mn;
char getmn(int head){
	char mn='z'+1;
	for (;head<=n;head++)
		mn=min(mn,s[head]);
	return mn;
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	head=1;
	mn=getmn(head);
	while (mn!='z'+1){
		for (int i=head;i<=n;i++)
			if (s[i]==mn){
				ans[++top]=s[i];
				for (int j=head;j<i;j++)
					sta[++top1]=s[j];
				head=i+1;
			}
		mn=getmn(head);
		for (;top1&&sta[top1]<=mn;top1--)
			ans[++top]=sta[top1];
	}
	printf("%s",ans+1);
}