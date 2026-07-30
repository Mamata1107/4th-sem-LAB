# Predicate Logic Representation
print("===== Predicate Logic Example =====")
# Facts
humans = {"Ram", "Sita", "Hari"}
students = {"Ram", "Hari"}

def Human(x):
    return x in humans
def Student(x):
    return x in students
def Intelligent(x):
    if Human(x) and Student(x):
        return True
    return False
name = input("Enter person's name: ")
if Intelligent(name):
    print(name, "is Intelligent.")
else:
    print(name, "is NOT Intelligent.")


