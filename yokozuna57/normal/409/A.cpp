#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
	string s,t;

	cin>>s;
	cin>>t;

	vector<int> A,B;

	for(int i=0;i<s.size();i+=2){
		if(s[i]=='[')A.push_back(0);
		if(s[i]=='(')A.push_back(1);
		if(s[i]=='8')A.push_back(2);
	}
	for(int i=0;i<t.size();i+=2){
		if(t[i]=='[')B.push_back(0);
		if(t[i]=='(')B.push_back(1);
		if(t[i]=='8')B.push_back(2);
	}

	int a=0,b=0;
	for(int i=0;i<A.size();i++){
		if(A[i]==0&&B[i]==1)a++;
		if(A[i]==1&&B[i]==2)a++;
		if(A[i]==2&&B[i]==0)a++;
		if(B[i]==0&&A[i]==1)b++;
		if(B[i]==1&&A[i]==2)b++;
		if(B[i]==2&&A[i]==0)b++;
	}

	if(a>b){
		printf("TEAM 1 WINS\n");
	}
	else if(a<b){
		printf("TEAM 2 WINS\n");
	}
	else {
		printf("TIE\n");
	}
}