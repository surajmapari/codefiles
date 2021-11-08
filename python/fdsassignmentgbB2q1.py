"""Write a Python program to store second year percentage of students in array. Write
function for sorting array of floating point numbers in ascending order using :
a) Insertion sort
b) Display top five scores.""" 

#Insertion sort

array = []
n = eval(input("Enter the number of students: "))

print("Enter the second year percentage of students")
for i in range(n):
    array.append(eval(input()))
print("Scores in unsorted order: ",array)

for i in range(1, len(array)):
    currentele = array[i]
    j = i-1
    while (j>=0 and array[j] > currentele):
        array[j+1] = array[j]
        j -= 1
    array[j+1] = currentele    

print("Scores in sorted order: ", array)            
print("Top 5 scores are: ", array[-1:-6:-1])
