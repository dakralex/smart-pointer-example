#include <utility>
#include "hospital.h"

Hospital::Hospital(std::string name)
        :name {std::move(name)}
{
    if (this->name.empty()) {
        throw std::runtime_error("Name must not be empty.");
    }
}

void
Hospital::erase_patient_if_expired(const std::string& patient_name)
{
    if (auto p = patients.find(patient_name);
            p == patients.end() || p->second.expired()) {
        patients.erase(patient_name);
    }
}

bool
Hospital::admit_patient(std::shared_ptr<Patient> patient)
{
    const auto& patient_name = patient->get_name();
    erase_patient_if_expired(patient_name);

    return std::get<bool>(patients.try_emplace(patient_name, patient));
}

bool
Hospital::sign_hcp(std::shared_ptr<Health_Care_Provider> provider)
{
    return std::get<bool>(providers.try_emplace(provider->get_name(), provider));
}

bool
Hospital::dismiss_patient(const std::string& patient_name)
{
    erase_patient_if_expired(patient_name);

    return patients.erase(patient_name);
}

bool
Hospital::dismiss_hcp(const std::string& provider_name)
{
    return providers.erase(provider_name);
}

std::shared_ptr<Patient>
Hospital::get_patient(const std::string& patient_name) const
{
    auto p = patients.find(patient_name);

    if (p == patients.end() || p->second.expired()) {
        throw std::runtime_error("Patient was not found.");
    }

    return p->second.lock();
}

std::shared_ptr<Health_Care_Provider>
Hospital::get_hcp(const std::string& provider_name) const
{
    auto p = providers.find(provider_name);

    if (p == providers.end()) {
        throw std::runtime_error("Health care provider was not found.");
    }

    return p->second;
}

std::ostream&
operator<<(std::ostream& o, const Hospital& hospital)
{
    o << "[" << hospital.name << ", " << hospital.providers << ", "
      << hospital.patients << "]";

    return o;
}

Special_Hospital::Special_Hospital(std::string name)
        :Hospital(std::move(name)) { }

const std::map<Medical_Specialty, std::size_t>&
Special_Hospital::get_map() const
{
    return counter_map;
}

bool
Special_Hospital::admit_patient(std::shared_ptr<Patient> patient)
{
    if (!Hospital::admit_patient(patient)) {
        return false;
    }

    std::set<Medical_Specialty> specialties;
    for (const auto& illness: patient->get_illnesses()) {
        specialties.insert(illness.get_specialty());
    }

    for (const auto& specialty: specialties) {
        counter_map[specialty] += 1;
    }

    return true;
}
