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

const int INF=1000000000;
const int dre_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dre_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
const int kaijou[10]={1,1,2,6,24,120,720,5040,40320,362880};

bool comp(char *a,char *b){
	while(1){
		if(*a<*b)return true;
		if(*a>*b)return false;
		a++; b++;
	}
	return false;
}

int main(){
	int n;
	static char f[100010][52],s[100010][52];
	static int p[100010];
	
	cin>>n;
	rep(i,n){
		scanf("%s%s",&f[i],&s[i]);
		if(comp(s[i],f[i]))swap(s[i],f[i]);
	}
	
	rep(i,n){
		scanf("%d",&p[i]);
		p[i]--;
	}
	
	char *loc=f[p[0]];
	
	rep1(i,n-1){
		//cout<<(*loc)<<endl;
		//loc-=3;
		if(comp(f[p[i]],loc)){
			if(comp(s[p[i]],loc)){
				//cout<<i;
				cout<<"NO\n"; return 0;
			}
			else loc=s[p[i]];
		}
		else loc=f[p[i]];
	}
	
	cout<<"YES\n";
}