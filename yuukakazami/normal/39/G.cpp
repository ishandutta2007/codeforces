/*
 * G. Inverse Function.cpp
 *
 *  Created on: 2011-2-23
 *      Author: user
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
const int MAX_VALUE=32768;

struct Tokenizer{
	string input;
	int at;

	void tokenize(const string&s){
		input=s+"@";
		at=0;
		token="";
	}

	char nextChar(){
		return input[at];
	}

	char nextNoneSpace(){
		while(nextChar()==' ')
			skipChar();
		return nextChar();
	}

	void skipChar(){
		++at;
	}

	string token;

	string nextToken(){
		if(!token.empty())
			return token;
		char ch=nextNoneSpace();
		if(isdigit(ch)){
			while(isdigit(nextChar())){
				token+=nextChar();
				skipChar();
			}
		} else if(isalpha(ch)){
			while(isalpha(nextChar())){
				token+=nextChar();
				skipChar();
			}
		} else {
			token=nextChar();
			skipChar();
		}
		return token;
	}

	void skipToken(){
		token="";
	}

	bool hasMoreTokens(){
		return at<input.size();
	}
};

Tokenizer tokenizer;

vector<string> tokens;

string input;
int what;
int n;

void readInput(){
	cin>>what;
	string line;
	input="";
	while(getline(cin,line))
		input+=line;
}

void tokenizeInput(){
	tokenizer.tokenize(input);
	while(tokenizer.hasMoreTokens()){
		tokens.push_back(tokenizer.nextToken());
		tokenizer.skipToken();
	}

//	for (int i = 0; i < tokens.size(); ++i) {
//		cout<<tokens[i]<<endl;
//	}
}

int	result[MAX_VALUE];

int at;
const string&nextToken(){
	return tokens[at];
}

void skipToken(){
	++at;
}

int parseFunction(int);
int parseOperatorSequence();
int parseOperator();
int parseLogicalExpr();
int parseArithmExpr();
int parseSum();
int parseProduct();
int parseMultiplier();
int parseNumber();

void eat(const string&s){
//	if(nextToken()==s)
//		skipToken();
//	else
//		cout<<"wrong! no "<<s<<endl;
	skipToken();
}

int parseFunction(){
	eat("int");eat("f");eat("(");eat("int");eat("n");eat(")");
	eat("{");
	int e=parseOperatorSequence();
	return e;
}

int parseOperatorSequence(){
	while(nextToken()!="}"){
		int e=parseOperator();
		if(e!=-1)
			return e;
	}
	return -1;
}

int parseOperator(){
	if(nextToken()=="return"){
		skipToken();
		return parseArithmExpr();
	} else {
		eat("if");
		eat("(");
		int ok=parseLogicalExpr();
		eat(")");
		eat("return");
		int res=parseArithmExpr();
		eat(";");
		if(ok)
			return res;
		else
			return -1;
	}
}

int parseLogicalExpr(){
	int a=parseArithmExpr();
	string token=nextToken();
	if(token==">"){
		eat(">");
		int b=parseArithmExpr();
		return a>b;
	} else if(token=="<"){
		eat("<");
		int b=parseArithmExpr();
		return a<b;
	} else {
		eat("=");eat("=");
		int b=parseArithmExpr();
		return a==b;
	}
}

inline int moduleAdd(int a,int b){
	return (a+b)%MAX_VALUE;
}

inline int moduleMinus(int a,int b){
	a-=b;if(a<0)a+=MAX_VALUE;
	return a;
}

inline int moduleMult(int a,int b){
	return (a*b)%MAX_VALUE;
}

inline int moduleDiv(int a,int b){
	if(!b)return -1;
	return a/b;
}

int parseArithmExpr(){
	return parseSum();
}

int parseSum(){
	int e=parseProduct();
	while(nextToken()=="+"||nextToken()=="-"){
		string token=nextToken();
		skipToken();
		if(token=="+")
			e=moduleAdd(e,parseProduct());
		else
			e=moduleMinus(e,parseProduct());
	}
	return e;
}

int parseProduct(){
	int e=parseMultiplier();
	while(nextToken()=="*" || nextToken()=="/"){
		string token=nextToken();
		skipToken();
		if(token=="*")
			e=moduleMult(e,parseMultiplier());
		else
			e=moduleDiv(e,parseMultiplier());
	}
	return e;
}

int parseMultiplier(){
	if(nextToken()=="n"){
		skipToken();
		return n;
	} else if(nextToken()=="f"){
		eat("f");eat("(");
		int arg=parseArithmExpr();
		eat(")");
		return result[arg];
	} else {
		istringstream iss(nextToken());
		skipToken();
		int num;iss>>num;
		return num;
	}
}

int main(){
//	freopen("in","r",stdin);
	readInput();
	tokenizeInput();

	int ans=-1;
	for(int i=0;i<MAX_VALUE;i++){
		at=0;n=i;
		result[i]=parseFunction();
//		cout<<i<<":"<<result[i]<<endl;
		if(result[i]==what)
			ans=i;
	}

	printf("%d\n",ans);
}