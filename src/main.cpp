#include "tasks.h"

void
test_medical_specialty();

void
test_illness();

void
test_patient();

void
test_hcp();

void
test_hospital();

void
test_task_1();

void
test_task_2();

void
test_task_3();

void
test_task_4();

void
print_map(const std::map<Medical_Specialty, size_t>& specialities);

int
main()
{
    // Test Medical_Specialty
    test_medical_specialty();

    // Test Illness
    test_illness();

    // Test Patient
    test_patient();

    // Test HCP
    test_hcp();

    // Test Hospital
    test_hospital();

    // Task 1
    test_task_1();

    // Task 2
    test_task_2();


    // Task 3
    test_task_3();

    // Task 4
    test_task_4();
}

void
test_task_1()
{
    std::shared_ptr<Health_Care_Provider> s1 {
            std::make_shared<Smart_Health_Care_Provider>(100, "Smart 1",
                                                         std::set<Medical_Specialty> {
                                                                 SPECIALTIES[0],
                                                                 SPECIALTIES[6]}, 220)};
    std::shared_ptr<Health_Care_Provider> s2 {
            std::make_shared<Smart_Health_Care_Provider>(100, "Smartsssss 2",
                                                         std::set<Medical_Specialty> {
                                                                 SPECIALTIES[0],
                                                                 SPECIALTIES[3]}, 3210)};
    std::shared_ptr<Health_Care_Provider> s3 {
            std::make_shared<Smart_Health_Care_Provider>(100, "Smartww 3",
                                                         std::set<Medical_Specialty> {
                                                                 SPECIALTIES[2],
                                                                 SPECIALTIES[6],
                                                                 SPECIALTIES[3]}, 22)};
    std::shared_ptr<Health_Care_Provider> s4 {
            std::make_shared<Smart_Health_Care_Provider>(100, "Smarte 4",
                                                         std::set<Medical_Specialty> {
                                                                 SPECIALTIES[3],
                                                                 SPECIALTIES[6],
                                                                 SPECIALTIES[5]}, 44)};

    std::cout << "[";
    for (const auto& x: task1({})) {
        std::cout << *x << ",";
    }
    std::cout << "]" << std::endl << "[";
    for (const auto& x: task1({s1, s2, s3, s4})) {
        std::cout << *x << ",";
    }
    std::cout << "]" << std::endl << "[";
    for (const auto& x: task1({s1, s2})) {
        std::cout << *x << ",";
    }
    std::cout << "]" << std::endl << "[";
    for (const auto& x: task1({s3, s4})) {
        std::cout << *x << ",";
    }
    std::cout << "]" << std::endl << "[";
    for (const auto& x: task1({s1, s4})) {
        std::cout << *x << ",";
    }
    std::cout << "]" << std::endl;
}

void
test_task_2()
{
    Special_Hospital sp {"1 and 2"};
    Illness i1 {SPECIALTIES[0], "A"};
    Illness i2 {SPECIALTIES[1], "AB"};
    Illness i3 {SPECIALTIES[2], "A"};
    Illness i4 {SPECIALTIES[2], "A"};
    std::shared_ptr<Patient> p1 {
            std::make_shared<Patient>("Hera", 69, std::set<Illness> {i1, i2, i3, i4}, 0)};
    std::shared_ptr<Patient> p2 {
            std::make_shared<Patient>("Hera2", 69, std::set<Illness> {i1, i2, i3}, 0)};
    std::shared_ptr<Patient> p3 {
            std::make_shared<Patient>("Hera2", 69, std::set<Illness> {i4, i3}, 0)};
    std::cout << sp << std::endl;
    print_map(sp.get_map());
    std::cout << sp.admit_patient(p1) << std::endl;
    std::cout << sp.admit_patient(p1) << std::endl;
    std::cout << sp.dismiss_patient(p1->get_name()) << std::endl;
    std::cout << sp.admit_patient(p1) << std::endl;
    std::cout << sp.dismiss_patient(p1->get_name()) << std::endl;
    std::cout << sp.admit_patient(p2) << std::endl;
    std::cout << sp.admit_patient(p2) << std::endl;
    std::cout << sp.dismiss_patient(p2->get_name()) << std::endl;
    print_map(sp.get_map());
    std::cout << sp.admit_patient(p2) << std::endl;
    std::cout << sp.dismiss_patient(p2->get_name()) << std::endl;
    std::cout << sp.admit_patient(p3) << std::endl;
    std::cout << sp.dismiss_patient(p3->get_name()) << std::endl;
    std::cout << sp.admit_patient(p3) << std::endl;
    std::cout << sp.dismiss_patient(p3->get_name()) << std::endl;
    print_map(sp.get_map());
    {
        std::shared_ptr<Patient> p4 {
                std::make_shared<Patient>("Hera4", 69, std::set<Illness> {i1, i2, i3}, 0)};
        std::cout << sp.admit_patient(p4) << std::endl;
        std::cout << sp.admit_patient(p4) << std::endl;
        print_map(sp.get_map());
    }
    {
        std::shared_ptr<Patient> p4 {
                std::make_shared<Patient>("Hera4", 69, std::set<Illness> {i1}, 0)};
        std::cout << sp.admit_patient(p4) << std::endl;
        std::cout << sp.admit_patient(p4) << std::endl;
        print_map(sp.get_map());
    }
    std::cout << sp << std::endl;
    print_map(sp.get_map());
}

