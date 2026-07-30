# Semantic Network

semantic_net = {
    "Canary": {
        "is-a": "Bird",
        "color": "Yellow"
    },

    "Bird": {
        "is-a": "Animal",
        "can": "Fly"
    },

    "Animal": {
        "can": "Move"
    }
}

print("===== Semantic Network =====")

entity = input("Enter entity (Canary/Bird/Animal): ")

if entity in semantic_net:
    print("\nRelationships of", entity)

    for relation, value in semantic_net[entity].items():
        print(entity, "--", relation, "-->", value)

else:
    print("Entity not found.")
