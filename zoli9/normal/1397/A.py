if __name__ == '__main__':
    tests = int(input())
    for test in range(tests):
        dictionary = {}
        for c in range(26):
            dictionary[chr(97+c)] = 0
        n = int(input())
        for i in range(n):
            s = input()
            for c in s:
                dictionary[c] = dictionary[c]+1
        answer = "YES"
        for key, value in dictionary.items():
            if value % n != 0:
                answer = "NO"
        print(answer)