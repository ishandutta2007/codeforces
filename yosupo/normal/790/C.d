/+ dub.sdl:
    name "C"
    dependency "dcomp" version=">=0.6.0"
+/

import std.stdio, std.range, std.algorithm, std.conv, std.math;
// import dcomp.scanner;

int main() {
    auto sc = new Scanner(stdin);
    int n;
    string s;
    sc.read(n, s);


    auto V = s.count('V').to!int;
    auto K = s.count('K').to!int;
    auto O = n-V-K;

    int[] vlist = iota(n).filter!(i => s[i] == 'V').array;
    int[] klist = iota(n).filter!(i => s[i] == 'K').array;
    int[] olist = iota(n).filter!(i => s[i] != 'V' && s[i] != 'K').array;

    int[2][][][] dp = new int[2][][][](V+1, K+1, O+1);
    bool[2][][][] used = new bool[2][][][](V+1, K+1, O+1);
    int dfs(int vc, int kc, int oc, int ba) {
//        writeln(vc, " ", kc, " ", oc, " ", ba);
        int p = (vc+kc+oc);
        if (p == n) return 0;
        if (used[vc][kc][oc][ba]) return dp[vc][kc][oc][ba];
        used[vc][kc][oc][ba] = true;

        int ans = 10^^9;
        int calc(int u) {
            int ans = 0;
            foreach (q; vlist[0..vc]) {
                if (q > u) ans++;
            }
            foreach (q; klist[0..kc]) {
                if (q > u) ans++;
            }
            foreach (q; olist[0..oc]) {
                if (q > u) ans++;
            }
            return ans;
        }
        
        if (vc < V) {
            int fr = calc(vlist[vc]);
            ans = min(ans, fr+dfs(vc+1, kc, oc, 0));
        }
        if (kc < K && ba != 0) {
            int fr = calc(klist[kc]);
            ans = min(ans, fr+dfs(vc, kc+1, oc, 1));
        }
        if (oc < O) {
            int fr = calc(olist[oc]);
            ans = min(ans, fr+dfs(vc, kc, oc+1, 1));
        }
//        writeln(vc, " ", kc, " ", oc, " ", ba, " ", p, " ", ans);
        return dp[vc][kc][oc][ba] = ans;
    }

//    writeln(vlist, " ", klist, " ", olist);
    writeln(dfs(0, 0, 0, 1));
    return 0;
}
/* IMPORT /home/yosupo/Program/dcomp/source/dcomp/scanner.d */
// module dcomp.scanner;

class Scanner {
    import std.stdio : File;
    import std.conv : to;
    import std.range : front, popFront, array, ElementType;
    import std.array : split;
    import std.traits : isSomeChar, isStaticArray, isArray; 
    import std.algorithm : map;
    File f;
    this(File f) {
        this.f = f;
    }
    string[] buf;
    private bool succ() {
        while (!buf.length) {
            if (f.eof) return false;
            buf = f.readln.split;
        }
        return true;
    }
    private bool readSingle(T)(ref T x) {
        if (!succ()) return false;
        static if (isArray!T) {
            alias E = ElementType!T;
            static if (isSomeChar!E) {
                //string or char[10] etc
                x = buf.front;
                buf.popFront;
            } else {
                static if (isStaticArray!T) {
                    //static
                    assert(buf.length == T.length);
                }
                x = buf.map!(to!E).array;
                buf.length = 0;                
            }
        } else {
            x = buf.front.to!T;
            buf.popFront;            
        }
        return true;
    }
    int read(T, Args...)(ref T x, auto ref Args args) {
        if (!readSingle(x)) return 0;
        static if (args.length == 0) {
            return 1;
        } else {
            return 1 + read(args);
        }
    }
}

unittest {
    import std.path : buildPath;
    import std.file : tempDir;
    import std.algorithm : equal;
    import std.stdio : File;
    string fileName = buildPath(tempDir, "kyuridenanmaida.txt");
    auto fout = File(fileName, "w");
    fout.writeln("1 2 3");
    fout.writeln("ab cde");
    fout.writeln("1.0 1.0 2.0");
    fout.close;
    Scanner sc = new Scanner(File(fileName, "r"));
    int a;
    int[2] b;
    char[2] c;
    string d;
    double e;
    double[] f;
    sc.read(a, b, c, d, e, f);
    assert(a == 1);
    assert(equal(b[], [2, 3]));
    assert(equal(c[], "ab"));
    assert(equal(d, "cde"));
    assert(e == 1.0);
    assert(equal(f, [1.0, 2.0]));
}