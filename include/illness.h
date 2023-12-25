#ifndef PR2_SMART_POINTER_ILLNESS_H
#define PR2_SMART_POINTER_ILLNESS_H

#include <array>
#include <sstream>
#include "hcp.h"

enum class Medical_Specialty {
    Cardiology,
    Dermatology,
    Endocrinology,
    Gynecology,
    Neurology,
    Oncology,
    Pathology,
    Pediatrics,
    Pulmonology,
    Urology
};

const std::array MEDICAL_SPECIALTY_NAMES {"Cardiology", "Dermatology",
                                          "Endocrinology", "Gynecology",
                                          "Neurology", "Oncology",
                                          "Pathology", "Pediatrics",
                                          "Pulmonology", "Urology"};

std::ostream&
operator<<(std::ostream& o, Medical_Specialty specialty);

std::ostream&
operator<<(std::ostream& o, const std::set<Medical_Specialty>& specialties);

class Illness {
    std::string name;
    Medical_Specialty specialty;
public:
    Illness(Medical_Specialty specialty, const std::string& name);

    bool
    operator==(const Illness& other) const;

    bool
    operator<(const Illness& other) const;

    [[nodiscard]] std::string
    get_name() const;

    [[nodiscard]] Medical_Specialty
    get_specialty() const;

    friend std::ostream&
    operator<<(std::ostream& o, const Illness& illness);

    friend std::ostream&
    operator<<(std::ostream& o, const std::set<Illness>& illnesses);
};

#endif //PR2_SMART_POINTER_ILLNESS_H
