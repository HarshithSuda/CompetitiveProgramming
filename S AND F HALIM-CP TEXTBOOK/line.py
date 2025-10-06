filename = "input.txt"  # replace with your filename

count = 0
with open(filename, 'r', encoding='utf-8') as file:
    for line_number, line in enumerate(file, 1):
        if line.count(' ') == 2:
            count += 1
            if count == 103:
                print(f"Line {line_number}: {line.strip()}")
                break
    else:
        print("Less than 103 lines with exactly two spaces found.")
