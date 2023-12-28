    #include <memory>

template <typename T, class Allocator = std::allocator<T>>
class Vector
{
private:
    T *_array;
    size_t _size;
    size_t _capacity;
    Allocator _allocator;
    using alloc_traits = std::allocator_traits<Allocator>;

public:
    using value_type = T;

    class Iterator
    {

    private:
        value_type *_link;

    public:
        friend Vector;

        using difference_type = int;
        using value_type = Vector::value_type;
        using reference = Vector::value_type &;
        using pointer = Vector::value_type *;
        using iterator_category = std::forward_iterator_tag; // std::random_access_iterator_tag;

        Iterator() : _link(nullptr)
        {
        }

        Iterator(pointer p) : _link(p)
        {
        }

        ~Iterator() = default;

        reference operator*()
        {
            return *_link;
        }

        pointer operator->()
        {
            return _link;
        }

        Iterator &operator++()
        {
            _link += 1;
            return *this;
        }

        Iterator operator++(int)
        {
            Iterator new_one = *this;
            _link += 1;
            return new_one;
        }

        Iterator &operator--()
        {
            _link -= 1;
            return *this;
        }

        Iterator operator--(int)
        {
            Iterator new_one = *this;
            _link -= 1;
            return new_one;
        }

        Iterator operator+(const int &cnst) const
        {
            Iterator new_one = *this;
            new_one._link += cnst;
            return new_one;
        }

        Iterator &operator+=(const int &cnst)
        {
            _link = _link + cnst;
            return *this;
        }

        Iterator operator-(const int &cnst) const
        {
            Iterator new_one = *this;
            new_one._link -= cnst;
            return new_one;
        }

        Iterator &operator-=(const int &cnst)
        {
            _link = _link - cnst;
            return *this;
        }

        bool operator==(const Iterator &iter) const
        {
            return (this->_link == iter._link);
        }

        bool operator!=(const Iterator &iter) const
        {
            return (this->_link != iter._link);
        }
    };

    class Const_Iterator
    {

    private:
        const value_type *_link;

    public:
        friend Vector;

        using difference_type = int; // в чем меряем расстояние
        using value_type = const Vector::value_type;
        using reference = const Vector::value_type &;
        using pointer = const Vector::value_type *;
        using iterator_category = std::forward_iterator_tag; // std::random_access_iterator_tag;

        Const_Iterator()
        {
            _link = nullptr;
        }

        Const_Iterator(pointer p) : _link(p)
        {
        }

        ~Const_Iterator() = default;

        reference operator*()
        {
            return *_link;
        }

        pointer operator->()
        {
            return _link;
        }

        Const_Iterator &operator++()
        {
            _link += 1;
            return *this;
        }

        Const_Iterator operator++(int)
        {
            Const_Iterator new_one = *this;
            _link += 1;
            return new_one;
        }

        Const_Iterator &operator--()
        {
            _link -= 1;
            return *this;
        }

        Const_Iterator operator--(int)
        {
            Const_Iterator new_one = *this;
            _link -= 1;
            return new_one;
        }

        Const_Iterator operator+(const int &cnst) const
        {
            Const_Iterator new_one = *this;
            new_one._link += cnst;
            return new_one;
        }

        Const_Iterator &operator+=(const int &cnst)
        {
            _link = _link + cnst;
            return *this;
        }

        Const_Iterator operator-(const int &cnst) const
        {
            Const_Iterator new_one = *this;
            new_one._link -= cnst;
            return new_one;
        }

        Const_Iterator &operator-=(const int &cnst)
        {
            _link = _link - cnst;
            return *this;
        }

        bool operator==(const Const_Iterator &iter) const
        {
            return (this->_link == iter._link);
        }

        bool operator!=(const Const_Iterator &iter) const
        {
            return (this->_link != iter._link);
        }
    };

    Vector() : _size(0), _capacity(0), _allocator()
    {
    }

    Vector(const size_t &ln, const value_type &elem = T()) : _size(ln), _capacity(ln), _allocator()
    {
        _array = alloc_traits::allocate(_allocator, _size);
        for (size_t i = 0; i < _size; ++i)
        {
            _array[i] = elem;
        }
    }

    Vector(std::initializer_list<value_type> p) : _size(p.size()), _capacity(p.size()), _allocator()
    {
        _array = alloc_traits::allocate(_allocator, _size);
        size_t i = 0;
        for (const value_type &elem : p)
        {
            _array[i++] = elem;
        }
    }

    Vector(const Vector<value_type, Allocator> &other) : _size(other._size), _capacity(other._capacity),
                                                         _allocator(other._allocator)
    {
        _array = alloc_traits::allocate(_allocator, _size);
        for (size_t i = 0; i < _size; ++i)
        {
            _array[i] = other._array[i];
        }
    }

    ~Vector()
    {
        for (size_t i = 0; i < _size; ++i)
        {
            _array[i].~T();
        }
        _capacity = 0;
        alloc_traits::deallocate(_allocator, _array, _size);
        _size = 0;
    }

    void resize(size_t ln)
    {
        if (ln > _capacity)
        {
            value_type *_new_array = alloc_traits::allocate(_allocator, _capacity * 2);
            for (size_t i = 0; i < _size; ++i)
            {
                _new_array[i] = _array[i];
            }
            alloc_traits::deallocate(_allocator, _array, _capacity);
            _capacity *= 2;
            _array = _new_array;
            _size = ln;
        }
        else if (ln < _capacity)
        {
            _size = ln;
        }
    }

    const value_type &operator[](size_t index) const
    {
        return _array[index];
    }

    value_type &operator[](size_t index)
    {
        return _array[index];
    }

    void push_back(const value_type &elem)
    {
        if (_size + 1 > _capacity)
        {
            resize(_size + 1);
            _array[_size - 1] = elem;
        }
        else
        {
            _array[++_size - 1] = elem;
        }
    }

    void pop_back()
    {
        resize(_size - 1);
    }

    Vector &operator=(const Vector<value_type, Allocator> &other)
    {
        _size = other._size;
        _capacity = other._capacity;
        _array = alloc_traits::allocate(_allocator, _size);
        for (size_t i = 0; i < _size; ++i)
        {
            _array[i] = other._array[i];
        }
    }

    Iterator begin() noexcept
    {
        return Iterator(_array);
    }

    Const_Iterator cbegin() const noexcept
    {
        return Const_Iterator(_array);
    }

    Iterator end()
    {
        return Iterator(_array + _size);
    }

    Const_Iterator cend() const
    {
        return Const_Iterator(_array + _size);
    }

    size_t size()
    {
        return _size;
    }

    size_t capacity()
    {
        return _capacity;
    }
};