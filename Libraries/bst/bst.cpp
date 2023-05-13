
namespace lasd {

/* ************************************************************************** */

// Default constructor
// XXXXXXXXXXXXXXXXXX

// Specific constructor #1: BST obtained from a MappableContainer
template<typename Data>
BST<Data>::BST(const MappableContainer<Data>& container){

    container.Map(
        
        [this](const Data& value){
            
            Insert(value);
        });
}


// Specific constructor #2: BST obtained from a MutableMappableContainer
template<typename Data>
BST<Data>::BST( MutableMappableContainer<Data>&& cont){

    container.Map(
        
        [this]( Data&& value){
            
            Insert(std::move(value));
        });
}


// Copy constructor
template<typename Data>
BST<Data>::BST(const BST<Data>& tree) : BinaryTreeLnk<Data>::BinaryTreeLnk(tree){}


// Move constructor
template<typename Data>
BST<Data>::BST(BST<Data>&& tree) : BinaryTreeLnk<Data>::BinaryTreeLnk(std::move(tree)){}



// Copy assignment
template<typename Data>
BST<Data>& BST<Data>::operator = (const BST<Data>& otherTree){

    BinaryTreeLnk<Data>::operator = (otherTree);
    return *this;
}


// Move assignment
template<typename Data>
BST<Data>& BST<Data>::operator=( BST<Data>&& otherTree){

    BinaryTreeLnk<Data>::operator = (std::move(otherTree));
    return *this;
}


// Operator ==
template<typename Data>
bool BST<Data>::operator == (const BST<Data>& tree) const noexcept{
    
    if(size != tree.Size()){ return false; }
    if(size == 0){ return true; }

    BTBreadthIterator<Data> IT(tree);
    while(!IT.Terminated()){

        if(!this->Exists(*IT)){ return false; }
        ++IT;
    }   

    return true; 

/* ISAAC

    if(size != tree.size){ return false; }
    if(size == 0){ return true; }

    BTInOrderIterator<Data> iterator_on_second_tree(tree);
    BTInOrderIterator<Data> iterator_on_first_tree(*this);
    while(!iterator_on_first_tree.Terminated() && !iterator_on_second_tree.Terminated()){
        if(*iterator_on_first_tree!=*iterator_on_second_tree)
            return false;

        ++iterator_on_first_tree;
        ++iterator_on_second_tree;
    }

    return true;
*/    
}


// Operator !=
template<typename Data>
bool BST<Data>::operator!=(const BST<Data>& tree) const noexcept{

    return !(*this == tree);
}


// Defining function Insert (Copy of value)
template<typename Data>
bool BST<Data>::Insert(const Data& value) noexcept{

    NodeLnk*& cursor = FindPointerTo(root, value);

    if(cursor != nullptr){ return false; }

    cursor = new NodeLnk(value);
    size ++;
    return true;
}


// Defining function Insert (Move of value)
template<typename Data>
bool BST<Data>::Insert( Data&& value){

    NodeLnk*& cursor = FindPointerTo(root, value);
    
    if(cursor != nullptr){ return false; }
    
    cursor = new NodeLnk(std::move(value));
    size ++;
    return true;
}


// Defining function Min
template<typename Data>
const Data& BST<Data>::Min() const{

    if(this->Size() == 0){ throw std::length_error("Error: Tree is Empty!"); }

    return FindPointerToMin(root)->element;
}


// Defining function MinNRemove
template<typename Data>
Data BST<Data>::MinNRemove(){

    if(this->Size() == 0){ throw std::length_error("Error: Tree is Empty!"); }

    Data temp = Min();
    RemoveMin();
    return temp;
}


// Defining function RemoveMin
template<typename Data>
void BST<Data>::RemoveMin(){

    if(this->Size() == 0){ throw std::length_error("Error: Tree is Empty!"); }

    Detach(FindPointerToMin(root));
    size --;
}


// Defining function Max
template<typename Data>
const Data& BST<Data>::Max() const{

    if(this->Size() == 0){ throw std::length_error("Error: Tree is Empty!"); }

    return FindPointerToMax(root)->element;
}


// Defining function MaxNRemove
template<typename Data>
Data BST<Data>::MaxNRemove(){

    if(this->Size() == 0){ throw std::length_error("Error: Tree is Empty!"); }

    Data temp = Max();
    RemoveMax();
    return temp;
}


// Defining function RemoveMax
template<typename Data>
void BST<Data>::RemoveMax(){

    if(this->Size() == 0){ throw std::length_error("Error: Tree is Empty!"); }

    Detach(FindPointerToMax(root));  //DA CAMBIARE????????
    size--;
}


// Defining function FindPointerTo (Non-Mutable version)
template<typename Data>
typename BST<Data>::NodeLnk* const & BST<Data>::FindPointerTo(NodeLnk* const& node, const Data& key) const{
    
    if(node == nullptr || node->element == key){ return node; }

    if(node->element > key){ return FindPointerTo(node->left, key); }
    
    else{ return FindPointerTo(node->right, key); }
}


// Defining function FindPointerTo (Mutable version)
template<typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerTo(NodeLnk*& node, const Data& key) {

    return const_cast<BST<Data>::NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerTo(node, key));
}


