/+ dub.sdl:
    name "C"
    dependency "dcomp" version=">=0.6.0"
+/

import std.stdio, std.algorithm, std.range, std.conv;
// import dcomp.foundation, dcomp.scanner;

int main() {
    auto sc = new Scanner(stdin);
    int n;
    sc.read(n);
    int[][] g = new int[][](n);
    foreach (i; 0..n-1) {
        int a, b;
        sc.read(a, b); a--; b--;
        g[a] ~= b;
        g[b] ~= a;
    }
    bool[] isCent = new bool[n];
    int[] sz = new int[n];
    void dfs(int p, int b) {
        sz[p] = 1; isCent[p] = true;
        foreach (d; g[p]) {
            if (d == b) continue;
            dfs(d, p);
            sz[p] += sz[d];
            if (sz[d] > n/2) isCent[p] = false;
        }
        if (n - sz[p] > n/2) isCent[p] = false;
    }
    dfs(0, -1);

//    writeln(isCent);

    Appender!(int[]) ap;
    int[] par = new int[n];
    void sea(int p, int b) {
        par[p] = b;
        ap ~= p;
        foreach (d; g[p]) {
            if (d == b) continue;
            sea(d, p);
        }
    }
    int[3][] res;
    foreach (i; 0..n) {
        if (!isCent[i]) continue;
        foreach (j; g[i]) {
            if (isCent[j]) continue;
//            writeln(i, " -> ", j);
            ap.clear();
            sea(j, i);
            int p = j;
            foreach (d; ap.data) {
                if (d == j) continue;
                res ~= [i, p, d]; p = d;
                res ~= [d, par[d], j];
            }
            res ~= [i, p, j];
        }
    }

    writeln(res.length);
    foreach (v; res) {
        writeln(v[].map!(x => (x+1).to!string).join(" "));
    }
    return 0;
}
/* IMPORT /home/yosupo/Program/dcomp/source/dcomp/foundation.d */
// module dcomp.foundation;
 
static if (__VERSION__ <= 2070) {
    template fold(fun...) if (fun.length >= 1) {
        auto fold(R, S...)(R r, S seed) {
            import std.algorithm : reduce;
            static if (S.length < 2) {
                return reduce!fun(seed, r);
            } else {
                import std.typecons : tuple;
                return reduce!fun(tuple(seed), r);
            }
        }
    }
     
}
version (X86) static if (__VERSION__ < 2071) {
    import core.bitop : bsf, bsr, popcnt;
    int bsf(ulong v) {
        foreach (i; 0..64) {
            if (v & (1UL << i)) return i;
        }
        return -1;
    }
    int bsr(ulong v) {
        foreach_reverse (i; 0..64) {
            if (v & (1UL << i)) return i;
        }
        return -1;   
    }
    int popcnt(ulong v) {
        int c = 0;
        foreach (i; 0..64) {
            if (v & (1UL << i)) c++;
        }
        return c;
    }
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
    char[512] lineBuf;
    char[] line;
    private bool succ() {
        import std.range.primitives : empty, front, popFront;
        import std.ascii : isWhite;
        while (true) {
            while (!line.empty && line.front.isWhite) {
                line.popFront;
            }
            if (!line.empty) break;
            if (f.eof) return false;
            line = lineBuf[];
            f.readln(line);
        }
        return true;
    }

    private bool readSingle(T)(ref T x) {
        import std.algorithm : findSplitBefore;
        import std.string : strip;
        import std.conv : parse;
        if (!succ()) return false;
        static if (isArray!T) {
            alias E = ElementType!T;
            static if (isSomeChar!E) {
                 
                 
                auto r = line.findSplitBefore(" ");
                x = r[0].strip.dup;
                line = r[1];
            } else {
                auto buf = line.split.map!(to!E).array;
                static if (isStaticArray!T) {
                     
                    assert(buf.length == T.length);
                }
                x = buf;
                line.length = 0;
            }
        } else {
            x = line.parse!T;
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