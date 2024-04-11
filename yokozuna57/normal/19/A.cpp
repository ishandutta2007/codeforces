#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct TEAM{
	int num;
	int point;
	int dif;
	int score;
};
TEAM mkt(int n,int p,int d,int s){
	TEAM t;
	t.num=n;
	t.point=p;
	t.dif=d;
	t.score=s;
	return t;
}

bool compare(TEAM t1,TEAM t2){
	if(t1.point==t2.point){
		if(t1.dif==t2.dif){
			return t1.score>=t2.score;
		}
		return t1.dif>=t2.dif;
	}
	return t1.point>=t2.point;
}

int main(){
	int n;
	string name[52];
	int point[52]={0},score[52]={0},miss[52]={0};

	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>name[i];
	}

	for(int i=0;2*i<n*(n-1);i++){
		string s;
		string name1,name2;
		int team1,team2;
		int score1,score2;

		cin>>s;
		name1="";
		int k=0;
		while(s[k]!='-'){ name1+=s[k]; k++; }
		name2=s.substr(k+1);

		for(int i=0;i<n;i++){
			if(name1==name[i])team1=i;
			if(name2==name[i])team2=i;
		}

		scanf(" %d:%d",&score1,&score2);

		score[team1]+=score1;
		score[team2]+=score2;
		miss[team1]+=score2;
		miss[team2]+=score1;

		if(score1>score2){
			point[team1]+=3;
		}
		else if(score1<score2){
			point[team2]+=3;
		}
		else {
			point[team1]+=1;
			point[team2]+=1;
		}
	}

	vector<TEAM> t;
	for(int i=0;i<n;i++){
		t.push_back(mkt(i,point[i],score[i]-miss[i],score[i]));
	}

	sort(t.begin(),t.end(),compare);

	vector<string> ans;

	for(int i=0;i<n/2;i++){
		ans.push_back(name[t[i].num]);
	}

	sort(ans.begin(),ans.end());

	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<endl;
	}
}