#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Doctor; // forward declaration

class Patient
{
private:
    string m_name;
    vector<Doctor *> m_doctors;

public:
    Patient(string name_in)
        : m_name(name_in)
    {
    }

    void addDoctor(Doctor *new_doctor)
    {
        m_doctors.push_back(new_doctor);
    }

    void meetDoctors();

    friend class Doctor;
};

class Doctor
{
private:
    string m_name;
    vector<Patient *> m_patient;

public:
    Doctor(string name_in)
        : m_name(name_in)
    {
    }

    void addPatient(Patient *new_patient)
    {
        m_patient.push_back(new_patient);
    }

    void meetPatient()
    {
        for (auto &ele : m_patient)
        {
            cout << "Meet patient : " << ele->m_name << endl;
        }
    }
    friend class Patient;
};

void Patient::meetDoctors()
{
    for (auto &ele : m_doctors)
    {
        cout << "Meet doctor : " << ele->m_name << endl;
    }
}

int main()
{
    Patient *p1 = new Patient("Jack Jack");
    Patient *p2 = new Patient("Dash");
    Patient *p3 = new Patient("Violet");

    Doctor *d1 = new Doctor("Doctor K");
    Doctor *d2 = new Doctor("Doctor L");

    p1->addDoctor(d1);
    d1->addPatient(p1);

    p2->addDoctor(d2);
    d2->addPatient(p2);

    p2->addDoctor(d1);
    d1->addPatient(p2);

    p1->meetDoctors();
    d1->meetPatient();

    delete p1;
    delete p2;
    delete p3;

    delete d1;
    delete d2;

    return 0;
}