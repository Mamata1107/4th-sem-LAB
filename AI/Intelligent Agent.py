# Simple Vacuum Cleaner Agent

def vacuum_agent(location, status):
    print("Current Location:", location)
    print("Room Status:", status)

    if status == "Dirty":
        print("Action: Clean the room")
        status = "Clean"
    else:
        print("Action: Move to the next room")

    print("Updated Status:", status)


# Main Program
location = input("Enter Room (A/B): ")
status = input("Enter Room Status (Clean/Dirty): ")

vacuum_agent(location, status)
