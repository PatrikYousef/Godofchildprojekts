def create_list():
    number_list = []
    start = int(input("Enter the start number: "))
    end = int(input("Enter the end number (not included): "))
    for i in range(start, end):
        number_list.append(i)
        print(number_list)

create_list()