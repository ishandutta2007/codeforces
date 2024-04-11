#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <map>
#include <cctype>
using namespace std;

enum Token {
	Expr, Multiplier, Addend, Suspicious
};

map<string, Token> def;

string input;
int at;

char peekChar() {
	while (input[at] == ' ')
		++at;
	return input[at];
}

char nextChar() {
	char ch = peekChar();
	++at;
	return ch;
}

inline Token invoke(char op, Token l, Token r) {
	if (l == Suspicious || r == Suspicious)
		return Suspicious;
	if (op == '+' || op == '-') {
		if (op == '-' && r == Addend)
			return Suspicious;
		else
			return Addend;
	}
	if (op == '*' || op == '/') {
		if (l == Addend || r == Addend)
			return Suspicious;
		else if (op == '/' && r == Multiplier)
			return Suspicious;
		else
			return Multiplier;
	}
	return Suspicious;
}

Token expr();
Token addend();
Token multiplier();

Token expr() {
	Token ret = addend();
	for (;;) {
		char op = peekChar();
		if (op == '+' || op == '-') {
			nextChar();
			ret = invoke(op, ret, addend());
		} else
			break;
	}
	return ret;
}

Token addend() {
	Token ret = multiplier();
	for (;;) {
		char op = peekChar();
		if (op == '*' || op == '/') {
			nextChar();
			ret = invoke(op, ret, multiplier());
		} else
			break;
	}
	return ret;
}

Token multiplier() {
	if (peekChar() == '(') {
		nextChar();
		Token ret = expr();
		nextChar();
		return ret == Suspicious ? Suspicious : Expr;
	} else {
		string id;
		while (isalnum(peekChar()))
			id += nextChar();
		if (def.count(id))
			return def[id];
		else
			return Expr;
	}
}

Token parse() {
	getline(cin, input);
	at = 0;
	input += "@";
//	cout << input << endl;
	return expr();
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		scanf(" ");
		scanf("# define");
		string name;
		cin >> name;
		def[name] = parse();
	}
	scanf(" ");
	cout << (parse() == Suspicious ? "Suspicious" : "OK") << endl;
	return 0;
}