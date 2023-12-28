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

std::set<Medical_Specialty>
get_specialties_intersection(const std::vector<std::shared_ptr<Health_Care_Provider>>& providers)
{
    if (providers.empty()) {
        return {};
    }

    std::set<Medical_Specialty> curr {providers[0]->get_topics()};
    std::set<Medical_Specialty> temp;

    for (std::size_t i {0}; i < providers.size(); ++i) {
        std::set_intersection(curr.begin(), curr.end(), providers[i]->get_topics().begin(),
                              providers[i]->get_topics().end(),
                              std::inserter(temp, temp.begin()));
        std::swap(curr, temp);
        temp.clear();
    }

    return curr;
}

std::vector<std::shared_ptr<Health_Care_Provider>>
task1(const std::vector<std::shared_ptr<Health_Care_Provider>>& providers)
{
    std::vector<std::shared_ptr<Health_Care_Provider>> res;

    std::set<Medical_Specialty> common_specialties {get_specialties_intersection(providers)};

    auto total_wealth = std::accumulate(providers.begin(), providers.end(), 0,
                                        [](auto wealth, const auto& provider) {
                                            return wealth + provider->get_wealth();
                                        });

    std::transform(providers.begin(), providers.end(), std::back_inserter(res),
                   [&common_specialties, &total_wealth](const std::shared_ptr<
                           Health_Care_Provider>& provider) {
                       std::string name {provider->get_name()};
                       std::reverse(name.begin(), name.end());

                       return std::make_shared<Teaching_Health_Care_Provider>(5, name,
                                                                              common_specialties,
                                                                              total_wealth
                                                                                      + name.length());
                   });

    return res;
}

class Super_Task {
    std::vector<std::weak_ptr<Patient>> patients;
public:
    explicit Super_Task(const std::vector<std::shared_ptr<Patient>>& patients);

    std::vector<std::shared_ptr<Patient>>
    screening(const std::vector<Medical_Specialty>& specialties) const;
};

Super_Task::Super_Task(const std::vector<std::shared_ptr<Patient>>& patients)
        :patients {patients.begin(),
                   patients.end()} { }

std::vector<std::shared_ptr<Patient>>
Super_Task::screening(const std::vector<Medical_Specialty>& specialties) const
{
    std::vector<std::weak_ptr<Patient>> res;

    std::copy_if(patients.begin(), patients.end(), std::back_inserter(res),
                 [&specialties](const std::weak_ptr<Patient>& p) {
                     if (p.expired()) {
                         return false;
                     }

                     const auto& illnesses = p.lock()->get_illnesses();

                     return std::any_of(specialties.begin(), specialties.end(), [&](Medical_Specialty specialty) {
                         auto count = std::count_if(illnesses.begin(), illnesses.end(), [&](const Illness& illness) {
                             return illness.get_specialty() == specialty;
                         });

                         return count > 1;
                     });
                 });

    return {res.begin(), res.end()};
}

#endif
