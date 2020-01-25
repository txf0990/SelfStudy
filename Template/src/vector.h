#include <iostream>

namespace tutorial {
  template<typename T>
  class vector {
    public:
      vector() {
        _array = new T[4];
      }
      vector(int num, T data = T()) : vector() {
        if (num > 4) {
          allocateNew(num);
        }
        for(int i = 0; i < num; i++) {
          _array[i] = data;
        };
        _size = num;
      }
      ~vector() {
        delete []_array;
      }
      typedef T* iterator;
      int size() const;
      T front() const;
      T back() const;
      void push_back(const T& data);
      void pop_back();
      
      iterator begin();
      iterator end();
      
      vector& operator= (const vector<T>& v);
      T& operator[](int i);
      const T& operator[](int i) const;

    private:
      int _size = 0;
      int _cap = 4;
      T* _array;

      void allocateNew(int newSize);
  };

  template<typename T> int vector<T>::size()  const{
    return _size;
  }
  template<typename T> T& vector<T>::operator[](int i) {
    return _array[i];
  }
  template<typename T> const T& vector<T>::operator[](int i)  const{
    return _array[i];
  }
  template<typename T> vector<T>& vector<T>::operator=(const vector<T>& v) {
    if (v.size() > _size) {
      allocateNew(v.size());
    }
    for(int i = 0; i < v.size(); i++) {
      _array[i] = v[i];
    }
    _size = v.size();

    return *this;
  }
  template<typename T> void vector<T>::allocateNew(int newSize) {
    while (_cap <= newSize) {
      _cap *= 2;
    }
    T* oldArray = _array;
    _array = new T[_cap];
    for(int i = 0; i < _size; i++) {
      _array[i] = oldArray[i];
    }
    delete []oldArray;
  }

  template<typename T> T vector<T>::front() const{
    if (_size == 0) {
      cout << "size == 0" << endl; 
      return T();
    } else {
      return _array[0];
    }
  }

  template<typename T> T vector<T>::back() const{
    if (_size == 0) {
      cout << "size == 0" << endl; 
      return T();
    } else {
      return _array[_size - 1];
    }
  }

  template<typename T> void vector<T>::push_back(const T& data){
    if (_size == _cap) allocateNew(_size + 1);
    _array[_size] = data;
    _size++;
  }
  template<typename T> void vector<T>::pop_back(){
    if (_size == 0) {cout << "size == 0" << endl;}
    _size--;
  }
  template<typename T> typename vector<T>::iterator vector<T>::begin(){
    return _array;
  }
  template<typename T> typename vector<T>::iterator vector<T>::end(){
    return _array + _size;
  }
}
