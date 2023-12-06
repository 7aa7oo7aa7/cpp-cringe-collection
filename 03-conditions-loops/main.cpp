#include <iostream>
#include <optional>
#include <cassert>

int f(int x) {
    return x % 2;
}

std::optional<int> g(int x) {
    if (x == 1) {
        return x;
    } else {
        return std::nullopt;
    }
}

// std::optional -> bool
// std::nullopt -> false, else true

int main() {

    if (bool expr) {
        // code
    } else if (bool expr) {
        // code
    } else {
        // code
    }

    if (1);  // 1 -> true -> if (true)

    if (1) {
        // code
    } else if (2) {
        // code
    } else if (1) {
        // code
        // не будет выполнено
    }

    int x = 0;
    if (std::cin >> x) {
        // прочитано либо 1 число, либо 0
    }

    int a = 0;
    std::cin >> a;
    if (int x = f(a); g(x)) {
        std::cout << x;
    }
    
    // тернарный оператор

    // <bool expr> ? <expr> : <expr>;

    // std::cout << (a ? a : "aaaa") << std::endl;

    int x = 0;
    if (a == 1) {
        x = 2;
    } else {
        x = -1;
    }

    (a == 1) ? (x = 2) : (x = -1);
    x = (a == 1 ? 2 : -1);

    int y1 = 0;
    int y2 = 0;
    if (a == 1) {
        y1 = 1;
    } else {
        y2 = 1;
    }
    // i = 0;

    for (;;) {
        
    }

    int j = 0;
    for (; j < a; ++j) {
        //
    }

    for (int i1 = 0, i2 = 0; i1 < a; ++i1, ++i2);

    int y = 5;
    while (y > 3 || ++y > 0) {
        std::cout << y << std::endl;
        --y;
    }
    if (y > 3 || ++y > 0) {
        --y;
    }
    // 4
    if (y > 10000 && ++y > 0) {
        --y;
    }
    // 4
    std::cout << y << std::endl;

    // i = 0;

    for (;;) {
        
    }

    int j = 0;
    for (; j < a; ++j) {
        //
    }

    for (int i1 = 0, i2 = 0; i1 < a; ++i1, ++i2);

    int y = 5;
    while (y > 3 || ++y > 0) {
        std::cout << y << std::endl;
        --y;
    }
    if (y > 3 || ++y > 0) {
        --y;
    }
    // 4
    if (y > 10000 && ++y > 0) {
        --y;
    }
    // 4
    std::cout << y << std::endl;

    // switch

    int x = 1;
    switch (x) {
        case 1:
            // code
            break;
        case 2:
            // code
            break;
        // default:
            // code
            // break;
    }
    // switch

    int x = 1;
    // switch (x) {
    //     case 1:
    //         // code
    //         break;
      

    // (a == 1) ? (y1 = 1) : (y2 = 1);
    // (a == 1 ? y1 : y2) = 1;  // int&

    // // циклы

    // // while (a) {
    // //     //
    // // }

    // // do {
    // //     //
    // //     //
    // // } while (a);

    // for (int i = 0; i < a; ++i) {
    //     //
    // }
    // // i = 0;

    // // for (;;) {
    //     //
    // // }

    // int j = 0;
    // for (; j < a; ++j) {
    //     //
    // }

    // for (int i1 = 0, i2 = 0; i1 < a; ++i1, ++i2);

    int y = 5;
    // while (y > 3 || ++y > 0) {
    //     std::cout << y << std::endl;
    //     --y;
    // }
    if (y > 3 || ++y > 0) {
        --y;
    }
    // 4
    if (y > 10000 && ++y > 0) {
        --y;
    }
    // 4
    std::cout << y << std::endl;

    // switch

    int x = 1;
    switch (x) {
        case 1:
            // code
            break;
        case 2:
            // code
            break;
        // default:
            // code
            // break;
    }

    int a = 0;
    std::cin >> a;
    assert(a >= 0 && a <= 30000);
    int b = f(11111);
    assert(b == 1);
    std::cout << b << std::endl;

    return 0;
}
