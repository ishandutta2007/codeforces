#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<string>
using namespace std;

int main(){
	/*int n;
	string s="";
	char c[10];
	scanf("%d",&n);
	scanf("\n");
	scanf("%s",&c);
	for(int i=0;i<n;i++){
		s+=c[i];
	}*/

	int n;
	string s;
	scanf("%d",&n);
	cin>>s;

	string ans[8]={"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
	int ret=-1;
	
	if(n==6){ ret=3; }
	else if(n==8){ ret=0; }
	else {
		for(int i=0;i<8;i++){
			if(i!=0&&i!=3){
				bool c=true;
				for(int j=0;j<n;j++){
					if(s[j]!='.'&&s[j]!=ans[i][j]){
						c=false;
					}
				}
				if(c)ret=i;
			}
		}
	}

	cout<<ans[ret]<<endl;
}