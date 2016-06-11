#include <iostream>
#include <string>
#include <typeinfo>
#include <utility>
#include <memory>
using namespace std;

template<typename...Args>
struct Data
{

};

template<typename T, typename...Args>
struct Data<T, Args...> : public Data<Args...>
{
public:
    Data(T&& t, Args&&... args):Data<Args...>(std::forward<Args>(args)...),m_value(t){}
    T m_value;
    typedef T TYPE;
};

template <size_t n, typename> struct DataType{};

template <typename T, typename... Ts>
struct DataType<0, Data<T, Ts...>> {
  typedef typename Data<T,Ts...>::TYPE type;
};

template <size_t k, typename T, typename... Ts>
struct DataType<k, Data<T, Ts...>> {
  typedef typename DataType<k - 1, Data<Ts...>>::type type;
};

template <size_t k, typename... Ts>
typename std::enable_if<k == 0, typename DataType<0, Data<Ts...>>::type&>::type
Get(Data<Ts...>& t) {
  return t.m_value;
}

template <size_t k, typename T, typename... Ts>
typename std::enable_if<k != 0, typename DataType<k, Data<T, Ts...>>::type&>::type
Get(Data<T, Ts...>& t) {
  return Get<k - 1>(static_cast<Data<Ts...>&>(t));
}

int main()
{
    Data<double, float, string> d(3.0, 5.0f, "This is a joke");
    cout<<typeid(Data<char, float, string>::TYPE).name()<<endl;
    cout<<typeid(DataType<2,Data<double,float,string>>::type).name()<<endl;
    cout<<Get<2>(d)<<endl;
}
