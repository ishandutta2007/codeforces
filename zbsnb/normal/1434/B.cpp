#include<bits/stdc++.h>
using namespace std;
#define ll long long
int pos[1000010];
int ans[1000010];
int a[1000010];
int b[1000010];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int n;cin>>n;
	stack<int> q;
	int now=0;
	int flg=0;
	for(int i=1;i<=2*n;i++){
		char s[5];cin>>s;
		if(s[0]=='+'){
			a[i]=1;
			if(flg) continue;
			q.push(++now);
		}
		else{
			a[i]=-1;
			int tmp;cin>>tmp;
			b[i]=tmp;
			if(flg) continue;
			if(q.empty()){
				flg=1;
				continue;
			}
			int pos=q.top();q.pop();
			ans[pos]=tmp;
			// cout<<pos<<" "<<tmp<<endl;
		}
	}
	if(flg) cout<<"NO"<<endl;
	else{
		int now=0;
		for(int i=1;i<=2*n;i++){
			if(a[i]==1){
				if(!q.empty()){
					int pre=q.top();
					int tmp=ans[now+1];
					if(tmp>pre){
						flg=1;
						break;
					}
				}
				q.push(ans[++now]);
			}
			else{
				q.pop();
			}
		}
		if(flg){
			cout<<"NO"<<endl;
			return 0;
		}
		cout<<"YES"<<endl;
		for(int i=1;i<=n;i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
}