void
test_task_3()
{
    Task3_HCP x {100, "X", std::set<Medical_Specialty> {}, 0};
    Task3_HCP y {100, "Y", std::set<Medical_Specialty> {SPECIALTIES[0], SPECIALTIES[1]},
                 10};
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    y.receive_license(SPECIALTIES[0]);
    x.receive_license(SPECIALTIES[0]);
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    y.receive_license(SPECIALTIES[0]);
    x.receive_license(SPECIALTIES[0]);
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    y.receive_license(SPECIALTIES[3]);
    x.receive_license(SPECIALTIES[3]);
    y.receive_license(SPECIALTIES[0]);
    x.receive_license(SPECIALTIES[0]);
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    x.receive_license(SPECIALTIES[2]);
    y.receive_license(SPECIALTIES[2]);
    y.receive_license(SPECIALTIES[3]);
    x.receive_license(SPECIALTIES[3]);
    std::cout << x << std::endl;
    std::cout << y << std::endl;
}

void
test_task_4()
{
    Illness i1 {SPECIALTIES[0], "AAA"};
    Illness i2 {SPECIALTIES[0], "AB"};
    Illness i3 {SPECIALTIES[2], "AAASS"};
    Illness i4 {SPECIALTIES[3], "ADASD"};
    Illness i5 {SPECIALTIES[3], "AB"};
    std::shared_ptr<Patient> p1 {
            std::make_shared<Patient>("Hera", 9, std::set<Illness> {i1, i2}, 10)};
    std::shared_ptr<Patient> p2 {
            std::make_shared<Patient>("Hera2", 69, std::set<Illness> {i1, i4, i3}, 220)};
    std::shared_ptr<Patient> p3 {
            std::make_shared<Patient>("Hera2", 69, std::set<Illness> {i4, i1}, 30)};
    std::shared_ptr<Patient> p4 {
            std::make_shared<Patient>("Hera4", 9, std::set<Illness> {i4, i5, i1, i2, i3},
                                      1110)};
    std::shared_ptr<Patient> p5 {
            std::make_shared<Patient>("Hera5", 9, std::set<Illness> {i4, i1, i2, i3},
                                      1110)};
    std::shared_ptr<Patient> p6 {
            std::make_shared<Patient>("Hera6", 9, std::set<Illness> {i4, i5, i2, i3},
                                      1110)};
    Super_Task st1 {{p1, p2, p4}};
    Super_Task st2 {{p1, p2, p3, p4, p5, p6}};
    p2.reset();
    std::cout << "[";
    for (const auto& x: st1.screening({SPECIALTIES[0]})) {
        std::cout << *x << ",";
    }
    std::cout << "]" << std::endl << "[";
    for (const auto& x: st2.screening({SPECIALTIES[2]})) {
        std::cout << *x << ",";
    }
    std::cout << "]" << std::endl << "[";
    for (const auto& x: st1.screening({SPECIALTIES[0], SPECIALTIES[2]})) {
        std::cout << *x << ",";
    }
    std::cout << "]" << std::endl << "[";
    for (const auto& x: st2.screening({SPECIALTIES[2], SPECIALTIES[6]})) {
        std::cout << *x << ",";
    }
    std::cout << "]" << std::endl << "[";
    for (const auto& x: st1.screening({SPECIALTIES[3], SPECIALTIES[0]})) {
        std::cout << *x << ",";
    }
    std::cout << "]" << std::endl << "[";
    for (const auto& x: st2.screening({SPECIALTIES[3], SPECIALTIES[0]})) {
        std::cout << *x << ",";
    }
    std::cout << "]" << std::endl << "[";
    for (const auto& x: st1.screening({})) {
        std::cout << *x << ",";
    }
    std::cout << "]" << std::endl << "[";
    for (const auto& x: st2.screening({})) {
        std::cout << *x << ",";
    }
    std::cout << "]" << std::endl;
}

