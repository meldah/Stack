#pragma once

///
/// An implementation of a FILO stack
///

template <typename TYPE, int MAX_SIZE>
class StaticStack {
private:
    TYPE Data[MAX_SIZE]; /// Stores the stack elements
    size_t Size;         /// Number of elements stored in the stack

public:

    StaticStack()
        : Size(0)
    {}

    void Push(const TYPE & Element)
    {
        if (Size >= MAX_SIZE)
            throw std::exception();

        Data[Size++] = Element;
    }

    bool Pop(TYPE& Element)
    {
        if (Size > 0)
        {
            Element = Data[--Size];
            return true;
        }

        return false;
    }

    void Pop()
    {
        if(Size > 0)
            --Size;
    }


    TYPE& Peek()
    {
        if (Size == 0)
            throw std::exception();

        return Data[Size - 1];
    }

    const TYPE& Peek() const
    {
        if (Size == 0)
            throw std::exception();

        return Data[Size - 1];
    }

    void Clear()
    {
        Size = 0;
    }

    size_t GetSize() const
    {
        return Size;
    }


    size_t GetMaxSize() const
    {
        return MAX_SIZE;
    }

    bool IsEmpty() const
    {
        return Size == 0;
    }
};
