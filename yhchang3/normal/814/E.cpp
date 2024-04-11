#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int d[51];

long long int dp[2][51][51][51][51];

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>d[i];
	dp[0][d[1]==2?1:0][d[1]==3?1:0][d[2]==2?1:0][d[2]==3?1:0]=1;
	for(int i=3;i<=n;i++){
		int now=i&1,pre=now^1;
		for(int pre1=0;pre1<=n;pre1++)
			for(int pre2=0;pre2<=n;pre2++)
				for(int cur1=0;cur1<=n;cur1++)
					for(int cur2=0;cur2<=n;cur2++)
						dp[now][pre1][pre2][cur1][cur2]=0;
		for(int pre1=0;pre1<=n;pre1++)
			for(int pre2=0;pre2<=n;pre2++)
				for(int cur1=0;cur1<=n;cur1++)
					for(int cur2=0;cur2<=n;cur2++){
						if(dp[pre][pre1][pre2][cur1][cur2]==0)	continue;
						if(pre1!=0){
							if(d[i]==2){
								dp[now][pre1-1][pre2][cur1+1][cur2]+=dp[pre][pre1][pre2][cur1][cur2]*pre1;
								if(cur1!=0)
									dp[now][pre1-1][pre2][cur1-1][cur2]+=dp[pre][pre1][pre2][cur1][cur2]*pre1*cur1;
								if(cur2!=0)
									dp[now][pre1-1][pre2][cur1+1][cur2-1]+=dp[pre][pre1][pre2][cur1][cur2]*pre1*cur2;
							}
							else{
								dp[now][pre1-1][pre2][cur1][cur2+1]+=dp[pre][pre1][pre2][cur1][cur2]*pre1;
								if(cur1!=0)
									dp[now][pre1-1][pre2][cur1][cur2]+=dp[pre][pre1][pre2][cur1][cur2]*pre1*cur1;
								if(cur1>1)
									dp[now][pre1-1][pre2][cur1-2][cur2]+=dp[pre][pre1][pre2][cur1][cur2]*pre1*cur1*(cur1-1)/2;
								if(cur2!=0)
									dp[now][pre1-1][pre2][cur1+2][cur2-1]+=dp[pre][pre1][pre2][cur1][cur2]*pre1*cur2;
								if(cur2>1)
									dp[now][pre1-1][pre2][cur1+2][cur2-2]+=dp[pre][pre1][pre2][cur1][cur2]*pre1*cur2*(cur2-1)/2;
								if(cur1!=0&&cur2!=0)
									dp[now][pre1-1][pre2][cur1][cur2-1]+=dp[pre][pre1][pre2][cur1][cur2]*pre1*cur1*cur2;

								
							}
						}
						if(pre2!=0){
							if(d[i]==2){
								dp[now][pre1+1][pre2-1][cur1+1][cur2]+=dp[pre][pre1][pre2][cur1][cur2]*pre2;
								if(cur1!=0)
									dp[now][pre1+1][pre2-1][cur1-1][cur2]+=dp[pre][pre1][pre2][cur1][cur2]*pre2*cur1;
								if(cur2!=0)
									dp[now][pre1+1][pre2-1][cur1+1][cur2-1]+=dp[pre][pre1][pre2][cur1][cur2]*pre2*cur2;
							}
							else{
								dp[now][pre1+1][pre2-1][cur1][cur2+1]+=dp[pre][pre1][pre2][cur1][cur2]*pre2;
								if(cur1!=0)
									dp[now][pre1+1][pre2-1][cur1][cur2]+=dp[pre][pre1][pre2][cur1][cur2]*pre2*cur1;
								if(cur1>1)
									dp[now][pre1+1][pre2-1][cur1-2][cur2]+=dp[pre][pre1][pre2][cur1][cur2]*pre2*cur1*(cur1-1)/2;
								if(cur2!=0)
									dp[now][pre1+1][pre2-1][cur1+2][cur2-1]+=dp[pre][pre1][pre2][cur1][cur2]*pre2*cur2;
								if(cur2>1)
									dp[now][pre1+1][pre2-1][cur1+2][cur2-2]+=dp[pre][pre1][pre2][cur1][cur2]*pre2*cur2*(cur2-1)/2;
								if(cur1!=0&&cur2!=0)
									dp[now][pre1+1][pre2-1][cur1][cur2-1]+=dp[pre][pre1][pre2][cur1][cur2]*pre2*cur1*cur2;
							}
						}
						if(pre1==0&&pre2==0){
							if(cur1!=0){
								dp[now][cur1-1][cur2][d[i]==2][d[i]==3]+=dp[pre][0][0][cur1][cur2]*cur1;
							}
							if(cur2!=0){
								dp[now][cur1+1][cur2-1][d[i]==2][d[i]==3]+=dp[pre][0][0][cur1][cur2]*cur2;
							}
						}
					}
		for(int pre1=0;pre1<=n;pre1++)
			for(int pre2=0;pre2<=n;pre2++)
				for(int cur1=0;cur1<=n;cur1++)
					for(int cur2=0;cur2<=n;cur2++)
						dp[now][pre1][pre2][cur1][cur2]%=mod;
		
	}
	cout<<dp[n&1][0][0][0][0]<<endl;

}