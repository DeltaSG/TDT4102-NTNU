#include "LinkedList.h"

namespace LinkedList {
std::ostream& operator<<(std::ostream& os, const Node & node)
{
    os << node.getValue() << std::endl;
    return os;
}

Node* LinkedList::insert(Node* pos, const std::string & value)
{

}
Node* LinkedList::remove(Node* pos)
{

}
Node* LinkedList::find(const std::string& value)
{

}
void LinkedList::remove(const std::string& value)
{

}
std::ostream& operator<<(std::ostream & os , const LinkedList& list)
{

    return os;
}
}