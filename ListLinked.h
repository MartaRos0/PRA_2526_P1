#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <iostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

using namespace std;

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first;
    int n;

public:
    ListLinked() {
        first = nullptr;
        n = 0;
    }

    ~ListLinked() {
        while (first != nullptr) {
            Node<T>* aux = first->next;
            delete first;
            first = aux;
        }
    }

    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) throw std::out_of_range("Posición inválida");

        Node<T>* nuevo = new Node<T>(e);

        if (pos == 0) {
            nuevo->next = first;
            first = nuevo;
        } else {
            Node<T>* actual = first;
            for (int i = 0; i < pos - 1; ++i) {
                actual = actual->next;
            }
            nuevo->next = actual->next;
            actual->next = nuevo;
        }

        n++;
    }

    T remove(int pos) override {
        if (pos < 0 || pos >= n) throw std::out_of_range("Posición inválida");

        Node<T>* borrar;
        T valor;

        if (pos == 0) {
            borrar = first;
            valor = borrar->data;
            first = first->next;
        } else {
            Node<T>* actual = first;
            for (int i = 0; i < pos - 1; ++i) {
                actual = actual->next;
            }
            borrar = actual->next;
            valor = borrar->data;
            actual->next = borrar->next;
        }

        delete borrar;
        n--;
        return valor;
    }

    T get(int pos) const override {
        if (pos < 0 || pos >= n) throw std::out_of_range("Posición inválida");

        Node<T>* actual = first;
        for (int i = 0; i < pos; ++i) {
            actual = actual->next;
        }
        return actual->data;
    }

    int search(T e) const override {
        Node<T>* actual = first;
        int i = 0;
        while (actual != nullptr) {
            if (actual->data == e) return i;
            actual = actual->next;
            i++;
        }
        return -1;
    }

    bool empty() const override {
        return n == 0;
    }

    int size() const override {
        return n;
    }

    T operator[](int pos) {
        if (pos < 0 || pos >= n) throw std::out_of_range("Índice fuera de rango");

        Node<T>* actual = first;
        for (int i = 0; i < pos; ++i) {
            actual = actual->next;
        }
        return actual->data;
    }

    friend std::ostream& operator<<(std::ostream& out, const ListLinked<T>& list) {
        Node<T>* actual = list.first;
        while (actual != nullptr) {
            out << actual->data << " ";
            actual = actual->next;
        }
        return out;
    }
};

#endif
