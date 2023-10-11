#include <iostream>
#include <cstring>
#include <ctype.h>
#include <stdbool.h>

size_t my_strlen(char* s) {
    for (size_t i = 0; true; ++i) {
        if (s[i] == '\0') {
            return i;
        }
    }
}

int main() {
    // char s[6];
    // std::cin.getline(s, 6);
    // size_t length = std::strlen(s);  // strlen - O(N)
    // for (size_t i = 0; i < strlen(s); ++i) {
    // for (size_t i = 0; i < length; ++i) {
        // O(N^2) -> O(N)
    // }
    // std::strcpy(dest, res);  // copy
    // std::strcmp(s1, s2);  // compare
    // std::cout << s << std::endl;
    char res[5] = "abcd";
    char dest[5];
    // res -> copy to dest
    std::strcpy(dest, res);
    dest[0] = '1';
    std::strcmp(res, dest);  // return 0 if equal
    std::cout << (std::strcmp(res, dest) == 0 ? 0 : 1) << std::endl;
    dest[0] = '\0';
    char a = 'A';
    char b = 'a';
    char c = '1';
    char d = '(';
    std::cout << (isdigit(a) == 0 ? 0 : 1) << (isupper(a) == 0 ? 0 : 1) << (islower(a) == 0 ? 0 : 1) << std::endl;
    std::cout << (isdigit(b) == 0 ? 0 : 1) << isupper(b) << islower(b) << std::endl;
    std::cout << (isdigit(c) == 0 ? 0 : 1) << isupper(c) << islower(c) << std::endl;
    std::cout << (isdigit(d) == 0 ? 0 : 1) << isupper(d) << islower(d) << std::endl;
    return 0;
}
