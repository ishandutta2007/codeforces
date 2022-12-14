#include<iostream>
#include<cstring>
using namespace std;
 
int dp[51][51][51];
struct Restriction{
	int l,r,h,c;
}res[50];
int cost[52];
int main(){
	int n,h,m;
	cin>>n>>h>>m;
	for(int i=0;i<m;i++)
		cin>>res[i].l>>res[i].r>>res[i].h>>res[i].c;
	for(int len=1;len<=n;len++){
		for(int l=1;l+len-1<=n;l++){
			int r=l+len-1;
			for(int mid=l;mid<=r;mid++){
				memset(cost,0,sizeof cost);
				for(int i=0;i<m;i++)
					if(l<=res[i].l&&res[i].l<=mid&&mid<=res[i].r&&res[i].r<=r)
						cost[res[i].h+1]+=res[i].c;
				for(int i=0;i<=50;i++)
					cost[i+1]+=cost[i];
				for(int mid_h=0;mid_h<=h;mid_h++){
					int sum=mid_h*mid_h-cost[mid_h];
					if(mid!=l)
						sum+=dp[l][mid-1][mid_h];
					if(mid!=r)
						sum+=dp[mid+1][r][mid_h];
					dp[l][r][mid_h]=max(dp[l][r][mid_h],sum);
				}
			}
			for(int mid_h=0;mid_h<h;mid_h++)
				dp[l][r][mid_h+1]=max(dp[l][r][mid_h+1],dp[l][r][mid_h]);
		}
	}
	cout<<dp[1][n][h]<<endl;
}