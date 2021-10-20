"""Write a Python program to store marks scored in subject “Fundamental of Data
Structure” by N students in the class. Write functions to compute following:
a)The average score of class
b)Highest score and lowest score of class
c)Count of students who were absent for the test
d)Display mark with highest frequency."""

import sys

arr1 = []

print("Enter the 10 students marks : ")
for i in range(10):     
    mark = eval(input(""))    
    arr1.append(mark)
print(arr1)

#Algorithm for average marks in an array:
totalmarks = 0
for i in range(len(arr1)):
    totalmarks = totalmarks + arr1[i]    
avgmarks = totalmarks / len(arr1)    
print("The average score of class: ",avgmarks)    
    
# Algorithm for highest mark in an array:
max1 = - (sys.maxsize)  #initializing this variable to least minimum value
for i in range(len(arr1) ):
    if arr1[i] > max1 and arr1[i] != -1 :
        max1 = arr1[i]
    else :
        continue    
print("Highest score of class: ",max1)        

#Algorithm for lowest mark in an array:
min1 = sys.maxsize  #initializing this variable to maximum value
for i in range(len(arr1) ):
    if arr1[i] < min1 and arr1[i] != -1 :
        min1 = arr1[i]
    else :
        continue
print("Lowest score of class: ",min1)

#Algorithm for mark scored by most of the students: 
fcount = 0
for i in range(len(arr1)):
    count = 0
    for j in range(len(arr1)):
        if arr1[i] == arr1[j] :
            count = count + 1
        if fcount < count :
            fcount = count
            most = arr1[j]
print("Marks scored by most of the students: ",most) 

#Algorithm for calculating absent students:
abcount = 0
for i in range(len(arr1)):
    if arr1[i] == -1 :
        abcount = abcount + 1
print("Absent for the test: ",abcount)
