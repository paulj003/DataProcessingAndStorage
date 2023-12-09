#include "InMemory.h"
#include <iostream>


InMemory::InMemory() {
    transaction = false;

    std::cout << "Starting in-memory database" << std::endl;
    std::cout << "---------------------------" << std::endl;
}


void InMemory::begin_transaction() {
    transaction = true;

    std::cout << "Starting a new transaction." << std::endl;
}


void InMemory::put(std::string key, int value) {
    try {
        if (!transaction)
            throw -1;

        if (temporary.count(key) == 1) {
            temporary[key] = value;

            std::cout << "Insertion of Key: " << key << " has been updated to Value: " << value << " and is pending." << std::endl;
        }
        else {
            temporary[key] = value;

            std::cout << "Insertion of Key: " << key << " and Value: " << value << " is now pending." << std::endl;
        }
    }
    catch (int e) {
        std::cout << "An exception occurred: Tried to do an insertion but a transaction is not in progress." << std::endl;
        exit(EXIT_FAILURE);
    }
}


int InMemory::get(std:: string key) {
    
    if (memory.count(key) == 0) {
        std::cout << "Value of Key: " << key << " is NULL" << std::endl;
        std::cout << "     The transaction may not have been committed or an entry with that key may not exist." << std::endl;

        return NULL;
    }

    std::cout << "Value of Key: " << key << " is " << memory[key] << std::endl;

    return memory[key];
}


void InMemory::commit() {
    try {
        if (!transaction)
            throw -1;

        for (auto i : temporary) {
            memory[i.first] = i.second;
        }

        temporary.clear();

        transaction = false;

        std::cout << "The open transaction has been committed." << std::endl;
    }
    catch (int e){
        std::cout << "An exception occurred: Tried to commit the transaction but a transaction is not in progress." << std::endl;
        exit(EXIT_FAILURE);
    }
}


void InMemory::rollback() {
    try {
        if (!transaction)
            throw -1;
        
        temporary.clear();

        std::cout << "The open transaction has been rolled back." << std::endl;
    }
    catch (int e) {
        std::cout << "An exception occurred: Tried to rollback the transaction but a transaction is not in progress." << std::endl;
        exit(EXIT_FAILURE);
    }
}


InMemory::~InMemory() {
    std::cout << "---------------------------" << std::endl;
    std::cout << "Ending program execution and deleting in memory database." << std::endl;
}