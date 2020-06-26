from sys import argv, exit

if len(argv) != 2:
    print("missing command line argument")
    exit(1)
print(f"Hello, {argv[1]}")
exit(0)
