#include "sequence.h"

// Constructor
Sequence::Sequence(size_type sz) : numElts(0),
                                   head(nullptr),
                                   tail(nullptr)
{
    // create a list of sz nodes
    for (int i = 0; i < sz; i++)
    {
        push_back(0);
    }
}

// Copy constructor
Sequence::Sequence(const Sequence &s)
{
    numElts = s.numElts;
    head = s.head;
    tail = s.tail;

    // traverse the list and copy each node
    SequenceNode *currNode = s.head;
    while (currNode != nullptr)
    {
        push_back(currNode->elt);
        currNode = currNode->next;
    }
}

// Destructor
Sequence::~Sequence()
{
    clear();
}

// Copy constructor
Sequence &Sequence::operator=(const Sequence &s)
{
    clear();

    numElts = s.numElts;
    head = s.head;
    tail = s.tail;

    // traverse the list and copy each node
    SequenceNode *currNode = s.head;
    while (currNode != nullptr)
    {
        push_back(currNode->elt);
        currNode = currNode->next;
    }
    return *this;
}

// Bracket overload
Sequence::value_type &Sequence::operator[](size_type position) const
{
    // check if position is valid (not neg or greater than numElts)
    if (position < 0 || position > numElts)
        throw exception();
    else
    {
        // traverse the list to the position
        SequenceNode *currNode = head;
        for (int i = 0; i < position; i++)
        {
            currNode = currNode->next;
        }
        return currNode->elt;
    }
}

// Grows the sequence by one and adds value to the end of the sequence
void Sequence::push_back(const value_type &value)
{
    // nothing in the list
    if (tail == nullptr && head == nullptr)
    {
        head = new SequenceNode(value);
        numElts++;
        tail = head;
        head->prev = nullptr;
        tail->next = nullptr;
    }
    else
    {
        SequenceNode *nextNode = new SequenceNode(value);
        nextNode->prev = tail;
        tail->next = nextNode;
        tail = nextNode;
        numElts++;
    }
}

// Removes the last item in the sequence
void Sequence::pop_back()
{
    // nothing in the list
    if (tail == nullptr && head == nullptr)
    {
        throw exception();
    }
    else
    {
        SequenceNode *prevNode = tail->prev;
        delete tail;
        tail = prevNode;
        numElts--;
    }
}

// Inserts value at position in the sequence
void Sequence::insert(size_type position, value_type value)
{
    if (position < 0 || position > numElts)
    {
        throw exception();
    }
    else if (position == 0)
    {
        SequenceNode *newNode = new SequenceNode(value);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        numElts++;
    }
    else if (position == numElts)
    {
        SequenceNode *newNode = new SequenceNode(value);
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
        numElts++;
    }
    else
    {
        // traverse the list to the position
        SequenceNode *currNode = head;
        for (int i = 0; i < position; i++)
        {
            currNode = currNode->next;
        }

        // insert the new node
        SequenceNode *newNode = new SequenceNode(value);
        newNode->next = currNode;
        newNode->prev = currNode->prev;
        currNode->prev->next = newNode;
        currNode->prev = newNode;
        numElts++;
    }
}

// Returns the first item in the sequence
const Sequence::value_type &Sequence::front() const
{
    if (head != nullptr)
        return head->elt;
    else
        throw exception();
}

// Returns the last item in the sequence
const Sequence::value_type &Sequence::back() const
{
    if (tail != nullptr)
        return tail->elt;
    else
        throw exception();
}

// Returns true if the sequence is empty
bool Sequence::empty() const
{
    if (numElts == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Returns the number of items in the sequence
Sequence::size_type Sequence::size() const
{
    return numElts;
}

// Removes all items from the sequence
void Sequence::clear()
{
    if (numElts > 0)
    {
        SequenceNode *currNode = head;
        while (currNode != nullptr)
        {
            SequenceNode *nextNode = currNode->next;
            delete currNode;
            currNode = nextNode;
        }
        numElts = 0;
        head = tail = nullptr;
    }
    else
    {
        throw exception();
    }
}

// Removes count number of items starting from position
void Sequence::erase(size_type position, size_type count)
{
    // if the position or count is invalid, throw an exception
    if (position < 0 || position > numElts || count < 1 || position + count > numElts)
    {
        throw exception();
    }

    // traverse the list to the position
    SequenceNode *currNode = head;
    for (int i = 0; i < position; i++)
    {
        currNode = currNode->next;
    }

    // if the position is at the beginning of the list
    if (position == 0)
    {
        for (int i = 0; i < count; i++)
        {
            SequenceNode *nextNode = currNode->next;
            delete currNode;
            currNode = nextNode;
            numElts--;
        }
        head = currNode;
        head->prev = nullptr;
    }
    // if the position is at the end of the list
    else if (position + count == numElts)
    {
        for (int i = 0; i < count; i++)
        {
            SequenceNode *prevNode = currNode->prev;
            delete currNode;
            currNode = prevNode;
            numElts--;
        }
        tail = currNode;
        tail->next = nullptr;
    }
    // if the position is in the middle of the list
    else
    {
        // save the previous and next nodes
        SequenceNode *nextNode = currNode->next;
        SequenceNode *prevNode = currNode->prev;

        // copy the next node to delete
        SequenceNode *oldNextNode = currNode->next;
        for (int i = 0; i < count; i++)
        {
            currNode = nextNode;
            nextNode = currNode->next;
            delete currNode;
            numElts--;
        }
        prevNode->next = currNode;
        nextNode->prev = oldNextNode;
    }
}

ostream &operator<<(ostream &os, const Sequence &s)
{
    // print each element in the sequence
    if (s.size() == 0)
    {
        os << "<>";
        return os;
    }
    else
    {
        os << "<";
        for (Sequence::size_type i = 0; i < s.size(); i++)
        {
            os << s[i];
            if (i == s.size() - 1)
            {
                os << ">";
            }
            else
            {
                os << ", ";
            }
        }
        return os;
    }
}