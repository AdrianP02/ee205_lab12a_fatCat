#include "Weight.h"

#include <iostream>

using namespace std;

Weight hi;

int main() {

    Weight testCat;
    testCat.dump();     // Should print a default cat with no set values

    cout << Weight::convertWeight(2.7, Weight::SLUG, Weight::KILO); // Should convert our 2.7 slugs to kilos

    testCat = Weight(2.7, Weight::SLUG, 25);
    testCat.dump();         // Should print a cat with the set values

    Weight::UnitOfWeight unitOfWeight = Weight::SLUG;
    cout << unitOfWeight;               // Should print the unit of weight. Slug = 2



//    std::cout << Weight::convertWeight(3.0, Weight::KILO, Weight::POUND);
//    hi = Weight(3.0, Weight::KILO, 300);
//    Weight eknl = Weight(4.1, Weight::SLUG, 30);
//    Weight::UnitOfWeight unitOfWeight = Weight::KILO;
//    std::cout << unitOfWeight ;
//    hi.dump();
//    eknl.dump();
//    Weight nan = Weight();
//    nan.dump();

    return 0;
}
