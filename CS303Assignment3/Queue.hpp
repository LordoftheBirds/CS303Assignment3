#ifndef QUEUE_HPP_
#define QUEUE_HPP_

template<typename Item_Type>
class Queue {
private:

	struct Node {
		Item_Type data;
		Node* next;

		Node(const Item_Type& data_item, Node* next_ptr = nullptr) :data(data_item), next(next_ptr) {}
	};

	Node* frontQueue;
	Node* backQueue;
	size_t numItems;

public:
	Queue();
	
	/*
	* Adds an item to the back of the queue.
	*/
	void push(Item_Type item);

	/*
	* Remove the item at the front of the queue and return it.
	* Cannot be called on empty queue.
	*/
	Item_Type pop();

	/*
	* Return the item at the front of the queue.
	* Cannot be called on empty queue.
	*/
	Item_Type peek();

	/*
	* Returns true if queue as no items. False otherwise.
	*/
	bool isEmpty();

	/*
	* Returns the number of items currently in queue.
	*/
	size_t queueSize();
};

template<typename Item_Type>
Queue<Item_Type>::Queue() {
	frontQueue = nullptr;
	backQueue = nullptr;
	numItems = 0;
}

template<typename Item_Type>
void Queue<Item_Type>::push(Item_Type item) {
	Node* newNode = new Node(item);

	if (isEmpty()) {
		frontQueue = newNode;
		backQueue = newNode;
	}
	else {
		backQueue->next = newNode;
		backQueue = newNode;
	}

	numItems++;
}

template<typename Item_Type>
bool Queue<Item_Type>::isEmpty() {
	if (numItems == 0) {
		return true;
	}
	return false;
}

template<typename Item_Type>
Item_Type Queue<Item_Type>::pop() {

	Item_Type returnItem = frontQueue->data;
	Node* toDelete = frontQueue;
	frontQueue = frontQueue->next;
	delete toDelete;
	numItems--;

	return returnItem;
}

template<typename Item_Type>
Item_Type Queue<Item_Type>::peek() {
	return frontQueue->data;
}

template<typename Item_Type>
size_t Queue<Item_Type>::queueSize() {
	return numItems;
}

#endif // QUEUE_HPP_
