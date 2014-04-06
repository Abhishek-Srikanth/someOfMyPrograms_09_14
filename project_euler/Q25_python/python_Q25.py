a = 1
b = 1
t_no = 2

# print( len( str(a)) )

while( len(str(a)) < 1000 and len(str(b)) < 1000):
    if a>b:
        b += a
    else:
        a += b
    t_no+=1
if len(str(a))>=1000:
    print("a : ",a)
else:
    print("b : ",b)
print("t_no : ", t_no)
