#include<bits/stdc++.h>
#define maxn 300100
using namespace std;
char s[maxn],t[maxn],p[maxn];
int l1,r1,l2,r2,n,l3,r3;
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%s%s",s,t);
	n=strlen(s);
	r3=n-1;
	sort(s,s+n);
	if(n%2==0)r1=n/2-1,r2=n/2-1;
	else r1=n/2,r2=n/2-1;
	sort(t,t+n);
	reverse(t,t+n);
	for(int i=1,j=0;i<=(n+1)/2;++i){
		if(s[l1]>=t[l2])p[r3--]=s[r1--];
		else p[l3++]=s[l1++];
		if(r3>=l3){
			if(t[l2]<=s[l1])p[r3--]=t[r2--];
			else p[l3++]=t[l2++];
		}
	}
	printf("%s",p);
}