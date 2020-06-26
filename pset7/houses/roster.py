import sqlite3
import csv
import sys
# imported sqlite library to connect the database without the cs50 library
# following the guide from the link: https://pynative.com/python-cursor-fetchall-fetchmany-fetchone-to-read-rows-from-table/#:~:text=fetchall()%20fetches%20all%20the,cursor.

def main():
    # check command line arguments
    if (len(argv) != 2):
        sys.exit("Missing command line arguments")

    study_house = sys.argv[1].lower()

    houses = ["slytherin", "ravenclaw", "hufflepuff", "gryffindor"]

    if study_house.lower() not in houses:
        sys.exit("Add valid house name: Gryffindor, Slytherin, Hufflepuff or Ravenclaw.")

    # query database for all students in house
    sqlite3_db = "students.db"
    connection = sqlite3.connect(sqlite3_db)
    cursor = connection.cursor()

    # students should be sorted alphabetically by last name and the first name
    cursor.execute('SELECT first, middle, last, birth FROM students WHERE lower(house) = "{}" ORDER BY last, first;'.format(study_house))

    house_students = list(cursor)

    # print out each student full name and birth year
    for row in house_students:

        if not row[1]:
            print("{} {}, birth year: {}".format(row[0], row[2], row[3]))
        else:
            print("{} {} {}, birth year: {}".format(row[0], row[1], row[2], row[3]))

    connection.close()


main()
