#include<iostream>
using namespace std;

int main(){
	string s,t;
	char ss[200],tt[200];
	scanf("%s",&ss);
	scanf("%s",&tt);

	int n=0,m=0;

	while(ss[n]!='\0'){ s+=ss[n]; n++; }
	while(tt[m]!='\0'){ t+=tt[m]; m++; }
/*	
	cin>>s;
	cin>>t;

	int n=s.size();
	int m=t.size();
*/
	//automaton
	bool a=false;
	int loc=0;
	for(int i=0;i<n;i++){
		if(s[i]==t[loc])loc++;
		if(loc==m){ a=true; break; }
	}

	//array
	bool ar=true,bo=true;
	int cnt_s[30]={0},cnt_t[30]={0};

	for(int i=0;i<n;i++){
		cnt_s[s[i]-'a']++;
	}
	for(int i=0;i<m;i++){
		cnt_t[t[i]-'a']++;
	}

	for(int i=0;i<26;i++){
		if(cnt_s[i]!=cnt_t[i])ar=false;
		if(cnt_s[i]<cnt_t[i])bo=false;
	}

	if(a)printf("automaton\n");
	else if(ar)printf("array\n");
	else if(bo)printf("both\n");
	else printf("need tree\n");

}