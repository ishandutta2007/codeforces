#include<bits/stdc++.h>
using namespace std;

int dp[260][260][260];
int occ[26][100010];
string s,a,b,c;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,q;
	cin>>n>>q;
	cin>>s;
	s.insert(0," ");
	for(int i=0;i<26;i++){
		int tmp=1e9;
		for(int j=n;j>=0;j--){
			occ[i][j]=tmp;
			if(s[j]-'a'==i){
				tmp=j;
			}
		}
	}
	char op,ch;
	int which;
	dp[0][0][0]=0;
	for(int i=0;i<q;i++){
		cin>>op>>which;
		if(op=='+'){
			cin>>ch;
			if(which==1)
				a+=ch;
			else if(which==2)
				b+=ch;
			else
				c+=ch;
			int as=a.size(),bs=b.size(),cs=c.size();
			if(which==1){
				for(int j=0;j<=bs;j++)
					for(int k=0;k<=cs;k++){
						dp[as][j][k]=(dp[as-1][j][k]<=n?occ[a.back()-'a'][dp[as-1][j][k]]:1e9);
						if(j&&dp[as][j-1][k]<=n)
							dp[as][j][k]=min(dp[as][j][k],occ[b[j-1]-'a'][dp[as][j-1][k]]);
						if(k&&dp[as][j][k-1]<=n)
							dp[as][j][k]=min(dp[as][j][k],occ[c[k-1]-'a'][dp[as][j][k-1]]);
					}
			}
			else if(which==2){
				for(int j=0;j<=as;j++)
					for(int k=0;k<=cs;k++){
						dp[j][bs][k]=(dp[j][bs-1][k]<=n?occ[b.back()-'a'][dp[j][bs-1][k]]:1e9);
						//cout<<j<<' '<<k<<' '<<dp[j][bs][k]<<endl;
						if(j&&dp[j-1][bs][k]<=n)
							dp[j][bs][k]=min(dp[j][bs][k],occ[a[j-1]-'a'][dp[j-1][bs][k]]);
						if(k&&dp[j][bs][k-1]<=n)
							dp[j][bs][k]=min(dp[j][bs][k],occ[c[k-1]-'a'][dp[j][bs][k-1]]);			
					}
			}
			else{
				for(int j=0;j<=as;j++)
					for(int k=0;k<=bs;k++){
						dp[j][k][cs]=(dp[j][k][cs-1]<=n?occ[c.back()-'a'][dp[j][k][cs-1]]:1e9);
						if(j&&dp[j-1][k][cs]<=n)
							dp[j][k][cs]=min(dp[j][k][cs],occ[a[j-1]-'a'][dp[j-1][k][cs]]);
						if(k&&dp[j][k-1][cs]<=n)
							dp[j][k][cs]=min(dp[j][k][cs],occ[b[k-1]-'a'][dp[j][k-1][cs]]);
						
					}
			}
		//	cout<<as<<' '<<bs<<' '<<cs<<' '<<dp[as][bs][cs]<<endl;
			if(dp[as][bs][cs]<=n)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
		else{
			if(which==1)
				a.pop_back();
			else if(which==2)
				b.pop_back();
			else
				c.pop_back();	
			int as=a.size(),bs=b.size(),cs=c.size();
			if(dp[as][bs][cs]<=n)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
	}
	
}