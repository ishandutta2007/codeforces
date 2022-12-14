#include<bits/stdc++.h>
using namespace std;

int D[257],Q[257];
int from[8];
bool ok[257],on[257];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1,x,y,z;i<=n;i++){
		cin>>x>>y>>z;
		D[i]=x<<2|y<<1|z;
	}
	for(int i=1,x,y,z;i<=n;i++){
		cin>>x>>y>>z;
		Q[i]=x<<2|y<<1|z;
		Q[i]&=D[i];
	}
	from[7]=1;
	ok[1]=true;
	vector<pair<int,int> > e;
	while(true){
		bool chg=false;
		for(int i=1;i<=n;i++)
			if(!ok[i]){
				int cnt=(D[i]&4)/4+(D[i]&2)/2+(D[i]&1);
				if(cnt==0){
					chg=ok[i]=true;
				}
				else if(cnt==3){
					chg=ok[i]=true;
					e.emplace_back(1,i);
					if(!from[Q[i]]){
						from[Q[i]]=i;
						on[i]=true;
					}
					else{
						from[D[i]]=i;
					}
				}
				else if(cnt==1){
					if(from[D[i]]){
						chg=ok[i]=true;
						e.emplace_back(from[D[i]],i);
					}
					else	continue;
					if(!from[Q[i]]){
						from[Q[i]]=i;
						on[i]=true;
					}
					else{
						from[D[i]]=i;
					}
				}
				else{
					if(from[D[i]]){
						ok[i]=true;
						e.emplace_back(from[D[i]],i);
					}
					else if((D[i]&4)&&(D[i]&2)&&from[4]&&from[2]){
						e.emplace_back(from[4],i);
						e.emplace_back(from[2],i);
						ok[i]=true;
					}
					else if((D[i]&1)&&(D[i]&2)&&from[1]&&from[2]){
						e.emplace_back(from[1],i);
						e.emplace_back(from[2],i);
						ok[i]=true;
					}
					else if((D[i]&4)&&(D[i]&1)&&from[4]&&from[1]){
						e.emplace_back(from[4],i);
						e.emplace_back(from[1],i);
						ok[i]=true;
					}
					else	continue;
					chg=true;
					if(!from[Q[i]]){
						from[Q[i]]=i;
						on[i]=true;
					}
					else{
						from[D[i]]=i;
					}
				}
			}
		if(!chg)	break;
	}
	for(int i=1;i<=n;i++)
		if(!ok[i]){
			cout<<"Impossible"<<endl;
			return 0;
		}
	cout<<"Possible"<<endl;
	for(int i=1;i<=n;i++)
		cout<<on[i]<<' ';
	cout<<endl<<e.size()<<endl;
	for(auto it:e)
		cout<<it.first<<' '<<it.second<<'\n';

}