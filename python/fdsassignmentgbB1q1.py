"""Write a Python program to store first year percentage of students in array. Write function
for sorting array of floating point numbers in ascending order using
a) Selection Sort
b) Display top five scores."""

#Selection Sort

array = []
n = eval(input("Enter the number of students: "))

print("Enter the first year percentage of students")
for i in range(n):
    array.append(eval(input()))
print("Scores in unsorted order is: ", array)

for i in range(len(array)):
    min = i
    for j in range(min + 1, len(array)):
        if array[min] > array[j]:
            min = j
    temp = array[min]
    array[min] = array[i]
    array[i] = temp

print("Scores in sorted order is: ", array)            
print("Top 5 scores are: ", array[-1:-6:-1])
