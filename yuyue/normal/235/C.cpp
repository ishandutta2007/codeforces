#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=2e6+10,N=1e6+10;
struct node{
	int fa,len,c[26];
}t[M];
int lst=1,tot=1,sz[M];
void extend(int o){
	int np=++tot,p=lst; t[np].len=t[p].len+1; lst=tot;
	sz[np]++;
	while (p && !t[p].c[o]) t[p].c[o]=np,p=t[p].fa;
	if (!p) t[np].fa=1;
	else{
		int q=t[p].c[o];
		if (t[q].len==t[p].len+1) t[np].fa=q;
		else {
			int nq=++tot; t[nq]=t[q];
			t[nq].len=t[p].len+1;
			t[q].fa=t[np].fa=nq;
			while (p && t[p].c[o]==q) t[p].c[o]=nq,p=t[p].fa;
		}
	}
} 
int head[M],to[M],nxt[M],cnt;
void add(int x,int y){
	to[++cnt]=y; nxt[cnt]=head[x]; head[x]=cnt; 
}
void dfs(int x){
	for (int i=head[x];i;i=nxt[i]){
		int y=to[i];
		dfs(y);
		sz[x]+=sz[y];
	}
}
int n,m;
char ch[N];
int kmp[N];
int period(int len){
	F(i,1,len) kmp[i]=0;
	int j=0;
	F(i,2,len){
		while (j && ch[j+1]!=ch[i]) j=kmp[j]; 
		if (ch[j+1]==ch[i]) j++;
		kmp[i]=j;
	}
	int xun=len-kmp[len];
	return len%xun==0 ? xun : len ;
}
void mat(int len){
	int pos=1,tl=0;
	int xun=period(len);
//	cout<<xun<<"   fucker \n";
	F(i,1,len){
		int o=ch[i]-'a';
		while (pos!=1 && !t[pos].c[o]) 
		pos=t[pos].fa,tl=t[pos].len;
		if (t[pos].c[o]) tl++,pos=t[pos].c[o];
//		cout<<"MATCH : "<<tl<<" "<<i<<"\n";
//		system("pause"); 
	}
	LL ret=0;
	if(tl==len) ret=sz[pos];
	F(i,1,len-1){
		if (i==xun) break;
		int o=ch[i]-'a';
		while (pos!=1 && !t[pos].c[o])
		pos=t[pos].fa,tl=t[pos].len;
		if (t[pos].c[o]) tl++,pos=t[pos].c[o]; 
		while (t[t[pos].fa].len
		>=len){
			pos=t[pos].fa;
			tl=t[pos].len;
		}
		if (tl>=len) ret+=sz[pos];
	}
	cout<<ret<<"\n";
}
int main(){
	scanf("%s",ch+1); n=strlen(ch+1);
	F(i,1,n) extend(ch[i]-'a');
	F(i,2,tot) add(t[i].fa,i);
	dfs(1);
	m=read();
	F(i,1,m){
		scanf("%s",ch+1); int len=strlen(ch+1);
		mat(len);
	}
	return 0;
}