void
test_medical_specialty()
{
    std::copy(SPECIALTIES.begin(), SPECIALTIES.end(),
              std::experimental::make_ostream_joiner(std::cerr, "\n"));

    std::copy(SPECIALTIES.begin(), SPECIALTIES.end(),
              std::experimental::make_ostream_joiner(std::cout, "\n"));

    std::cout << std::endl;
}

void
test_illness()
{
    // Check Ctor:
    try {
        Illness {SPECIALTIES[0], ""};
    }
    catch (std::runtime_error& e) {
        std::cout << "No name detected" << std::endl;
    }

    {
        const Illness x {SPECIALTIES[0], "ABC"};
        std::cout << x.get_name() << ", " << x.get_specialty() << std::endl;
    }

    const std::vector<std::string> names {"A", "A", "a", "AA", "CCC", "D"};
    std::vector<Illness> ills;

    for (const auto& n: names) {
        for (const auto& m: SPECIALTIES) {
            ills.push_back(Illness {m, n});
        }
    }

    for (const auto& n: names) {
        for (const auto& m: SPECIALTIES) {
            ills.push_back(Illness {m, n});
        }
    }

    const std::set<Illness> x {ills.begin(), ills.end()};

    std::copy(x.begin(), x.end(), std::experimental::make_ostream_joiner(std::cerr, "\n"));
    std::copy(x.begin(), x.end(), std::experimental::make_ostream_joiner(std::cout, "\n"));
    std::cout << std::endl;
    std::cout << (Illness {SPECIALTIES[0], "A"} == Illness {SPECIALTIES[0], "A"});
    std::cout << (Illness {SPECIALTIES[1], "A"} == Illness {SPECIALTIES[0], "A"});
    std::cout << (Illness {SPECIALTIES[0], "A"} == Illness {SPECIALTIES[0], "B"});
    std::cout << std::endl;
}

void
test_patient()
{
    //Patient(const std::string&,int,const std::set<Illness>&,unsigned=200);
    const std::vector<std::string> names {"Hera", "Aphrodite", "Koarl", "Franz"};
    Illness i1 {SPECIALTIES[1], "A"};
    Illness i2 {SPECIALTIES[1], "AB"};
    Illness i3 {SPECIALTIES[0], "A"};
    // Patient Ctor
    try {
        Patient {"", 1, {i1}};
    }
    catch (std::runtime_error& e) {
        std::cout << "Patient no name" << std::endl;
    }
    try {
        Patient {"A", 1, std::set<Illness> {}};
    }
    catch (std::runtime_error& e) {
        std::cout << "Patient no illness at start" << std::endl;
    }
    try {
        Patient {"A", -1, std::set<Illness> {i1}};
    }
    catch (std::runtime_error& e) {
        std::cout << "Patient negative age" << std::endl;
    }
    Patient p {"Hera", 69, {i1, i2}, 0};
    Patient p2 {"Hera", 69, {i1, i2}, 0};
    std::cout << p << std::endl;
    std::cout << "equals: " << (p == p2) << std::endl;
    std::cout << p.get_name() << std::endl;
    std::cout << "Pay 0: " << p.pay_procedure(0) << std::endl;
    std::cout << "Pay 1: " << p.pay_procedure(1) << std::endl;
    p.increase_wealth(1);
    std::cout << "equals: " << (p == p2) << std::endl;
    std::cout << "Pay 1: " << p.pay_procedure(1) << std::endl;
    std::cout << "Pay 1: " << p.pay_procedure(1) << std::endl;
    std::cout << "Healthy: " << p.healthy() << std::endl;
    p.catch_disease(i1);
    std::cout << "equals: " << (p == p2) << std::endl;
    std::cout << p << std::endl;
    std::cout << "Require in " << p.requires_treatment_in(SPECIALTIES[0]) << std::endl;
    std::cout << "Require in " << p.requires_treatment_in(SPECIALTIES[1]) << std::endl;
    p.catch_disease(i2);
    p.catch_disease(i3);
    std::cout << "Cure: " << p.cure(SPECIALTIES[1]) << std::endl;
    std::cout << "Healthy: " << p.healthy() << std::endl;
    std::cout << "Require in " << p.requires_treatment_in(SPECIALTIES[1]) << std::endl;
    p.catch_disease(i1);
    std::cout << "Require in " << p.requires_treatment_in(SPECIALTIES[1]) << std::endl;
    std::cout << "Cure: " << p.cure(SPECIALTIES[1]) << std::endl;
    std::cout << "Cure: " << p.cure(SPECIALTIES[1]) << std::endl;
    std::cout << p << std::endl;
}

