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
#include<time.h>
#include<stdlib.h>
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
	srand((unsigned int)time(NULL));
	
	int n;
	int a[102][102];
	int b[102];
	char c[102][102];
	scanf("%d",&n);
	rep(i,n){
		scanf("\n");
		rep(j,n){
			scanf("%c",&c[i][j]);
			if(c[i][j] == '0')a[i][j] = 0;
			else a[i][j] = 1;
		}
	}
	rep(i,n){
		scanf("%d",&b[i]);
	}
	
	int p[102] = {};
	while(1){
		NEXT:;
		int cnt[102] = {};
		rep(i,n){
			rep(j,n){
				cnt[j] += p[i]*a[i][j];
			}
		}
		rep(i,n){
			if(cnt[i] == b[i]){
				p[i] ++;
				goto NEXT;
			}
		}
		int ret = 0;
		rep(i,n){
			ret += p[i];
		}
		printf("%d\n",ret);
		rep(i,n){
			if(p[i] == 1){
				printf("%d",i+1);
				ret--;
				if(ret != 0)printf(" ");
			}
		}
		puts("");
		return 0;
	}
	puts("-1");
}