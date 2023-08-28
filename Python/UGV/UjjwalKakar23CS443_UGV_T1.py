#works for all one digit numbers
number = 5

#defines a function
def pattern(n):
    
    #list concatenation is used to make a list of elements from 1 to n
    #join function takes a list and makes a string out of it
    #list elements are seperated the initialiser string 
    #here initialiser string is ""
    
    s = "".join([str(k+1) for k in range(n)])

    #string slicing is used to inverse the string and add to itself
    s+=s[::-1]
    #this creates the required pattern
    #now we iterate through a loop where s is split at a varying number
    #then s in concatenated and join function is used to add underscores
    #the iteration here goes from 6(which is nonexistent hence default string)
    #all the way to 2
    for k in range(n):
        s = "_".join(s.split(str(n+1-k)))
        print(s)
        
#function call        
pattern(number)