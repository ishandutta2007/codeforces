#include<bits/stdc++.h>
using namespace std;

char s1[301000],s2[301000],ans[301000];
int n,now=1,p1,p2,w1=1,w2=1,w11,w22;

bool cmp(char c1,char c2){
	return c1>c2;
}

int main(){
	scanf("%s%s",s1+1,s2+1);
	n=strlen(s1+1);
	sort(s1+1,s1+n+1);
	sort(s2+1,s2+n+1,cmp);
	w22=n/2; w11=n-w22;
	p1=1,p2=n;
	while (p1<=p2){
		if (now){
			if (s1[w1]<s2[w2]){
				ans[p1++]=s1[w1++];
			}else{
				ans[p2--]=s1[w11--];
			}
		}else{
			if (s2[w2]>s1[w1]){
				ans[p1++]=s2[w2++];
			}else{
				ans[p2--]=s2[w22--];
			}
		}
		now^=1;
	}
	for (int i=1;i<=n;i++) printf("%c",ans[i]);
}