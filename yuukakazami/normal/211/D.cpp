#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#define REP(i,n) for(int i=0;i<n;i++)
#define PB push_back
using namespace std;
const int MAX_N=int(1e6)+10;
int a[MAX_N],n;
int k[MAX_N],m;

int get(int i,int j){
	if(i==-1||j==-1)
		return i==-1?j:i;
	return a[i]<a[j]?i:j;
}

struct Tree{
	int l,r;
	int mi;
	Tree*pl,*pr;
	Tree(int l,int r){
		this->l=l,this->r=r;
		if(l+1==r){
			mi=l;
			pl=pr=0;
			return;
		}
		pl=new Tree(l,l+r>>1);
		pr=new Tree(l+r>>1,r);
		mi=get(pl->mi,pr->mi);
	}
	
	int ask(int L,int R){
		if(L<=l && R>=r)
			return mi;
		if(L>=r ||l>=R)
			return -1;
		return get(pl->ask(L,R),pr->ask(L,R));
	}
}*root;

double k0[MAX_N],k1[MAX_N];

void add(int l,int r,double k[],double w){
	if(l>r)
		return;
	k[l]+=w;
	k[r+1]-=w;
}

void solve(int l,int r){//[l,r]
	if(l>r)
		return;
	int m=root->ask(l,r+1);
	int a=m-l,b=r-m;
	double mv=::a[m];
	
	if(a>b)swap(a,b);
	//k<a+1 -> k
	add(1,a,k1,1*mv);
	//k>=a+1 && k<=b+1 -> a+1
	add(a+1,b+1,k0,(a+1)*mv);
	//k>b+1 && k<=a+b+1 ->a+b+2-k
	add(b+2,a+b+1,k1,-1*mv);
	add(b+2,a+b+1,k0,(a+b+2)*mv);
	
	solve(l,m-1),solve(m+1,r);
}

int main(){
	cin>>n;REP(i,n)scanf("%d",a+i);
	cin>>m;REP(i,m)scanf("%d",k+i);
	REP(i,n+1)k0[i]=0,k1[i]=0;
	
	root = new Tree(0,n);
	solve(0,n-1);
	
	REP(i,n+1)if(i)k0[i]+=k0[i-1],k1[i]+=k1[i-1];
	
	REP(i,m){
		int me=k[i];
		double ret=k0[me]+k1[me]*me;
		ret/=(n+1-me);
		printf("%0.15lf\n",ret);
	}
}