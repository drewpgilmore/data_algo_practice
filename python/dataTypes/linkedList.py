#! /usr/bin/python3 
# Linked List Data Structure Module

class Node:
    def __init__(self, data: str):
        """Todo: enforce str types for node data"""
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
        self.length = 0

    def __repr__(self) -> str:
        node = self.head
        nodes = []
        while node is not None:
            nodes.append(node.data)
            node = node.next
        
        # signify end of ll
        nodes.append("End")
        return " -> ".join(nodes)

    def isEmpty(self):
        if self.head is None:
            return True
        else:
            return False

    def getLength(self):
        length = 0
        if not self.isEmpty():
            n = self.head
            length += 1
            while n.next is not None:
                length += 1
                n = n.next
        return length

    def traverseTo(self, index) -> Node:
        """Traverses to nth item in list"""
        n = self.head
        length = 1
        while length <= index:
            n = n.next
            length += 1

        return n

    # Inserting
    def insertFirst(self, node):
        node.next = self.head # make node point to current head
        self.head = node
        return self

    def insertLast(self, node):
        if self.head is None:
            self.head = node
        
        # traverse to end of list before inserting
        n = self.head
        while n.next is not None:
            n = n.next

        n.next = node
        return self

    def insertAfter(self, after, node):
        """Inserts node after target node"""
        if self.head is None:
            self.head = node

        # traverse list to node to insert after
        n = self.head
        while n.data != after.data:
            n = n.next

        newNext = n.next
        n.next = node
        node.next = newNext
        return self
    
    # Delete node 
    def contains(self, node) -> bool:
        '''Helper function to determine if node is in list'''
        if self.isEmpty():
            print('isEmpty returned True: list is empty')
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

        return self

    def reverse(self):
        n = self.head
        while n.next is not None:     
            a = n.next
            self.deleteNode(a)
            self.insertFirst(a)

        return self

    
    def sort(self, method='ascending'):
        """Returns sorted list according to method
        method (str): 'ascending' or 'descending' 
        """
        if self.isEmpty():
            print('Empty list')
            pass
        
        n = self.head
        while n.next is not None:
            a = n.data
            b = n.next.data
            if (method == 'ascending' and int(b) < int(a)) or (method == 'descending' and int(b) > int(a)):
                n.data = b
                n.next.data = a
                n = self.head
            else:
                n = n.next
            #print(self.__repr__())
        return self

    def isCircular(self):
        """Determine if list repeats itself"""

        pass


def compare(ll1, ll2) -> str:
    """Compare 2 linked lists and find similarities"""
    l1 = ll1.getLength()
    l2 = ll2.getLength()
    print(f'l1={l1}, l2={l2}')
    inCommon = []
    
    for i in range(min(l1, l2)):
        n1 = ll1.traverseTo(i)
        
        if ll2.contains(n1):
            inCommon.append(n1)

    return f'Nodes in Common: {inCommon}'