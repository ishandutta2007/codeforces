#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=57;
const bool v[10]={0,1,0,0,1,0,1,0,1,1};
int n,a[N];
char s[N];
bool vis[10];
bool is_prime(int x){
	for(int i=2;i*i<=x;i++)
		if(x%i==0)return 0;
	return 1;
}
inline void work(){
	n=read(),scanf("%s",s+1);
	for(int i=1;i<=n;i++)a[i]=s[i]&15;
	for(int i=1;i<=n;i++)
		if(v[a[i]]){printf("1\n%d\n",a[i]);return;}
	for(int i=0;i<10;i++)vis[i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<9;j++)if(vis[j] && !is_prime(j*10+a[i])){
			printf("2\n%d%d\n",j,a[i]);
			return;	
		}
		vis[a[i]]=1;	
	}
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}