"""Write a Python program to store second year percentage of students in array. Write
function for sorting array of floating point numbers in ascending order using :
a) Shell sort
b) Display top five scores."""

# Shell sort

array = []
n = eval(input("Enter the number of students: "))

print("Enter the second year percentage of students")
for i in range(n):
    array.append(eval(input()))
print("Scores in unsorted order: ", array)

interval = len(array) // 2
while interval > 0:
    for i in range(interval, len(array)):
        temp = array[i]
        j = i
        while j >= interval and array[j - interval] > temp:
            array[j] = array[j - interval]
            j -= interval

        array[j] = temp
    interval //= 2

print("Scores in sorted order: ", array)
print("Top 5 scores are: ", array[-1:-6:-1])
