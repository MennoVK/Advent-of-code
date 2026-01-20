part_number_sum = 0
characters = '*=/$@+%-&#'
prevline = ''
numbers = []
skip = 0
input = open('input.txt', 'r')
lines = input.readlines()

def get_number_from_indexes(indexes, line_number):
    number = ''
    for index in indexes:
        number += lines[line_number][index]
    return(int(number))

for line_index, line in enumerate(lines):
    for idx, letter in enumerate(line):
        if skip == 0:
            if str(letter).isdigit():
                numbers.append(int(idx))
                if(line[int(idx)+1]).isdigit():
                    numbers.append(int(idx)+1)
                    skip += 1
                    if (line[int(idx) + 2]).isdigit():
                        numbers.append(int(idx)+2)
                        skip += 2
                for number in numbers:
                    if line[number-1] in characters:
                        part_number_sum += get_number_from_indexes(numbers, line_index)
                        break
                    if line[number+1] in characters:
                        part_number_sum += get_number_from_indexes(numbers, line_index)
                        break
                    if line_index != 0 and prevline[number-1] in characters:
                        part_number_sum += get_number_from_indexes(numbers, line_index)
                        break
                    if line_index != 0 and prevline[number] in characters:
                        part_number_sum += get_number_from_indexes(numbers, line_index)
                        break
                    if line_index != 0 and prevline[number+1] in characters:
                        part_number_sum += get_number_from_indexes(numbers, line_index)
                        break
                    if line_index != 139 and lines[line_index+1][number-1] in characters:
                        part_number_sum += get_number_from_indexes(numbers, line_index)
                        break
                    if line_index != 139 and lines[line_index+1][number] in characters:
                        part_number_sum += get_number_from_indexes(numbers, line_index)
                        break
                    if line_index != 139 and lines[line_index+1][number+1] in characters:
                        part_number_sum += get_number_from_indexes(numbers, line_index)
                        break

                numbers = []
        else:
            skip -= 1
    prevline = line

print(part_number_sum)