#include <iostream>
#include <assert.h>
using namespace std;

template<int i>
struct exp2
{
    enum
    {
        value = exp2<i/2>::value,
        recur = i/2 == 0 ? exp2<i/2>::recur : exp2<i/2>::recur + 1
    };
};

template <>
struct exp2<0>
{
    enum
    {
        value = 1,
        recur = 0
    };
};

template<int i>
struct pow10
{
    enum
    {
        value = 10*pow10<i-1>::value
    };
};

template <>
struct pow10<0>
{
    enum
    {
        value = 1
    };
};

template<int i>
class get_bits
{
    public:
    enum
    {
        value = 2*get_bits<i/2>::value,
        rem = i % value,
        exp = exp2<value>::recur,
        bit_num = pow10< exp >::value + get_bits<rem>::bit_num
        
    };
};

template<>
class get_bits<1>
{
    public:
    enum
    {
        value = 1,
        rem = 0,
        exp = 0,
        bit_num = 1
    };
};

template<>
class get_bits<0>
{
    public:
    enum
    {
        value = 0,
        rem = 0,
        exp = 0,
        bit_num = 0
    };
};

template <int val>
struct Bin
{
    enum { value = 10 * Bin<(val >> 1)>::value + (val & 1) };
};

template <>
struct Bin<0>
{
    enum { value = 0 };
};

#define num 9
int main()
{
    static_assert(get_bits<num>::bit_num == 1001, "This is failure");
    static_assert(Bin<num>::value == 1001, "This is failure");

}

