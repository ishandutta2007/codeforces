#include <bits/stdc++.h>
using namespace std;
int p[100001];
vector <int> pr[100001];
bool on[100001];
int key[100001];
int n, m;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=2; i<=n; i++) if(p[i]==0) for(int j=i; j<=n; j+=i) if(p[j]==0) p[j]=i;
	for(int i=1; i<=n; i++){
		int x=i;
		while(x>1){
			int u=p[x];
			pr[i].push_back(u);
			while(x%u==0) x/=u;
		}
	}
	{
		char c;
		int x;
		for(int i=1; i<=m; i++){
			cin>>c>>x;
			if(c=='+'){
				if(on[x]){
					cout<<"Already on\n";
					continue;
				}
				bool good=1;
				for(int y: pr[x]) if(key[y]){
					good=0;
					break;
				}
				if(good){
					for(int y: pr[x]) key[y]=x;
					on[x]=1;
					cout<<"Success\n";
				}
				else{
					for(int y: pr[x]) if(key[y]){
						cout<<"Conflict with "<<key[y]<<'\n';
						break;
					}
				}
			}
			else{
				if(!on[x]){
					cout<<"Already off\n";
					continue;
				}
				for(int y: pr[x]) key[y]=0;
				on[x]=0;
				cout<<"Success\n";
			}
		}
	}
}