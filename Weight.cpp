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
#include <stdexcept>

using namespace std;

/// Define the Static Public Attributes
const float Weight::UNKNOWN_WEIGHT = -1.0;

const float Weight::KILOS_IN_A_POUND = 0.453592;
const float Weight::SLUGS_IN_A_POUND = 0.031081;

const string Weight::POUND_LABEL = "Pound";
const string Weight::KILO_LABEL  = "Kilo";
const string Weight::SLUG_LABEL  = "Slug";


/// Public Member Functions
// Create a default weight
Weight::Weight() noexcept {}

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
float Weight::getWeight(Weight::UnitOfWeight weightUnits) const noexcept {
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
        // cout << "Weight does not seem to be valid" << endl;
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
void Weight::dump(){
    cout << "===============================================" << endl;
    cout << "Weight     this                       " << &weight << endl;
    cout << "Weight     isKnown                    " << bIsKnown << endl;
    cout << "Weight     weight                     " << getWeight() << endl;
    cout << "Weight     unitOfWeight               " << unitOfWeight << endl;
    cout << "Weight     hasMax                     " << bHasMax << endl;
    cout << "Weight     maxWeight                  " << getMaxWeight() << endl;
    cout << "" << endl;
}


// Operators
bool Weight::operator==(const Weight& rhs_Weight) const {
    float lhs_weight = (bIsKnown) ? getWeight(Weight::POUND) : 0;
    float rhs_weight = (rhs_Weight.bIsKnown) ? rhs_Weight.getWeight(Weight::POUND) : 0;
    return lhs_weight == rhs_weight;
}

std::ostream& operator<<( std::ostream& lhs_stream
        ,const Weight::UnitOfWeight rhs_UnitOfWeight ) {
    switch( rhs_UnitOfWeight ) {
        case Weight::POUND: return lhs_stream << Weight::POUND_LABEL ;
        case Weight::KILO: return lhs_stream << Weight::KILO_LABEL ;
        case Weight::SLUG: return lhs_stream << Weight::SLUG_LABEL ;
        default:
            throw std::out_of_range( "The unit can’t be mapped to a string" );
    }
}

bool Weight::operator<( const Weight& rhs_Weight ) const {
    float lhs_weight = (bIsKnown) ? getWeight(Weight::POUND) : 0;
    float rhs_weight = (rhs_Weight.bIsKnown) ? rhs_Weight.getWeight(Weight::POUND) : 0;
    return lhs_weight < rhs_weight;
}

bool Weight::operator+=( float rhs_addToWeight ) const {
    float lhs_weight = (bIsKnown) ? getWeight(Weight::POUND) : 0;
    float rhs_weight = (rhs_addToWeight);
    return lhs_weight + rhs_weight;
}


/// Static Public Member Functions
// Convert from Kilograms to Pounds
float Weight::fromKilogramToPound( const float kilogram ) noexcept {
    return kilogram / KILOS_IN_A_POUND ;
}

// Convert from Pounds to Kilograms
float Weight::fromPoundToKilogram( const float pound ) noexcept {
    return pound * KILOS_IN_A_POUND ;
}


// Convert from Slugs to Pounds
float Weight::fromSlugToPound( const float slug ) noexcept {
    return slug / SLUGS_IN_A_POUND ;
}

// Convert from Pounds to Slugs
float Weight::fromPoundToSlug( const float pound ) noexcept {
    return pound * SLUGS_IN_A_POUND ;
}

// Convert a weight between two different units
// Recall the CatPower lab
float Weight::convertWeight(float fromWeight, UnitOfWeight fromUnit, UnitOfWeight toUnit) noexcept {
    // Set a common value
    float commonValue;
    // Set a to Value
    float toValue;

    switch (fromUnit) {
        case POUND: commonValue = fromWeight;
        break;

        case KILO: commonValue = fromKilogramToPound(fromWeight);
        break;

        case SLUG: commonValue = fromSlugToPound(fromWeight);
        break;
    }

    switch (toUnit) {
        case POUND: toValue = commonValue;
        break;

        case KILO: toValue = fromPoundToKilogram(commonValue);
        break;

        case SLUG: toValue = fromPoundToSlug(commonValue);
        break;
    }
    return toValue;
}


/// Private member functions
// Set the maximum weight
void Weight::setMaxWeight(float newMaxWeight) {
    if (bHasMax == false) {
        if (isWeightValid(newMaxWeight) == true) {
            maxWeight = newMaxWeight;
            bHasMax = true;
        }
    }
}