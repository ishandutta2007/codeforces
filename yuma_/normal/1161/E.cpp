#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string out1(vector<pair<int,int>>&querys){
	if(querys.empty())return "";
	cout<<"Q "<<querys.size();
	for(auto q:querys){
		cout<<' '<<q.first+1<<' '<<q.second+1;
	}
	cout<<endl;
	fflush(stdout);
	string st;cin>>st;
	return st;
}
void out2(vector<vector<int>>answer){

	cout<<"A "<<answer[0].size()<<' '<<answer[1].size()<<' '<<answer[2].size()<<endl;
	for(int i=0;i<3;++i){
		if(answer[i].empty())cout<<endl;
		for(int j=0;j<answer[i].size();++j){
			cout<<answer[i][j]+1;
			if(j==answer[i].size()-1)cout<<endl;
			else cout<<' ';
		}
	}
	fflush(stdout);
	return;
}
int main() {
	ios::sync_with_stdio(false);
	int T;cin>>T;
	while(T--){
		int N;cin>>N;
		vector<vector<int>>vals(1,vector<int>{0});
		{
				vector<int>sames(N-1);
			{
				vector<pair<int,int>>querys;
				for(int i=0;i<N-1;i+=2){
					querys.push_back(make_pair(i,i+1));
				}
				string st=out1(querys);
				for(int i=0;i<st.size();++i){
					sames[2*i]=st[i]=='1';
				}
			}
			{
				vector<pair<int,int>>querys;
				for(int i=1;i<N-1;i+=2){
					querys.push_back(make_pair(i,i+1));
				}
				string st=out1(querys);
				for(int i=0;i<st.size();++i){
					sames[2*i+1]=st[i]=='1';
				}
			}
			for(int i=0;i<N-1;++i){
				if(sames[i]){
				}else{
					vals.push_back(vector<int>());
				}
				vals.back().push_back(i+1);
			}
		}
		vector<int>types(vals.size(),-1);
		vector<vector<int>>answers(3);

		if(types.size()==1){
			types[0]=0;
		}else{
			types[0]=0;
			types[1]=1;
			vector<int>sames(types.size()-2);
			{
				vector<pair<int,int>>querys;
				for(int i=0;i<vals.size()-2;i+=4){
					querys.emplace_back(vals[i][0],vals[i+2][0]);
				}
				for(int i=1;i<vals.size()-2;i+=4){
					querys.emplace_back(vals[i][0],vals[i+2][0]);
				}
				string st=out1(querys);
				int id=0;
				for(int i=0;i<vals.size()-2;i+=4){
					sames[i]=st[id]=='1';
					id++;
				}
				for(int i=1;i<vals.size()-2;i+=4){
					sames[i]=st[id]=='1';
					id++;
				}
			}
			{
				vector<pair<int,int>>querys;
				for(int i=2;i<vals.size()-2;i+=4){
					querys.emplace_back(vals[i][0],vals[i+2][0]);
				}
				for(int i=3;i<vals.size()-2;i+=4){
					querys.emplace_back(vals[i][0],vals[i+2][0]);
				}
				string st=out1(querys);
				int id=0;
				for(int i=2;i<vals.size()-2;i+=4){
					sames[i]=st[id]=='1';
					id++;
				}
				for(int i=3;i<vals.size()-2;i+=4){
					sames[i]=st[id]=='1';
					id++;
				}
			}
			for(int type_id=2;type_id<types.size();++type_id){
				if(sames[type_id-2]){
					types[type_id]=types[type_id-2];
				}else{
					types[type_id]=3-types[type_id-1]-types[type_id-2];
				}
			}
			
		}
		for(int i=0;i<types.size();++i){
			int atype=types[i];
			for(auto v:vals[i]){
				answers[atype].push_back(v);
			}
		}
		out2(answers);
	}
	return 0;
}