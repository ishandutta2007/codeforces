private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    var t = readInt()
    while (t-- != 0) {
        var (a, b) = readInts()
        var (c, d) = readInts()
        var flg =0
        if(a==d){
            if(b+c==a) flg =1
        }
        if(a==c){
            if(b+d==a) flg =1
        }
        if(b==c){
            if(a+d==b) flg =1
        }
        if(b==d){
            if(a+c==b) flg =1
        }
        if (flg == 1) println("YES")
        else println("NO")
    }
}