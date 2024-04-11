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

typedef long long ll;
typedef long double ld;
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
#define mp1(a,b,c) P1(a,P(b,c))

const int INF=1000000000;
const int dir_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dir_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

int main(){
	static int n,q;
	scanf("%d%d",&n,&q);
	
	static map<int,P> MAP1,MAP2;
	MAP1.insert(mp1(1,n,0));
	MAP2.insert(mp1(1,n,0));
	
	rep(i,q){
		int x,y;
		char c;
		scanf("%d%d %c",&x,&y,&c);
		if(c == 'U'){
			map<int,P>::iterator itr1 = --MAP1.upper_bound(x);
			map<int,P>::iterator itr2 = --MAP2.upper_bound(y);
			printf("%d\n",y-itr1->sc.sc);
			
			if(itr1->sc.fr > x)MAP1.insert(mp1(x+1,itr1->sc.fr,itr1->sc.sc));
			itr1->sc.fr = x-1;
			if(itr1->fr > itr1->sc.fr)MAP1.erase(itr1);
			MAP1.insert(mp1(x,x,y));
			
			if(itr2->sc.fr > y)MAP2.insert(mp1(y+1,itr2->sc.fr,itr2->sc.sc));
			itr2->sc.fr = y; itr2->sc.sc = x;
		}
		else {
			map<int,P>::iterator itr1 = --MAP1.upper_bound(x);
			map<int,P>::iterator itr2 = --MAP2.upper_bound(y);
			printf("%d\n",x-itr2->sc.sc);
			
			if(itr2->sc.fr > y)MAP2.insert(mp1(y+1,itr2->sc.fr,itr2->sc.sc));
			itr2->sc.fr = y-1;
			if(itr2->fr > itr2->sc.fr)MAP2.erase(itr2);
			MAP2.insert(mp1(y,y,x));
			
			if(itr1->sc.fr > x)MAP1.insert(mp1(x+1,itr1->sc.fr,itr1->sc.sc));
			itr1->sc.fr = x; itr1->sc.sc = y;
		}
	}
	
	/*static map<int,P> MAP;
	MAP.insert(mp1(1,n,0));
	
	rep(i,q){
		int x,y;
		char c;
		scanf("%d%d %c",&x,&y,&c);
		if(c == 'U'){
			map<int,P>::iterator itr = --MAP.upper_bound(x);
			printf("%d\n",y-itr->sc.sc);
			if(itr->sc.fr > x)MAP.insert(mp1(x+1,itr->sc.fr,itr->sc.sc));
			itr->sc.fr = x-1;
			if(itr->fr > itr->sc.fr)MAP.erase(itr);
			MAP.insert(mp1(x,x,y));
		}
		else {
			map<int,P>::iterator itr = --MAP.upper_bound(x);
			if(itr->sc.sc < y)printf("%d\n",x-itr->fr+1);
			else printf("0\n");
			if(itr->sc.fr > x)MAP.insert(mp1(x+1,itr->sc.fr,itr->sc.sc));
			itr->sc.fr = x-1; itr->sc.sc = y;
			if(itr->fr > itr->sc.fr)MAP.erase(itr);
			MAP.insert(mp1(x,x,y));
		}
	}*/
}