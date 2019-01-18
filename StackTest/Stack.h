#pragma once
template <typename T>
class Stack
{
public:
	Stack();
	~Stack();
	void Push(T nodeValue);
	bool Pop();	
	bool Empty();
	int GetSize()const;
	T* Top()const;
private:
	struct Node
	{
		T m_value;
		Node* m_prevNode;
		Node()
		{
			this->m_prevNode = nullptr;
		}
		Node(T value, Node* prevNode)
		{
			this->m_value = value;
			this->m_prevNode = prevNode;
		}
	};
	int m_size;
	Node *m_startNode;
	Node *m_topNode;
};

template<typename T>
Stack<T>::Stack()
{
	this->m_size = 0;
	this->m_startNode = nullptr;
	this->m_topNode = nullptr;
}

template<typename T>
Stack<T>::~Stack()
{
	while (m_size != 0)
	{
		Node* temp = m_topNode->m_prevNode;;
		delete m_topNode;
		m_topNode = temp;
		--m_size;
	}
}

template<typename T>
void Stack<T>::Push(T nodeValue)
{
	if (m_startNode == nullptr)
	{
		m_startNode = new Node(nodeValue, nullptr);
		m_topNode = m_startNode;
		++m_size;
		return;
	}
	m_topNode = new Node(nodeValue, m_topNode);
	++m_size;
}

template<typename T>
bool Stack<T>::Pop()
{
	if (m_size == 0)
	{
		return false;
	}
	Node* temp = m_topNode->m_prevNode;;
	delete m_topNode;
	m_topNode = temp;
	--m_size;
	return true;
}

template<typename T>
bool Stack<T>::Empty()
{
    return m_size == 0;
}

template<typename T>
int Stack<T>::GetSize() const
{
	return m_size;
}

template<typename T>
T* Stack<T>::Top()const
{
	if (m_size == 0)
	{
		return nullptr;
	}
	return &m_topNode->m_value;
}