void
test_hcp()
{
    const std::vector<std::string> names {"Hera", "Aphrodite", "Koarl", "Franz"};

    //Teaching_Health_Care_Provider(unsigned fee,const std::string&,const std::set<Medical_Specialty>&,unsigned=500);
    try {
        Teaching_Health_Care_Provider(20, "", std::set<Medical_Specialty> {});
    }
    catch (std::runtime_error&) {
        std::cout << "HCP Ctor No Name" << std::endl;
    }
    try {
        Smart_Health_Care_Provider(20, "", std::set<Medical_Specialty> {});
    }
    catch (std::runtime_error&) {
        std::cout << "HCP Ctor No Name" << std::endl;
    }
    Teaching_Health_Care_Provider t1 {100, "Teacher 1", std::set<Medical_Specialty> {}, 0};
    std::cout << t1 << std::endl;
    std::cout << "Eligible for " << t1.eligible_for(SPECIALTIES[0]) << std::endl;
    std::cout << "Pay 1 " << t1.pay_license(1) << std::endl;
    std::cout << "Pay 0 " << t1.pay_license(0) << std::endl;
    t1.increase_wealth(1);
    std::cout << "Pay 1 " << t1.pay_license(1) << std::endl;
    std::cout << "Pay 1 " << t1.pay_license(1) << std::endl;
    t1.receive_license(SPECIALTIES[0]);
    std::cout << "Eligible for " << t1.eligible_for(SPECIALTIES[0]) << std::endl;
    std::cout << t1 << std::endl;
    std::cout << t1.get_name() << std::endl;
    Illness i1 {SPECIALTIES[1], "A"};
    Illness i2 {SPECIALTIES[0], "AB"};
    Illness i3 {SPECIALTIES[0], "A"};
    std::shared_ptr<Patient> sp {
            std::make_shared<Patient>("Hera", 69, std::set<Illness> {i1, i2, i3}, 0)};
    std::cout << "Perform: " << t1.perform_procedure(200, sp, SPECIALTIES[2]) << std::endl;
    std::cout << t1 << std::endl;
    sp->increase_wealth(3000);
    std::cout << "Perform: " << t1.perform_procedure(200, sp, SPECIALTIES[2]) << std::endl;
    std::cout << t1 << std::endl;
    std::cout << "Perform: " << t1.perform_procedure(200, sp, SPECIALTIES[0]) << std::endl;
    std::cout << t1 << std::endl;
    std::cout << "Perform: " << t1.perform_procedure(200, sp, SPECIALTIES[0]) << std::endl;
    std::cout << t1 << std::endl;
    std::shared_ptr<Health_Care_Provider> s1 {
            std::make_shared<Smart_Health_Care_Provider>(100, "Smart 1",
                                                         std::set<Medical_Specialty> {},
                                                         0)};
    std::shared_ptr<Health_Care_Provider> t2 {
            std::make_shared<Teaching_Health_Care_Provider>(100, "Teach 2",
                                                            std::set<Medical_Specialty> {},
                                                            30000)};
    std::cout << "Teach: " << t1.teach(SPECIALTIES[2], s1) << std::endl;
    std::cout << "Teach: " << t1.teach(SPECIALTIES[0], s1) << std::endl;
    s1->increase_wealth(2000);
    std::cout << "Teach: " << t1.teach(SPECIALTIES[2], s1) << std::endl;
    std::cout << "Teach: " << t1.teach(SPECIALTIES[0], s1) << std::endl;
    std::cout << "Teach: " << t1.teach(SPECIALTIES[0], s1) << std::endl;
    std::cout << t1 << std::endl;
    std::cout << *s1 << std::endl;
    std::cout << "Teach: " << t1.teach(SPECIALTIES[0], t2) << std::endl;
    std::cout << t1 << std::endl;
    std::cout << *t2 << std::endl;
}

