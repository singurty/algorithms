def removekdigits(num, n):
    if len(num) == n:
        return "0"
    for i in range(len(num)):
        second_place = 10 ** (len(num) - i - 1)
        for j in range(i, len(num)):
            
