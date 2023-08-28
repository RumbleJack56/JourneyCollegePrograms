#here number 5 refers to letter e, 
#it can work uptil 26 for all letters
number = 5
#initialise function

def pattern(n):
    #initialise a string using join function upto
    #n alphabets using ascii conversion
    s="".join([chr(x+97) for x in range(n)])
    #string is reversed and added with a "*" in between
    s=s+"*"+s[::-1]
    #this produces the pattern string
    #this iterates through a loop which turns all alphabets
    #larger than the threshold into *
    #and increments the rest
    for k in range(n):
        print(s)
        s="".join(["*" if x=="*" or ord(x)-96>=n else chr(ord(x)+1) for x in s])
#function call
pattern(5)