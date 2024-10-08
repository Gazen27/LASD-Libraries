
/* ************************************************************************** */

namespace lasd {

//////////////////////////////////////////////////////////////////////////// BinaryTreeLnk::NodeLnk

// Destructor
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::~NodeLnk(){

    delete left;
    delete right;
}


// Specific constructor #1
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const Data& data, NodeLnk* leftNode, NodeLnk* rightNode){

    key = data;
    left = leftNode;
    right = rightNode;
}


// Specific constructor #2
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const Data& otherData){ this->key = otherData; }


// Specific constructor #3
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(Data&& otherData) noexcept{ std::swap(this->key, otherData); }


// Copy constructor
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const BinaryTreeLnk<Data>::NodeLnk& otherNodeLnk){

    this->key = otherNodeLnk.key;
    if(otherNodeLnk.HasLeftChild()){ this->left = new NodeLnk(otherNodeLnk.LeftChild()); }
    if(otherNodeLnk.HasRightChild()){ this->right = new NodeLnk(otherNodeLnk.RightChild()); }
}


// Move constructor
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(BinaryTreeLnk<Data>::NodeLnk&& otherNodeLnk) noexcept{
    
    std::swap(this->key, otherNodeLnk.key);
    std::swap(this->left, otherNodeLnk.left);
    std::swap(this->right, otherNodeLnk.right);
}


// Copy assignment
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::operator = (const NodeLnk& otherNodeLnk){

    this.key = otherNodeLnk.key;
    if(otherNodeLnk.HasLeftChild()){ this->left = new NodeLnk(otherNodeLnk.LeftChild()); }
    if(otherNodeLnk.HasRightChild()){ this->right = new NodeLnk(otherNodeLnk.RightChild()); }

    return *this;
}


// Move assignment
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::operator = (NodeLnk&& otherNode) noexcept{

    std::swap(this->key, otherNode.key);
    std::swap(this->left, otherNode.left);
    std::swap(this->right, otherNode.right);

    return *this;
}


// Override function Element (Mutable)
template <typename Data>
Data& BinaryTreeLnk<Data>::NodeLnk::Element() noexcept{ return this->key; }


// Override function Element (Non-Mutable)
template <typename Data>
const Data& BinaryTreeLnk<Data>::NodeLnk::Element() const noexcept{ return this->key; }


// Defining function IsLeaf
template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::IsLeaf() const noexcept{

    if(this->left == nullptr && this->right == nullptr){ return true; }
    return false;
}


// Defining function HasLeftChild
template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasLeftChild() const noexcept{

    if(this->left != nullptr){ return true; }
    return false;
}


// Defining function HasRightChild
template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasRightChild() const noexcept{

    if(this->right != nullptr){ return true; }
    return false;
}


// Override function LeftChild (from MutableNode)
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::LeftChild(){

    if(!this->HasLeftChild()){ throw std::out_of_range("Error: Left Child Missing!"); }
    else return *(this->left);
}


// Override function RightChild (from MutableNode)
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::RightChild(){

    if(!this->HasRightChild()){ throw std::out_of_range("Error: Left Child Missing!"); }
    else return *(this->right);
}


// Override function LeftChild (from Node)
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::LeftChild() const{

    if(!this->HasLeftChild()){ throw std::out_of_range("Error : Left Child Missing"); }
    else return *(this->left);
}


// Override function RightChild (from Node)
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::RightChild() const{

    if(!this->HasRightChild()){ throw std::out_of_range("Error : Left Child Missing"); }
    else return *(this->right);
}

//////////////////////////////////////////////////////////////////////////// BinaryTreeLnk

// Default constructor
// XXXXXXXXXXXXXXXXXX


// Specific constructor #1: BinaryTreeLnk obtained from a MappableContainer
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const MappableContainer<Data>& container) noexcept{

    size = container.Size();
    lasd::QueueLst<NodeLnk*> mainQueue;
    
    container.Map(

        [this, &mainQueue](const Data& data){

            NodeLnk* temp = new NodeLnk(data);
            
            mainQueue.Enqueue(temp);

            if(root == nullptr){ root = temp; }

            else if(!mainQueue.Head()->HasLeftChild()){ mainQueue.Head()->left = temp; }

            else if(!mainQueue.Head()->HasRightChild()){
                
                mainQueue.Head()->right = temp;
                mainQueue.Dequeue();    
            }
        }
    );
}


// Specific constructor #2: BinaryTreeLnk obtained from a MutableMappableContainer
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(MutableMappableContainer<Data>&& container) noexcept{

    size = container.Size();
    lasd::QueueLst<NodeLnk*> mainQueue;
    
    container.Map(

        [this, &mainQueue](Data& data){

            NodeLnk* temp = new NodeLnk(std::move(data));
            
            mainQueue.Enqueue(temp);

            if(root == nullptr){ root = temp; }

            else if(!mainQueue.Head()->HasLeftChild()){ mainQueue.Head()->left = temp; }

            else if(!mainQueue.Head()->HasRightChild()){
                
                mainQueue.Head()->right = temp;
                mainQueue.Dequeue();    
            }
        }
    );
}


// Copy constructor
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk<Data>& otherTree){

    if(otherTree.size != 0){ root = new NodeLnk(otherTree.Root()); }
    size = otherTree.size;
}


// Move constructor
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk<Data>&& otherTree) noexcept{

    std::swap(otherTree.size, size);
    std::swap(otherTree.root, root);
}


// Destructor
template <typename Data>
BinaryTreeLnk<Data>::~BinaryTreeLnk(){ delete this->root; }


// Copy assignment
template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator = (const BinaryTreeLnk<Data>& otherTree){

    Clear();

    BinaryTreeLnk<Data>* temp = new BinaryTreeLnk(otherTree);

    std::swap(root, temp->root);
    std::swap(size, temp->size);

    delete temp;
    return (*this);
}


// Move assignment
template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator = (BinaryTreeLnk<Data>&& otherTree) noexcept{

    std::swap(root, otherTree.root);
    std::swap(size, otherTree.size);

    return (*this);
}


// Operator ==
template <typename Data>
bool BinaryTreeLnk<Data>::operator == (const BinaryTreeLnk<Data>& otherTree) const noexcept{

    if(this->size == 0 && otherTree.size == 0){ return true; }
    if(this->size == 0 && otherTree.size != 0){ return false; }
    if(this->Root() == otherTree.Root()){ return true; }
    return false;
}


// Operator !=
template <typename Data>
bool BinaryTreeLnk<Data>::operator != (const BinaryTreeLnk<Data>& otherTree) const noexcept{

    return !((*this) == otherTree);
}


// Override function Root (Non-Mutable version)
template <typename Data>
const BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::Root() const{
    
    if(size == 0){ throw std::length_error("Error: Tree is Empty!"); }
    return *root;
}


// Override function Root (Mutable version)
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::Root(){
    
    if(size == 0){ throw std::length_error("Error: Tree is Empty!"); }
    return *root;
}


// Override function Clear
template <typename Data>
void BinaryTreeLnk<Data>::Clear() noexcept{
    
    delete root;
    root = nullptr;
    size = 0;
}

/* ************************************************************************** */

}