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
typedef unsigned long long uLL;
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

const int M=1000000007;

string s;
LL n;
LL com[5010];

bool compare(int x,int y,int k){
	if(x+k>n||y+k>n)return false;
	if(k<60){
		rep(i,k){
			if(s[x+i]<s[y+i])return true;
			else if(s[x+i]>s[y+i])return false;
		}
		return true;
	}
	if(com[x]==com[y])return compare(x+60,y+60,k-60);
	else return com[x]<com[y];
}

/*int compare_0(int x,int y,int k){
	if(x+k>n||y+k>n)return -1;
	if(k<60){
		rep(i,k){
			if(s[x+i]<s[y+i])return 0;
			else if(s[x+i]>s[y+i])return -2;
		}
		return 2;
	}
	if(com[x]==com[y])return compare(x+60,y+60,k-60)-100;
	else if(com[x]<com[y])return 0;
	else return -3;
}*/

int main(){
	cin>>s;
	
	static LL dp[5002][5002];
	static int dp_0[5002][5002]; rep(i,5002)rep(j,5002)dp_0[i][j]=INF;
	static int dp_1[5002][5002]; rep(i,5002)rep(j,5002)dp_1[i][j]=INF;
	
	n=s.size();
	
	rep(i,n-59){
		com[i]=0;
		rep(j,60){
			com[i]<<=1;
			com[i]+=s[i+j]-48;
		}
	}
	
	LL cnt[5010];
	LL t=1;
	cnt[n]=0;
	rrep(i,n){
		cnt[i]=cnt[i+1]+t*(s[i]-48);
		cnt[i]%=M;
		t*=2;
		t%=M;
	}
	
	rrep(i,n){
		if(s[i]=='1'){
			rrep1(j,n){
				if(i+j>n)dp[i][j]=0;
				else if(i+j==n){
					dp[i][j]=1;
					dp_0[i][j]=j;
					dp_1[i][j]=1;
				}
				else {
					/*if(i+j+j>n){
						dp[i][j]=0;
						dp_0[i][j]=n;
						dp_1[i][j]=n;
					}
					else */if(compare(i,i+j,j)){
						dp[i][j]=dp[i+j][j];
						dp_0[i][j]=dp_0[i+j][j];
						dp_1[i][j]=dp_1[i+j][j]+1;
					}
					else{
//cout<<"____"<<endl; cout<<i<<" "<<i+j<<" "<<j<<endl;
//cout<<compare_0(i,i+j,j)<<endl;
//cout<<com[i]<<" "<<com[i+j]<<endl;
						dp_0[i][j]=dp_0[i+j][j+1];
						dp_1[i][j]=dp_1[i+j][j+1]+1;
						dp[i][j]=dp[i+j][j+1];
					}
				}

				if(max(dp_0[i][j],dp_0[i][j+1])>20){
					if(dp_0[i][j]>dp_0[i][j+1]){
						dp_0[i][j]=dp_0[i][j+1];
						dp_1[i][j]=dp_1[i][j+1];
					}
					else if(dp_0[i][j]==dp_0[i][j+1])dp_1[i][j]=min(dp_1[i][j],dp_1[i][j+1]);
				}
				else if((cnt[n-dp_0[i][j]]+(LL)dp_1[i][j])>(cnt[n-dp_0[i][j+1]]+(LL)dp_1[i][j+1])){
					dp_0[i][j]=dp_0[i][j+1];
					dp_1[i][j]=dp_1[i][j+1];
				}
				dp[i][j]+=dp[i][j+1];
				dp[i][j]%=M;

			}
		}
		else rep(j,n)dp[i][j]=0;
	}
	
	printf("%I64d\n",dp[0][1]);
	
	LL ret=INF;
	int k=INF;
	
	rep1(i,n){
		if(k>dp_0[0][i]){
			k=dp_0[0][i];
			ret=dp_1[0][i];
		}
		else if(k==dp_0[0][i]){
			ret=min(ret,(LL)dp_1[0][i]);
		}
	}
	
	//cout<<k<<endl;
	//cout<<cnt[0]<<endl;
	
	if(k>20){
		ret=(cnt[n-k]+ret)%M;
	}
	else {
		ret=INF;
		rep1(i,n){
			if(dp_0[0][i]<20)ret=min(ret,(cnt[n-dp_0[0][i]]+(LL)dp_1[0][i])%M);
		}
	}
	
	
	printf("%I64d\n",ret);
	
	/*rep(i,n){
		rep1(j,n){
			printf("%I64d ",dp[i][j]);
		}
		printf("\n");
	}
	rep(i,n){
		rep1(j,n){
			printf("%I64d ",dp_0[i][j]);
		}
		printf("\n");
	}
	rep(i,n){
		rep1(j,n){
			printf("%I64d ",dp_1[i][j]);
		}
		printf("\n");
	}*/
	
	//printf("%I64d\n",dp[0][1]);
	
	
	
}