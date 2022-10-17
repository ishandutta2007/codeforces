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

P rotate(P h,P r){
	P ret;
	ret.fr=r.fr+r.sc-h.sc;
	ret.sc=r.sc+h.fr-r.fr;
	return ret;
}

P vect(P x,P y){
	return P(y.fr-x.fr,y.sc-x.sc);
}

bool solver(P a,P b,P c,P d){
	P x=vect(a,b); //printf("%d %d\n",x.fr,x.sc);
	P y=vect(b,c); //printf("%d %d\n",y.fr,y.sc);
	P z=vect(d,c); //printf("%d %d\n",z.fr,z.sc);
	P w=vect(a,d); //printf("%d %d\n",w.fr,w.sc);
	if(x==z&&y==w&&x.sc==-y.fr&&x.fr==y.sc&&!(x.fr==0&&x.sc==0))return true;
	return false;
}

int main(){
	int n;
	cin>>n;
	
	//if(solver(P(-1,0),P(-1,1),P(-2,1),P(-2,0)))cout<<0;
	
	rep(ppp,n){
		P h[5],r[5];
		rep(i,4){
			int x,y,a,b;
			scanf("%d%d%d%d",&x,&y,&a,&b);
			h[i]=P(x,y);
			r[i]=P(a,b);
		}
		
		int ret=INF;
		
		rep(i0,4){
			rep(i1,4){
				rep(i2,4){
					rep(i3,4){
						int per[4]={0,1,2,3};
						do{
							if(solver(h[per[0]],h[per[1]],h[per[2]],h[per[3]]))ret=min(ret,i0+i1+i2+i3);
						} while(next_permutation(per,per+4));
						h[3]=rotate(h[3],r[3]);
					}
					h[2]=rotate(h[2],r[2]);
				}
				h[1]=rotate(h[1],r[1]);
			}
			h[0]=rotate(h[0],r[0]);
		}
		
		if(ret!=INF)printf("%d\n",ret);
		else printf("-1\n");
	}
}