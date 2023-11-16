#ifndef PR2_SMART_POINTER_PATIENT_H
#define PR2_SMART_POINTER_PATIENT_H

#include<set>
#include<sstream>
#include"illness.h"

class Patient {
    std::string name {nullptr};
    int age {0};
    std::set<Illness> illnesses {};
    unsigned wealth {0};
public:
    Patient(std::string name,
            int age,
            const std::set<Illness>& illnesses,
            unsigned wealth = 200);

    bool operator==(const Patient& other);

    bool pay_procedure(unsigned amount);

    void increase_wealth(unsigned amount);

    unsigned cure(Medical_Specialty topic);

    void catch_disease(const Illness& illness);

    bool healthy() const;

    std::string get_name() const;

    bool requires_treatment_in(Medical_Specialty topic) const;

    friend std::ostream& operator<<(std::ostream& o,
                                    const Patient& patient);
};

#endif //PR2_SMART_POINTER_PATIENT_H
