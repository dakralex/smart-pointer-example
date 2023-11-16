#ifndef PR2_SMART_POINTER_HCP_H
#define PR2_SMART_POINTER_HCP_H

#include<set>
#include<memory>
#include<sstream>
#include"patient.h"

enum class Medical_Specialty {
    Cardiology, Dermatology, Endocrinology, Gynecology,
    Neurology, Oncology, Pathology, Pediatrics, Pulmonology, Urology
};

std::ostream& operator<<(std::ostream& o,
                         Medical_Specialty specialty);

class Health_Care_Provider {
    std::string name {nullptr};
    std::set<Medical_Specialty> specialties {};
    unsigned wealth {0};
public:
    Health_Care_Provider(std::string name,
                         const std::set<Medical_Specialty>& specialties,
                         unsigned wealth = 500);

    virtual ~Health_Care_Provider();

    void increase_wealth(unsigned amount);

    virtual unsigned perform_procedure(unsigned amount,
                                       std::shared_ptr<Patient> patient,
                                       Medical_Specialty specialty) = 0;

    bool pay_license(unsigned amount);

    virtual void receive_license(Medical_Specialty specialty);

    bool eligible_for(Medical_Specialty specialty);

    std::string get_name() const;

    virtual std::string hcp_type() const = 0;

    friend std::ostream& operator<<(std::ostream& o,
                                    const Health_Care_Provider& provider);
};

class Teaching_Health_Care_Provider : public Health_Care_Provider {
    unsigned fee;
public:
    Teaching_Health_Care_Provider(unsigned fee,
                                  std::string name,
                                  const std::set<Medical_Specialty>& specialties,
                                  unsigned wealth = 500);

    unsigned perform_procedure(unsigned amount,
                               std::shared_ptr<Patient> patient,
                               Medical_Specialty specialty);

    bool teach(Medical_Specialty specialty,
               std::shared_ptr<Health_Care_Provider> target_provider);

    std::string hcp_type() const;
};

class Smart_Health_Care_Provider : public Health_Care_Provider {
    unsigned fee {0};
public:
    Smart_Health_Care_Provider(unsigned fee,
                               std::string name,
                               const std::set<Medical_Specialty>& specialties,
                               unsigned wealth = 500);

    unsigned perform_procedure(unsigned amount,
                               std::shared_ptr<Patient> patient,
                               Medical_Specialty specialty);

    void receive_license(Medical_Specialty specialty);

    std::string hcp_type() const;
};

#endif //PR2_SMART_POINTER_HCP_H
