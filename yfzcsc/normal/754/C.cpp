#include<bits/stdc++.h>
#define __exit() {printf("Impossible\n");goto end;}
using namespace std;
map<string,int>st;
vector<string>vec;
int lim[110],n,m,t,hehe[110];
string chose[110],msg,rmsg[110];
queue<int>q;
void push(string& x){
	st[x]=vec.size();
	vec.push_back(x);
}
int only(int x){
	int p=-2;
	for(int i=0;i<n;++i)if(!((1<<i)&x)){
		if(p<0)p=i;
		else return -1;
	}
	return p;
}
int make(){
	for(int i=1;i<=m;++i)if(chose[i]==""){
		int g=0;
		for(int j=0;j<n;++j)
			if(!((1<<j)&lim[i])){g=j;break;}
		chose[i]=vec[g];
		lim[i+1]|=1<<g;
	}
}
void out(int x){
	bool flag=0;
	if(hehe[x])cout<<rmsg[x];
	else for(int i=0;i<rmsg[x].length();++i){
		if(rmsg[x][i]=='?'&&!flag)
			flag=true,cout<<chose[x];
		else cout<<rmsg[x][i];
	}
	printf("\n");
}
int main(){
	scanf("%d",&t);
	string man;
	while(t--){
		scanf("%d",&n);
		memset(lim,0,sizeof(lim));
		memset(hehe,0,sizeof(hehe));
		vec.clear();st.clear();
		for(int i=1;i<=n;++i)
			cin>>man,push(man);
		scanf("%d",&m);
//		printf("<%d>",m);
		for(int i=1;i<=m;++i){
//			printf("<%d>",i);
			msg="";
			while(msg=="")getline(cin,msg);
	//		cout<<msg;
			rmsg[i]=msg;
			bool maohao=0;
			for(int j=0;j<msg.length();++j)
				if(!isalpha(msg[j])&&!isdigit(msg[j])){
					if(msg[j]=='?'){if(maohao)msg[j]=' ';}
					else if(msg[j]==':')maohao=1,msg[j]=' ';
					else msg[j]=' ';
				}
			stringstream ss(msg);
			string ren,beren;ss>>ren;
			if(ren=="?")ren="";
			else hehe[i]=1;
			chose[i]=ren;
			while(ss>>beren){
		//		cout<<'['<<beren<<'.'<<ren<<']'<<endl;
				if(st.find(beren)!=st.end()){
					if(beren==ren)__exit()
					else if(ren=="")lim[i]|=1<<st[beren];
				}
			}
		}
	//	printf("aisdjfoasdji");
		while(true){
			for(int i=1;i<=m;++i)if(chose[i]==""){
				if(i>1&&chose[i-1]!="")lim[i]|=1<<st[chose[i-1]];
				if(i<m&&chose[i+1]!="")lim[i]|=1<<st[chose[i+1]];
			}
			bool has=0;
			for(int i=1;i<=m;++i)if(chose[i]==""){
				int g=only(lim[i]);
				if(g==-1)continue;
				else if(g==-2)__exit()
				else has=true,chose[i]=vec[g];
			}
			if(!has){
				make();
				break;
			}
		}
		for(int i=1;i<=m;++i)out(i);
		end:;
	}
}