/**
 * Go Singly Linked List
 * Skye Rhomberg, Tyler Hansen, Sawyer Strong
 * CS333 Project 5
 * Spring 2021
 *
 * EXTENSIONS:
 * Insert & Delete Functions
 */

package mylists

// Singly Linked Nodes
type Node struct {
    Data Data
    Next *Node
}

// List has a tail to make appending faster
type SLList struct {
    Head *Node
    Size int
}

// All types in Go implement the empty interface
// This is as close as one gets to polymorphism in Go
type Data interface{}

// Create list, return a pointer to it
func NewSLList() *SLList {
    return &SLList{nil,0}
}

/**
 * Push: add d to Head of list
 * Input: d Data : data to be pushed
 */
func (l *SLList) Push(d Data) {
    // New node whose next is head
    n := &Node{d,l.Head}
    // Reassign head, tail
    l.Head = n
    // Increment Size
    l.Size++
}

/**
 * Pop: remove and return Head of list
 * Return: Data : data of list's head
 */
func (l *SLList) Pop() Data {
    // Recover data to be returned
    d := l.Head.Data
    // Reassign head and tail
    l.Head = l.Head.Next
    // Decrement size
    l.Size--
    return d
}

/**
 * Append: add d to end of list
 * Input: d Data : data to be appended
 */
func (l *SLList) Append(d Data) {
    if l.Head == nil {
        l.Push(d)
        return
    }
    tmp := &l.Head
    for (*tmp).Next != nil {
        tmp = &(*tmp).Next
    }
    n := &Node{d,nil}
    (*tmp).Next = n;
    l.Size++
}

/**
 * Remove: remove and return first instance of target
 * if it appears in the list
 * Inputs:
 *  target Data : value to search for and remove
 *  cmpfunc (Data, Data) --> int : comparator to determine target match
 * Returns: Data. target if found, nil otherwise
 */
func (l *SLList) Remove(target Data, cmpfunc func(Data, Data)(int)) Data {
    // Traverse list, looking for target
    n := &l.Head
    for *n != nil && cmpfunc(target,(*n).Data) != 0 {
        n = &(*n).Next
    }
    // If target found...
    if *n != nil {
        // return node's data, remove node from list
        r := (*n).Data
        *n = (*n).Next
        // decrement size
        l.Size--
        return r
    }
    // If target not found, return nil
    return nil
}

/**
 * EXTENSION:
 * Delete: remove and return data of Node at index
 * Input: index int
 * Return: Data. data of removed Node
 */
func (l *SLList) Delete(index int) Data {
    // Traverse to index
    n := &l.Head
    for i := 0; i < index; i++ {
        n = &(*n).Next
    }
    // Return data, remove node
    r := (*n).Data
    *n = (*n).Next
    // Decrement size
    l.Size--
    return r
}

/**
 * Insert: put new node with d Data at index
 * Inputs:
 *  d Data : data to insert
 *  index int : index to insert at
 */
func (l *SLList) Insert(index int, d Data) {
    // Use append for empty list
    if index == l.Size {
        l.Append(d)
        return
    }
    // Use push for index 0 (i.e. list Head)
    if index == 0 {
        l.Push(d)
        return
    }
    // Traverse to right before index
    t := &l.Head
    for i := 0; i < index - 1; i++ {
        t = &(*t).Next
    }
    // Put new node right after (at index)
    n := &Node{d,(*t).Next}
    (*t).Next = n
    // Increment size
    l.Size++
}

// Size getter method
func (l *SLList) GetSize() int {
    return l.Size
}

/**
 * Clear: clear out list
 * Leave it with initial conditions (empty Head, Tail, 0 Size)
 */
func (l *SLList) Clear() {
    l.Head = nil
    l.Size = 0
}

/**
 * Map: apply mapfunc to data at every node
 * Input: mapfunc (*Data) --> void. function to be mapped
 */
func (l *SLList) Map(mapfunc func(*Data)) {
    for n := l.Head; n != nil; n = n.Next {
        mapfunc(&n.Data)
    }
}
