class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


# insert at end
def insert_at_end(head, value):
    new_node = Node(value)

    if head == None:
        return new_node
    current = head
    while current.next:
        current = current.next
    current.next = new_node
    return head


# Print the list
def print_list(head):
    current = head
    while current:
        print(f"{current.data}->", end="")
        current = current.next
    print("NULL")


# main function, as deleting is not necessary in python
if __name__ == "__main__":
    head = None

    try:
        with open("random_numbers.txt", "r") as file:
            # read the entire file content
            content = file.read()

            # Split the content by whitespace and convert to integers
            numbers = [int(num) for num in content.split()]

            # insert each number into the linkedlist
            for number in numbers:
                head = insert_at_end(head, number)
    except FileNotFoundError:
        print("Error: Ye file nahi mili")

    except ValueError:
        print("Error: Isme galat format ki values hai")

    print("Linked List:", end=" ")
    print_list(head)
