
#include <climits>

struct Void { Void() = delete; };

template <bool constrain>
concept tif = constrain; //template_if

template <type a, type b>
struct And
{
    a left;
    b right;

    And(): left(), right() {}
    And(const a& left_, const b& right_): left(left_), right(right_) {}
};

template <type T>
struct int_x
{
    T data;

    inline int_x() = default;
    inline int_x(const int_x<T>&) = default;
};



struct int_8 : int_x
<
#if CHAR_BIT >= 8
    signed char
#else
    signed short int
#endif
>{};

struct uint_8 : int_x
<
#if CHAR_BIT >= 8
    unsigned char
#else
    unsigned short int
#endif
>{};
