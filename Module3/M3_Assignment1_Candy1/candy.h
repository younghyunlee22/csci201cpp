/* Program name: main.cpp
* Author: Younghyun Lee
* Date last updated: 9/14/2024
* Purpose: Order custom candy
*/

#ifndef CANDY_H
#define CANDY_H

#include <string>
using namespace std;

enum flavorType {
    COTTON_CANDY = 1,
    WATERMELON_BURST,
    PAPAYA_BLISS,
    CITRUS_SPLASH,
    COLA
};

enum colorType {
    SCARLET_BLAZE = 1,
    AZURE_SKY,
    EMERALD_MIST,
    GOLDENROD_GLOW,
    AMETHYST_HAZE
};

class Candy {
private:
    flavorType flavor;
    colorType color;

public:
    Candy(flavorType flavor, colorType color);

    flavorType getFlavor() const;
    colorType getColor() const;

    static string getFlavorString(flavorType flavor);
    static string getColorString(colorType color);

    void print() const;
};

#endif //CANDY_H
