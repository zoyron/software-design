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
    head = insert_at_end(head, 10)
    head = insert_at_end(head, 20)
    head = insert_at_end(head, 30)
    print("Linked List:", end=" ")
    print_list(head)
