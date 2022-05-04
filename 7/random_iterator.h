#pragma once

#include <iterator>

template<class T>
class Iterator : std::iterator<std::random_access_iterator_tag, T> {
private:
    T *value;
public:
    //// Определяем типы для удобства ////
    typedef std::random_access_iterator_tag iterator_category;
    typedef T value_type;
    typedef T *pointer;
    typedef T &reference;
    typedef std::ptrdiff_t difference_type;

    //// Конструктор по умолчанию ////
    Iterator() = default;

    //// Конструктор копирования ////
    Iterator(const Iterator<value_type> &iterator) : value(iterator.value) {}

    //// Конструктор с параметрами ////
    explicit Iterator(pointer value) : value(value) {}

    //// Деструктор ////
    ~Iterator() = default;

    //// Метод, возвращающий указательна элемент, к которому есть доступ по итератору ////
    pointer get_value() const {
        return value;
    }

    //// Префиксный инкремент и декремент ////
    Iterator &operator++() {
        value++;
        return *this;
    }

    Iterator &operator--() {
        value--;
        return *this;
    }

    //// Постфиксный инкремент и декремент ////
    Iterator operator++(int) {
        Iterator tmp = *this;
        value++;
        return tmp;
    }

    Iterator operator--(int) {
        Iterator tmp = *this;
        value--;
        return tmp;
    }

    //// Операторы == и != ////
    bool operator==(const Iterator<value_type> &it) {
        return value == it.value;
    }

    bool operator!=(const Iterator<value_type> &it) {
        return value != it.value;
    }

    //// Оператор разыменования (доступ до элемента) ////
    reference operator*() {
        return *value;
    }

    //// ХЗ зачем оно надо, так как выше есть подобная штука, но пусть будет, если что удалю) ////
    pointer operator->() {
        return value;
    }

    //// Присваивание значения ВОТ ЭТО ПРЯМ ВООБЩЕ ХЗ НАДО ИЛИ НЕТ ХАХА////
//    Iterator &operator=(value_type new_value) {
//        value = new_value;
//        return *this;
//    }


    //// Операторы += и -= ////
    Iterator &operator+=(difference_type n) {
        value += n;
        return *this;
    }

    Iterator &operator-=(difference_type n) {
        value -= n;
        return *this;
    }

    //// Арифметические операции + и - ////
    Iterator operator+(difference_type n) {
        Iterator tmp = *this;
        tmp += n;
        return tmp;
    }

    Iterator operator+(const Iterator<value_type> &it) {
        Iterator tmp = *this;
        tmp.value += it.value;
        return tmp;
    }


    Iterator operator-(difference_type n) {
        Iterator tmp = *this;
        tmp -= n;
        return tmp;
    }

    friend difference_type operator-(const Iterator<value_type> &it_1, const Iterator<value_type> &it_2) {
        return it_1.value - it_2.value;
    }

    //// Остальные операторы ////

    bool operator>(const Iterator<value_type> &other_iterator) {
        return value > other_iterator.get_value();
    }

    bool operator<(const Iterator<value_type> &other_iterator) {
        return value < other_iterator.get_value();
    }

    bool operator>=(const Iterator<value_type> &other_iterator) {
        return value >= other_iterator.get_value();
    }

    bool operator<=(const Iterator<value_type> &other_iterator) {
        return value <= other_iterator.get_value();
    }

};



