/+ dub.sdl:
    name "A"
    dependency "dcomp" version=">=0.6.0"
+/

import std.stdio, std.algorithm, std.range, std.conv;
// import dcomp.foundation, dcomp.scanner;
// import dcomp.datastructure.unionfind;

int main() {
    auto sc = new Scanner(stdin);
    int n; int[] a;
    sc.read(n, a);
    int[] idx = iota(n).array;
    idx.sort!((x, y) => a[x] < a[y]);
    auto uf = UnionFind(n);
    foreach (i, j; idx) {
        uf.merge(i.to!int, j);
    }
    writeln(uf.count);
    foreach (v; uf.groups) {
        if (v.length == 0) continue;
        writeln(v.length, " ", v.map!(x => (x+1).to!string).join(" "));
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


 
 

 
/* IMPORT /home/yosupo/Program/dcomp/source/dcomp/datastructure/unionfind.d */
// module dcomp.datastructure.unionfind;

 
struct UnionFind {
    import std.algorithm : map, swap, each;
    import std.range : iota, array;
    int[] id;  
    int[][] groups;  
    int count;  
     
    this(int n) {
        id = iota(n).array;
        groups = iota(n).map!(a => [a]).array;
        count = n;
    }
     
    void merge(int a, int b) {
        if (same(a, b)) return;
        count--;
        int x = id[a], y = id[b];
        if (groups[x].length < groups[y].length) swap(x, y);
        groups[y].each!(a => id[a] = x);
        groups[x] ~= groups[y];
        groups[y] = [];
    }
     
    int[] group(int i) {
        return groups[id[i]];
    }
     
    bool same(int a, int b) {
        return id[a] == id[b];
    }
}