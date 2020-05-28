#pragma once

#include <exception>

template <typename TYPE>
class LinkedStack {

    class Box {
	public:
		TYPE Data;
		Box* pNext;
        
        Box(const TYPE& Data, Box* pNext = NULL)
            : Data(Data), pNext(pNext)
        {
        }
	};

private:
    Box* pTop;   /// Pointer to the top of the stack
    size_t Size; /// Number of elements in the stack

public:

    LinkedStack()
    {
        ZeroVariables();
    }

    ~LinkedStack()
    {
        Destroy();
    }


    LinkedStack(LinkedStack const & Other)
    {
        ZeroVariables();
        CopyFrom(Other);
    }

	LinkedStack& operator=(const LinkedStack & Other)
    {
        if (this != &Other)
        {
            Destroy();
            CopyFrom(Other);
        }

        return *this;
    }

public:
   
    void Push(const TYPE & Element)
    {
        pTop = new Box(Element, pTop);
        ++Size;
    }

    bool Pop(TYPE& Element)
    {
        if (Size == 0)
            return false;

        Element = pTop->Data;

        Pop();

        return true;
    }


    void Pop()
    {
        if (pTop)
        {
            Box* pOld = pTop;
            pTop = pTop->pNext;
            delete pOld;
            --Size;
        }
    }


    TYPE& Peek()
    {
        if (Size == 0)
            throw std::exception();

        return pTop->Data;
    }

    const TYPE& Peek() const
    {
        if (Size == 0)
            throw std::exception();

        return pTop->Data;
    }


    void Clear()
    {
        Destroy();
    }


    size_t GetSize() const
    {
        return Size;
    }
    
    bool IsEmpty() const
    {
        return Size == 0;
    }

private:

    void ZeroVariables()
    {
        pTop = 0;
        Size = 0;
    }

    void Destroy()
    {
        Box* p;

        while (pTop)
        {
            p = pTop;
            pTop = pTop->pNext;
            delete p;
        }

        ZeroVariables();
    }

    void CopyFrom(const LinkedStack & Other)
    {
        if (Other.IsEmpty())
            return;

        Box *ours, *theirs;

        try
        {
            pTop = new Box(Other.pTop->Data);

            ours = pTop;
            theirs = Other.pTop->pNext;

            while (theirs)
            {
                ours->pNext = new Box(theirs->Data);
                ours = ours->pNext;
                theirs = theirs->pNext;
            }

            Size = Other.Size;
        }
        catch (std::bad_alloc&)
        {
            Destroy();
            throw;
        }
    }

};
