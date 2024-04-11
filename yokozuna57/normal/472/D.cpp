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
#define min_3(a,b,c) min(a,min(b,c))
#define max_3(a,b,c) max(a,max(b,c))
#define mp1(a,b,c) P1(a,P(b,c))

const int INF=2000000010;
const int dre_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dre_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
const int kaijou[10]={1,1,2,6,24,120,720,5040,40320,362880};

int main(){
	int n; cin>>n;
	static int d[2002][2002];
	
	rep(i,n)rep(j,n)scanf("%d",&d[i][j]);
	
	rep(i,n)for(int j=i+1;j<n;j++)if(d[i][j]!=d[j][i]||d[i][j]==0){cout<<"NO\n"; return 0;}
	rep(i,n)if(d[i][i]!=0){cout<<"NO\n"; return 0;}
	
	vector<P> vec;
	rep1(i,n-1){
		vec.pb(P(d[i][0],i));
	}
	
	sor(vec);
	
	vector<int> vec1; vec1.pb(0);
	
	rep(i,n-1){
		//cout<<i<<endl;
		int m=vec[i].sc;
		int MIN=INF;
		int r=0;
		
		rep(j,vec1.size()){
			if(d[m][vec1[j]]+d[vec1[j]][0]==d[m][0]&&d[m][vec1[j]]<MIN){
				MIN=d[m][vec1[j]];
				r=vec1[j];
			}
		}
		
		bool t=true;
		rep(j,vec1.size()){
			if(d[m][r]+d[r][vec1[j]]!=d[m][vec1[j]])t=false;
		}
		
		if(!t){cout<<"NO\n"; return 0;}
		vec1.pb(m);
	}
	
	cout<<"YES\n"<<endl;
}