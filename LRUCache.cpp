#include <deque>
#include <list>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

/*
// deque version: iterator BUG! 
class LRUCache {
public:
    unordered_map<int, deque<pair<int, int>>::iterator> cache;
    int capacity;
    deque<pair<int, int>> dq;

    LRUCache(int _capacity) {
        capacity = _capacity;
    }

    int get(int key) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            int value = it->second->second;
            {
                // BUG CODE SEGMENT
                dq.erase(it->second);
                dq.emplace_back(make_pair(key, value));
            }
            cache[key] = prev(dq.end());
            return value;
        }
        return -1;
    }

    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            {
                // BUG CODE SEGMENT
                dq.erase(it->second);
                dq.emplace_back(make_pair(key, value));
            }
            cache[key] = prev(dq.end());
            return;
        }
        if (cache.size() == capacity) {
            cache.erase(dq.front().first);
            dq.erase(dq.begin());
        }
        dq.emplace_back(make_pair(key, value));
        cache[key] = prev(dq.end());
    }
};
*/

class LRUCache {
public:
    unordered_map<int, list<pair<int, int>>::iterator> cache;
    int capacity;
    list<pair<int, int>> dq;

    LRUCache(int _capacity) {
        capacity = _capacity;
    }

    int get(int key) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            int value = it->second->second;
            {
                // DEQUE BUG CODE SEGMENT
                dq.erase(it->second);
                dq.emplace_back(make_pair(key, value));
            }
            cache[key] = prev(dq.end());
            return value;
        }
        return -1;
    }

    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            {
                // DEQUE BUG CODE SEGMENT
                dq.erase(it->second);
                dq.emplace_back(make_pair(key, value));
            }
            cache[key] = prev(dq.end());
            return;
        }
        if (cache.size() == capacity) {
            cache.erase(dq.front().first);
            dq.erase(dq.begin());
        }
        dq.emplace_back(make_pair(key, value));
        cache[key] = prev(dq.end());
    }
};

int main() {
    LRUCache lru = LRUCache(3);
    // lru.put(1, 1);
    lru.put(2, 2);
    lru.put(3, 3);
    lru.put(4, 4);
    lru.get(4);
    lru.get(3);
    lru.get(2);
    lru.get(1);
    lru.put(5, 5);
    lru.get(1);
    lru.get(2);
    cout << lru.get(3) << endl;
    cout << lru.get(4) << endl;
    cout << lru.get(5) << endl;
}