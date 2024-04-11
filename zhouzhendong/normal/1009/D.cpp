#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100005;
LL read(){
	LL x=0;
	char ch=getchar();
	while (!isdigit(ch))
		ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+ch-48,ch=getchar();
	return x;
}
int n,m;
int pcnt=0,p[N],f[N];
int GCD[5000][5000];
int gcd(int a,int b){
	if (GCD[a][b])
		return GCD[a][b];
	return GCD[a][b]=b?gcd(b,a%b):a;
}
void Get_Prime(int n){
	memset(f,0,sizeof f);
	for (int i=2;i<=n;i++){
		if (f[i])
			continue;
		p[++pcnt]=i;
		for (int j=i*2;j<=n;j+=i)
			f[j]=1;
	}
}
int main(){
	n=read(),m=read();
	Get_Prime(n);
	if (m<n-1){
		puts("Impossible");
		return 0;
	}
	m-=n-1;
	if (pcnt*(pcnt-1)/2>=m){
//		puts("Prime");
		puts("Possible");
		for (int i=2;i<=n;i++)
			printf("%d %d\n",1,i);
		for (int i=1;i<=pcnt&&m>0;i++)
			for (int j=i+1;j<=pcnt&&m>0;j++){
				printf("%d %d\n",p[i],p[j]);
				m--;
			}
		return 0;
	}
	int tot=0;
	for (int i=2;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			if (gcd(i,j)==1)
				tot++;
	if (tot<m){
		puts("Impossible");
		return 0;
	}
	puts("Possible");
	for (int i=2;i<=n;i++)
		printf("%d %d\n",1,i);
	for (int i=2;i<=n&&m>0;i++)
		for (int j=i+1;j<=n&&m>0;j++)
			if (gcd(i,j)==1){
				printf("%d %d\n",i,j);
				m--;
			}
	return 0;
}