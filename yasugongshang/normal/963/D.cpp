#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<ctime>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
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
inline void write(ll a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
const int N=100005,M=N<<1,K=26;
int n,top,rig[M],T,que[N],len[M],pre[M],last=1,tot=1;
int go[M][K];
vector<int> v[M];
char ch[N];
void add(int c){
	int np=++tot,p=last; 
	len[np]=len[p]+1; last=np;
	for(;p&&!go[p][c];p=pre[p])go[p][c]=np;
	if(!p)pre[np]=1; else{
		int q=go[p][c];
		if(len[p]+1==len[q])pre[np]=q; else{
			int nq=++tot; memcpy(go[nq],go[q],sizeof(go[q]));//go[nq]=go[q];
			len[nq]=len[p]+1;
			pre[nq]=pre[q];
			pre[np]=pre[q]=nq;
			while(go[p][c]==q){
                go[p][c]=nq;
                p=pre[p];
            }
		}
	}
}
void dfs(int p){
	if(rig[p])que[++top]=rig[p];
	for(unsigned i=0;i<v[p].size();i++)dfs(v[p][i]);
}
signed main(){
	scanf("%s",ch);
	int len=n=strlen(ch); 
	for(int i=0;i<len;i++){add(ch[i]-'a'); rig[last]=i+1;}
	int q=read();
	for(int i=2;i<=tot;i++)v[pre[i]].push_back(i);
	while(q--){
		int k=read(),p=1,ans=1e9; scanf("%s",ch);
		len=strlen(ch);
		for(int i=0;i<len;i++)p=go[p][ch[i]-'a'];
		top=0; dfs(p);
		sort(&que[1],&que[top+1]);
		for(int i=1;i+k-1<=top;i++)ans=min(ans,que[i+k-1]-que[i]+len);
		if(ans>n)puts("-1"); else writeln(ans);
	}
}