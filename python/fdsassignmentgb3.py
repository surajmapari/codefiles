"""Write a Python program to store first year percentage of students in array. Write function
for sorting array of floating point numbers in ascending order using quick sort and
display top five scores"""

# Quick Sort

def swap(array, i, j):
    temp = array[i]
    array[i] = array[j]
    array[j] = temp
    
def partition(array, l, r):
    pivot = array[r]
    i = l -1
    for j in range(l,r):
        if array[j] < pivot:
            i +=1
            swap(array, i, j)
    swap(array, i + 1, r)
    return i + 1        

def quicksort(array, l, r):
    if l < r:
        pi = partition(array, l, r)
        quicksort(array, l, pi - 1)
        quicksort(array, pi + 1, r)

array = []
n = eval(input("Enter the number of students: "))

print("Enter the first year percentage of students")
for i in range(n):
    array.append(eval(input()))
print("Scores in unsorted order: ",array)

quicksort(array, 0, n-1)

print("Scores in sorted order: ", array)            
print("Top 5 scores are: ", array[-1:-6:-1])
