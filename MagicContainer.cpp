#include <vector>
#include <cstddef>

template <typename T>
struct Magic
{
    std::vector<T> data;
    std::vector<size_t> index;
    std::vector<size_t> id;

    T& operator[] (size_t i)
    {
        return data[index[i]];
    }

    void push_back(T newData)
    {
        if(index.size()>data.size())
        {
            data.push_back(newData);
        }else{
            index.push_back(index.size());
            data.push_back(newData);
            id.push_back(id.size());
        }
    }

    void pop_back()
    {
        data.pop_back();
    }

    unsigned int size ()
    {
        return index.size();
    }


};


int main()
{
    Magic<int> A;
    for(int i = 0; i<=200 ; i++)
    {
        A.push_back(i);
    }
    A[123] = A[100];
    return A[123];
}
