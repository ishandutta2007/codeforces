
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<ctime>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
const int M=1000005,N=1000005;
int tong[N],l,s3,nedge,s1,s2,n,m,s,t,di[M],nextt[M],son[N],ed[M],n1,oo=1000000000,rd[N];
inline void aedge(int a,int b){
	nextt[++nedge]=son[a]; son[a]=nedge; ed[nedge]=b; rd[b]++;
}
inline void write(int a){
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(int a){
	write(a); puts("");
}
inline int read()// 
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
		return positive ? x : -x;
}
struct data{
	int far;
}dui[M];
inline void up(int p){
	int i=p,j;
	while((j=i>>1)&&j){ 
		 if(dui[j].far<dui[i].far){
			data zs=dui[i]; dui[i]=dui[j]; dui[j]=zs; i=j;
		}else return;
	}
}
inline void down(int p){
	int i=p,j;
	while((j=i<<1)<=n1){//cout<<j<<endl;
		if(j+1<=n1&&dui[j+1].far>dui[j].far)j++; 
		if(dui[j].far>dui[i].far){
			data zs=dui[i]; dui[i]=dui[j]; dui[j]=zs; i=j;
		}else return;
	}
}
int main(){
	n=read(); m=read();
	while(m--){
		int s2=read(),s1=read();
		aedge(s1,s2);
	}
	for(int i=1;i<=n;i++)if(!rd[i]){
		dui[++n1].far=i; up(n1); //cout<<i<<endl
	}
	while(++l<=n){
		int k=dui[1].far;dui[1]=dui[n1--]; down(1); tong[k]=l;
		for(int i=son[k];i;i=nextt[i]){
			if(--rd[ed[i]]==0){
				dui[++n1].far=ed[i]; up(n1);
			}
		}
	}
	for(int i=1;i<=n;i++){write(n-tong[i]+1); putchar(' ');}
}