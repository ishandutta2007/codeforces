/*
 * E. Dead Ends.cpp
 *
 *  Created on: 2011-1-14
 *      Author: wjmzbmr
 */
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

typedef long long int64;
const int MAX_VERTEX=10;
bool adj[MAX_VERTEX][MAX_VERTEX];
int nVets;
int nSingle;
int64 dp[1<<MAX_VERTEX];
int bitCount[1<<MAX_VERTEX];
int64 chose[MAX_VERTEX+1][MAX_VERTEX+1];

int main(){
	int nEdges;
	scanf("%d%d%d",&nVets,&nEdges,&nSingle);
	memset(adj,0,sizeof adj);
	for(int edgeId=0;edgeId<nEdges;edgeId++){
		int s,t;scanf("%d%d",&s,&t);
		--s;--t;
		adj[s][t]=adj[t][s]=true;
	}

	bitCount[0]=0;
	for(int i=1;i<(1<<nVets);i++)
		bitCount[i]=bitCount[i>>1]+(i&1);

	for(int mask=1;mask<(1<<nVets);mask++){
		if(bitCount[mask]==1){
			dp[mask]=1;
			continue;
		}

		dp[mask]=0;
		for(int mask2=mask-1;mask2>0;mask2=(mask2-1)&mask){
			int mask3=mask-mask2;
			if(mask2<mask3){
				int cnt=0;
				for(int i=0;i<nVets;i++)if(mask2>>i&1)
					for(int j=0;j<nVets;j++)if(mask3>>j&1)
						if(adj[i][j])
							cnt++;
				dp[mask]+=dp[mask2]*dp[mask3]*cnt;
			}
		}
		dp[mask]/=(bitCount[mask]-1);
	}

	for(int r=0;r<=nVets;r++)
		for(int c=0;c<=r;c++)
			if(r==0||c==0)
				chose[r][c]=1;
			else
				chose[r][c]=chose[r-1][c]+chose[r-1][c-1];

	int64 ans=0;
	for(int mask=0;mask<(1<<nVets);mask++)
		if(bitCount[mask]>=nSingle&&bitCount[mask]<nVets){
			int64 tmp=dp[(1<<nVets)-1-mask];
			for(int i=0;i<nVets;i++)
				if(mask>>i&1){
					int cnt=0;
					for(int j=0;j<nVets;j++)if(~mask>>j&1)
						if(adj[i][j])
							cnt++;
					tmp*=cnt;
				}

			if(bitCount[mask]%2==nSingle%2)
				ans+=tmp*chose[bitCount[mask]][nSingle];
			else
				ans-=tmp*chose[bitCount[mask]][nSingle];
		}
	cout<<ans<<endl;
}