#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#define REP(i,n) for(int i=0;i<n;i++)
#define PB push_back
using namespace std;
const long long INF=1LL<<60;

long long solve(long long a,long long b,long long c){
	long long v[]={a,b,c};
	sort(v,v+3);
	if(v[0] < 0)
		return INF;
		
	long long ans=INF;
	do{
		a=v[0],b=v[1],c=v[2];
		if(b%2 == c%2){
			ans=min(ans,max(b,c));
		}
	}while(next_permutation(v,v+3));
	if(ans!=INF)
		return ans;
	ans=min(ans,solve(a-1,b-1,c+1));
	ans=min(ans,solve(a-1,b+1,c-1));
	ans=min(ans,solve(a+1,b-1,c-1));
	ans+=1;
	return ans;
}
int main(){
	long long a,b,c;
	cin>>a>>b>>c;
	cout<<solve(a,b,c);
}