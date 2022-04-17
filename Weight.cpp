///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-lab12a-fatCat - EE 205 - Spr 2022
///
/// @file Weight.cpp
/// @version 1.0
///
/// @author Adrian Peng <apeng2@hawaii.edu>
/// @date   16_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "Weight.h"

#include <iostream>
#include <iomanip>

using namespace std;

/// Define the Static Public Attributes
const float Weight::UNKNOWN_WEIGHT = -1;

const float Weight::KILOS_IN_A_POUND = 0.453592;
const float Weight::SLUGS_IN_A_POUND = 0.031081;

const string Weight::POUND_LABEL = "Pound";
const string Weight::KILO_LABEL  = "Kilo";
const string Weight::SLUG_LABEL  = "Slug";


/// Public Member Functions
// Create a default weight
Weight::Weight() noexcept {

}

// Create a weight with a value. Unit should be set to the default unit.
Weight::Weight(const float newWeight) {
    setWeight(newWeight);
}

// Create a weight with a unit of weight
Weight::Weight(Weight::UnitOfWeight newUnitOfWeight) noexcept {
    unitOfWeight = newUnitOfWeight;
}

// Create a weight with a value and a unit of weight
Weight::Weight(float newWeight, Weight::UnitOfWeight newUnitOfWeight) : Weight(newUnitOfWeight) {
    setWeight(newWeight, newUnitOfWeight);
}

// Create a weight with a value and a maximum weight
Weight::Weight(float newWeight, float newMaxWeight) {
    setWeight(newWeight);
    setMaxWeight(newMaxWeight);
}

// Create a weight with a unit of weight and a maximum weight value
Weight::Weight(Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight) : Weight(newUnitOfWeight) {
    setMaxWeight(newMaxWeight);
}

// Create a weight with a value, unit, and maximum weight
Weight::Weight(float newWeight, Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight) : Weight(newUnitOfWeight, newMaxWeight) {
    setWeight(newWeight);
}



// Getters
// If weight is known (bIsKnown == True) return the weight. Else, return UNKNOWN_WEIGHT
float Weight::getWeight() const noexcept {
    if (bIsKnown == true) {
        return weight;
    }
    else {
        return UNKNOWN_WEIGHT;
    }
}

// Get the weight in a specific unit. Essentially we should return the result of our convertWeight function since we need the result of that
float Weight::getWeight(Weight::UnitOfWeight weightUnits) {
    return convertWeight(weight, unitOfWeight, weightUnits);
}

// Get the maximum weight
float Weight::getMaxWeight() const noexcept {
    if (bHasMax == true) {
        return maxWeight;
    }
    else {
        return UNKNOWN_WEIGHT;
    }
}

// Get the UnitOfWeight for this Weight
Weight::UnitOfWeight Weight::getWeightUnit() const noexcept {
    return unitOfWeight;
}



// Setters
// Set the weight
void Weight::setWeight(float newWeight) {
    if (isWeightValid(newWeight) == true) {
        weight = newWeight;
        // Remember to now set bIsKnown to true
        bIsKnown = true;
    }
    else {
        cout << "Weight does not seem to be valid" << endl;
        exit(EXIT_FAILURE);
    }
}

//Set the weight as a specific unit. Here we can just return the convertWeight() results
void Weight::setWeight(float newWeight, UnitOfWeight weightUnits) {
    setWeight(convertWeight(newWeight, weightUnits, unitOfWeight));
}



// Validation and other stuff
// Check if a weight is known. Return true if it is known.
bool Weight::isWeightKnown() const noexcept {
    if (bIsKnown == true) {
        return true;
    }
    else {
        return false;
    }
}

// Check if a maximum weight is set. Return true if so.
bool Weight::hasMaxWeight() const noexcept {
    if (bHasMax == true) {
        return true;
    }
    else {
        return false;
    }
}

// Checks if a weight is valid
bool Weight::isWeightValid(float checkWeight) const noexcept {
    if (checkWeight <= 0) {
        cout << "Weight must be greater than 0 " << endl;
        return false;
    }

    if (bHasMax == true) {
        if (checkWeight > maxWeight) {
            cout << "Weight cannot be greater than " << maxWeight << endl;
            return false;
        }
    }
    return true; // Yes the weight is valid
}

// Validate everything
bool Weight::validate() const noexcept {
    if (bIsKnown == true) {
        if (isWeightValid(weight) == false) {
            return false;
        }
    }
    if (bHasMax == true) {
        if (isWeightValid(maxWeight) == false) {
            return false;
        }
        if (weight > maxWeight) {
            return false;
        }
    }
    return true;
}

// Print the weight class
// I just reused the PrintCat formatting from Cat.cpp that was provided and edited to match the variables
#define FORMAT_LINE( className, member ) std::cout \
                                      << std::setw(8) << (className) \
                                      << std::setw(20) << (member)   \
                                      << std::setw(52)  /* (data) */

void Weight::dump() const noexcept {

    cout << setw(80) << setfill( '=' ) << "" << endl ;
    cout << setfill( ' ' ) ;
    cout << left ;
    cout << boolalpha ;
    FORMAT_LINE( "Weight", "this" )         << "I'm not sure what goes here"   << endl ;
    FORMAT_LINE( "Weight", "isKnown" )       << bIsKnown << endl ;
    FORMAT_LINE( "Weight", "weight" )        <<  weight  << endl ;
    FORMAT_LINE( "Weight", "unitOfWeight" )      << unitOfWeight << endl ;
    FORMAT_LINE( "Weight", "hasMax" )       << bHasMax << endl ;
    FORMAT_LINE( "Weight", "maxWeight")        << maxWeight << endl;
}
