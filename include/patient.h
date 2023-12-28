#ifndef PR2_SMART_POINTER_PATIENT_H
#define PR2_SMART_POINTER_PATIENT_H

#include <set>
#include <map>
#include <memory>
#include <ostream>
#include "hcp.h"
#include "illness.h"

class Illness;

enum class Medical_Specialty;

class Patient {
    std::string name;
    int age {0};
    unsigned wealth {0};
    std::set<Illness> illnesses;
public:
    Patient(std::string name,
            int age,
            const std::set<Illness>& illnesses,
            unsigned wealth = 200);

    bool
    operator==(const Patient& other) const;

    void
    increase_wealth(unsigned amount);

    bool
    pay_procedure(unsigned amount);

    void
    catch_disease(const Illness& illness);

    unsigned
    cure(Medical_Specialty specialty);

    [[nodiscard]] bool
    requires_treatment_in(Medical_Specialty specialty) const;

    [[nodiscard]] bool
    healthy() const;

    [[nodiscard]] std::string
    get_name() const;

    [[nodiscard]] const std::set<Illness>&
    get_illnesses() const;

    friend std::ostream&
    operator<<(std::ostream& o, const Patient& patient);

    friend std::ostream&
    operator<<(std::ostream& o,
               const std::map<std::string, std::weak_ptr<Patient>, std::less<>>& patients);
};

#endif //PR2_SMART_POINTER_PATIENT_H
