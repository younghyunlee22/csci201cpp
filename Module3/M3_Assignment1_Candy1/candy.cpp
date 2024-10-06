/* Program name: main.cpp
* Author: Younghyun Lee
* Date last updated: 9/14/2024
* Purpose: Order custom candy
*/
#include <iostream>
#include "candy.h"
using namespace std;

// Constructor for the Candy class
Candy::Candy(flavorType f, colorType c) {
    flavor = f;
    color = c;
}

// Returns the flavor of the candy
flavorType Candy::getFlavor() const {
    return flavor;
}

// Returns the color of the candy
colorType Candy::getColor() const {
    return color;
}

// Converts flavor enum to string
string Candy::getFlavorString(flavorType flavor) {
    switch (flavor) {
        case COTTON_CANDY: return "Cotton Candy";
        case WATERMELON_BURST: return "Watermelon Burst";
        case PAPAYA_BLISS: return "Papaya Bliss";
        case CITRUS_SPLASH: return "Citrus Splash";
        case COLA: return "Cola";
        default: return "";
    }
}

// Converts color enum to string
string Candy::getColorString(colorType color) {
    switch (color) {
        case SCARLET_BLAZE: return "Scarlet Blaze";
        case AZURE_SKY: return "Azure Sky";
        case EMERALD_MIST: return "Emerald Mist";
        case GOLDENROD_GLOW: return "Goldenrod Glow";
        case AMETHYST_HAZE: return "Amethyst Haze";
        default: return "";
    }
}

// Print function to display candy details
void Candy::print() const {
    cout << getColorString(color) << " " << getFlavorString(flavor);
}
