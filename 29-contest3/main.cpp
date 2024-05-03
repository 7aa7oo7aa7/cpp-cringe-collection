#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <type_traits>

template <class T>
void advance(T it, int n) {
    for (int i = 0; i < n; ++i) {
        ++it;
    }
    // it += n;
}

template <class T>
void Advance(T it, int n) {
    if constexpr(std::is_same_v<std::random_access_iterator_tag, std::iterator_traits<T>::iterator_category>) {
        it += n;
    } else {
        for (int i = 0; i < n; ++i) {
            ++it;
        }
    }
}

template <class T, class = void>
struct kIsDereferenceableV : public std::false_type {};

template <class T>
struct kIsDereferenceableV<T, std::void_t<decltype(*std::declval<T>())>> : public std::true_type {};

template <class T, class Equal = decltype(std::declval<T>() == std::declval<T>())>
std::is_same<Equal, bool> IsEqualityComparableTest(int);

template <class T>
std::false_type IsEqualityComparableTest(long);

template <class T>
struct IsEqualityComparable : decltype(IsEqualityComparableTest<T>(0)) {};

template <class T>
constexpr bool kIsEqualityComparableV = IsEqualityComparable::value;

template <class Key, class Value>
class LRUMap {
public:
    Value Get(Key key) {
        ++current_time;
        timestamps[key] = current_time;
        return map[key];
    }

    void Insert(Key key, Value value) {
        ++current_time;
        // if size < capacity, insert
        // if size == capacity:
        // find the oldest element
        // replace it with new
        timestamps[key] = current_time;
    }
private:
    std::unordered_map<Key, Value> map;
    std::unordered_map<Key, size_t> timestamps;
    size_t current_time{0};
};

int main() {

    std::vector<int>::iterator it_vector;
    std::list<int>::iterator it_list;

    const int n = 42;
    
    advance(it_vector, n);
    advance(it_list, n);

    return 0;
}
