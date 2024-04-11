#include<bits/stdc++.h>
using namespace std;
int m[60][60];
char ch;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			cin>>ch;
			if(ch=='.')
				m[i][j]=1;
		}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(m[i][j]==1){
				if(m[i+1][j]==0||m[i+1][j-1]==0||m[i+1][j+1]==0||m[i+2][j]==0){
					cout<<"NO"<<endl;
					return 0;
				}
				else{
					m[i][j]=m[i+1][j]=m[i+1][j-1]=m[i+1][j+1]=m[i+2][j]=0;
				}
			}
		}
	}
	cout<<"YES"<<endl;
	
}