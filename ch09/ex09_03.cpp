#include "std_lib_facilities.h"

class Name_pairs
{
public:
    void read_names(istream& is);
    void read_ages(istream& is);
    void sort();

    vector<string> name() const { return m_name; }
    vector<double> age() const { return m_age; }

private:
    vector<string> m_name;
    vector<double> m_age;

    int index_of(const vector<string>& v, string str);
};

ostream& operator<<(ostream& os, const Name_pairs& np);
bool operator==(const Name_pairs& lhs, const Name_pairs& rhs);
bool operator!=(const Name_pairs& lhs, const Name_pairs& rhs);

int main()
try {
    cout << "enter several names, end by '|': ";
    Name_pairs np1;
    np1.read_names(cin);
    np1.read_ages(cin);
    cout << np1;

    cout << "enter the other several names, end by '|': ";
    Name_pairs np2;
    np2.read_names(cin);
    np2.read_ages(cin);
    cout << np2;

    cout << "the two pairs are " << (np1 == np2 ? "equal" : "not equal") << '\n';
    return 0;
}
catch (const std::exception& e) {
    cout << e.what() << '\n';
    return 1;
}

// implementation of Name_pairs
void Name_pairs::read_names(istream& is)
{
    for (string name; is >> name;) {
        if (name == "|") {
            break;
        }
        m_name.push_back(name);
    }
}

void Name_pairs::read_ages(istream& is)
{
    if (m_name.empty()) {
        error("no input names");
    }

    for (const auto& name : m_name) {
        cout << "enter an age for " << name << ':';
        double age;
        is >> age;
        m_age.push_back(age);
    }
}

void Name_pairs::sort()
{
    vector<string> name_copies(m_name);      // copies
    std::sort(m_name.begin(), m_name.end());       // sort m_name
    vector<double> age_copies;      // empty

    for (size_t i = 0; i != m_name.size(); ++i) {       // ordered already
        age_copies.push_back(m_age[index_of(name_copies, m_name[i])]);        // add in order
    }
    m_age.swap(age_copies);  // get the ordered m_age
}

int Name_pairs::index_of(const vector<string>& v, string str)
{
    for (size_t i = 0; i != v.size(); ++i) {       // simple search
        if (v[i] == str) {
            return i;
        }
    }
    return -1;
}

// implementationn of global functions
ostream& operator<<(ostream& os, const Name_pairs& np)
{
    if (np.name().size() != np.age().size()) {
        error("not paired");
    }

    for (size_t i = 0; i != np.name().size(); ++i) {
        os << '(' << np.name()[i] << ',' << np.age()[i] << ")\n";
    }
    return os;
}

bool operator==(const Name_pairs& lhs, const Name_pairs& rhs)
{
    return lhs.name() == rhs.name() && lhs.age() == rhs.age();
}

bool operator!=(const Name_pairs& lhs, const Name_pairs& rhs)
{
    return !(lhs == rhs);
}
