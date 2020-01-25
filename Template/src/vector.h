#include <iostream>

namespace tutorial {
  template<typename T>
  class vector {
    public:
      vector() {
        _array = new T[4];
      }
      vector(int num, T data = T()) {
        _array = new T[num];
        _cap = num;
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
      const T& front() const;
      T& front();
      const T& back() const;
      T& back();
      void push_back(const T& data);
      void pop_back();
      
      iterator begin();
      const iterator begin() const;
      iterator end();
      const iterator end() const;
      
      vector& operator= (const vector& v);
      T& operator[](int i);
      const T& operator[](int i) const;

    private:
      int _size = 0;
      int _cap = 4;
      T* _array;
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
    if (v.size() > _cap) {
      delete [] _array;
      _array = new T[v.size()];
      _cap = v.size();
    }
    for(int i = 0; i < v.size(); i++) {
      _array[i] = v[i];
    }
    _size = v.size();

    return *this;
  }

  template<typename T> const T& vector<T>::front() const{
    return _array[0];
  }
  template<typename T> T& vector<T>::front(){
    return _array[0];
  }
  template<typename T> const T& vector<T>::back() const{
    return _array[_size - 1];
  }
  template<typename T> T& vector<T>::back() {
    return _array[_size - 1];
  }

  template<typename T> void vector<T>::push_back(const T& data){
    if (_size == _cap) {
      T* oldArray = _array;
      _cap = _size * 2;
      _array = new int[_cap];
      for(int i = 0; i < _size; i++) {
        _array[i] = oldArray[i];
      }
      delete [] oldArray;
    }
    _array[_size] = data;
    _size++;
  }
  template<typename T> void vector<T>::pop_back(){
    _size--;
  }
  template<typename T> typename vector<T>::iterator vector<T>::begin(){
    return _array;
  }
  template<typename T> const typename vector<T>::iterator vector<T>::begin() const{
    return _array;
  }
  template<typename T> typename vector<T>::iterator vector<T>::end(){
    return _array + _size;
  }
  template<typename T> const typename vector<T>::iterator vector<T>::end() const{
    return _array + _size;
  }
}
