#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
#define PI pair<int,int>
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
const int N=100005;
char ch[N];
int cnt=1,n,nxt[N][26],tree[N],coun[N];
int ans;
void insert(char ch[]){
	int p=1,len=strlen(ch);
	for(int i=0;i<len;i++){
		int t=ch[i]-'a';
		if(!nxt[p][t])nxt[p][t]=++cnt;
		p=nxt[p][t]; //cout<<p<<" "<<tree[p]<<endl;
	}
	ans+=len;
	coun[p]++; 
}
void build(int p){
	for(int i=0;i<26;i++)if(nxt[p][i]){build(nxt[p][i]); tree[p]=max(tree[p],tree[nxt[p][i]]);}
	tree[p]+=coun[p];
}
void update(int p){
	tree[p]=0;
	for(int i=0;i<26;i++)tree[p]=max(tree[p],tree[nxt[p][i]]);
	tree[p]+=coun[p];
}
void change(int p,int dep){
	if(coun[p]&&tree[p]==1){
		tree[p]=coun[p]=0; ans-=dep; return;
	}
	int mx=0,pos;
	for(int i=0;i<26;i++){
		if(tree[nxt[p][i]]>mx){
			mx=tree[nxt[p][i]]; pos=nxt[p][i];
		}
	}
	change(pos,dep+1);
	update(p);
}
void dfs(int p,int dep){
	for(int i=0;i<26;i++)if(nxt[p][i])dfs(nxt[p][i],dep+1);
	int mx=0,pos; 
	for(int i=0;i<26;i++)if(nxt[p][i]){
		if(tree[nxt[p][i]]>mx){
			mx=tree[nxt[p][i]]; pos=nxt[p][i];
		}
	}
	if(!coun[p]){ans+=dep; coun[p]=1; change(pos,dep+1); }
	update(p);
	//if(p==2)cout<<pos<<" "<<tree[pos]<<endl;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		scanf("%s",ch); insert(ch); 
	}
	for(int i=0;i<26;i++)if(nxt[1][i]){
		dfs(nxt[1][i],1); 
	}
	writeln(ans);
}