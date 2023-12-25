#ifndef PR2_SMART_POINTER_TASKS_H
#define PR2_SMART_POINTER_TASKS_H

#include <set>
#include <memory>
#include <vector>
#include <numeric>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <stdexcept>
#include <experimental/iterator>
#include <experimental/iterator>
#include "illness.h"
#include "hcp.h"
#include "patient.h"
#include "hospital.h"

const std::vector SPECIALTIES {Medical_Specialty::Cardiology, Medical_Specialty::Dermatology,
                               Medical_Specialty::Endocrinology, Medical_Specialty::Gynecology,
                               Medical_Specialty::Neurology, Medical_Specialty::Oncology,
                               Medical_Specialty::Pathology, Medical_Specialty::Pediatrics,
                               Medical_Specialty::Pulmonology, Medical_Specialty::Urology};

const std::set<Medical_Specialty> SPECIALTIES_SET {Medical_Specialty::Cardiology,
                                                   Medical_Specialty::Dermatology,
                                                   Medical_Specialty::Endocrinology,
                                                   Medical_Specialty::Gynecology,
                                                   Medical_Specialty::Neurology,
                                                   Medical_Specialty::Oncology,
                                                   Medical_Specialty::Pathology,
                                                   Medical_Specialty::Pediatrics,
                                                   Medical_Specialty::Pulmonology,
                                                   Medical_Specialty::Urology};

/*
std::vector<std::shared_ptr<Health_Care_Provider>> task1(const std::vector<std::shared_ptr<Health_Care_Provider>>& v){
}
*/

#endif
