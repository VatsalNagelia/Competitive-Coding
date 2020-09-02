import java.util.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun printYesOrNo(flag: Boolean) = if (flag) println("YES") else println("NO")

fun isSquare(a1: Int, b1: Int, a2:Int, b2: Int): Boolean {
    return when {
        (a1 + a2 == b1 && b1 == b2) -> true
        (a1 + b2 == a2 && a2 == b1) -> true
        (b1 + a2 == a1 && a1 == b2) -> true
        (b1 + b2 == a2 && a2 == a1) -> true
        else -> false
    }
}

fun main() {
    val t = readInt()
    val res = Vector<Boolean>()
    for (i in 1..t) {
        val (a1, b1) = readInts()
        val (a2, b2) = readInts()
        res.addElement(isSquare(a1, b1, a2, b2))
    }
    res.forEach {
        printYesOrNo(it)
    }
}