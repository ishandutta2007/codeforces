#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<stack>
#include<cstdio>
#include<cmath>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> P;
typedef pair<int,P> P1;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define rep(i,x) for(int i=0;i<x;i++)
#define rep1(i,x) for(int i=1;i<=x;i++)
#define rrep(i,x) for(int i=x-1;i>=0;i--)
#define rrep1(i,x) for(int i=x;i>0;i--)
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
#define min_3(a,b,c) min(a,min(b,c))
#define max_3(a,b,c) max(a,max(b,c))
#define mp1(a,b,c) P1(a,P(b,c))
#define pque(a) priority_queue<a>
#define rpque(a) priority_queue<a,vector<a>,greater<a>>

const int INF=1000000000;
const int dre_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dre_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
const int kaijou[10]={1,1,2,6,24,120,720,5040,40320,362880};

int gcd(int x,int y){
	if(y==0)return x;
	return gcd(y,x%y);
}

int siz;
int MIN[400010];
int CNT[400010];
int GCD[400010];

int query_gcd(int a,int b,int k,int l,int r){
	//printf("query_gcd(%d,%d,%d,%d,%d)\n",a,b,k,l,r);
	if(a>=r||b<=l)return 0;
	if(a<=l&&r<=b)return GCD[k];
	return gcd(query_gcd(a,b,2*k+1,l,(l+r)/2),query_gcd(a,b,2*k+2,(l+r)/2,r));
}

P query_min(int a,int b,int k,int l,int r){
	if(a>=r||b<=l)return P(INF,0);
	if(a<=l&&r<=b)return P(MIN[k],CNT[k]);
	P chl=query_min(a,b,2*k+1,l,(l+r)/2);
	P chr=query_min(a,b,2*k+2,(l+r)/2,r);
	if(chl.fr<chr.fr)return chl;
	if(chl.fr>chr.fr)return chr;
	return P(chl.fr,chl.sc+chr.sc);
}
	
	

int main(){
	rep(i,400010)MIN[i]=INF;
	
	int n;
	cin>>n;
	
	siz=1;
	while(siz<n)siz*=2;
	
	rep(i,n){
		scanf("%d",&MIN[siz-1+i]);
		CNT[siz-1+i]=1;
		GCD[siz-1+i]=MIN[siz-1+i];
	}
	
	rrep(i,siz-1){
		if(MIN[2*i+1]<MIN[2*i+2]){
			MIN[i]=MIN[2*i+1];
			CNT[i]=CNT[2*i+1];
		}
		else if(MIN[2*i+1]>MIN[2*i+2]){
			MIN[i]=MIN[2*i+2];
			CNT[i]=CNT[2*i+2];
		}
		else {
			MIN[i]=MIN[2*i+2];
			CNT[i]=CNT[2*i+1]+CNT[2*i+2];
		}
		GCD[i]=gcd(GCD[2*i+1],GCD[2*i+2]);
	}
	
	int m; cin>>m;
	
	rep(i,m){
		int l,r;
		scanf("%d%d",&l,&r);
		
		int g=query_gcd(l-1,r,0,0,siz);
		//cout<<0;
		P p=query_min(l-1,r,0,0,siz);
		
		//printf("%d %d\n",g,p.fr);
		if(g==p.fr)printf("%d\n",r-l+1-p.sc);
		else printf("%d\n",r-l+1);
	}
}