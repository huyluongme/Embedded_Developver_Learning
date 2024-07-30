#ifndef DOUBLY_LINKED_LISH_EXCEPTIONS_H
#define DOUBLY_LINKED_LISH_EXCEPTIONS_H

#include <exception>
#include <string>

class ListIsEmpty : public std::exception {
public:
    const char* what() const noexcept override {
        return "List is empty.";
    }
};

class TargetValueIsNotExist : public std::exception {
public:
    const char* what() const noexcept override {
        return "Target value is not exist.";
    }
};

class ItemNotExist : public std::exception {
public:
    const char* what() const noexcept override {
        return "Item isn't exist.";
    }
};

class IDInvalid : public std::exception {
public:
    const char* what() const noexcept override {
        return "ID invalid.";
    }
};

#endif