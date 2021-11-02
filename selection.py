def selection_sort(s, n):
    for i in range(n):
        minimum = i
        for j in range(i + 1, n):
            if s[j] < s[minimum]:
                minimum = j
        temp = s[i]
        s[i] = s[minimum]
        s[minimum] = temp

test_list = [4,2,6,4,3,3,5,3,7,523,4,74,645,2,56,23,6,35,3,4,6,2,7,9,325,47,63,24,34,332,32,5,45,46,7,5533,25,76,44,3,6453,7,5,34,45,43,43,43,3,5,3,4,53,6,6,56,4,54,6,45,4,5,457,7,68,7,897,9,5,3323,3,69,8,97,3,23,65,7,89,7,74,42,6,5,879874,5,3,325,4534,233,5,56,3,312,6,68,7,4,42,4,7,5664,521]
selection_sort(test_list, len(test_list))
print(test_list)
