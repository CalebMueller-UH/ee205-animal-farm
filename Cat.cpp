///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file Cat.cpp
/// @version 1.0
///
/// @author Caleb Mueller <mc61@hawaii.edu>
/// @date   02_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#include "Cat.h"

const char *Cat::getName() const {
    return _name;
}

Gender Cat::getGender() const {
    return _gender;
}

Breed Cat::getBreed() const {
    return _breed;
}

bool Cat::isCatFixed() const {
    return _catFixed;
}

Weight Cat::getWeight() const {
    return _weight;
}

void Cat::setName(const char *name) {
    strcpy(_name, name);
}

void Cat::setCatFixed(bool catFixed) {
    _catFixed = catFixed;
}

void Cat::setWeight(Weight weight) {
    _weight = weight;
}

void Cat::setGender(Gender gender) {
    _gender = gender;
}

void Cat::setBreed(Breed breed) {
    _breed = breed;
}

/// Default Cat constructor initializes member variables to default values given in spec document
Cat::Cat() :
        _gender(UNKNOWN_GENDER), _breed(UNKNOWN_BREED), _catFixed(false), _weight(UNKNOWN_WEIGHT) {
    strcpy(_name, "");
    _next = nullptr;
}

/// Explicit Cat constructor initializes with user defined values, or
/// If a specific field isn't given, will initialize to a default value
Cat::Cat(const char *name, Gender gender, Breed breed, Weight weight) :
        _gender(gender), _breed(breed), _weight(weight) {

    if (strlen(name) > MAX_NAME_LEN) {
#ifdef DEBUG_ENABLE
        {
            fprintf(stderr, "%s Error: invalid name entry, the name %s is too long", PROG_NAME, *name);
        }
#endif
    }

    strcpy(_name, name);
    _next = nullptr;
}

Cat::~Cat() {
    memset(_name, '0', MAX_NAME_LEN);
}

/// @returns true if everything worked correctly. false if something goes
/// wrong
bool Cat::print() const noexcept {
assert(validate());
cout << setw(80) << setfill('=') << "" << endl;
cout << setfill(' ');
cout << left;
cout << boolalpha;
FORMAT_LINE("Cat", "name") << getName() << endl;
FORMAT_LINE("Cat", "gender") << genderLiteral(getGender()) << endl;
FORMAT_LINE("Cat", "breed") << breedLiteral(getBreed()) << endl;
FORMAT_LINE("Cat", "isFixed") << isCatFixed() << endl;
FORMAT_LINE("Cat", "weight") << getWeight() << endl;
return true;
}

/// @returns true if all member variables are valid, and
/// false if any of the member variables are invalid.
bool Cat::validate() const {
    if (strcmp(_name, nullptr) == 0) {
#ifdef DEBUG_ENABLE
        {
            fprintf(stderr, "%s Error: invalid name entry, member name set to nullptr", PROG_NAME);
        }
#endif
        return false;
    }

    if (strcmp(_name, "") == 0) {
#ifdef DEBUG_ENABLE
        {
            fprintf(stderr, "%s Error: invalid name entry, member name is empty", PROG_NAME);
        }
#endif
        return false;
    }


    return true;
}


const char *genderLiteral(const enum Gender gender) {
    switch (gender) {
        case (UNKNOWN_GENDER):
            return "UNKNOWN_GENDER";
        case (MALE):
            return "MALE";
        case (FEMALE):
            return "FEMALE";
        default:
            return "\0"; //
    }
}

const char *breedLiteral(const enum Breed breed) {
    switch (breed) {
        case (UNKNOWN_BREED):
            return "UNKNOWN_BREED";
        case (MAINE_COON):
            return "MAINE_COON";
        case (MANX):
            return "MANX";
        case (SHORTHAIR):
            return "SHORTHAIR";
        case (PERSIAN):
            return "PERSIAN";
        case (SPHYNX):
            return "SPHYNX";
        default:
            return "\0";
    }
}
