
namespace lasd {

/* ************************************************************************** */

// Default constructor
// XXXXXXXXXXXXXXXXXX


// Specific constructor #1: BST obtained from a MappableContainer
template <typename Data>
BST<Data>::BST(const MappableContainer<Data>& container) noexcept{

    /////////////////////////// TODO
}


// Specific constructor #2: BST obtained from a MutableMappableContainer
template <typename Data>
BST<Data>::BST(MutableMappableContainer<Data>&& container) noexcept{

    /////////////////////////// TODO
}


// Copy constructor
template <typename Data>
BST<Data>::BST(const BST<Data>& otherBst) : BinaryTreeLnk<Data>(otherBst){};


// Move constructor
template <typename Data>
BST<Data>::BST(BST<Data>&& otherBst) noexcept : BinaryTreeLnk<Data>(std::move(otherBst)){};


// Copy assignment
template <typename Data>
BST<Data>& BST<Data>::operator = (const BST<Data>& otherBST){
    BinaryTreeLnk<Data>::operator = (otherBST);
    return (*this);
}


// Move assignment
template <typename Data>
BST<Data>& BST<Data>::operator = (BST<Data>&& otherBST) noexcept {
    BinaryTreeLnk<Data>::operator = (std::move(otherBST));
    return (*this);
}


// Operator ==
template <typename Data>
bool BST<Data>::operator == (const BST<Data>& otherBST) const noexcept{

    if(size != otherBST.size){ return false; } 
    if(size == 0 && otherBST.size == 0){ return true; }

    BTInOrderIterator<Data> myIterator(*this); 
    BTInOrderIterator<Data> otherIterator(otherBST);

    while(!myIterator.Terminated()){
        
        if(*myIterator != *otherIterator){ return false; }
        
        ++myIterator;
        ++otherIterator;

    }

    return true;
}


// Operator !=
template <typename Data>
bool BST<Data>::operator != (const BST<Data>& otherBST) const noexcept{

    return !((*this) == otherBST);
}


// Defining fuction Min
template <typename Data>
const Data& BST<Data>::Min() const{

    if(size == 0){ throw std::length_error("Error : BST is Empty!"); }
    else{ return (FindPointerToMin(root))->key; }
}


// Defining function MinNRemove
template <typename Data>
Data BST<Data>::MinNRemove(){

    if(size == 0){ throw std::length_error("Error : BST is Empty!"); }
    else{ return DataNDelete(DetachMin(root)); }
}


// Defining function RemoveMin
template <typename Data>
void BST<Data>::RemoveMin(){

    if(size == 0){ throw std::length_error("Error : BST is Empty!"); }
    else{ delete DetachMin(root); }
    
}


// Defining function Max
template <typename Data>
const Data& BST<Data>::Max() const{

    if(size == 0){ throw std::length_error("Error : BST is Empty!"); }
    else{ return (FindPointerToMax(root))->key; }
}


// Defining function MaxNRemove
template <typename Data>
Data BST<Data>::MaxNRemove(){

    if(size == 0){ throw std::length_error("Error : BST is Empty!"); }
    else{ return DataNDelete(DetachMax(root)); }
}


// Defining function RemoveMax
template <typename Data>
void BST<Data>::RemoveMax(){

    if(size == 0){ throw std::length_error("Error : BST is Empty!"); }
    else { delete DetachMax(root); }
}


// Defining function Predecessor
template <typename Data>
const Data& BST<Data>::Predecessor(const Data& data) const{

    if(size == 0){ throw std::length_error("Error : BST is Empty!"); }
    
    else{

        struct BST<Data>::NodeLnk* const* result = FindPointerToPredecessor(root, data);

        if(result != nullptr){ return (*(result))->key; }
        else{ throw std::length_error("Error : Predecessor not found."); }
    }
}


// Defining function PredecessorNRemove
template <typename Data>
Data BST<Data>::PredecessorNRemove(const Data& data){

    if(size == 0){ throw std::length_error("Error : BST is Empty!"); }
    
    else{
        
        struct BST<Data>::NodeLnk** tempPredecessor = FindPointerToPredecessor(root, data);
        
        if(tempPredecessor != nullptr){ return DataNDelete(Detach(*tempPredecessor)); }
        else{ throw std::length_error("Error : Predecessor not found!"); }
    }
}


// Defining function RemovePredecessor
template <typename Data>
void BST<Data>::RemovePredecessor(const Data& data){

    if(size == 0){ throw std::length_error("Error : BST is Empty!"); } 
    
    else{
        
        struct BST<Data>::NodeLnk** tempPredecessor = FindPointerToPredecessor(root, data);
        
        if(tempPredecessor != nullptr){ delete Detach(*tempPredecessor); }
        else{ throw std::length_error("Error : Predecessor not found!"); }
    } 
}


// Defining function Successor
template <typename Data>
const Data& BST<Data>::Successor(const Data& data) const{

    if(size == 0){ throw std::length_error("Error : BST is Empty!"); }
    
    else{
        
        struct BST<Data>::NodeLnk* const* result = FindPointerToSuccessor(root, data);
        
        if(result != nullptr){ return (*(result))->key; }
        else{ throw std::length_error("Error : Successor not found!"); }
    }
}


// Defining function SuccessorNRemove
template <typename Data>
Data BST<Data>::SuccessorNRemove(const Data& data){
    
    if(size == 0){ throw std::length_error("Error : BST is Empty!"); }

    else{
        
        struct BST<Data>::NodeLnk** tempSuccessor = FindPointerToSuccessor(root, data);
        
        if(tempSuccessor != nullptr){ return DataNDelete(Detach(*tempSuccessor)); }
        else{ throw std::length_error("Error : Successor not found!"); }
    }
}


// Defining function RemoveSuccessor
template <typename Data>
void BST<Data>::RemoveSuccessor(const Data& data){

    if(size == 0){ throw std::length_error("Error : BST is Empty!"); }
    
    else{
        
        struct BST<Data>::NodeLnk** tempSuccessor = FindPointerToSuccessor(root, data);
        
        if(tempSuccessor != nullptr){ delete Detach(*tempSuccessor); }
        else{ throw std::length_error("Error : Successor not found!"); }
    }
}


// Defining function Insert (Copy)
template <typename Data>
bool BST<Data>::Insert(const Data& data){

    struct BST<Data>::NodeLnk*& tempPointer = FindPointerTo(root, data);
    
    if(tempPointer == nullptr){

        tempPointer = new struct BST<Data>::NodeLnk(data);
        size = size + 1;
        return true;
    }

    return false;
}


// Defining function Insert (Move)
template <typename Data>
bool BST<Data>::Insert(Data&& data){

    struct BST<Data>::NodeLnk*& tempPointer = FindPointerTo(root, data);
    
    if(tempPointer == nullptr){
        
        tempPointer = new struct BST<Data>::NodeLnk(std::move(data));
        size = size + 1;
        return true;
    }
    
    return false;
}


// Defining function Remove
template <typename Data>
bool BST<Data>::Remove(const Data& data){

    int tempSize = size;
    delete Detach(FindPointerTo(root, data));
    return (tempSize != size);
}


// Defining function Exists
template <typename Data>
bool BST<Data>::Exists(const Data& data) const noexcept{
    
    if(size == 0){ return false; }
    
    else{

        struct BST<Data>::NodeLnk* resultExists = FindPointerTo(root, data);

        if(resultExists != nullptr){ return true; }
        else { return false; }
    }
}


// Function Clear Inherited from BinaryTreeLnk


/* ************************************************************************** */

// AUXILIARY - Defining function DataNDelete
template <typename Data>
Data BST<Data>::DataNDelete(struct BST<Data>::NodeLnk* nodeLnk){
 
    Data tempKey = nodeLnk->key;
    delete nodeLnk;
    return tempKey;
}


// AUXILIARY - Defining function Detach
template <typename Data>
struct BST<Data>::NodeLnk* BST<Data>::Detach(struct BST<Data>::NodeLnk*& nodeLnk) noexcept{

