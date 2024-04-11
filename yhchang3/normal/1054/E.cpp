#include<bits/stdc++.h>
using namespace std;

deque<int> dq[300][300],dq2[300][300];

vector<int> v1,v2;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			string s;
			cin>>s;
			for(int k=0;k<s.size();k++)
				dq[i][j].emplace_back(s[k]-'0');
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			string s;
			cin>>s;
			for(int k=0;k<s.size();k++)
				dq2[i][j].emplace_front(s[k]-'0');
		}
	while(!dq[0][0].empty()){
		v1.emplace_back(0);
		v1.emplace_back(0);
		v1.emplace_back(n-1);
		v1.emplace_back(0);
		dq[n-1][0].emplace_front(dq[0][0].back());
		dq[0][0].pop_back();
	}
	while(!dq[n-1][m-1].empty()){
		v1.emplace_back(n-1);
		v1.emplace_back(m-1);
		v1.emplace_back(0);
		v1.emplace_back(m-1);
		dq[0][m-1].emplace_front(dq[n-1][m-1].back());
		dq[n-1][m-1].pop_back();
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			if((i==0&&j==0)||(i==n-1&&j==m-1))	continue;
			while(!dq[i][j].empty()){
				if(dq[i][j].back()==1){
					if(i!=n-1){
						v1.emplace_back(i);
						v1.emplace_back(j);
						v1.emplace_back(n-1);
						v1.emplace_back(j);
						dq[n-1][j].emplace_front(1);
					}
					else{
						v1.emplace_back(i);
						v1.emplace_back(j);
						v1.emplace_back(n-1);
						v1.emplace_back(m-1);
						dq[n-1][m-1].emplace_front(1);
					}
					dq[i][j].pop_back();
				}
				else{
					if(i!=0){
						v1.emplace_back(i);
						v1.emplace_back(j);
						v1.emplace_back(0);
						v1.emplace_back(j);
					}
					if(j!=0){
						v1.emplace_back(0);
						v1.emplace_back(j);
						v1.emplace_back(0);
						v1.emplace_back(0);
					}
					dq[0][0].emplace_front(0);
					dq[i][j].pop_back();
				}
			}
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			dq[i][j]=dq2[i][j];
	while(!dq[0][0].empty()){
		v2.emplace_back(0);
		v2.emplace_back(0);
		v2.emplace_back(n-1);
		v2.emplace_back(0);
		dq[n-1][0].emplace_front(dq[0][0].back());
		dq[0][0].pop_back();
	}
	while(!dq[n-1][m-1].empty()){
		v2.emplace_back(n-1);
		v2.emplace_back(m-1);
		v2.emplace_back(0);
		v2.emplace_back(m-1);
		dq[0][m-1].emplace_front(dq[n-1][m-1].back());
		dq[n-1][m-1].pop_back();
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			if((i==0&&j==0)||(i==n-1&&j==m-1))	continue;
			while(!dq[i][j].empty()){
				if(dq[i][j].back()==1){
					if(i!=n-1){
						v2.emplace_back(i);
						v2.emplace_back(j);
						v2.emplace_back(n-1);
						v2.emplace_back(j);
						dq[n-1][j].emplace_front(1);
					}
					else{
						v2.emplace_back(i);
						v2.emplace_back(j);
						v2.emplace_back(n-1);
						v2.emplace_back(m-1);
						dq[n-1][m-1].emplace_front(1);
					}
					dq[i][j].pop_back();
				}
				else{
					if(i!=0){
						v2.emplace_back(i);
						v2.emplace_back(j);
						v2.emplace_back(0);
						v2.emplace_back(j);
					}
					if(j!=0){
						v2.emplace_back(0);
						v2.emplace_back(j);
						v2.emplace_back(0);
						v2.emplace_back(0);
					}
					dq[0][0].emplace_front(0);
					dq[i][j].pop_back();
				}
			}
		}
	cout<<(v1.size()+v2.size())/4<<'\n';
	for(int i=0;i<v1.size();i+=4)
		cout<<v1[i]+1<<' '<<v1[i+1]+1<<' '<<v1[i+2]+1<<' '<<v1[i+3]+1<<'\n';
	for(int i=(int)v2.size()-4;i>=0;i-=4)
		cout<<v2[i+2]+1<<' '<<v2[i+3]+1<<' '<<v2[i]+1<<' '<<v2[i+1]+1<<'\n';
	
}