# Frame Representation
class Person:
    def __init__(self, name, age, profession):
        self.name = name
        self.age = age
        self.profession = profession

    def display(self):
        print("\n----- Person Frame -----")
        print("Name       :", self.name)
        print("Age        :", self.age)
        print("Profession :", self.profession)


# Create Frame
person1 = Person("Ram", 22, "Student")
person1.display()

