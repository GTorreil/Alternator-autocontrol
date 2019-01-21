import csv
import pyperclip

filename = "map_inter_i32.csv"

serialized = "map32,"

with open(filename, 'r') as csvfile:
     reader = csv.reader(csvfile, delimiter=',', quotechar='|')
     for row in reader:
         row = [int(numeric_string) for numeric_string in row]
         serialized += str(row)[1:-1].strip()+",l,"

serialized = serialized[0:-2] + "end"

#print(serialized)
pyperclip.copy(serialized)

print("Serialized map copied to the clipboard")