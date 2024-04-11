#include<iostream>
#include<string>
#include<vector>
using namespace std;
string s,t[12],u;
int n,x[12],y[12],ts[12];
vector<string> ansans;	

string sub(int l,int r){
	string sss="";
	for(;l<=r;l++)sss+=s[l];
	return sss;
} 

int main(){
	cin>>s>>n;
	for(int i=0;i<n;i++){cin>>t[i]>>x[i]>>y[i]; ts[i]=t[i].size();}
	int ss=s.size(),ans=0;
	for(int i=0;i<ss;i++){
		for(int j=i;j<ss;j++){
			bool c=true;
			for(int k=0;k<n;k++){
				int d=0;
				for(int m=0;m<ts[k]-j+i;m++){
					bool e=true;
					for(int a=0;a<j-i+1;a++){
						if(t[k][m+a]!=s[i+a])e=false;
					}
					if(e)d++;
				}
				if(!(x[k]<=d&&d<=y[k]))c=false;
			}
			if(c){
				u=sub(i,j);
				for(int k=0;k<ans;k++)if(ansans[k]==u)c=false;
				if(c){ans++; ansans.push_back(u);}
			}
		}
	}
	printf("%d\n",ans);
}