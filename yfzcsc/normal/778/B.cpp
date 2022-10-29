#include<bits/stdc++.h>
#include<tr1/unordered_map>
using namespace std;
int n,m,st[10010];
map<string,int>xst;
vector<string>vec;
int getid(string& a){
	if(xst.count(a))return xst[a];
	return vec.push_back(a),xst[a]=vec.size()-1;
}
struct data{
	int a,b,c;
	int op;
}z[5010];
int check(int w){
	for(int i=1;i<=n;++i){
		if(z[i].op==0)st[z[i].a]=vec[z[i].b][w]-'0';//,cout<<z[i].a<<"----"<<vec[z[i].b]<<"--------"<<w<<"---------"<<st[z[i].a]<<endl;
		else if(z[i].op==1)st[z[i].a]=(st[z[i].b])^(st[z[i].c]);//,printf("[%s,%d,%d]",vec[z[i].b].c_str(),st[z[i].b],st[z[i].c]);
		else if(z[i].op==2)st[z[i].a]=(st[z[i].b])&(st[z[i].c]);
		else st[z[i].a]=(st[z[i].b])|(st[z[i].c]);
	}
	int ans=0;
	for(int i=0;i<vec.size();++i){if(st[i]&&vec[i][0]!='?')ans++;}//printf("[%s=%d]",vec[i].c_str(),st[i]);}putchar(10);
	return ans;
}
int main(){
	scanf("%d%d\n",&n,&m);
	for(int i=1;i<=n;++i){
		string str="";
		while(str=="")getline(cin,str);
		stringstream ss(str);
		string x;
		ss>>x;
		z[i].a=getid(x);
		ss>>x;
		ss>>x;
		if(x[0]!='1'&&x[0]!='0'){
			z[i].b=getid(x);
			ss>>x;
			z[i].op=(x=="XOR"?1:(x=="AND"?2:3));
			ss>>x;
			z[i].c=getid(x);
		} else z[i].b=getid(x);
	}
	char mn[5010],mx[5010];
	for(int i=0;i<m;++i)mn[i]='0',mx[i]='0';
	string str="?";
	int a=getid(str);
	for(int i=m-1;i>=0;--i){
		st[a]=1;
		int x=check(i);
		st[a]=0;
		int y=check(i);
		if(x==y)mn[i]=mx[i]='0';
		else if(x>y)mn[i]='1',mx[i]='0';
		else mn[i]='0',mx[i]='1';
	}
	for(int i=0;i<m;++i)printf("%c",mx[i]);puts("");
	for(int i=0;i<m;++i)printf("%c",mn[i]);
}