// Defining function FindPointerToMin (Non-Mutable version)
template<typename Data>
typename BST<Data>::NodeLnk* const & BST<Data>::FindPointerToMin(NodeLnk* const& node) const{
    
    if (node != nullptr && node->HasLeftChild()){ return FindPointerToMin(node->left); }
    else { return node; }
}


// Defining function FindPointerToMin (Mutable version)
template<typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMin( NodeLnk*& node){
    
    return const_cast<BST<Data>::NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerToMin(node));
}


// Defining function FindPointerToMax (Non-Mutable version)
template<typename Data>
typename BST<Data>::NodeLnk* const & BST<Data>::FindPointerToMax(NodeLnk* const& node) const{

   if (node != nullptr && node->HasRightChild()){ return FindPointerToMax(node->right); }
    else { return actual_node; }
}


// Defining function FindPointerToMax (Mutable version)
template<typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMax( NodeLnk*& node){

    return const_cast<BST<Data>::NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerToMax(node));
}


// Defining function Remove
template<typename Data>
bool BST<Data>::Remove(const Data& value){

    if(size==0){ throw std::length_error("Error: Tree is empty!"); }
    
    NodeLnk*& toDelete =(FindPointerTo(root, value));

    if(toDelete == nullptr){ return false; }

    Detach(toDelete);
    size--;
    return true;
}


// Defining function Detach
template<typename Data>
void BST<Data>::Detach(NodeLnk*& toDelete){

    if(toDelete->left == nullptr && toDelete->right == nullptr){
        delete toDelete;
        toDelete = nullptr;
    }

    else if(toDelete->left != nullptr && toDelete->right == nullptr){ delete Skip2Left(toDelete); }
        
    else if(toDelete->left == nullptr && toDelete->right != nullptr){ delete Skip2Right(toDelete); }
    
    else{

        NodeLnk*& temp = DetachMin(toDelete->right, toDelete);
        
        std::swap(toDelete->element, temp->element );
        delete temp;
        temp = nullptr;
    }

}


// Defining function Skip2Left
template<typename Data>
typename BST<Data>::NodeLnk* BST<Data>::Skip2Left(NodeLnk*& node){

    NodeLnk* temp = node;
    node = node->left;
    temp->left = temp->right = nullptr;
    return temp;
}


// Defining function Skip2Right
template<typename Data>
typename BST<Data>::NodeLnk* BST<Data>::Skip2Right(NodeLnk*& node){

    NodeLnk* temp = node;
    node = node->right;
    temp->left = temp->right = nullptr;
    return temp;
}


// Defining function DetachMin
template<typename Data> 
BST<Data>::NodeLnk*& BST<Data>::DetachMin(BST<Data>::NodeLnk*& current, BST<Data>::NodeLnk*& parent){

    if(current == nullptr){ return current; }
        
    if(current->HasLeftChild()){ return DetachMin(current->left , current); }        
    
    else{

        if(parent != nullptr){
                
            if(parent->left == current){ parent->left = current->right; }
            else { parent->right = current->right; }
        }

        else { root = root->right; }
    }

    return current;
}


// Defining function Exists
template<typename Data>
bool BST<Data>::Exists(const Data& value) const noexcept{

    return (FindPointerTo(root, value) != nullptr);
}


