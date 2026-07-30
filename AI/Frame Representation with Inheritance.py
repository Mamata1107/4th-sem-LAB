class Animal:
    def __init__(self):
        self.can_breathe = True
        self.can_move = True


class Bird(Animal):
    def __init__(self):
        super().__init__()
        self.can_fly = True


bird = Bird()

print("Bird Properties")
print("Can Breathe :", bird.can_breathe)
print("Can Move    :", bird.can_move)
print("Can Fly     :", bird.can_fly)
