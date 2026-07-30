# Rule-Based Knowledge Representation
# Simple Medical Diagnosis System

print("===== Rule-Based Expert System =====")
fever = input("Do you have fever? (yes/no): ").lower()
cough = input("Do you have cough? (yes/no): ").lower()
headache = input("Do you have headache? (yes/no): ").lower()

# Rule 1
if fever == "yes" and cough == "yes":
    print("\nDiagnosis: You may have Flu.")

# Rule 2
elif fever == "yes" and headache == "yes":
    print("\nDiagnosis: You may have Viral Fever.")

# Rule 3
elif cough == "yes":
    print("\nDiagnosis: You may have Common Cold.")

# Rule 4
else:
    print("\nDiagnosis: You appear healthy.")