void
test_hospital()
{
    const std::vector<std::string> names {"Hera", "Aphrodite", "Koarl", "Franz"};

    try {
        Hospital("");
    }
    catch (std::runtime_error&) {
        std::cout << "Hospital Ctor No Name" << std::endl;
    }

    std::shared_ptr<Health_Care_Provider> s1 {
            std::make_shared<Smart_Health_Care_Provider>(100, "Smart 1",
                                                         std::set<Medical_Specialty> {
                                                                 SPECIALTIES[0],
                                                                 SPECIALTIES[6]}, 0)};
    std::shared_ptr<Health_Care_Provider> s2 {
            std::make_shared<Smart_Health_Care_Provider>(100, "Smart 2",
                                                         std::set<Medical_Specialty> {
                                                                 SPECIALTIES[1],
                                                                 SPECIALTIES[2]}, 2000)};
    Hospital h {"Hospital"};
    Illness i1 {SPECIALTIES[1], "A"};
    Illness i2 {SPECIALTIES[0], "AB"};
    Illness i3 {SPECIALTIES[0], "A"};
    std::cout << h << std::endl;
    std::cout << "Sign: " << h.sign_hcp(s1) << std::endl;
    std::cout << "Sign: " << h.sign_hcp(s1) << std::endl;
    std::cout << h << std::endl;
    std::cout << "Sign: " << h.sign_hcp(s2) << std::endl;
    std::cout << h << std::endl;
    std::cout << *h.get_hcp(s2->get_name()) << std::endl;
    std::cout << "Dismiss: " << h.dismiss_hcp(s2->get_name()) << std::endl;
    std::cout << h << std::endl;
    try {
        std::cout << h.get_hcp(s2->get_name()) << std::endl;
    }
    catch (std::runtime_error&) {
        std::cout << "HCP not found" << std::endl;
    }
    std::cout << "Dismiss: " << h.dismiss_hcp(s2->get_name()) << std::endl;
    std::cout << h << std::endl;

    std::shared_ptr<Patient> p1 {
            std::make_shared<Patient>("Hera", 69, std::set<Illness> {i1, i2, i3}, 0)};
    std::shared_ptr<Patient> p2 {
            std::make_shared<Patient>("Hera2", 69, std::set<Illness> {i1, i2, i3}, 0)};
    std::shared_ptr<Patient> p3 {
            std::make_shared<Patient>("Hera2", 69, std::set<Illness> {i1, i2, i3}, 20)};
    std::cout << "Admit: " << h.admit_patient(p1) << std::endl;
    std::cout << "Admit: " << h.admit_patient(p1) << std::endl;
    std::cout << h << std::endl;
    std::cout << "Admit: " << h.admit_patient(p2) << std::endl;
    std::cout << "Admit: " << h.admit_patient(p3) << std::endl;
    std::cout << h << std::endl;
    p2 = nullptr;
    std::cout << h << std::endl;
    std::cout << "Admit: " << h.admit_patient(p3) << std::endl;
    std::cout << h << std::endl;
    std::cout << *h.get_patient("Hera2") << std::endl;
    p3 = nullptr;
    try {
        std::cout << h.get_patient("Hera2") << std::endl;
    }
    catch (std::runtime_error&) {
        std::cout << "Patient not found" << std::endl;
    }
    std::cout << "Dismiss: " << h.dismiss_patient("Hera") << std::endl;
    std::cout << "Dismiss: " << h.dismiss_patient("Hera") << std::endl;
    std::cout << "Dismiss: " << h.dismiss_patient("Hera2") << std::endl;
    std::cout << h << std::endl;
}

void
print_map(const std::map<Medical_Specialty, size_t>& specialities)
{
    if (specialities.empty()) {
        std::cout << "Empty map\n";
    }

    for (const auto& [key, speciality]: specialities) {
        std::cout << key << ": " << speciality << std::endl;
    }
}
