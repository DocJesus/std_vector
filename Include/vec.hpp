#include <iostream>
#include <iterator>
#include <vector>


template<typename T>
class vec
{
    private:
        T* data;
        int memory_size;
        int elem_size;
    public:
        vec()
        {
            this->data = new T[0];
            this->memory_size = 0;
            this->elem_size = 0;
        }
        ~vec()
        {
            delete this->data;
        }

        void push_back(const T &_elem)
        {
            bool need_realloc = this->require_expansion(this->get_elem_size() + 1);
            if (need_realloc == true)
            {
                this->expand();
            }
            this->place_elem(_elem, this->get_elem_size());
            this->elem_size = this->get_elem_size() + 1;
        }

        void reverse()
        {
            int i = 0;
            T tmp;

            while (i <= (this->get_elem_size() / 2) - 1)
            {
                tmp = this->data[i];
                this->data[i] = this->data[this->get_elem_size() - 1 - i];
                this->data[this->get_elem_size() - 1 - i] = tmp;
                i++;
            }
        }

        constexpr int get_memory_size() {return memory_size; }
        constexpr int get_elem_size() {return elem_size; }

        constexpr T* begin()
        {
            return &this->data[0];
        }

        constexpr T* end()
        {
            return &this->data[this->elem_size];
        }

        constexpr T& operator[](int _pos)
        {
            return this->data[_pos];
        }

    private:
        constexpr bool require_expansion(const int &_size)
        {
            if (_size > this->get_memory_size())
                return true;
            return false;
        }

        void expand()
        {
            T* new_data = new T[(this->get_memory_size() + 1) * 2];

            int counter = 0;
            while (counter < this->get_elem_size())
            {
                new_data[counter] = this->data[counter];
                counter++;
            }

            delete this->data;
            this->data = new_data;
            this->memory_size = (this->get_memory_size() + 1) * 2;
        }

        void place_elem(const T &_elem, int _pos)
        {
            this->data[_pos] = _elem;
        }

};
