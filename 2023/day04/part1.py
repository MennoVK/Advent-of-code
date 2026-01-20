total_points = 0
won_numbers = []

with open("input.txt") as input:
    for idx, line in enumerate(input):
        line = line.replace('   ', ' ')
        line = line.replace('  ', ' ')
        line = line.replace(f'Card {idx + 1}: ', '')
        line = line.replace('\n', '')
        split_line = line.split(' | ')
        winning_numbers = split_line[0].split(' ')
        my_numbers = split_line[1].split(' ')
        for winning_number in winning_numbers:
            for my_number in my_numbers:
                if my_number == winning_number:
                    won_numbers.append(my_number)
        total_points += int(pow(2, len(won_numbers) - 1))
        won_numbers = []

print(total_points)