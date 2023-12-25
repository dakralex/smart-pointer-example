#include "hospital.h"

Hospital::Hospital(std::string name)
        :name {std::move(name)}
{
    if (this->name.empty()) {
        throw std::runtime_error("Name must not be empty.");
    }
}

bool
Hospital::admit_patient(std::shared_ptr<Patient> patient)
{
    const auto& patient_name = patient->get_name();

    if (auto p = patients.find(patient_name);
            p == patients.end() || p->second.expired()) {
        patients.erase(patient_name);
    }

    return std::get<bool>(patients.try_emplace(patient_name, patient));
}

bool
Hospital::sign_hcp(std::shared_ptr<Health_Care_Provider> provider)
{
    return std::get<bool>(providers.try_emplace(provider->get_name(), provider));
}

bool
Hospital::dismiss_patient(std::string patient_name)
{
    return patients.erase(patient_name);
}

bool
Hospital::dismiss_hcp(std::string provider_name)
{
    return providers.erase(provider_name);
}

std::shared_ptr<Patient>
Hospital::get_patient(std::string patient_name) const
{
    auto p = patients.find(patient_name);

    if (p == patients.end() || p->second.expired()) {
        throw std::runtime_error("Patient was not found.");
    }

    return p->second.lock();
}

std::shared_ptr<Health_Care_Provider>
Hospital::get_hcp(std::string provider_name) const
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
