#include "hcp.h"

Health_Care_Provider::Health_Care_Provider(std::string name,
                                           const std::set<Medical_Specialty>& specialties,
                                           unsigned int wealth)
        :name {std::move(name)}, wealth {wealth}, specialties {specialties}
{
    if (this->name.empty()) {
        throw std::runtime_error("Name must not be empty.");
    }
}

Health_Care_Provider::~Health_Care_Provider() = default;

void
Health_Care_Provider::increase_wealth(unsigned int amount)
{
    wealth += amount;
}

bool
Health_Care_Provider::pay_license(unsigned int amount)
{
    if (wealth < amount) {
        return false;
    }

    wealth -= amount;
    return true;
}

void
Health_Care_Provider::receive_license(Medical_Specialty specialty)
{
    specialties.insert(specialty);
}

bool
Health_Care_Provider::eligible_for(Medical_Specialty specialty)
{
    return specialties.find(specialty) != specialties.end();
}

std::string
Health_Care_Provider::get_name() const
{
    return name;
}

Teaching_Health_Care_Provider::Teaching_Health_Care_Provider(unsigned int fee,
                                                             std::string name,
                                                             const std::set<Medical_Specialty>& specialties,
                                                             unsigned int wealth)
        :Health_Care_Provider(std::move(name), specialties, wealth), fee {fee} { }

unsigned
Teaching_Health_Care_Provider::perform_procedure(unsigned int amount,
                                                 std::shared_ptr<Patient> patient,
                                                 Medical_Specialty specialty)
{
    if (eligible_for(specialty) && patient->requires_treatment_in(specialty)
            && patient->pay_procedure(amount)) {
        increase_wealth(amount);
        return patient->cure(specialty);
    }

    return 0;
}

bool
Teaching_Health_Care_Provider::teach(Medical_Specialty specialty,
                                     std::shared_ptr<Health_Care_Provider> target_provider)
{
    if (bool target_can_afford = target_provider->pay_license(fee);
            target_provider.get() == this
                    || target_provider->eligible_for(specialty)
                    || !target_can_afford
                    || !eligible_for(specialty)) {
        // Pay back the fee if nothing was taught
        if (target_can_afford) {
            target_provider->increase_wealth(fee);
        }

        return false;
    }

    increase_wealth(fee);
    target_provider->receive_license(specialty);
    return true;
}

std::string
Teaching_Health_Care_Provider::hcp_type() const
{
    return "Teacher";
}

Smart_Health_Care_Provider::Smart_Health_Care_Provider(unsigned int fee,
                                                       std::string name,
                                                       const std::set<Medical_Specialty>& specialties,
                                                       unsigned int wealth)
        :Health_Care_Provider(std::move(name), specialties, wealth), fee {fee} { }

unsigned
Smart_Health_Care_Provider::perform_procedure(unsigned int,
                                              std::shared_ptr<Patient>,
                                              Medical_Specialty)
{
    return 0;
}

void
Smart_Health_Care_Provider::receive_license(Medical_Specialty specialty)
{
    increase_wealth(fee);
    Health_Care_Provider::receive_license(specialty);
}

std::string
Smart_Health_Care_Provider::hcp_type() const
{
    return "Smart";
}

std::ostream&
operator<<(std::ostream& o, const Health_Care_Provider& provider)
{
    o << "[" << provider.name << ", " << provider.specialties << ", "
      << provider.wealth << " moneyz, " << provider.hcp_type() << "]";

    return o;
}

std::ostream&
operator<<(std::ostream& o,
           const std::map<std::string, std::shared_ptr<Health_Care_Provider>>& providers)
{
    o << "hcps {";

    std::string separator;

    for (const auto& [key, provider]: providers) {
        if (provider) {
            o << separator << *provider.get();

            separator = ",";
        }
    }

    o << "}";

    return o;
}
