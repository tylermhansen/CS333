# Tyler Hansen, Sawyer Strong, Skye Rhomberg
# CS333 Spring 2021 -- Programming Languages
# 03/31/2021

# linked_list.rb: Describes the singly-linked list data structure.


class LinkedList

    # Get and Set Instance variables head, tail, and length
    attr_accessor :head, :tail, :length

    # Function: initialize
    # ----------------------
    # The constructor for a LinkedList object.
    # 
    # Parameters: N/A
    #
    # Returns: N/A
	def initialize
		self.head   = nil
		self.tail   = nil
		self.length = 0
	end

	# Function: append
    # ----------------------
    # Append a new node to the bottom of the list.
    # 
    # Parameters:
    # data -- The data stored in the new node.
    #
    # Returns: N/A
	def append data
        # Create a new Node
		node = Node.new data
		unless head # Unless there is a head node, set the head to the new node.
			self.head = node
        end
		# Set the next of the tail to the new node. 
		current_tail = self.tail
        self.tail.next = node
		self.tail = node
		self.length += 1
	end

	# Function: delete
    # ----------------------
    # Delete a node from the list.
    # 
    # Parameters:
    # node -- The node to remove (actually a node object, not the data stored at that node).
    #
    # Returns: N/A
	def delete node # Takes in a node

		return nil unless node # Return nil if no node is passed in

        # If it is the head node...
		if node == head
			if head.next.nil?
				self.head = self.tail = nil
			else
				self.head = self.head.next
			end
		else # If it is not the head node...
			tmp = self.head
			while tmp && tmp.next != node
				tmp = tmp.next
			end
			tmp.next = node.next if tmp
		end
		self.length -= 1
	end

	# Function: clear
    # ----------------------
    # Remove all nodes from the list.
    # 
    # Parameters: N/A
    #
    # Returns: N/A
	def clear
		while self.head.next != nil
            remove self.head.next.data
        end
        remove self.head.data
        self.length = 0
	end


    # Function: remove
    # ----------------------
    # The constructor for a Node object.
    # 
    # Parameters:
    # value -- The data in the node to remove.
    #
    # Returns: NA
    def remove(value)
        if self.head.data == value
          self.head = self.head.next
          return
        end
        node = find(value)
        node.next = node.next.next
        self.length -= 1
    end

    # Function: find
    # ----------------------
    # Get a node by value.
    # 
    # Parameters:
    # value -- The data in the node to seek.
    #
    # Returns:
    # node -- The node with the found value or false
    def find(value)
        node = self.head
        return false if !node.next
        return node  if node.next.data == value
        while (node = node.next)
          return node if node.next && node.next.data == value
        end
    end

    # Function: is_empty?
    # ----------------------
    # Returns whether or not the LinkedList is empty.
    # 
    # Parameters: N/A
    #
    # Returns: true if empty, false otherwise
    def is_empty?
        if self.head == nil
            return true
        else
            return false
        end
    end

    # Function: push
    # ----------------------
    # Push a node on top of the list.
    # 
    # Parameters:
    # data -- the data in to store in the new head node.
    #
    # Returns: N/A
    def push(data)
        new_node = Node.new(data)
        if self.is_empty?
            self.tail = new_node
        else
            current_head = self.head
            new_node.next = current_head
        end
        self.head = new_node
        self.length += 1
    end

    # Function: pop
    # ----------------------
    # Remove and return the top node in the list.
    # 
    # Parameters: N/A
    #
    # Returns: N/A
    def pop
        if self.is_empty?
            return "This list is currently empty"
        else
            current_node = self.head
            while current_node.next.next != nil
                current_node = current_node.next
            end
            last_node = current_node.next
            current_node.next = nil
        end
        return last_node
        self.length -= 1
    end

    # Function: pretty_print
    # ----------------------
    # Print all of the elements in the list as a nice, pretty array.
    # 
    # Parameters: N/A
    #
    # Returns: N/A
    def pretty_print
        puts "Head"
        array = []
        current_node = self.head
        if self.is_empty?
            puts "Tail"
            return array
        else
            while current_node.next != nil
                array << current_node.data
                current_node = current_node.next
            end
            array << current_node.data
       end
       array.append(self.tail.data)
       puts array
       puts "Tail"
    end

    class Node
        # Get and Set instance variables next and data
        attr_accessor :next, :data
    
        # Function: initialize
        # ----------------------
        # The constructor for a Node object.
        # 
        # Parameters:
        # data -- The data to store in the node.
        #
        # Returns: NA
        def initialize data
            self.data = data
            self.next = nil
        end
    end

end