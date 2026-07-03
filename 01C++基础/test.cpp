// #include <iostream>
// using namespace std;

// int main()
// {
//     cout << "hello world\n" << endl;
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// namespace hehe
// {
//     int rand = 0;
// }

// int main()
// {
//     printf("%p\n", rand);
//     return 0;
// }

// #include <stdio.h>

// int a = 0;

// namespace hehe
// {
//     int a = 2;

//     int Add(int a, int b)
//     {
//         return a + b;
//     }

//     struct Node
//     {
//         int val;
//         Node* next;
//     };
// }

// int main()
// {
//     int a = 1;
//     printf("%d\n", a);
//     // ::域作用限定符（左边什么都没有就去全局找）
//     printf("%d\n", ::a);

//     printf("%d\n", hehe::a);

//     printf("%d\n", hehe::Add(1, 2));

//     struct hehe::Node p;
// }

#include <iostream>
using namespace std;

namespace hehe
{
    int a = 1;
    int b = 2;
}

using hehe::a;

void test01()
{
    cout << a << endl;

    // int x, y;

    // cin >> x >> y;
    // cout << x << y << endl;

    double x = 2.222222;
    
}

// 缺省参数：从右往左连续缺省，从左往右传参

void Fun(int a = 10, int b = 20, int c = 30)
{
    cout << a << " " << b << " " << c << endl;
}

void test02()
{
    Fun();
    Fun(1);
    Fun(1, 2);
    Fun(1, 2, 3);
}

// 引用(传参或者做返回值)

void Swap(int& rx, int& ry)
{
    int tmp = rx;
    rx = ry;
    ry = tmp;
}

void test03()
{
    int a = 10, b = 20;
    printf("%d %d\n", a, b);

    Swap(a, b);

    printf("%d %d\n", a, b);
    
    getchar();
}

void test04()
{
    const int a = 10;
    //int& ra = a;
    // 权限放大不允许
    const int& ra = a;

    int b = 20;
    int& rb1 = b;
    // 权限缩小允许
    const int& rb2 = b;

    // const引用可以给常量取别名
    const int& rc = 30;

    // 给临时对象取别名(临时对象具有常性)
    const int& rd = (a + b);

    // 隐式类型转换，也会开辟一个临时对象
    double d = 12.34;
    int i = d;
    //int& ri = d;
    const int& ri = d;

    // 总结产生临时对象的情况：1.函数传值返回 2.表达式相加 3.隐式类型转换
}


// debug版本默认不展开
inline int Add(int x, int y)
{
    return x + y;
}

void test05()
{
    int* p = nullptr;
    printf("%d", 5);
}

int main()
{
    test05();
    return 0;
}