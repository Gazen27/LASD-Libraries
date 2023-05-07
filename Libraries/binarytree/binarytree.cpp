
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
bool BinaryTree<Data>::Node::operator != (const Node& otherNode) const noexcept{

    return !(*this == otherNode);
}

/* ************************************************************************** */

}