    if(nodeLnk == nullptr){ return nullptr; }
    
    // Has both left and right child
    if(nodeLnk->left != nullptr && nodeLnk->right != nullptr){
        
        struct BST<Data>::NodeLnk* temp = DetachMin(nodeLnk->right);
        std::swap(nodeLnk->key, temp->key);
        return temp;
    }

    // Has left child only
    else if(nodeLnk->left != nullptr){ return Skip2Left(nodeLnk); }

    // Has right child only
    else if(nodeLnk->right != nullptr){ return Skip2Right(nodeLnk); }

    else{ return DetachMin(nodeLnk); }
}


// AUXILIARY - Defining function DetachMin
template <typename Data>
struct BST<Data>::NodeLnk* BST<Data>::DetachMin(struct BST<Data>::NodeLnk*& nodeLnk) noexcept{

    if(size != 0){ return Skip2Right(FindPointerToMin(nodeLnk)); }
    return nullptr;
}


// AUXILIARY - Defining function DetachMax
template <typename Data>
struct BST<Data>::NodeLnk* BST<Data>::DetachMax(struct BST<Data>::NodeLnk*& nodeLnk) noexcept{
    
    if(size != 0){ return Skip2Left(FindPointerToMax(nodeLnk)); }
    return nullptr;
}


// AUXILIARY - Defining function Skip2Left
template <typename Data>
struct BST<Data>::NodeLnk* BST<Data>::Skip2Left(struct BST<Data>::NodeLnk*& nodeLnk) noexcept{

