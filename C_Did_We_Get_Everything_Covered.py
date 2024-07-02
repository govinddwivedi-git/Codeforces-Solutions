def solve(n, k, s):
    # Generate all possible strings of length n
    # that can be formed using the first k lowercase English alphabets
    strings = []
    def generate_string(s, n, k, curr):
        if len(curr) == n:
            strings.append(curr)
            return
        for i in range(k):
            generate_string(s, n, k, curr + s[i])
    generate_string(s, n, k, "")

    # Check if each string is a subsequence of s
    for string in strings:
        i = 0
        for c in s:
            if i < n and c == string[i]:
                i += 1
        if i == n:
            return "YES"

    # If no string is a subsequence of s, return NO and any string of length n
    return "NO\n" + strings[0]
