total_points = 0
won_numbers = []

copies = {}

def seed_dict(input):
    for idx, line in enumerate(input):
        copies[idx+1] = 1

def strip_line(line):
    line = line.replace('   ', ' ')
    line = line.replace('  ', ' ')
    line = line.replace(f'Card {idx + 1}: ', '')
    line = line.replace('\n', '')
    return line

with open("input.txt") as input:
    seed_dict(input)
    input.seek(0)
    for idx, line in enumerate(input):
        line = strip_line(line)
        split_line = line.split(' | ')
        winning_numbers = split_line[0].split(' ')
        my_numbers = split_line[1].split(' ')
        for winning_number in winning_numbers:
            for my_number in my_numbers:
                if my_number == winning_number:
                    won_numbers.append(my_number)
        for i in range(copies[idx+1]):
            for i in range(len(won_numbers)):
                copies[i+2+idx] += 1
        won_numbers = []

for i in copies:
    total_points += int(copies[i])

print(total_points)