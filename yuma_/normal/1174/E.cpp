#include<bits/stdc++.h>
using namespace std;
using ll=long long  ;
vector<int>divisor(ll x){
  vector<int>divs;
  for(ll i=1;i*i<=x;++i){
    if(x%i==0){
      if(i*i!=x){
	divs.push_back(x/i);
      }
      divs.push_back(i);
    }
  }
  sort(divs.begin(),divs.end());
  return divs;;
}
ll mod=1e9+7;
ll solve(int N,int x){
  vector<int>divs=divisor(x);
  map<int,int>tos;
  for(int i=0;i<divs.size();++i){
    tos[divs[i]]=i;
  }
  vector<int>nums(divs.size());
  for(int i=0;i<divs.size();++i){
    nums[i]=N/divs[i];
    if(divs[i]%2==0){
      nums[tos[divs[i]/2]]-=nums[i];
    }
    if(divs[i]%3==0){
      nums[tos[divs[i]/3]]-=nums[i];
    }
    if(divs[i]%6==0){
      nums[tos[divs[i]/6]]+=nums[i];
    }
  }
  for(int i=0;i<divs.size();++i){
    //cout<<divs[i]<<" "<<nums[i]<<endl;
  }
  vector<vector<ll>>dp(2,vector<ll>(divs.size()));
  dp[0][divs.size()-1]=1;
  for(int i=0;i<N-1;++i){
    int cur=i&1;
    int tar=!cur;
    for(int j=0;j<divs.size();++j){
      int a=N/divs[j]-i-1;
      if(a>0){
	
	dp[tar][j]+=dp[cur][j]*a;
	dp[tar][j]%=mod;
      }
      if(divs[j]%2==0){
	int to=tos[divs[j]/2];
        int b=N/divs[to]-N/divs[j];
	dp[tar][tos[divs[j]/2]]+=dp[cur][j]*b;
      }
      if(divs[j]%3==0){
	
	int to=tos[divs[j]/3];
        int b=N/divs[to]-N/divs[j];
	dp[tar][tos[divs[j]/3]]+=dp[cur][j]*b;
      }
      
    }
    for(int j=0;j<divs.size();++j){
      dp[cur][j]=0;
      dp[tar][j]%=mod;
    }
  }
  return dp[(N-1)%2][0];
  
}

int main(){
  int N;cin>>N;
  ll num=1;
  int x=0;
  while(num*2<=N){
    num*=2;
    x++;
  }
  ll ans1=solve(N,num);
  //cout<<ans1<<endl;
  if(num/2*3<=N)ans1+=solve(N,num/2*3);
  ans1%=mod;
  
  cout<<ans1<<endl;
  return 0;
}