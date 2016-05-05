#pragma once

#include <vector>
#include <boost/throw_exception.hpp>

namespace raccoon
{

template <typename T>
class Node
{
public:
  
  Node(const T& data, Node<T>* parent = nullptr);
  
  void AddChild(Node<T>* child);
  
  unsigned GetNumChildren()const; 
  
  Node<T>* GetParent()const;
  
  Node<T>* GetChild(unsigned index)const;
  
  T& Data();
  
private:
    
  T m_data;
  Node<T> *m_parent;
  std::vector< Node<T>* > m_children;
  
};

template<typename T>
Node<T>::Node(const T& data, Node<T>* parent):
m_data(data),
m_parent(parent){}

template<typename T>
void Node<T>::AddChild(Node<T>* child){
    m_children.push_back(child);
}

template<typename T>
unsigned Node<T>::GetNumChildren()const{
    return m_children.size();
}

template<typename T>
Node<T>* Node<T>::GetParent()const{
    return m_parent;
}

template<typename T>
Node<T>* Node<T>::GetChild(unsigned index)const{
if(index >= m_children.size()){
    BOOST_THROW_EXCEPTION(std::range_error("Index out of range"));
}

    return m_children[index];
}

template<typename T>
T& Node<T>::Data(){
    return m_data;
}

  
} // namespace raccoon