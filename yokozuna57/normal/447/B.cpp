#include<iostream>
#include<string>
using namespace std;

int main(){
	string s;
	int k;
	int w[30];

	cin>>s;
	scanf("%d",&k);
	for(int i=0;i<26;i++){
		scanf("%d",&w[i]);
	}

	int len=s.size();
	int ret=0;

	for(int i=0;i<len;i++){
		ret+=(i+1)*w[s[i]-'a'];
	}

	w[26]=0;
	for(int i=0;i<26;i++){
		w[26]=max(w[i],w[26]);
	}

	ret+=w[26]*((len+1+k+len)*(k)/2);

	printf("%d\n",ret);
}