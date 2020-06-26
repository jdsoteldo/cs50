from sys import argv, exit
from csv import DictReader, reader

if len(argv) != 3:
    print("Missing command line arguments.")
    exit()


with open(argv[2], newline='') as dna_file:
    dna_reader = reader(dna_file)
    for row in dna_reader:
        dnas_list = row

# initialize an array
dnas = dnas_list[0]

# initialize a dict
str_sequences = {}

# open database file and iterate thru each row
with open(argv[1], newline='') as database_file:
    data_each = reader(database_file)
    for row in data_each:
        data_row = row
        # adds the sequence from the file into a list
        data_row.pop(0)
        break

# add the data into the dictionary
for data in data_row:
    str_sequences[data] = 1

# iterates dna
for str in str_sequences:
    seqMax = 0
    seqNorm = 0
    for i in range(len(dnas)):
        # goes to the end of the sequence so it doesnt repeat count
        while seqNorm > 0:
            seqNorm -= 1
            continue

        if dnas[i: i + len(str)] == str:
            while dnas[i - len(str): i] == dnas[i: i + len(str)]:
                seqNorm += 1
                i += len(str)

            # over writes the longer sequence
            if seqNorm > seqMax:
                seqMax = seqNorm

    # stores the longer sequence
    str_sequences[str] += seqMax

# open the databse file and iterates thru it as a list
with open(argv[1], newline='') as people_data:
    person_all = DictReader(people_data)
    for person in person_all:
        str_match = 0
        for dnas in str_sequences:
            # compares the str sequences with the database files
            if str_sequences[dnas] == int(person[dnas]):
                str_match += 1

        if str_match == len(str_sequences):
            # if the number of matches is equal to the lenght of the sequence then is a macth
            print(person['name'])
            exit()

    # otherwise no match
    print("No Match")
