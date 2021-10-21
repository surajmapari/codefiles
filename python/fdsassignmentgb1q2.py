"""Write a Python program to store first year percentage of students in array. Write function
for sorting array of floating point numbers in ascending order using
a) Bubble Sort
b) Display top five scores."""

#Bubble Sort

array = []
n = eval(input("Enter the number of students: "))

print("Enter the first year percentage of students")
for i in range(n):
    array.append(eval(input()))
print("Scores in unsorted order is: ",array)

for i in range(len(array) - 1):
    swapped = False
    for j in range(len(array) - i - 1):
        if (array[j] > array[j+1]):
            temp = array[j]
            array[j] = array[j+1]
            array[j+1] = temp
            swapped = True       
    if swapped == False:
        break                
        
print("Scores in sorted order is: ", array)            
print("Top 5 scores are: ", array[-1:-6:-1])