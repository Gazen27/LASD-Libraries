
namespace lasd {

/* ************************************************************************** */

////////////////////////////////////////////////////////////////////// NODE

// Operator ==
template <typename Data>
bool BinaryTree<Data>::Node::operator == (const Node& otherNode) const noexcept{

    if(this->key != otherNode.key){ return false; }

    // Has no child
    if(!this->HasLeftChild() && !this->HasRightChild()){
        if(otherNode.HasLeftChild() || otherNode.HasRightChild()){ return false; }
        return true;
    }

    // Has Left Child only
    if(this->HasLeftChild() && !this->HasRightChild()){
        if(!otherNode.HasLeftChild() || otherNode.HasRightChild()){ return false; }
        if(this->LeftChild() != otherNode.LeftChild()){ return false; }
        return true;
    }

    // Has Right Child only
    if(!this->HasLeftChild() && this->HasRightChild()){
        if(otherNode.HasLeftChild() || !otherNode.HasRightChild()){ return false; }
        if(this->RightChild() != otherNode.RightChild()){ return false; }
        return true;
    }
    
    // Has both Left and Right Child
    if(this->HasLeftChild() && this->HasRightChild()){
        if(!otherNode.HasLeftChild() || !otherNode.HasRightChild()){ return false; }
        if(this->LeftChild() != otherNode.LeftChild()){ return false; }
        if(this->RightChild() != otherNode.RightChild()){ return false; }
        return true;
    }
}


// Operator !=
template <typename Data>
bool BinaryTree<Data>::Node::operator != (const Node& otherNode) const noexcept{ return !(*this == otherNode); }


// Defining function Element
template <typename Data>
Data& BinaryTree<Data>::Node::Element() const noexcept{ return this->key; }


////////////////////////////////////////////////////////////////////// BINARYTREE

// Operator ==
template <typename Data>
bool BinaryTree<Data>::operator == (const BinaryTree<Data>& otherTree) const noexcept{

    if(this->Root() == otherTree.Root()){ return true; }
    return false;
}


// Operator !=
template <typename Data>
bool BinaryTree<Data>::operator != (const BinaryTree<Data>& otherTree) const noexcept{ return !(*this == otherTree); }


// Override function Fold
template <typename Data>
void BinaryTree<Data>::Fold(FoldFunctor f, void* acc) const{ PreOrderMappableContainer<Data>::Fold(f, acc); }


// Override function Map
template <typename Data>
void BinaryTree<Data>::Map(MapFunctor f) const{ PreOrderMappableContainer<Data>::Map(f); }


// Override function PreOrderMap
template <typename Data>
void BinaryTree<Data>::PreOrderMap(MapFunctor f) const{ PreOrderMap(f, Root()); }


// Override function PostOrderMap
template <typename Data>
void BinaryTree<Data>::PostOrderMap(MapFunctor f) const{ PostOrderMap(f, Root()); }


// Override function InOrderMap
template <typename Data>
void BinaryTree<Data>::InOrderMap(MapFunctor f) const{ InOrderMap(f, Root()); }


// Override function BreadthMap
template <typename Data>
void BinaryTree<Data>::BreadthMap(MapFunctor f) const{ BreadthMap(f, Root()); }


// Auxiliary PreOrderMap
template <typename Data>
void BinaryTree<Data>::PreOrderMap(MapFunctor f, Node& start){ /*/////////////////////////////// TODO*/ }

// Auxiliary PostOrderMap
template <typename Data>
void BinaryTree<Data>::PostOrderMap(MapFunctor f, Node& start){ /*/////////////////////////////// TODO*/ }


// Auxiliary InOrderMap
template <typename Data>
void BinaryTree<Data>::InOrderMap(MapFunctor f, Node& start){ /*/////////////////////////////// TODO*/ }


// Auxiliary BreadthMap
template <typename Data>
void BinaryTree<Data>::BreadthMap(MapFunctor f, Node& start){ /*/////////////////////////////// TODO*/ }


////////////////////////////////////////////////////////////////////// MUTABLEBINARYTREE



/* ************************************************************************** */

}