    struct BST<Data>::NodeLnk* leftChild = nullptr;

    if(nodeLnk != nullptr){

        std::swap(leftChild, nodeLnk->left);
        std::swap(leftChild, nodeLnk);
        size = size - 1;
    }

    return leftChild;
}


// AUXILIARY - Defining function Skip2Right
template <typename Data>
struct BST<Data>::NodeLnk* BST<Data>::Skip2Right(struct BST<Data>::NodeLnk*& nodeLnk) noexcept{
    
    struct BST<Data>::NodeLnk* rightChild = nullptr;
    
    if(nodeLnk != nullptr){
    
        std::swap(rightChild, nodeLnk->right);
        std::swap(rightChild, nodeLnk);
        size = size - 1;
    }
   
    return rightChild;
}


// AUXILIARY - Defining function FindPointerToMin (const)
template <typename Data>
struct BST<Data>::NodeLnk*& BST<Data>::FindPointerToMin(struct BST<Data>::NodeLnk*& nodeLnk) noexcept{
    return const_cast<struct BST<Data>::NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerToMin(nodeLnk));
}


// AUXILIARY - Defining function FindPointerToMin
template <typename Data>
struct BST<Data>::NodeLnk* const& BST<Data>::FindPointerToMin(struct BST<Data>::NodeLnk* const& nodeLnk) const noexcept{

    struct BST<Data>::NodeLnk* const* pointerToMin = &nodeLnk;
    struct BST<Data>::NodeLnk* temp = nodeLnk;

    if(temp != nullptr){

        while(temp->left != nullptr){
            pointerToMin = &(temp->left);
            temp = temp->left;
        }
    }

    return *pointerToMin;
}


// AUXILIARY - Defining function FindPointerToMax (const)
template <typename Data>
struct BST<Data>::NodeLnk*& BST<Data>::FindPointerToMax(struct BST<Data>::NodeLnk*& nodeLnk) noexcept{
    return const_cast<struct BST<Data>::NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerToMax(nodeLnk));
}


// AUXILIARY - Defining function FindPointerToMax
template <typename Data>
struct BST<Data>::NodeLnk* const& BST<Data>::FindPointerToMax(struct BST<Data>::NodeLnk* const& nodeLnk) const noexcept{

    struct BST<Data>::NodeLnk* const* pointerToMax = &nodeLnk;
    struct BST<Data>::NodeLnk* temp = nodeLnk;

    if(temp != nullptr){

        while(temp->right != nullptr){
            pointerToMax = &(temp->right);
            temp = temp->right;
        }
    }
    
    return *pointerToMax;
}


