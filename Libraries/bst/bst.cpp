
namespace lasd {

/* ************************************************************************** */

// Specific constructor #1: BinaryTreeLnk obtained from a MappableContainer
template <typename Data>
BST<Data>::BST(const MappableContainer<Data>& container) noexcept{

    container.Map(
        [this](const Data& data){

            this->Insert(data);
        }
    );
}


// Specific constructor #2: BinaryTreeLnk obtained from a MutableMappableContainer
template <typename Data>
BST<Data>::BST(MutableMappableContainer<Data>&& container) noexcept{

    container.Map(
        [this](Data& data){

            this->Insert(std::move(data));
        }
    );
}


// Copy constructor
// XXXXXXXXXXXXXXX

// Move constructor
// XXXXXXXXXXXXXXX

// Destructor
// XXXXXXXXXX


// Copy assignment
template <typename Data>
BST<Data>& BST<Data>::operator = (const BST<Data>& tree){

    BinaryTreeLnk<Data>::operator = (tree);
}


// Move assignment
template <typename Data>
BST<Data>& BST<Data>::operator = (BST<Data>&& tree) noexcept{

    BinaryTreeLnk<Data>::operator = (std::move(tree));
}


// Operator ==
template <typename Data>
bool BST<Data>::operator == (const BST& otherTree) const noexcept{

    if(this->Size() != otherTree.Size()){ return false; }
    if(this->Size() == 0){ return true; }

    BTBreadthIterator<Data> IT(otherTree);
    while(!IT.Terminated()){

        if(!this->Exists(*IT)){ return false; }
        ++IT;
    }   

    return true; 
}


// Operator !=
template <typename Data>
bool BST<Data>::operator != (const BST& otherTree) const noexcept{

    return !(*(this) == otherTree);
}


// Definingn function Min
template <typename Data>
const Data& BST<Data>::Min() const{

    if(this->Size() == 0){ throw std::length_error("Error: Tree is Empty!"); }

    using Node = typename BinaryTree<Data>::Node;
    Node current = this->Root();
    while(current.HasLeftChild()){ current = current.LeftChild(); }
    return current.Element();
}


// Defining function MinNRemove
template <typename Data>
Data BST<Data>::MinNRemove(){

    Data temp = std::move(this->Min());
    Remove(temp);
    return temp;
}


// Defining function RemoveMin
template <typename Data>
inline void BST<Data>::RemoveMin(){ Remove(this->Min()); }


// Defining function Max
template <typename Data>
const Data& BST<Data>::Max() const{

    if(this->Size() == 0){ throw std::length_error("Error: Tree is Empty!"); }

    using Node = typename BinaryTree<Data>::Node;
    Node current = this->Root();
    while(current.HasRightChild()){ current = current.RightChild(); }
    return current.Element();
}


// Defining function MaxNRemove
template <typename Data>
Data BST<Data>::MaxNRemove(){

    Data temp = std::move(this->Max());
    Remove temp;
    return temp;
}


// Defining function RemoveMax
template <typename Data>
void BST<Data>::RemoveMax(){ Remove(this->Max()); }


// Override function Insert (Copy of the value)
template <typename Data>
bool BST<Data>::Insert(const Data& value) noexcept{

    NodeLnk*& cursor = this->Search(value, root);

    if(cursor != nullptr){ return false; }

    cursor = new NodeLnk(value);
    size ++;
    return true;
}


// Override function Insert (Move of the value)
template <typename Data>
bool BST<Data>::Insert(Data&& value) noexcept{

    NodeLnk*& cursor = this->Search(value, root);

    if(cursor != nullptr){ return false; }
    
    cursor = new NodeLnk(std::move(value));
    size ++;
    
    return true;
}


// Override function Remove
template <typename Data>
bool BST<Data>::Remove(const Data& value) noexcept{

    NodeLnk*& cursor = this->Search(value, root);
    if(cursor == nullptr){ return false; }
    Detach(cursor);
    return true;
}


// Override function Exists
template <typename Data>
bool BST<Data>::Exists(const Data& value) const noexcept{

    BST<Data>* castedTree = const_cast<BST<Data>*>(this);

    if(castedTree->Search(value, castedTree->root) != nullptr){ return true; }
    return false;
}


// AUXILIARY - Defining function Detach
template <typename Data>
void BST<Data>::Detach(NodeLnk*& current){

    if(current->IsLeaf()){ RemoveLeaf(current); }
    else if(current->HasLeftChild() && current->HasRightChild()){ SimpleRemove(current); }
    else{ FullRemove(current); }
}


// AUXILIARY - Defining function Search
template <typename Data>
BST<Data>::NodeLnk*& BST<Data>::Search(const Data& value, NodeLnk*& node) noexcept{

    if(node == nullptr){ return node; }
    else if(value < node->Element()){ return Search(value, node->left); }
    else if(value > node->Element()){ return Search(value, node->right); }

    return node; 
}


// AUXILIARY - SimpleRemove
template <typename Data>
void BST<Data>::RemoveLeaf(NodeLnk*& node){

    delete node;
    node = nullptr;
}


// AUXILIARY - SimpleRemove
template <typename Data>
void BST<Data>::SimpleRemove(NodeLnk*& node){

    NodeLnk* child = nullptr;
    if(node->HasLeftChild()){ child = node->left; }
    else{ child = node->right; }

    std::swap(node->Element(), child->Element());
    node->left = child->left;
    node->right = child->right;

    child->left = nullptr;
    child->right = nullptr;
    delete child;
}


// AUXILIARY - FullRemove
template <typename Data>
void BST<Data>::FullRemove(NodeLnk*& node){

    NodeLnk*& cursor = node->left;
    NodeLnk* backup = cursor;
    while(cursor->right != nullptr){ cursor = cursor->right; }
    std::swap(cursor->Element(), node->Element());
    
    NodeLnk* temp = cursor;
    cursor = cursor->left;
    delete temp;
    cursor = backup;
}

/* ************************************************************************** */

}
