#include <bits/stdc++.h>

using namespace std;
class Max_Heap
{
private:
    int capacity = 10;
    int size = 0;
    int *items;

    int get_left_child_index(int parent_index) { return 2 * parent_index + 1; }
    int get_right_child_index(int parent_index) { return 2 * parent_index + 2; }
    int get_parent_index(int child_index) { return (child_index - 1) / 2; }

    bool has_left_child(int index) { return get_left_child_index(index) < size; }
    bool has_right_child(int index) { return get_right_child_index(index) < size; }
    bool has_parent(int index) { return get_parent_index(index) >= 0; }

    int left_child(int index) { return items[get_left_child_index(index)]; }
    int right_child(int index) { return items[get_right_child_index(index)]; }
    int parent(int index) { return items[get_parent_index(index)]; }

    void ensure_extra_capacity()
    {
        if (size == capacity)
        {
            capacity *= 2;
            int *temp = new int[capacity];
            for (int i = 0; i < size; i++)
                temp[i] = items[i];
            items = temp;
        }
    }

    void swap(int index_one, int index_two)
    {
        int temp = items[index_one];
        items[index_one] = items[index_two];
        items[index_two] = temp;
    }

    void heapify_up()
    {
        int index = size - 1;
        while (has_parent(index) && parent(index) < items[index])
        {
            swap(get_parent_index(index), index);
            index = get_parent_index(index);
        }
    }

    void heapify_down()
    {
        int index = 0;
        while (has_left_child(index))
        {
            int smaller_child_index = get_left_child_index(index);
            if (has_right_child(index) && right_child(index) > left_child(index))
                smaller_child_index = get_right_child_index(index);

            if (items[index] > items[smaller_child_index])
                break;
            else
                swap(index, smaller_child_index);
            index = smaller_child_index;
        }
    }

public:
    Max_Heap()
    {
        items = new int[capacity];
    }

    int get_size()
    {
        return size;
    }

    int top()
    {
        if (size == 0)
            throw out_of_range("array is empty");
        return items[0];
    }

    int pop()
    {
        if (size == 0)
            throw out_of_range("array is empty");

        int item = items[0];
        items[0] = items[size - 1];
        size--;
        heapify_down();
        return item;
    }

    void add(int item)
    {
        ensure_extra_capacity();
        items[size] = item;
        size++;
        heapify_up();
    }

    void print_heap()
    {
        for (int i = 0; i < size; i++)
            cout << items[i] << " ";

        cout << "\n";
    }
};

int main()
{
    Max_Heap mh;
    mh.add(3);
    mh.add(2);
    mh.add(15);
    mh.add(5);
    mh.add(4);
    mh.add(45);
    mh.add(66);
    mh.add(13);
    mh.add(12);
    mh.add(7);
    mh.add(8);
    mh.print_heap();
    while (mh.get_size() > 0)
        try
        {
            mh.pop();
        }
        catch (std::exception &e)
        {
            cout << e.what();
        }
    return 0;
}