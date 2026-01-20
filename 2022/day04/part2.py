f = open("input.txt", "r")

def check_contains_pair():
    overlapping_assignment_pairs = 0
    for i in f:
        i = i.strip()
        list_both_pairs = i.split(",")
        first_range = list_both_pairs[0].split("-")
        second_range = list_both_pairs[1].split("-")
        first_range_stripped = list(map(int, first_range))
        second_range_stripped = list(map(int, second_range))
        if first_range_stripped[0] >= second_range_stripped[0] and first_range_stripped[0] <= second_range_stripped[1]:
            overlapping_assignment_pairs += 1
        elif first_range_stripped[1] >= second_range_stripped[0] and first_range_stripped[1] <= second_range_stripped[1]:
            overlapping_assignment_pairs += 1
        elif second_range_stripped[0] >= first_range_stripped[0] and second_range_stripped[0] <= first_range_stripped[1]:
            overlapping_assignment_pairs += 1
        elif second_range_stripped[1] >= first_range_stripped[0] and second_range_stripped[1] <= first_range_stripped[1]:
            overlapping_assignment_pairs += 1
    print(overlapping_assignment_pairs)

check_contains_pair()