// Defining function Predecessor
template<typename Data>
const Data& BST<Data>::Predecessor(const Data& value) const{

    if(size==0){ throw std::length_error("Error: Tree is empty!"); }

    NodeLnk* temp = FindPointerToPredecessor(root, value);

    if(temp==nullptr){ throw std::length_error("Predecessor not found !"); }

    return temp->element;
}


// Defining function Successor
template<typename Data>
const Data& BST<Data>::Successor(const Data& value) const{

    if(size==0){ throw std::length_error("Error: Tree is empty!"); }

    NodeLnk* temp = FindPointerToSuccessor(root, value);

    if(temp == nullptr){ throw std::length_error("Successor not found !"); }

    return temp->element;
}


// Defining function PredecessorNRemove
template<typename Data>
Data BST<Data>::PredecessorNRemove(const Data& value){

    if(size==0){ throw std::length_error("Error: Tree is empty!"); }
    
    NodeLnk*& temp = FindPointerToPredecessor(root, value); 
    
    if(temp == nullptr){ throw std::length_error("Predecessor not found !"); }

    Data predecessor = temp->element;
    Detach(temp);
    size--;
    return predecessor;
}


// Defining function SuccessorNRemove
template<typename Data>
Data BST<Data>::SuccessorNRemove(const Data& value){

    if(size==0){ throw std::length_error("Error: Tree is empty!"); }
    
    NodeLnk*& temp = FindPointerToSuccessor(root, value);

    if(temp == nullptr){ throw std::length_error("Successor not found !"); }

    Data successor = temp->element;
    Detach(temp);
    size--;
    return successor;
}


// Defining function RemovePredecessor
template<typename Data>
void BST<Data>::RemovePredecessor(const Data& value){

    if(size==0){ throw std::length_error("Error: Tree is empty!"); }
    
    NodeLnk*& temp = FindPointerToPredecessor(root, value); 

    if(temp == nullptr){ throw std::length_error("Predecessor not found !"); }

    Detach(temp);
    size--;
}


// Defining function RemoveSuccessor
template<typename Data>
void BST<Data>::RemoveSuccessor(const Data& value){

    if(size == 0){ throw std::length_error("Error: Tree is empty!"); }
    
    NodeLnk*& temp = FindPointerToSuccessor(root, value);
    
    if(temp == nullptr){ throw std::length_error("Successor not found!"); }

    Detach(temp);
    size--;
}


// Defining function FindPointerToPredecessor (Non-Mutable version)
template<typename Data>
typename BST<Data>::NodeLnk*const& BST<Data>::FindPointerToPredecessor( NodeLnk* const & node , const Data& value) const{

    NodeLnk* const* pre = nullptr;
    NodeLnk* const* current = &node;
    
    while (*current != nullptr){

        if(value > (*current)->element){

            pre = current;
            current = &((*current)->right);
        }

        else { current = &((*current)->left); }
    }
    
    if(pre == nullptr){ return *current; }
    if(*pre == nullptr){ return *current; }
    else{ return *pre; }
}


// Defining function FindPointerToPredecessor (Mutable version)
template<typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToPredecessor(NodeLnk*& node , const Data& value){

    return const_cast<BST<Data>::NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerToPredecessor(node, value));
}


// Defining function FindPointerToSuccessor (Non-Mutable version)
template<typename Data>
typename BST<Data>::NodeLnk*const& BST<Data>::FindPointerToSuccessor( NodeLnk* const & node, const Data& value) const{

    NodeLnk* const* suc = nullptr;
    NodeLnk* const* current = &node;
    
    while (*current != nullptr){

        if(value >= (*current)->element){ current = &((*current)->right); }
        
        else{
            suc = current;
            current = &((*current)->left);
        }
    }
    
    if(suc == nullptr){ return *current; } 
    if(*suc == nullptr){ return *current; }
    else {return *suc; }
}


// Defining function FindPointerToSuccessor (Mutable version)
template<typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToSuccessor(NodeLnk*& node, const Data& value){

    return const_cast<BST<Data>::NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerToSuccessor(node,value));
}


// Defining function Clear
//XXXXXXXXXXXXXXXXXXXXXXXX

/* ************************************************************************** */

};
