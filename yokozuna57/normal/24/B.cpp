#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

int Point[11]={0,25,18,15,12,10,8,6,4,2,1};

struct player{
	int point;
	int win;
	vector<int> places;
};
player mkp(){ player P; P.point=0; P.win=0; return P; }

bool compare1(pair<player,string> x,pair<player,string> y){
	if(x.first.point==y.first.point){
		for(int i=0;i<min(x.first.places.size(),y.first.places.size());i++){
			if(x.first.places[i]<y.first.places[i])return true;
			if(x.first.places[i]>y.first.places[i])return false;
		}
		return x.first.places.size()>=y.first.places.size();
	}
	return x.first.point>=y.first.point;
}

bool compare2(pair<player,string> x,pair<player,string> y){
	if(x.first.win==y.first.win)return compare1(x,y);
	return x.first.win>=y.first.win;
}

int main(){
	map<string,player> MAP;

	int t;
	scanf("%d",&t);

	for(;t>0;t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			string s;
			cin>>s;

			map<string,player>::iterator itr=MAP.find(s);
			if(itr==MAP.end()){MAP[s]=mkp(); itr=MAP.find(s);}

			if(i<=10){
				if(i==1)(*itr).second.win++;
				(*itr).second.point+=Point[i];
			}
			(*itr).second.places.push_back(i);
		}
	}

	vector<pair<player,string>> P1;
	vector<pair<player,string>> P2;

	map<string,player>::iterator itr=MAP.begin();
	for(;itr!=MAP.end();itr++){
		sort((*itr).second.places.begin(),(*itr).second.places.end());
		P1.push_back(pair<player,string>((*itr).second,(*itr).first));
/*cout<<(*itr).first<<"::"<<endl;
cout<<(*itr).second.point<<" "<<(*itr).second.win<<endl;
for(int j=0;j<(*itr).second.places.size();j++){
cout<<(*itr).second.places[j]<<" ";
}*/
	}
	P2=P1;

	sort(P1.begin(),P1.end(),compare1);
	sort(P2.begin(),P2.end(),compare2);

	cout<<P1[0].second<<endl;
	cout<<P2[0].second<<endl;
}