///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file updateCats.h
/// @version 1.0
///
/// @author Caleb Mueller <mc61@hawaii.edu>
/// @date   15_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#ifndef EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_UPDATECATS_H
#define EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_UPDATECATS_H

#include <string.h>

#include "catDatabase.h"
#include "addCats.h"
#include "validate.h"

bool fixCat(const size_t index);

bool updateCatName(const size_t index, const char *newName);

bool updateCatWeight(const size_t index, const float newWeight);

bool updateCatCollar1(const size_t index, const enum Color newColor);

bool updateCatCollar2(const size_t index, const enum Color newColor);

bool updateLicense(const size_t index, const unsigned long long int newLicense);

#endif //EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_UPDATECATS_H
