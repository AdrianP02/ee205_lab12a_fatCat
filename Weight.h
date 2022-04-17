///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205-lab12a-fatCat - EE 205 - Spr 2022
///
/// @file Weight.h
/// @version 1.0
///
/// @author Adrian Peng <apeng2@hawaii.edu>
/// @date   16_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <string>
#include <ostream>

class Weight {

/// Public types
public:         // The different units of measure for weight
    enum UnitOfWeight {
        POUND,  // The default value
        KILO,
        SLUG
    };

/// Public member functions
public:         // Constructors
    // Create a default weight
    Weight() noexcept;

    // Create a weight with a value. Unit should be set to the default unit.
    Weight(float newWeight);

    // Create a weight with a unit of weight
    Weight(UnitOfWeight newUnitOfWeight) noexcept;

    // Create a weight with a value and a unit of weight
    Weight(float newWeight, UnitOfWeight newUnitOfWeight);

    // Create a weight with a value and a maximum weight
    Weight(float newWeight, float newMaxWeight);

    // Create a weight with a unit of weight and a maximum weight value
    Weight(UnitOfWeight newUnitOfWeight, float newMaxWeight);

    // Create a weight with a value, unit, and maximum weight
    Weight(float newWeight, UnitOfWeight newUnitOfWeight, float newMaxWeight);


public:         // Getters
    // Gets the weight in the Weight's units
    float getWeight() const noexcept;

    // Get the weight in a specified unit
    float getWeight(UnitOfWeight weightUnits) const noexcept;

    // Get the maximum weight
    float getMaxWeight() const noexcept;

    // Get the UnitOfWeight for this Weight
    UnitOfWeight getWeightUnit() const noexcept;


public:         // Setters
    // Set the weight
    void setWeight(float newWeight);

    // Set the weight as a specific unit
    void setWeight(float newWeight, UnitOfWeight weightUnits);


public:         // Validation and other stuff
    // Checks if a weight is known. Return true if a weight is known
    bool isWeightKnown() const noexcept;

    // Checks if a maximum weight is set. Return true if it is set.
    bool hasMaxWeight() const noexcept;

    // Check if the weight is valid (Cannot be < 0). Return true if it is valid.
    bool isWeightValid(float checkWeight) const noexcept;

    // Validation. Checks if the Weight is good and valid
    bool validate() const noexcept;

    // Print the weight class
    void dump() const noexcept;


public:         // Operators
    // Weights are equal when their weights are equal
    bool operator==(const Weight &rhs_Weight) const;

    // Compare two weights
    bool operator<(const Weight &rhs_Weight) const;

    // Add to an existing weight
    Weight &operator+=(float rhs_addToWeight);


/// Static Public Member Functions
public:         // Static Methods
    // Convert from Kilograms to Pounds
    static float fromKilogramToPound(float kilogram) noexcept;

    // Convert from Pounds to Kilograms
    static float fromPoundToKilogram(float pound) noexcept;


    // Convert from Slugs to Pounds
    static float fromSlugToPound(float slug) noexcept;

    // Convert from Pounds to Slugs
    static float fromPoundToSlug(float pound) noexcept;


    // Convert a weight between two different units
    static float convertWeight(float fromWeight, UnitOfWeight fromUnit, UnitOfWeight toUnit) noexcept;


/// Static Public Attributes
public:         // Constants and other stuff
    // If weight is unknown, return this.
    static const float UNKNOWN_WEIGHT;


    // How many Kilograms in a Pound
    static const float KILOS_IN_A_POUND;

    // How many Slugs in a Pound
    static const float SLUGS_IN_A_POUND;


    // The string label for Pounds
    static const std::string POUND_LABEL;

    // The string label for Kilograms
    static const std::string KILO_LABEL;

    // The string label for Slugs
    static const std::string SLUG_LABEL;


/// Private Member Functions
private:        // Private methods
    // Set the maximum weight
    void setMaxWeight(float newMaxWeight);


/// Private Attributes
private:        // Private variables
    // Is weight known. Default is false.
    bool bIsKnown = false;

    // Is maximum weight defined. Default is false.
    bool bHasMax = false;

    // How the weight is held and displayed. Default is POUND. UnitOfWeight can only be set when Weight is being constructed
    enum UnitOfWeight unitOfWeight = POUND;

    // The Weight. Must be > 0. If maxWeight is set, then it must also be <= maxWeight
    float weight{};

    // The maximum weight. Can only be set when Weight is being constructed
    float maxWeight{};

};
