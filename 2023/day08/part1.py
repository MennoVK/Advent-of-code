order = ''
stripped_input = []
steps = 0
current_letters = 'AAA'

def strip_input(line):
    line = line.replace('= ', '')
    line = line.replace('(', '')
    line = line.replace(')', '')
    line = line.replace(',', '')
    line = line.replace('\n', '')
    return line

with open("input.txt") as input:
    for idx,line in enumerate(input):
        if idx == 0:
            order = line.replace('\n', '')
            continue
        elif idx == 1:
            continue
        else:
            line = strip_input(line)
            stripped_input += [[line.split(' ')[0], [line.split(' ')[1], line.split(' ')[2]]]]
    while current_letters != 'ZZZ':
        for direction in order:
            for line in stripped_input:
                if line[0] == current_letters:

                    if direction == 'R':
                        current_letters = line[1][1]
                    else:
                        current_letters = line[1][0]
                    steps += 1
                    break

print(steps)