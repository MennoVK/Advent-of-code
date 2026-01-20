f = open("input.txt", "r")
lines_list = f.readlines()


def check_rucksack():
    total_amount = 0
    for i in range(0, len(lines_list), 3):
        first_of_three = to_set(lines_list[i].strip())
        second_of_three = to_set(lines_list[i+1].strip())
        third_of_three = to_set(lines_list[i+2].strip())
        intersected_letter_set = first_of_three.intersection(second_of_three, third_of_three)
        intersected_letter_list = list(intersected_letter_set)
        total_amount += getPriority(intersected_letter_list[0])
    print(total_amount)

def to_set(string):
    string_in_set = set()
    for i in string:
        string_in_set.add(i)
    return(string_in_set)

def getPriority(letter):
    alfa = "abcdefghijklmnopqrstuvwxyz"
    for idx, i in enumerate(alfa):
        if letter.lower() == i:
            if letter.islower():
                amount_lower = (idx+1)
                return(amount_lower)
            else:
                amount_upper = (idx + 1 + 26)
                return(amount_upper)

check_rucksack()