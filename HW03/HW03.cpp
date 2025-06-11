#include <iostream>
#include <algorithm> // sort를 위한 헤더
using namespace std;

template <typename T>
class SimpleVector {
private:
    T* data;
    int _size;
    int _capacity;

public:
    // 기본 생성자
    SimpleVector() : _size(0), _capacity(10) {
        data = new T[_capacity]; // 지정된 크기의 동적 배열 생성
    }

    // 사용자 정의 생성자
    SimpleVector(int capacity) : _size(0), _capacity(capacity) {
        data = new T[_capacity];
    }

    // 복사 생성자
    SimpleVector(const SimpleVector& other)
        : _size(other._size), _capacity(other._capacity) {
        data = new T[_capacity];
        for (int i = 0; i < _size; ++i) {
            data[i] = other.data[i];
        }
    }

    // 소멸자
    ~SimpleVector() {
        delete[] data;
    }

    // push_back (공간 부족 시 +5 크기로 확장)
    void push_back(const T& value) {
        if (_size >= _capacity) {
            resize(_capacity + 5);
        }
        data[_size++] = value;
    }

    // pop_back
    void pop_back() {
        if (_size > 0) {
            --_size;
        }
    }

    // 현재 원소 개수 반환
    int size() const {
        return _size;
    }

    // 현재 배열 크기 반환
    int capacity() const {
        return _capacity;
    }

    // 배열처럼 인덱스로 접근 가능하도록
    T& operator[](int index) {
        return data[index];
    }

    // resize 기능
    void resize(int new_capacity) {
        if (new_capacity <= _capacity) return;

        T* new_data = new T[new_capacity];
        for (int i = 0; i < _size; ++i) {
            new_data[i] = data[i];
        }

        delete[] data;
        data = new_data;
        _capacity = new_capacity;
    }

    // STL sort 활용한 정렬 함수
    void sortData() {
        std::sort(data, data + _size);
    }
};
