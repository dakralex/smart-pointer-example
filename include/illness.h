#ifndef PR2_SMART_POINTER_ILLNESS_H
#define PR2_SMART_POINTER_ILLNESS_H

#include<sstream>
#include"hcp.h"

class Illness {
    Medical_Specialty specialty;
    std::string name {nullptr};
public:
    Illness(Medical_Specialty specialty,
            const std::string& name);

    bool operator==(const Illness& other);

    bool operator<(const Illness& other);

    std::string get_name() const;

    Medical_Specialty get_specialty() const;

    friend std::ostream& operator<<(std::ostream& o,
                                    const Illness& illness);
};

#endif //PR2_SMART_POINTER_ILLNESS_H
