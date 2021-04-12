use std::rc::Rc;


// define our list struct
pub struct List<T> {
    head: Link<T>,
}

// variable type to link nodes within list 
type Link<T> = Option<Rc<Node<T>>>;


//nodes to be stored in Linked list
struct Node<T> {
    elem: T,
    next: Link<T>,
}


//methods for the linked list
impl<T> List<T> {
    //create a new list
    pub fn new() -> Self {
        List { head: None }
    }

    // add a node to the front of hte list
    pub fn append(&self, elem: T) -> List<T> {
        List { head: Some(Rc::new(Node {
            elem: elem,
            next: self.head.clone(),
        }))}
    }

    // set the back of the list 
    pub fn tail(&self) -> List<T> {
        List { head: self.head.as_ref().and_then(|node| node.next.clone()) }
    }

    // set the head 
    pub fn head(&self) -> Option<&T> {
        self.head.as_ref().map(|node| &node.elem)
    }
    // set the iterable object 
    pub fn iter(&self) -> Iter<'_, T> {
        Iter { next: self.head.as_deref() }
    }
}

// create custom method for dropping list 
impl<T> Drop for List<T> {
    fn drop(&mut self) {
        let mut head = self.head.take();
        while let Some(node) = head {
            if let Ok(mut node) = Rc::try_unwrap(node) {
                head = node.next.take();
            } else {
                break;
            }
        }
    }
}

// create iterable struct
pub struct Iter<'a, T> {
    next: Option<&'a Node<T>>,
}


// iterating through the list to allow us to access and set specific values 
impl<'a, T> Iterator for Iter<'a, T> {
    type Item = &'a T;

    fn next(&mut self) -> Option<Self::Item> {
        self.next.map(|node| {
            self.next = node.next.as_deref();
            &node.elem
        })
    }
}


// test code
#[cfg(test)]
mod test {
    use super::List;

    #[test]
    fn basics() {

        // test basic methods 
        let list = List::new();
        assert_eq!(list.head(), None);

        let list = list.append(1).append(2).append(3);
        assert_eq!(list.head(), Some(&3));

        let list = list.tail();
        assert_eq!(list.head(), Some(&2));

        let list = list.tail();
        assert_eq!(list.head(), Some(&1));

        let list = list.tail();
        assert_eq!(list.head(), None);

        // Make sure empty tail works
        let list = list.tail();
        assert_eq!(list.head(), None);
    }

    #[test]
    fn iter() {

        // test that the iterable objects  work 
        let list = List::new().append(1).append(2).append(3);

        let mut iter = list.iter();
        assert_eq!(iter.next(), Some(&3));
        assert_eq!(iter.next(), Some(&2));
        assert_eq!(iter.next(), Some(&1));
    }
}