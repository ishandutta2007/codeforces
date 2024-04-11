#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<set>
#include<ctime>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
const int M=200005,N=100005;
int vis[N],last[N],l,s3,nedge,dist[N],s1,s2,n,m,s,t,di[M],nextt[M],son[N],ed[M],n1,oo=1000000005;
struct data{
	int num,far;
}dui[M+N];
inline void up(int p){
	int i=p,j;
	while((j=i>>1)){ 
		 if(dui[j].far>dui[i].far){
			data zs=dui[i]; dui[i]=dui[j]; dui[j]=zs; i=j;
		}else return;
	}
}
inline void down(int p){
	int i=p,j;
	while((j=i<<1)<=n1){//cout<<j<<endl;
		if(j+1<=n1&&dui[j+1].far<dui[j].far)j++; 
		if(dui[j].far<dui[i].far){
			data zs=dui[i]; dui[i]=dui[j]; dui[j]=zs; i=j;
		}else return;
	}
}
inline int duidi(int s,int t){
	n1=1;
	for(int i=1;i<=n;i++)dist[i]=oo; dist[s]=0;
	for(int i=1;i<=n;i++)last[i]=0;
	dui[1].far=0; dui[1].num=s;
	while(n1){
		int k=dui[1].num,k1=dui[1].far;  
		dui[1].far=oo; data zs=dui[1]; dui[1]=dui[n1]; dui[n1]=zs; down(1); n1--;
		 if(k1!=dist[k])continue; if(k==t) return dist[k]; //if(k)cout<<k<<endl;
		for(int j=son[k];j;j=nextt[j])if(dist[ed[j]]>dist[k]+di[j]){last[ed[j]]=j;
			dist[ed[j]]=dist[k]+di[j]; dui[++n1].num=ed[j]; dui[n1].far=dist[k]+di[j]; 
			up(n1); 
		}
	}
	return -1;
}
inline void write(int a){
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(int a){
	write(a); puts("");
}
inline  int read()// 
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void aedge(int a,int b,int c){
	nextt[++nedge]=son[a];
	son[a]=nedge;
	ed[nedge]=b;
	if(!c){
		di[nedge]=1; vis[nedge]=1;
	}else
	di[nedge]=c;
}
inline int chu(int x){
	return ((x-1)^1)+1;
}
int main(){
	n=read(); m=read(); l=read(); s=read()+1; t=read()+1;
	while(m--){
		int s1=read()+1,s2=read()+1,s3=read(); 
		aedge(s1,s2,s3); aedge(s2,s1,s3);
	}
	int tt=duidi(s,t); if(tt>l||tt==-1){
		puts("NO"); return 0;
	}
	while((tt=duidi(s,t))<l){int flag=0;
		for(int i=t;i!=s;i=ed[chu(last[i])])if(vis[last[i]]){
			di[last[i]]=di[chu(last[i])]=di[last[i]]+l-tt; vis[last[i]]=vis[chu(last[i])]=0; flag=true; break;
		}if(!flag){
			puts("NO"); return 0;
		}
	}puts("YES");
	for(int i=1;i<=nedge;i+=2){
		printf("%d %d %d\n",ed[i+1]-1,ed[i]-1,di[i]);
	}
}