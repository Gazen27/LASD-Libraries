
typedef unsigned long ulong;

namespace lasd {

////////////////////////////////////////////////////////////////// Node structure

// Specific constructor #1: Given initial value (copy)
template <typename Data>
List<Data>::Node::Node(const Data& value){

    key = value;
}


// Specific constructor #2: Given initial value (move)
template <typename Data>
List<Data>::Node::Node(Data&& value){

    std::swap(key, value);
}


// Copy constructor
template <typename Data>
List<Data>::Node::Node(const Node& otherNode){

    key = otherNode.key;
    next = otherNode.next;
}


// Move constructor
template <typename Data>
List<Data>::Node::Node(Node&& otherNode){

    std::swap(key, otherNode.key);
    std::swap(next, otherNode.next);
}


// Destructor
template <typename Data>
List<Data>::Node::~Node(){

    delete next;
}


// Operator ==
template <typename Data>
bool List<Data>::Node::operator == (const Node& otherNode) const noexcept{

    if(key == otherNode.key){

        if(next == otherNode.next){ return true; }
        else{

            if(next == nullptr && otherNode.next == nullptr){ return true; }
            else{ return false; }
        }
    }
    else { return false; }
}


// Operator !=
template <typename Data>
bool List<Data>::Node::operator != (const Node& otherNode) const noexcept{

    return !(*this) == otherNode;
}


////////////////////////////////////////////////////////////////// List

// Default constructor
// XXXXXXXXXXXXXXXXXXX

// Specific constructor #1: List obtained from a MappableContainer
template <typename Data>
List<Data>::List(const MappableContainer<Data>& container) noexcept{

    container.Map(

        [this](const Data& element){

            this->InsertAtBack(element);
        }
    );
}


// Specific constructor #2: List obtained from a MutableMappableContainer
template <typename Data>
List<Data>::List(MutableMappableContainer<Data>&& container) noexcept{

    container.Map(

        [this](Data& element){

            this->InsertAtBack(std::move(element));
        }
    );
}


// Copy constructor
template <typename Data>
List<Data>::List(const List<Data>& otherList){

    Node* tempList = otherList.head;

    while(tempList != nullptr){
        
        this->InsertAtBack(tempList->key);
        tempList = tempList->next;
    }

    tempList = nullptr;
}


// Move constructor
template <typename Data>
List<Data>::List(List<Data>&& otherList) noexcept{

    std::swap(size, otherList.size);
    std::swap(head, otherList.head);
    std::swap(tail, otherList.tail);
}


// Destructor
template <typename Data>
List<Data>::~List(){

    Clear();
}


// Copy assignment
template <typename Data>
List<Data>& List<Data>::operator = (const List<Data>& otherList) noexcept{

    List<Data>* tempList = new List<Data>(otherList);

    std::swap(size, tempList->size);
    std::swap(head, tempList->head);
    std::swap(tail, tempList->tail);

    delete tempList;
    return (*this);
}


// Move assignment
template <typename Data>
List<Data>& List<Data>::operator = (List<Data>&& otherList) noexcept{

    std::swap(size, otherList->size);
    std::swap(head, otherList->head);
    std::swap(tail, otherList->tail);

    return (*this);
}


// Operator ==
template <typename Data>
bool List<Data>::operator == (const List<Data>& otherList) const noexcept{

    if((size == 0) && (otherList == 0)) { return true; }

    if(size == otherList.size){

        Node* tempList = head;
        Node* tempOtherList = otherList.head;

        while(tempList != nullptr){

            if(tempList->key != tempOtherList->key){
                
                tempList = nullptr;
                tempOtherList = nullptr;
                return false;
            }

            tempList = tempList->next;
            tempOtherList = tempOtherList->next;
        }

        tempList = nullptr;
        tempOtherList = nullptr;
        return true;
    }
    else { return false; }
}


// Operator !=
template <typename Data>
bool List<Data>::operator != (const List<Data>& otherList) const noexcept{

    if((*this) == otherList) { return false; }
    else{ return true; }
}


// Defining function InsertAtFront (copy)
template <typename Data>
void List<Data>::InsertAtFront(const Data& newData){

    Node* newNode = new Node(newData);

    newNode->next = head;

    if(size == 0){ tail = newNode; }

    head = newNode;

    size = size + 1;
}


// Defining function InsertAtFront (move)
template <typename Data>
void List<Data>::InsertAtFront(Data&& newData){

    Node* newNode = new Node(newData);

    newNode->next = head;

    if(size == 0){ tail = newNode; }

    head = newNode;

    size = size + 1;
}


// Defining function RemoveFromFront()
template <typename Data>
void List<Data>::RemoveFromFront(){

    if(size == 0 || head = nullptr){

        throw std::length_error("Error: the structure is empty!");
    }

    else{

        Node* temp = head;
        if(size == 1){

            tail = nullptr;
        }

        head = head->next;
        temp = nullptr;
        delete temp;
        size = size - 1;
    }
}


// Defining function FrontNRemove
template <typename Data>
Data& List<Data>::FrontNRemove(){

    if(size == 0 || head == nullptr){

        throw std::length_error("Error: the structure is empty!");
    }

    else{

        Data value = head->key;
        Node* temp = head;

        if(size == 1){

            tail = nullptr;
        }

        head = head->next;
        temp = nullptr;
        delete temp;
        size = size - 1;

        return value;
    }
}


// Defining function InsertAtBack (copy)
template <typename Data>
void List<Data>::InsertAtBack(const Data& newData){

    if(size == 0){ InsertAtFront(newData); }
    else{

        Node* newNode = new Node(newData);
        tail->next = newNode;
        tail = newNode;
        size = size + 1;
    }
}


// Defining function InsertAtBack (move)
template <typename Data>
void List<Data>::InsertAtBack(Data&& newData){

    if(size == 0){ InsertAtFront(newData); }
    else{

        Node* newNode = new Node(newData);
        tail->next = newNode;
        tail = newNode;
        size = size + 1;
    } 
}


// Override function Clear
template <typename Data>
void List<Data>::Clear() noexcept{

    while(head != nullptr){ RemoveFromFront(); }
}


// Override function Exists
template <typename Data>
bool List<Data>::Exists(const Data& element) const noexcept{

    Node* temp = head;

    while(temp != nullptr){

        if(temp->key == element){ return true; }
        temp = temp->next;
    }

    return false;
}


// Override function Insert (copy)
template <typename Data>
bool List<Data>::Insert(const Data& element){

    if(this->Exists(element)){ return false; }

    else{
        
        this->InsertAtBack(element);
        return true;    
    }
}


// Override function Insert (move)
template <typename Data>
bool List<Data>::Insert(Data&& element){

    if(this->Exists(element)){ return false; }

    else{
        
        this->InsertAtBack(std::move(element));
        return true;    
    }
}


// Override function Remove
template <typename Data>
bool List<Data>::Remove(const Data& element){

    if(head->key == element){

        this->RemoveFromFront();
        return true;
    }

    Node* temp = head;

    while(temp != nullptr){

        if(temp != this->tail && (temp->next)->key == element){

            Node* toRemove = temp->next;
            temp->next = (temp->next)->next;
            delete toRemove;
            size = size - 1;

            return true;
        }

        temp = temp->next;
    }

    return false;
}


// Override operator [] (Non-Mutable version)
template <typename Data>
const Data& List<Data>::operator [] (const ulong index) const{

    if(index >= size || index < size - 1){ throw std::out_of_range("Error: index out of range!");}
    else{

        Node* temp = head;
        ulong tempIndex = 0;

        while(temp != nullptr){

            if(tempIndex == index){ return temp->key; }
            else{

                tempIndex = tempIndex + 1;
                temp = temp->next;
            }
        }        
    }
}


// Override operator [] (Mutable version)
template <typename Data>
Data& List<Data>::operator [] (const ulong index){

    if(index >= size || index < size - 1){ throw std::out_of_range("Error: index out of range!");}
    else{

        Node* temp = head;
        ulong tempIndex = 0;

        while(temp != nullptr){

            if(tempIndex == index){ return temp->key; }
            else{

                tempIndex = tempIndex + 1;
                temp = temp->next;
            }
        }        
    }
}


// Override function Front (Non-Mutable version)
template <typename Data>
const Data& List<Data>::Front() const{

    if(size == 0){ throw std::length_error("Error: the structure is empty!");}
    else{ return head->key; }
}


// Override function Front (Mutable version)
template <typename Data>
Data& List<Data>::Front(){

    if(size == 0){ throw std::length_error("Error: the structure is empty!");}
    else{ return head->key; } 
}


// Override function Back (Non-Mutable version)
template <typename Data>
const Data& List<Data>::Back() const{

    if(size == 0){ throw std::length_error("Error: the structure is empty!");}
    else{ return tail->key; }   
}


// Override function Back (Mutable version)
template <typename Data>
Data& List<Data>::Back(){

    if(size == 0){ throw std::length_error("Error: the structure is empty!");}
    else{ return tail->key; }   
}


// Override function Fold
template <typename Data>
void List<Data>::Fold(FoldFunctor f, void* accumulator) const{

    ///////// TODO
}


// Override function PreOrderFold
template <typename Data>
void List<Data>::PreOrderFold(FoldFunctor f, void* accumulator) const{

    ///////// TODO
}


// Override function PostOrderFold
template <typename Data>
void List<Data>::PostOrderFold(FoldFunctor f, void* accumulator) const{

    ///////// TODO
}


// Override function Map (Non-Mutable)
template <typename Data>
void List<Data>::Map(MapFunctor f) const{

    ///////// TODO
}


// Override function PreOrderMap (Non-Mutable)
template <typename Data>
void List<Data>::PreOrderMap(MapFunctor f) const{

    ///////// TODO
}


// Override function PostOrderMap (Non-Mutable)
template <typename Data>
void List<Data>::PostOrderMap(MapFunctor f) const{

    ///////// TODO
}


// Override function Map (Mutable)
template <typename Data>
void List<Data>::Map(MutableMapFunctor f) {

    ///////// TODO
}


// Override function PreOrderMap (Mutable)
template <typename Data>
void List<Data>::PreOrderMap(MutableMapFunctor f) {

    ////////// TODO
}


// Override function PostOrderMap (Mutable)
template <typename Data>
void List<Data>::PostOrderMap(MutableMapFunctor f) {

    ////////// TODO
}


}
