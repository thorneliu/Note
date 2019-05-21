# std::set with user defined type, how to ensure no duplicates

Since there is no duplicates in std::set<T>, we need to define our own operator in user defined types for duplicate check
when we insert element into container.

However, operator==(const T& rhs) does not work because

> operator== is not used by std::set. Elements a and b are considered equal iff !(a < b) && !(b < a)
>

So we need to define our specific operator<

