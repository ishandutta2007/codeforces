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

map<int,LL> ans;

void add(int x,int y){
	map<int,LL>::iterator itr=ans.find(x);
	if(itr==ans.end())ans.insert(P(x,y));
	else itr->sc+=y;
}

int main(){
	int n;
	static int a[100010];
	vector<P> vec;
	
	cin>>n;
	rep(i,n){
		scanf("%d",&a[i]);
	}
	rrep(i,n){
		vector<P> vec0;
		rep(j,vec.size()){
			P p=P(gcd(vec[j].fr,a[i]),vec[j].sc);
			add(p.fr,p.sc);
			vec0.pb(p);
		}
		add(a[i],1);
		vec0.pb(P(a[i],1));
		//cout<<i<<" "<<ans.size()<<endl;
		
		vec.clear();
		int s;
		vec.pb(vec0[0]); s=vec0[0].fr;
		rep1(j,vec0.size()-1){
			if(vec0[j].fr==s)vec[vec.size()-1].sc+=vec0[j].sc;
			else {vec.pb(vec0[j]); s=vec0[j].fr;}
		}
		//cout<<i<<" "<<ans.size()<<endl;
	}
	
	//cout<<ans.size()<<endl;
	/*map<int,LL>::iterator itritr=ans.begin();
	for(;itritr!=ans.end();itritr++){
		cout<<itritr->fr<<" "<<itritr->sc<<endl;
	}*/
	
	int q;
	cin>>q;
	
	map<int,LL>::iterator itr;
	rep(i,q){
		int x;
		scanf("%d",&x);
		itr=ans.find(x);
		if(itr==ans.end())printf("0\n");
		else printf("%I64d\n",itr->sc);
	}
}