total_amount = 0
line_number = []

input = open('input.txt', 'r')

for line in input:
    for letter in line:
        if letter.isnumeric():
            line_number.append(str(letter))
    total_amount += int(line_number[0] + line_number[-1])
    line_number = []

print(total_amount)