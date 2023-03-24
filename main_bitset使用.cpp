/**
 */
#include <iostream>
#include <bitset>

int main()
{
    std::bitset<12> bs = 0b010101001001;
    std::cout << bs[0] << std::endl;
    std::cout << bs.test(3) << std::endl;
    bs.flip();
    std::cout << bs << std::endl;
    bs.set();
    std::cout << bs << std::endl;
    bs.reset();
    std::cout << bs << std::endl;
    return 0;
}