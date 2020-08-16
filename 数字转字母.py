# （1-->A,27-->AA,30-->AD）
def num_to_char(number):
    second_num = int(number % 26)
    first_num = int(number / 26)
    alphabet_list = ['']
    for i in range(65, 91):
        alphabet_list.append(chr(i))
    letter_str = alphabet_list[first_num] + alphabet_list[second_num]
    return letter_str
