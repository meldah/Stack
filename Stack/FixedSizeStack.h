#pragma once

///
/// An implementation of a FILO stack
///

template <typename TYPE>
class FixedSizeStack {
private:
    TYPE* pData;       /// Pointer to the stack's contents
    size_t BufferSize; /// Size of the allocated buffer
    size_t Size;       /// Number of elements currently stored in the array

public:

    FixedSizeStack(size_t Size)
    {
        ZeroVariables();
        pData = new TYPE[Size];
        BufferSize = Size;
    }

    ~FixedSizeStack()
    {
        Destroy();
    }

    FixedSizeStack(const FixedSizeStack & Other)
    {
        ZeroVariables();
        CopyFrom(Other);
    }

    FixedSizeStack& operator=(const FixedSizeStack & Other)
    {
        if (this != &Other)
        {
            Destroy();
            CopyFrom(Other);
        }

        return *this;
    }


    void Push(const TYPE & Element)
    {
        if (Size >= BufferSize)
            throw std::exception();

        pData[Size++] = Element;
    }

    bool Pop(TYPE& Element)
    {
        if (Size > 0)
        {
            Element = pData[--Size];
            return true;
        }

        return false;
    }

    void Pop()
    {
        if (Size > 0)
            --Size;
    }

    TYPE& Peek()
    {
        if (Size == 0)
            throw std::exception();

        return pData[Size - 1];
    }

    const TYPE& Peek() const
    {
        if (Size == 0)
            throw std::exception();

        return pData[Size - 1];
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
        return BufferSize;
    }

    bool IsEmpty() const
    {
        return Size == 0;
    }

private:
    void ZeroVariables()
    {
        pData = nullptr;
        BufferSize = 0;
        Size = 0;
    }

    void Destroy()
    {
        delete[] pData;
        ZeroVariables();
    }


    void CopyFrom(FixedSizeStack const & Other)
    {
        if (Other.IsEmpty())
            return;

        pData = new TYPE[Other.BufferSize];
        BufferSize = Other.BufferSize;
        Size = Other.Size;

        for (size_t i = 0; i < Size; i++)
            pData[i] = Other.pData[i];
    }

};