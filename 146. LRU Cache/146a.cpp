const int ZERO = []() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;

}();


class LRUCache {

private:

    int capacity;

    unordered_map<int, int> keyToValue;

    unordered_map<int, list<int>::iterator> keyToIterator;

    list<int> order; // хронит порядок ключей

public:

    LRUCache(int capacity) : capacity(capacity) {}


    int get(int key) {

        auto it = keyToValue.find(key);

        if (it == keyToValue.end()) {return -1; }

        auto listIt = keyToIterator[key];

        assert(listIt != order.end());

        if (listIt != order.begin()) {

            order.erase(listIt);            
            order.push_front(key);
            
            keyToIterator[key] = order.begin();

        }
        
        return it->second;
    }


    void put(int key, int value) {

        auto it = keyToValue.find(key);

        if (it != keyToValue.end()) { // еслю ключ нашли, то надо его перекинуть в начало списка -- это происходит после if...else 
                            
        auto listIt = keyToIterator[key];

        assert(listIt != order.end());

        if (listIt == order.begin()) {

            keyToValue[key] = value;
            return;

        }

            order.erase(listIt); // удаляем key, который НЕ находится в начале

        }
        else { // it == keyToValue.end() <-->  ключ НЕ нашли

            assert(it == keyToValue.end());

            if ((int)order.size() == capacity) { // ключ НЕ нашли и LRU Cache заполнен максимально, надо освободить место для новой пары {key, value}

                int lastKey = order.back();

                order.pop_back();
                keyToValue.erase(lastKey);
                keyToIterator.erase(lastKey);

            }

        }

        assert((int)order.size() < capacity);

        order.push_front(key);

        keyToIterator[key] = order.begin();
        keyToValue[key] = value;

    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
