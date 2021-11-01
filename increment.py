def increment(y):
    if y == 0:
        return 1
    elif y % 2 == 1:
        return 2 * increment(y / 2)
    else:
        return y + 1

print(increment(16))
print(increment(22))
