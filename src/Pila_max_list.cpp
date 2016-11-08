//#include "../include/Pila_max_list.h"


//----------------------------------------------------------------------
//                        PILA MAX
//---------------------------------------------------------------------

template <class T>
PilaMax<T>::PilaMax(T e){
  this->list(e);
  this->maximo = e;
}


template <class T>
PilaMax<T>::PilaMax(PilaMax<T>& p){
  this->list = p.list;
  this->maximo = p.maximo;
}

template <class T>
PilaMax<T>::~PilaMax(){
  this->~list();
}

template <class T>
void PilaMax<T>::push(T e){
  this->pila.push(e);
  if(e>this->maximo){
    this->maximo = e;
  }
}

template <class T>
T PilaMax<T>::pop(){
  if (this->list.getLast() == maximo){
    this->maximo = 0;
    for(int i = 0; i < this->list.size(); i++){
      if(this->list.at(i) > maximo){
	maximo = this->list.at(i);
      }
    }
  }

  T to_ret = this->list.getLast();
  this->list.remove(this->size());
  return to_ret;
}


template <class T>
int PilaMax<T>::size(){
  return this->list.size();
}

template <class T>
T PilaMax<T>::getMax(){
  return this->maximo;
}

template <class T>
PilaMax<T>& PilaMax<T>::operator=(PilaMax<T>& p){
  if( this!= p){
    this->list = p.list;
    this->maximo = p.maximo;
  }

  return this;
}

template <class T>
bool PilaMax<T>::operator==(PilaMax<T>& p){
  if(this->maximo == p.maximo){
    bool equal = true;
    for(int i = 0; i < this->list.size() && true; ++i){
      if(this->list.at(i) != p.list.at(i)){
	equal = false;
      }
    }

    return equal;
  }else return false;
}

template <class T>
bool PilaMax<T>::operator!=(PilaMax<T>& p){
  return !(this == p);
}
