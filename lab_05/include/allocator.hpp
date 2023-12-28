#include <iostream>
#include <memory>
#include <utility>
#include <deque>

template <typename T, size_t max_count = 500000> //определение шаблонного класса Allocator
class Allocator
{
private:
    std::deque<T> _used_blocks; //контейнер используемый для хранения выделенной памяти
    typename std::deque<T>::iterator _free_blocks; //для отслеживания свободной памяти

public:
    using value_type = T;
    using pointer = T *;
    using const_pointer = const T *;
    using size_type = std::size_t;

    Allocator() : _used_blocks(max_count)
    {
        _free_blocks = _used_blocks.begin();
    }

    ~Allocator() = default;

    T *allocate(size_t n) // выделяет блок памяти размера n
    {
        T *result = nullptr;
        if (_used_blocks.end() != _free_blocks)
        {
            result = &(*_free_blocks);
        }
        else
        {
            std::cout << "allocator: No memory exception :-)" << std::endl;
        }
        return result;
    }

    void deallocate(T *pointer, size_t)
    {
        //итератор на блок памяти, который мы освобождаем
    auto it = std::find(_used_blocks.begin(), _used_blocks.end(), *pointer);

    //если блок найден, он помечается как свободный
    if (it != _used_blocks.end())
    {
        _free_blocks = it;
    }
    else
    {
        std::cout << "allocator: Trying to deallocate memory that was not allocated by this allocator" << std::endl;
    }
    }

    template <typename U, typename... Args>
    void construct(U *p, Args &&...args) //строит объект U 
    {
        new (p) U(std::forward<Args>(args)...);
    }

    void destroy(pointer p) //уничтожает объект
    {
        p->~T();
    }

    template <class U>
    struct rebind //для аллокаторов других типов
    {
        using other = Allocator<U>;
    };
};

template <class T, class U>
constexpr bool operator==(const Allocator<T> &lhs, const Allocator<U> &rhs)
{
    return true;
}

template <typename T, typename U, size_t BLOCK_COUNT>
constexpr bool operator!=(const Allocator<T> &lhs, const Allocator<U> &rhs)
{
    return false;
}
