#include<bits/stdc++.h>
using namespace std;
bool dif[200001];

vector<pair<int,int> > e;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	for(int i=0;i<n;i++)
		dif[i]=(s[i]!=s[(i+1)%n]&&s[i]!=s[(i-1+n)%n]);
	
	for(int i=0;i<n;i++){
		if(!dif[i])	continue;
		int j=i;
		while(j+1<n&&dif[j+1])	j++;
		e.emplace_back(make_pair(i,j));
		i=j;
	}
	if(e.size()==0)
		cout<<s<<endl;
	else{
		if(e.size()>1&&e[0].first==0&&e.back().second==n-1)
			e[0].first=e.back().first,e.pop_back();
		if(e[0].first==0&&e[0].second==n-1){
			if(k&1)
				for(auto& it:s)
					it=char('W'+'B'-it);
			cout<<s<<endl;
			return 0;
		}
		for(auto it:e){
			int cnt=1;
			for(int i=it.first;i!=it.second;i=(i+1)%n)
				cnt++;
			if(k&1){
				if(cnt&1){
					bool ok=false;
					if(k>cnt/2)	ok=true;
					cnt=min(cnt/2,k);
					char now=s[(it.first-1+n)%n];
					for(int i=0;i<cnt;i++)
						s[(i+it.first)%n]=s[(it.second+n-i)%n]=now;
					for(int i=(it.first+cnt)%n;i!=(it.second+n-cnt)%n;i=(i+1)%n)
					s[i]=char('W'+'B'-s[i]);
					s[(it.second+n-cnt)%n]=char('W'+'B'-s[(it.second+n-cnt)%n]);
					if(ok)
						s[(cnt+it.first)%n]=now;
				}
				else{
					int tmp=cnt;
					cnt=min(cnt/2,k);
					char now=s[(it.first-1+n)%n];
					for(int i=0;i<cnt;i++)
						s[(i+it.first)%n]=now,s[(it.second+n-i)%n]=char('W'+'B'-now);
					if(tmp==cnt*2)	continue;
					for(int i=(it.first+cnt)%n;i!=(it.second+n-cnt)%n;i=(i+1)%n)
					s[i]=char('W'+'B'-s[i]);
					s[(it.second+n-cnt)%n]=char('W'+'B'-s[(it.second+n-cnt)%n]);
				}
			}
			else{
				if(cnt&1){
					bool ok=false;
					if(k>cnt/2)	ok=true;
					cnt=min(cnt/2,k);
					char now=s[(it.first-1+n)%n];
					for(int i=0;i<cnt;i++)
						s[(i+it.first)%n]=s[(it.second+n-i)%n]=now;
					if(ok)
						s[(cnt+it.first)%n]=now;
				}
				else{
					cnt=min(cnt/2,k);
					char now=s[(it.first-1+n)%n];
					for(int i=0;i<cnt;i++)
						s[(i+it.first)%n]=now,s[(it.second+n-i)%n]=char('W'+'B'-now);
				}
			}
		}
		cout<<s<<endl;
	}
}