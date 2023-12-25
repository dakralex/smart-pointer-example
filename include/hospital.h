#ifndef PR2_SMART_POINTER_HOSPITAL_H
#define PR2_SMART_POINTER_HOSPITAL_H

#include <map>
#include <memory>
#include <ostream>
#include "hcp.h"
#include "patient.h"

class Hospital {
    std::string name;
    std::map<std::string, std::weak_ptr<Patient>> patients;
    std::map<std::string, std::shared_ptr<Health_Care_Provider>> providers;
public:
    explicit Hospital(std::string name);

    bool
    admit_patient(std::shared_ptr<Patient> patient);

    bool
    sign_hcp(std::shared_ptr<Health_Care_Provider> provider);

    bool
    dismiss_patient(std::string patient_name);

    bool
    dismiss_hcp(std::string provider_name);

    [[nodiscard]] std::shared_ptr<Patient>
    get_patient(std::string patient_name) const;

    [[nodiscard]] std::shared_ptr<Health_Care_Provider>
    get_hcp(std::string provider_name) const;

    friend std::ostream&
    operator<<(std::ostream& o, const Hospital& hospital);

    friend std::ostream&
    operator<<(std::ostream& o,
               const std::map<std::string, std::shared_ptr<Health_Care_Provider>>& providers);
};

#endif //PR2_SMART_POINTER_HOSPITAL_H
