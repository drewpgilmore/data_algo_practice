# Linked List Data Structure Module

class Node:
    def __init__(self, data: str):
        try:
            self.data = data
        except TypeError as err:
            print(err)
        
        self.next = None

    def __repr__(self) -> str:
        return self.data

class LinkedList:
    def __init__(self):
        # starting node
        self.head = None
    
    def __repr__(self) -> str:
        node = self.head
        nodes = []
        while node is not None:
            nodes.append(node.data)
            node = node.next
        
        # signify end of ll
        nodes.append("End")
        return " -> ".join(nodes)

    # Inserting
    def insertFirst(self, node):
        node.next = self.head # make node point to current head
        self.head = node

    def insertLast(self, node):
        if self.head is None:
            self.head = node
        
        # traverse to end of list before inserting
        n = self.head
        while n.next is not None:
            n = n.next

        n.next = node

    def insertAfter(self, after, node):
        '''Inserts node after target node'''
        if self.head is None:
            self.head = node

        # traverse list to node to insert after
        n = self.head
        while n != after:
            n = n.next

        newNext = n.next
        n.next = node
        node.next = newNext
    
    
    # Delete node 
    def contains(self, node) -> bool:
        '''Helper function to determine if node is in list'''
        if self.head is None:
            print('Empty List')
            return False
        
        n = self.head
        while n.data != node.data:
            if n.next is None:
                return False
            n = n.next
        
        return True


    def deleteNode(self, node):
        '''Deletes node from list'''
        
        # check if node is in list
        if not self.contains(node):
            return 'Node not in list'

        n = self.head 
        while n.next.data != node.data:
            n = n.next

        n.next = n.next.next