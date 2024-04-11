import std.stdio, std.string;

int main() {
	string s1, s2;
	s1 = chomp(readln());
	s2 = chomp(readln());
	if ((count(s1, '1')+1)/2*2 >= count(s2, '1')) {
		writeln("YES");
	} else {
		writeln("NO");
	}
    return 0;
}