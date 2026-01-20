total_amount = 0
line_number = []

string_numbers = {'one': 'o1e', 'two': 't2o', 'three': 't3e', 'four': 'f4r', 'five': 'f5e', 'six': 's6x', 'seven': 's7n', 'eight': 'e8t', 'nine': 'n9e'}

input = open('input.txt', 'r')

for line in input:
    for string_number in string_numbers:
        if string_number in line:
            line = line.replace(string_number, string_numbers[string_number])
    for letter in line:
        if letter.isnumeric():
            line_number.append(str(letter))
    total_amount += int(line_number[0] + line_number[-1])
    line_number = []

print(total_amount)