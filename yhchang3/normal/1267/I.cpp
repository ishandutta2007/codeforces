#include<bits/stdc++.h>
using namespace std;


char ask(int i,int j){
	char c;
	cout<<'?'<<' '<<i<<' '<<j<<endl;
	cin>>c;
	return c;
}
set<pair<int,int> > st;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	char c;
	while(T--){
		st.clear();
		int n;
		cin>>n;
		vector<int> v,vvv;
		for(int i=1;i<=n;i++){
			c=ask(i,i+n);
			st.insert(make_pair(i,i+n));
			if(c=='>')
				v.emplace_back(i+n),vvv.emplace_back(i);
			else
				v.emplace_back(i),vvv.emplace_back(i+n);
		}
		vector<int> cnt(n,0);
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++){
				c=ask(v[i],v[j]);
				if(v[i]>v[j])
					st.insert(make_pair(v[j],v[i]));
				else
					st.insert(make_pair(v[i],v[j]));
				if(c=='>')
					cnt[j]++;
				else
					cnt[i]++;
			}
		int who;
		for(int i=0;i<n;i++)
			if(cnt[i]==1){
				who=v[i];
				break;
			}
		int z=0;
		vector<int> vv;
		for(int i=1;i<=2*n;i++)
			if(i!=who){
				if(ask(who,i)=='>'){
					vv.emplace_back(i);
					z++;
				}
				if(who<i)
					st.insert(make_pair(who,i));
				else
					st.insert(make_pair(i,who));
			}
		if(z==n-2){
			int y;
			for(int i=0;i<n;i++)
				if(cnt[i]==0)
					y=v[i];
			int yy;
			if(y>n)
				yy=y-n;
			else
				yy=y+n;
			vector<int> kk;
			kk.emplace_back(y);
			for(int i=0;i<n;i++)
				if(vvv[i]==yy){
					swap(vvv[i],vvv.back());
					vvv.pop_back();
					break;
				}
			if((n-1)&1)	kk.emplace_back(vvv.back());
			for(int i=0;i+1<n-1;i+=2){
				c=ask(vvv[i],vvv[i+1]);
				if(c=='>')
					kk.emplace_back(vvv[i+1]);
				else
					kk.emplace_back(vvv[i]);
			}
			for(int i=0;i<kk.size();i++)
				for(int j=i+1;j<kk.size();j++)
					ask(kk[i],kk[j]);
		}
		else{
			for(int i=0;i<vv.size();i++)
				for(int j=i+1;j<vv.size();j++)
					if(!st.count(make_pair(vv[i],vv[j])))
						ask(vv[i],vv[j]);
		}
		cout<<'!'<<endl;
	}
}