/*
 * E. Common ancestor.cpp
 *
 *  Created on: 2011-1-15
 *      Author: wjmzbmr
 */
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
const int N_MAX=50+1;
const int INF=~0U>>2;
string a,b;
int trans[26][26];
int n;
int aSet[N_MAX][N_MAX];
int bSet[N_MAX][N_MAX];
void calc(string s,int Set[N_MAX][N_MAX]){
	int n=s.size();
	for(int i=0;i<n;i++)
		Set[i][i]=(1<<s[i]-'a');
	for(int l=n-1;l>=0;l--)
		for(int r=l+1;r<n;r++){
			Set[l][r]=0;
			for(int k=l;k<r;k++){
				for(int a=0;a<26;a++)if(Set[l][k]>>a&1)
					for(int b=0;b<26;b++)if(Set[k+1][r]>>b&1)
						Set[l][r]|=trans[a][b];
			}
		}
}

int dp[N_MAX][N_MAX];
int main(){
	cin>>a;cin>>b;cin>>n;
	memset(trans,0,sizeof trans);
	for(int i=0;i<n;i++){
		string s;cin>>s;
		int from;
		int c1,c2;
		from=s[0]-'a';
		c1=s[3]-'a';c2=s[4]-'a';
		trans[c1][c2]|=1<<from;
	}
	calc(a,aSet);
	calc(b,bSet);
	for(int i=0;i<=a.size();i++)
		for(int j=0;j<=b.size();j++){
			if(i==0&&j==0){
				dp[i][j]=0;
			} else if(i==0||j==0){
				dp[i][j]=INF;
			} else {
				dp[i][j]=INF;
				for(int pi=0;pi<i;pi++)
					for(int pj=0;pj<j;pj++)
						if(aSet[pi][i-1]&bSet[pj][j-1]){
							dp[i][j]=min(dp[i][j],dp[pi][pj]+1);
						}
			}
		}
	int res=dp[a.size()][b.size()];
	if(res==INF)
		res=-1;
	cout<<res<<endl;
}