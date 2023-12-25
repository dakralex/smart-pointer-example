#include <algorithm>
#include "patient.h"

Patient::Patient(std::string name,
                 int age,
                 const std::set<Illness>& illnesses,
                 unsigned int wealth)
        :name {std::move(name)},
         age {age},
         wealth {wealth},
         illnesses {illnesses}
{
    if (this->name.empty()) {
        throw std::runtime_error("Patient's name must not be empty.");
    }

    if (age < 0) {
        throw std::runtime_error("Patient's age must be greater or equal to 0.");
    }

    if (illnesses.empty()) {
        throw std::runtime_error("Patient must have more than one illness.");
    }
}

bool
Patient::operator==(const Patient& other) const
{
    return this->name == other.name && this->age == other.age
            && this->illnesses == other.illnesses
            && this->wealth == other.wealth;
}

void
Patient::increase_wealth(unsigned int amount)
{
    wealth += amount;
}

bool
Patient::pay_procedure(unsigned int amount)
{
    if (wealth < amount) {
        return false;
    }

    wealth -= amount;
    return true;
}

void
Patient::catch_disease(const Illness& illness)
{
    illnesses.insert(illness);
}

unsigned
Patient::cure(Medical_Specialty specialty)
{
    unsigned count {0};

    for (auto it = illnesses.begin(); it != illnesses.end();) {
        if (it->get_specialty() == specialty) {
            it = illnesses.erase(it);
            ++count;
        }
        else {
            ++it;
        }
    }

    return count;
}

bool
Patient::requires_treatment_in(Medical_Specialty specialty) const
{
    return std::count_if(illnesses.begin(), illnesses.end(), [specialty](
            const Illness& illness) {
        return illness.get_specialty() == specialty;
    });
}

bool
Patient::healthy() const
{
    return illnesses.empty();
}

std::string
Patient::get_name() const
{
    return name;
}

std::ostream&
operator<<(std::ostream& o, const Patient& patient)
{
    o << "[" << patient.name << ", " << patient.age << " years, "
      << patient.illnesses << ", " << patient.wealth
      << " moneyz]";

    return o;
}

std::ostream&
operator<<(std::ostream& o,
           const std::map<std::string, std::weak_ptr<Patient>>& patients)
{
    o << "patients {";

    std::string separator;

    for (const auto& [key, patient]: patients) {
        o << separator << *patient.lock();

        separator = ",";
    }

    o << "}";

    return o;
}
