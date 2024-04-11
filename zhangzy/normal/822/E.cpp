#include<bits/stdc++.h>
using namespace std;
char s[520233],t[520233];
int n,m,k;
struct Node{
	int far,pos;
}f[33],tem;
int main(){
	scanf("%d%s%d%s%d",&n,s,&m,t,&k);
	for (int i=0;i<n;i++){
		for (int j=k-1;j>=0;j--){
			if (i<f[j].pos){
				continue;
			}
			tem.far=f[j].far;
			tem.pos=i;
			while (s[tem.pos]==t[tem.far]&&tem.far<m){
				tem.pos++;tem.far++;
			}
			if (tem.far==m){
				printf("YES");
				return 0;
			}
			if (tem.far>f[j+1].far){
				f[j+1]=tem;
			}
		}
	}
	printf("NO");
	return 0;
}