import random
with open('Vaccine_System\\nationalId.txt', 'r') as file:
    strr = (file.read())
file.close()
s = strr.split()
s = set(s)
file.close()
n=0
l=[]
for i in s:
    if len(i)!=14:
        l.append(i)
    else:
        n+=1
for i in l:
    s.remove(i)
print(len(l))
print(len(s))
for i in range(1000):
    ran = "2780301"+str(random.randint(1000000, 10000000-1))
    s.add(ran)
with open('Vaccine_System\\nationalId.txt', 'w') as file:
    for i in s:
        file.write(i+'\n')
file.close()


#     id=3020728+range(10000000,100000000)

# with open('Vaccine_System\\namesofgirls.txt', 'r') as file:
#     strr = (file.read())
# file.close()
# s=set()
# l=strr.split()
# for i in l:
#     s.add(i)

# with open('Vaccine_System\\namesofgirls.txt', 'w') as file:
#     for i in s:
#         file.write(i+'\n')
    

