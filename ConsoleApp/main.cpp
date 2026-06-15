#include <format>
#include <initializer_list>
#include <memory>
#include <vector>
#include <cstdint>
#include <iostream>
//using namespace std::string_literals;


//REQUIRE(data == tree->data());
//REQUIRE((bool)tree->left() == has_left);
//REQUIRE((bool)tree->right() == has_right);
//tree->insert(*data_iter);


// The tests below require an implementation of an iterator.
// You can get more details here: http://www.cplusplus.com/reference/iterator/

namespace binary_search_tree {
    template <typename T>
    class binary_tree
    {
    public:
        binary_tree();
        //binary_tree(const std::initializer_list<T>& items);
        std::shared_ptr<binary_tree> left() const;
        std::shared_ptr<binary_tree> right() const;
        void insert(T element);
    private:
        T m_data{};
        std::shared_ptr<binary_tree> m_left{};
        std::shared_ptr<binary_tree> m_right{};
    };

    template<typename T>
    binary_tree<T>::binary_tree() : m_data{}, m_left{ nullptr }, m_right{ nullptr }
    {}

    template<typename T>
    std::shared_ptr<binary_tree<T>> binary_tree<T>::left() const
    {
        return std::shared_ptr<binary_tree>();
    }
    template<typename T>
    std::shared_ptr<binary_tree<T>> binary_tree<T>::right() const
    {
        return std::shared_ptr<binary_tree>();
    }
    template<typename T>
    void binary_tree<T>::insert(T element) {
        std::cout << "Inserting " << element << '\n';
    }
}  // namespace binary_search_tree


namespace {
    template <typename T>
    using tree_ptr = typename std::unique_ptr<binary_search_tree::binary_tree<T>>;

    template <typename T>
    static tree_ptr<T> make_tree(const std::vector<T>& data) {
        if (data.empty()) return tree_ptr<T>(nullptr);
        auto data_iter = data.begin();
        auto tree = tree_ptr<T>(new binary_search_tree::binary_tree<T>(*data_iter));
        ++data_iter;
        for (; data_iter != data.end(); ++data_iter) {
            tree->insert(*data_iter);
        }
        return tree;
    }
}

int main() {
    //auto tp = tree_ptr<uint32_t>(std::make_unique<binary_search_tree::binary_tree<uint32_t>>(binary_search_tree::binary_tree<uint32_t>{}));
    //auto tested = make_tree<uint32_t>({ 4, 2, 6, 1, 3, 5, 7 });
    //binary_search_tree::binary_tree<uint32_t> t({ 4, 2, 6, 1, 3, 5, 7 });

    auto tp = tree_ptr<uint32_t>(std::make_unique<binary_search_tree::binary_tree<uint32_t>>(binary_search_tree::binary_tree<uint32_t>{}));
    for (int i{ 0 }; i < 5; ++i) {
        tp->insert(i + 1);
    }

    return 0;
}