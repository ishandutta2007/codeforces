#include<iostream>
using namespace std;
char mp[110][110];
char ans[110][110];
char s[64];
int main(){
	for(int i=0;i<=9;i++)s[i]=i+'0';
	for(int i=0;i<26;i++){
		s[i+10]='a'+i;
		s[i+36]='A'+i;
	}

	int t;cin>>t;
	while(t--){
		int cnt=0;
		int n,m,k;cin>>n>>m>>k;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>mp[i][j];
				cnt+=mp[i][j]=='R';
			}
		}

		int num1=cnt/k,num2=num1+1;
		int cnt1=k-cnt%k,cnt2=cnt%k;

		//cout<<cnt<<" "<<num1<<" "<<cnt1<<endl;

		int now=0;
		int ind=0;

		for(int i=1;i<=n;i++){
			for(int j=i%2?1:m;i%2?j<=m:j>=1;i%2?j++:j--){
				//cout<<i<<" "<<j<<endl;
				if(mp[i][j]=='R')now++;
				ans[i][j]=s[ind];

				if(now==num1&&cnt1){
					cnt1--;
					if(cnt1+cnt2!=0)ind++;
					now=0;
					continue;
				}

				if(now==num2&&cnt2){
					cnt2--;
					if(cnt1+cnt2!=0)ind++;
					now=0;
					continue;
				}
			}
		}

		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cout<<ans[i][j];
			}
			cout<<endl;
		}
	}
}