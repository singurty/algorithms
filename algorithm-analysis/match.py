def find_match(p, t):
    plen = len(p)
    tlen = len(t)
    if plen > tlen:
        return -1
    for i in range(tlen - plen + 1):
        j = 0
        while j < plen and t[i + j] == p[j]:
            j += 1
        if j == plen:
            return i
    return -1

print(find_match("pok", "sipok"))