// AUXILIARY - Defining function FindPointerTo (const)
template <typename Data>
struct BST<Data>::NodeLnk*& BST<Data>::FindPointerTo(struct BST<Data>::NodeLnk*& nodeLnk, const Data& data) noexcept{
    return const_cast<struct BST<Data>::NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerTo(nodeLnk, data));
}


// AUXILIARY - Defining function FindPointerTo
template <typename Data>
struct BST<Data>::NodeLnk* const& BST<Data>::FindPointerTo(struct BST<Data>::NodeLnk* const& nodeLnk, const Data& data) const noexcept{
    
    struct BST<Data>::NodeLnk* const* pointerToNode = &nodeLnk;
    struct BST<Data>::NodeLnk* temp = nodeLnk;

    while(temp != nullptr){

        if(temp->key == data){ temp = nullptr; }

        else if(temp->key < data){
            pointerToNode = &(temp->right);
            temp = temp->right;
        }

        else{
            pointerToNode = &(temp->left);
            temp = temp->left;
        } 
    }

    return *pointerToNode;
}


// AUXILIARY - Defining function FindPointerToPredecessor (const)
template <typename Data>
struct BST<Data>::NodeLnk** BST<Data>::FindPointerToPredecessor(struct BST<Data>::NodeLnk*& nodeLnk, const Data& data) noexcept{
    return const_cast<struct BST<Data>::NodeLnk**>(static_cast<const BST<Data>*>(this)->FindPointerToPredecessor(nodeLnk, data));
}


// AUXILIARY - Defining function FindPointerToPredecessor /////////////////////////////////////////////////////// REVISION
template <typename Data>
struct BST<Data>::NodeLnk* const* BST<Data>::FindPointerToPredecessor(struct BST<Data>::NodeLnk* const& nodeLnk, const Data& data) const noexcept{
    
    struct BST<Data>::NodeLnk* const* temporaryPredecessor = &nodeLnk;
    struct BST<Data>::NodeLnk* const* pointerToPredecessor = nullptr;

    while(true){

        struct BST<Data>::NodeLnk& temp = **temporaryPredecessor;

        if(temp.key == data)
            if(temp.left != nullptr)
                return &FindPointerToMax(temp.left);
            else
                return pointerToPredecessor;
        else{
            if(temp.key < data){
                pointerToPredecessor = temporaryPredecessor;
                if(temp.right != nullptr)
                    temporaryPredecessor = &temp.right;
                else
                    return pointerToPredecessor;
            }
            else{
                if(temp.left != nullptr)
                    temporaryPredecessor = &temp.left;
                else
                    return pointerToPredecessor;
            }
        }
    } 
}


// AUXILIARY - FindPointerToSuccessor (const)
template <typename Data>
struct BST<Data>::NodeLnk** BST<Data>::FindPointerToSuccessor(struct BST<Data>::NodeLnk*& nodeLnk, const Data& data) noexcept{
    return const_cast<struct BST<Data>::NodeLnk**>(static_cast<const BST<Data>*>(this)->FindPointerToSuccessor(nodeLnk, data));
}


// AUXILIARY - FindPointerToSuccessor ///////////////////////////////////// REVISION
template <typename Data>
struct BST<Data>::NodeLnk* const* BST<Data>::FindPointerToSuccessor(struct BST<Data>::NodeLnk* const& nodeLnk, const Data& data) const noexcept{
    
    struct BST<Data>::NodeLnk* const* temporarySuccessor = &nodeLnk;
    struct BST<Data>::NodeLnk* const* pointerToSuccessor = nullptr;

    while(true){

        struct BST<Data>::NodeLnk& temp = **temporarySuccessor;

        if(temp.key == data)
            if(temp.right != nullptr)
                return &FindPointerToMin(temp.right);
            else
                return pointerToSuccessor;
        else{
            if(temp.key < data){
                if(temp.right != nullptr)
                    temporarySuccessor = &temp.right;
                else
                    return pointerToSuccessor;
            }
            else{
                pointerToSuccessor = temporarySuccessor;
                if(temp.left != nullptr)
                    temporarySuccessor = &temp.left;
                else
                    return pointerToSuccessor; 
            }
        }
    }
   
}

/* ************************************************************************** */

}
