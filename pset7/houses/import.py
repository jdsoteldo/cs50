import sqlite3
import csv
import sys


def main():

    # check for correct amount of command line arguments
    if (len(sys.argv) != 2):
        sys.exit("Missing command line arguments")

    # check for csv file in the command line argument
    file = sys.argv[1]
    if not (file.endswith(".csv")):
        # .endswith function determines the ending of a file
        sys.exit("Import csv file")

    # connects with db
    sqlite3_db = "students.db"
    connection = sqlite3.connect(sqlite3_db)
    cursor = connection.cursor()

    # open csv file
    with open(file, "r") as characters:
        reader = csv.DictReader(characters)

        for row in reader:
            names = []
            # creates a list for the names

            for middle in row["name"].split(" "):
                # split on space
                names.append(middle)

            names.append(row["house"])
            names.append(row["birth"])

            if (len(names) == 4):
                cursor.execute("INSERT INTO students (first, last, house, birth) VALUES(?, ?, ?, ?)", names[:4])

            if (len(names) == 5):
                cursor.execute("INSERT INTO students (first, middle, last, house, birth)VALUES(?, ?, ?, ?, ?)", names[:5])

    connection.commit()
    connection.close()


main()
