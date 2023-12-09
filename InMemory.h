#include <string>
#include <map>


class InMemory {
    bool transaction;
    std::map<std::string, int> temporary;
    std::map<std::string, int> memory;

    public:
        InMemory();
        void begin_transaction();
        void put(std::string key, int value);
        int get(std:: string key);
        void commit();
        void rollback();
        ~InMemory();
};