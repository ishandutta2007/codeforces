#include<bits/stdc++.h>
using namespace std;
char str[300];
int len,ans1,ans2;
int main(){
	scanf("%d%s",&len,str);
	bool flg=false;
	int mxlen=0;
	for(int i=0;i<=len;++i){
		if(i==len){
			ans1=max(ans1,mxlen);
			break;
		}
		if(str[i]=='_'){
			if(flg)ans2+=(mxlen?1:0);
			else ans1=max(ans1,mxlen);
			mxlen=0;
		} else if(str[i]=='('){
			ans1=max(ans1,mxlen);
			flg=true,mxlen=0;
		} else if(str[i]==')'){
			ans2+=(mxlen?1:0);
			flg=false;
			mxlen=0;
		}
		else mxlen++;
	}
	printf("%d %d",ans1,ans2);
}