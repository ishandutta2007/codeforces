#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=200005,logN=21;
struct data{
    int ls,rs,val;
}tree[N*logN];
int cur,rt[N],n,q,sortb[N],b[N];
inline void init(){
    cur=0;
}
inline void push_up(int p){
    tree[p].val=tree[tree[p].ls].val+tree[tree[p].rs].val;
}
inline int build(int l,int r){
    int k=cur++;
    if(l==r){
        tree[k].val=0; return k;
    }
    int mid=(l+r)>>1;
    tree[k].ls=build(l,mid); tree[k].rs=build(mid+1,r);
    push_up(k);
    return k;
}
inline int insert(int nod,int l,int r,int pos,int add){
    int k=cur++; tree[k]=tree[nod];
    if (l==r){
        tree[k].val+=add;
        return k;
    }
    int mid=(l+r)>>1;
    if (pos<=mid) tree[k].ls=insert(tree[nod].ls,l,mid,pos,add);
    else tree[k].rs=insert(tree[nod].rs,mid+1,r,pos,add);
    push_up(k);
    return k;
}
inline int ask(int l,int r,int i,int j,int nod){
	if(i>j)return 0; //cout<<l<<" "<<r<<" "<<i<<" "<<j<<" "<<nod<<" "<<tree[nod].val<<endl;
    if(l==i&&r==j)return tree[nod].val;
    int mid=l+r>>1;
    if(j<=mid)return ask(l,mid,i,j,tree[nod].ls); else
    if(i>mid)return ask(mid+1,r,i,j,tree[nod].rs); else
    return ask(l,mid,i,mid,tree[nod].ls)+ask(mid+1,r,mid+1,j,tree[nod].rs);
}
inline int	read(){
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(long long a){
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(long long a){
	if(a<0){
		putchar('-'); a=-a;
	}
	write(a); puts("");
}
int an[N][9];
int main(){
	n=read(); int m=read();
    init();
    rt[0]=build(1,n);
    for (int i=1;i<=n;i++){
        rt[i]=insert(rt[i-1],1,n,read(),1);
    }
	for(int i=1;i<=m;i++){
		int l=read(),d=read(),r=read(),h=read();
		an[i][0]=ask(1,n,1,d-1,rt[l-1]); an[i][1]=ask(1,n,1,h,rt[l-1]); an[i][2]=ask(1,n,1,n,rt[l-1]);
		an[i][3]=ask(1,n,1,d-1,rt[r])-an[i][0]; an[i][4]=ask(1,n,1,h,rt[r])-an[i][1]; an[i][5]=ask(1,n,1,n,rt[r])-an[i][2];
		an[i][6]=ask(1,n,1,d-1,rt[n])-an[i][0]-an[i][3]; an[i][7]=ask(1,n,1,h,rt[n])-an[i][1]-an[i][4]; an[i][8]=ask(1,n,1,n,rt[n])-an[i][2]-an[i][5];
		an[i][1]-=an[i][0]; an[i][2]-=an[i][0]+an[i][1];
		an[i][4]-=an[i][3]; an[i][5]-=an[i][3]+an[i][4];
		an[i][7]-=an[i][6]; an[i][8]-=an[i][6]+an[i][7];
		//for(int j=0;j<9;j++)cout<<an[i][j]<<" "<<i<<" "<<j<<endl;
	}
	for(int i=1;i<=m;i++){
		writeln((long long)an[i][0]*(an[i][4]+an[i][5]+an[i][7]+an[i][8])+(long long)an[i][1]*(n-an[i][1]-an[i][2]-an[i][0])+(long long)an[i][2]*(an[i][3]+an[i][4]+an[i][6]+an[i][7])+(long long)an[i][3]*(an[i][4]+an[i][5]+an[i][7]+an[i][8])+(long long)an[i][4]*(an[i][5]+an[i][6]+an[i][7]+an[i][8])+(long long)an[i][5]*(an[i][6]+an[i][7])+(long long)an[i][4]*(an[i][4]-1)/2);
	}
    return 0;
}