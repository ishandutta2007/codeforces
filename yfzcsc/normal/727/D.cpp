#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<map>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
map<string,int>st;
int a[10],n;
int chose[100011];
int deg[10];
char str[30];
char ansx[][6]={"","S","M","L","XL","XXL","XXXL"};
int rel[]={0,3,5,7,9,11};
int f[][2]={{0,0},{1,2},{2,3},{3,4},{4,5},{5,6}};
vector<int>x[20];
int main(){
	
	st["S"]=1,st["M"]=2,st["L"]=3;
	st["XL"]=4,st["XXL"]=5,st["XXXL"]=6;
	for(int i=1;i<=6;++i)scanf("%d",&a[i]);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%s",str);
		int pos=0;
		while(str[pos]&&str[pos]!=',')pos++;
		if(!str[pos]){a[chose[i]=st[str]]--;}
		else {
			str[pos]=0;
			x[st[str]+st[str+pos+1]].push_back(i);
		}
	}
	for(int i=1;i<=6;++i)if(a[i]<0){
		printf("NO\n");
		return 0;
	}
	for(int i=1;i<=5;++i){
		for(int j=0;j<x[rel[i]].size();++j){
			if(a[f[i][0]]>0)a[f[i][0]]--,chose[x[rel[i]][j]]=f[i][0];
			else if(a[f[i][1]]>0)a[f[i][1]]--,chose[x[rel[i]][j]]=f[i][1];
			else {
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
	for(int i=1;i<=n;++i){
		printf("%s\n",ansx[chose[i]]);
	}
}