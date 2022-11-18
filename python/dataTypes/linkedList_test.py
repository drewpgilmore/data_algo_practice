#! /usr/local/bin/python3
# linkedList_test.py - testing linkedList.py 

from dataTypes.linkedList import Node, LinkedList, compare, generateLL

# ---Test Node----
def test_empty_node() -> None:
    """Tests node initiated with no data"""
    node = Node()
    assert node.data is None
    assert node.next is None

    node = Node(3)
    assert node.data == '3'  

    node = Node('65')
    r = node.__repr__()
    assert r == '65'

# ---Test LinkedList---
def test_linkedList() -> None:
    """Test LinkedList"""
    llist = LinkedList()
    assert llist.head is None
    assert llist.isEmpty() is True
    assert llist.getLength == 0

    llist.head = Node('4')
    assert llist.head.data == '4'
    
    llist.insertFirst(Node('5'))
    assert llist.head.next == '5'
    assert llist.__repr__() == '4 -> 5 -> End'

    llist.insertLast(Node('7'))
    llist.insertLast(Node('1'))
    llist.sort()
    assert llist.head == Node('1')



