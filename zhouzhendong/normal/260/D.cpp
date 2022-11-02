#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int n,c[N],s[N];
int a[N],A=0,b[N],B=0;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&c[i],&s[i]);
		if (c[i])
			a[++A]=i;
		else
			b[++B]=i;
	}
	int j=1;
	for (int i=1;i<=A;i++){
		while (s[a[i]]>s[b[j]]&&j<=n){
			printf("%d %d %d\n",a[i],b[j],s[b[j]]);
			s[a[i]]-=s[b[j]];
			s[b[j]]=0;
			j++;
		}
		printf("%d %d %d\n",a[i],b[j],s[a[i]]);
		s[b[j]]-=s[a[i]];
		s[a[i]]=0;
	}
	for (int i=j+1;i<=B;i++)
		printf("%d %d 0\n",a[A],b[i]);
	return 0;
}