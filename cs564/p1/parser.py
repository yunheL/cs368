import csv

r1 = set()
r2 = set()
r3 = set()
r4 = set()

with open("SalesFile.csv", 'r') as csvfile:
    reader = csv.reader(csvfile)
    for i, line in enumerate(reader):
        if i > 0:
            r1.add((line[0], line[5], line[6]))
            r2.add((line[2], line[4]))
            r3.add((line[0], line[1], line[2], line[3]))
            r4.add((line[0], line[2], line[7], line[8], line[9], line[10]))

with open("r1.csv", 'w') as f:
    f.write('"Store","Type","Size"\n')
    for t in r1:
        f.write(str(t[0]) + ',"' + str(t[1]) + '",' + str(t[2]) + '\n')

with open("r2.csv", 'w')as f:
    f.write('"WeekDate","IsHoliday"\n')
    for t in r2:
        f.write('"' + str(t[0]) + '",' + str(t[1]) + '\n')

with open("r3.csv", 'w') as f:
    f.write('"Store","Dept","WeekDate","WeeklySales"\n')
    for t in r3:
        f.write(str(t[0]) + ',' + str(t[1]) + ',"' + str(t[2]) + '",')
        f.write(str(t[3]) +'\n')

with open("r4.csv", 'w') as f:
    f.write('"Store","WeekDate","Temperature","FuelPrice","CPI",')
    f.write('"UnemploymentRate"\n')
    for t in r4:
        f.write(str(t[0]) + ',"' + str(t[1]) + '",' + str(t[2]) + ',')
        f.write(str(t[3]) + ',' + str(t[4]) + ',' + str(t[5]) + '\n')
