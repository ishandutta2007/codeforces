#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	int x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
const int N=300005,M=N<<1,K=10;
int cnt[M],nxt[M][26],sum[M],fail[M],nodecnt;
char ch[N];
vector<int> rt[K];
int merge(int a,int b){
	if(!a)return b; cnt[a]+=cnt[b]; if(!b)return a;
	//for(int i=0;i<26;i++)cout<<nxt[a][i]<<" "<<nxt[b][i]<<endl;
	for(int i=0;i<26;i++)nxt[a][i]=merge(nxt[a][i],nxt[b][i]);
	return a;
}
int insert(char ch[],int id){
	int p=++nodecnt,last=nodecnt,len=strlen(ch);
	for(int i=0;i<len;i++){
		int t=ch[i]-'a';
		if(!nxt[p][t])nxt[p][t]=++nodecnt;
		p=nxt[p][t];
	}
	cnt[p]+=id;
	return last;
}
int ask(int nod,char ch[]){
	int p=nod,len=strlen(ch),ans=0;
	for(int i=0;i<len;i++){
		int t=ch[i]-'a';
		while(!nxt[p][t]&&p)p=fail[p];
		p=nxt[p][t]; if(p==0)p=nod;
		ans+=sum[p];
	}
	return ans;
}
void makefail(int rt){
	static int q[N];
    int l=0,r=0; fail[q[0]=rt]=0;
    for(int now=rt;l<=r;now=q[++l]){
    	sum[now]=sum[fail[now]]+cnt[now];
    	for(int i=0;i<26;i++)if(nxt[now][i]){
			fail[q[++r]=nxt[now][i]]=rt;
    		for(int j=fail[now];j;j=fail[j])if(nxt[j][i]){
    			fail[nxt[now][i]]=nxt[j][i]; break;
			}
		}
    }
}
int main(){
	int q=read();
	for(int i=1;i<=q;i++){
		int op=read();
		if(op==1){
			scanf("%s",ch);
			int dq=insert(ch,1); 
			for(int i=0;;i++)if(rt[i].size()==3){
				for(int j=0;j<rt[i].size();j++)dq=merge(dq,rt[i][j]); rt[i].clear();
			}else {rt[i].push_back(dq); break;}
			makefail(dq);
		}else if(op==2){
			scanf("%s",ch);
			int dq=insert(ch,-1);
			for(int i=0;;i++)if(rt[i].size()==3){
				for(int j=0;j<rt[i].size();j++)dq=merge(dq,rt[i][j]); rt[i].clear();
			}else {rt[i].push_back(dq); break;}
			makefail(dq);
		}else{
			int ans=0;
			scanf("%s",ch);
			//cout<<ask(rt[0],ch); return 0;
			for(int i=0;i<K;i++)for(int j=0;j<rt[i].size();j++)ans+=ask(rt[i][j],ch);
			writeln(ans);
			fflush(stdout);
		}
	}
}
/*
6
1 abc
1 bcd
1 abcd
2 abcd
2 bcd
3 abcd
*/