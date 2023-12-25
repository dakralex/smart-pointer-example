#include "illness.h"

Illness::Illness(Medical_Specialty specialty, const std::string& name)
        :name {name}, specialty {specialty}
{
    if (this->name.empty()) {
        throw std::runtime_error("Name must not be empty.");
    }
}

bool
Illness::operator==(const Illness& other) const
{
    return this->specialty == other.specialty && this->name == other.name;
}

bool
Illness::operator<(const Illness& other) const
{
    return this->specialty < other.specialty;
}

Medical_Specialty
Illness::get_specialty() const
{
    return this->specialty;
}

std::string
Illness::get_name() const
{
    return name;
}

std::ostream&
operator<<(std::ostream& o, Medical_Specialty specialty)
{
    o << MEDICAL_SPECIALTY_NAMES[static_cast<size_t>(specialty)];

    return o;
}

std::ostream&
operator<<(std::ostream& o, const std::set<Medical_Specialty>& specialties)
{
    o << "{";

    std::string separator;

    for (const auto& specialty: specialties) {
        o << separator << specialty;

        separator = ",";
    }

    o << "}";

    return o;
}

std::ostream&
operator<<(std::ostream& o, const Illness& illness)
{
    o << "[" << illness.specialty << ", " << illness.name << "]";

    return o;
}

std::ostream&
operator<<(std::ostream& o, const std::set<Illness>& illnesses)
{
    o << "{";

    std::string separator;

    for (const auto& illness: illnesses) {
        o << separator << illness;

        separator = ",";
    }

    o << "}";

    return o;
}