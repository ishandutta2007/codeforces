#include<bits/stdc++.h>
using namespace std;
int level[10],vis[5000],s,T;
char S[10];
queue<int>q;
string anses[512],f[512][5];
int upd(string& A,const string& B){
	if(A=="")A=B;
	else if(A.length()<B.length())return 0;
	else if(A.length()==B.length()&&A<B)return 0;
	else A=B;
	return 1;
}
string addk(string s,int a,int b){
	if(s.length()>1&&level[a]<level[b])return "("+s+")";
	else return s;
}

int main(){
	level[0]=10,level[3]=3,level[2]=1,level[1]=2;
	f[15][0]="x",f[51][0]="y",f[85][0]="z";
	q.push(15<<2|0);
	q.push(51<<2|0);
	q.push(85<<2|0);
	while(q.size()){
		int u=q.front();
		q.pop();
		int s=u>>2,t=u&3;
		vis[u]=false;
		if(f[s][t]=="")printf("<%d,%d>",s,t),exit(-1); 
		for(int ni=0;ni<256;++ni)
			for(int k=0;k<=3;++k)if(f[ni][k]!=""){
				if(upd(f[s&ni][1],min(addk(f[s][t],t,1)+"&"+addk(f[ni][k],k,1),addk(f[ni][k],k,1)+"&"+addk(f[s][t],t,1)))&&!vis[(s&ni)<<2|1])
					q.push((s&ni)<<2|1),vis[(s&ni)<<2|1]=true;
				if(upd(f[s|ni][2],min(addk(f[s][t],t,2)+"|"+addk(f[ni][k],k,2),addk(f[ni][k],k,2)+"|"+addk(f[s][t],t,2)))&&!vis[(s|ni)<<2|2])
					q.push((s|ni)<<2|2),vis[(s|ni)<<2|2]=true;
			}
		if(upd(f[~s&255][3],"!"+addk(f[s][t],t,3))&&!vis[(~s&255)<<2|3])
			q.push((~s&255)<<2|3),vis[(~s&255)<<2|3]=true;
	}
	for(int i=0;i<256;++i)
		for(int j=0;j<=3;++j)if(f[i][j]!="")
			upd(anses[i],f[i][j]);
	scanf("%d",&T);
	while(T--){
		scanf("%s",S),s=0;
		for(int i=0;i<8;++i)
			s=s<<1|(S[i]-48);
//		printf("[%d]",s);
		printf("%s\n",anses[s].c_str());
	}
}