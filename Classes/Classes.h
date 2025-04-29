#include <iostream>
#include <string>
#include <vector>

#include <iostream>
#include <string>
#include <vector>

class BaseClassName {
public:
    enum class eType { CAT, DOG, BIRD };

    virtual ~BaseClassName() = default;

    virtual void Read(std::ostream& ostream, std::istream& istream);
    virtual void Write(std::ostream& ostream);
    std::string GetName();
    virtual eType GetType() = 0;

protected:
    std::string name;
};

class Cat : public BaseClassName {
public:
    void Read(std::ostream& ostream, std::istream& istream) override;
    void Write(std::ostream& ostream) override;
    eType GetType() override;

private:
    int agility;
};

class Dog : public BaseClassName {
public:
    void Read(std::ostream& ostream, std::istream& istream) override;
    void Write(std::ostream& ostream) override;
    eType GetType() override;

private:
    int strength;
};

class Database {
public:
    ~Database();
    void Create(BaseClassName::eType type);
    void DisplayAll();
    void Display(const std::string& name);
    void Display(BaseClassName::eType type);

private:
    std::vector<BaseClassName*> objects;
};

void BaseClassName::Read(std::ostream& ostream, std::istream& istream) {
    ostream << "Enter name: ";
    istream >> name;
}

void BaseClassName::Write(std::ostream& ostream) {
    ostream << "Name: " << name << "\n";
}

std::string BaseClassName::GetName() {
    return name;
}

// Derived Class: Cat
void Cat::Read(std::ostream& ostream, std::istream& istream) {
    BaseClassName::Read(ostream, istream);
    ostream << "Enter agility: ";
    istream >> agility;
}

void Cat::Write(std::ostream& ostream) {
    BaseClassName::Write(ostream);
    ostream << "Agility: " << agility << "\n";
}

BaseClassName::eType Cat::GetType() {
    return eType::CAT;
}

// Derived Class: Dog
void Dog::Read(std::ostream& ostream, std::istream& istream) {
    BaseClassName::Read(ostream, istream);
    ostream << "Enter strength: ";
    istream >> strength;
}

void Dog::Write(std::ostream& ostream) {
    BaseClassName::Write(ostream);
    ostream << "Strength: " << strength << "\n";
}

BaseClassName::eType Dog::GetType() {
    return eType::DOG;
}

// Database Class
Database::~Database() {
    for (BaseClassName* obj : objects) {
        delete obj;
    }
}

void Database::Create(BaseClassName::eType type) {
    BaseClassName* obj = nullptr;
    switch (type) {
    case BaseClassName::eType::CAT:
        obj = new Cat;
        break;
    case BaseClassName::eType::DOG:
        obj = new Dog;
        break;
    default:
        std::cout << "Invalid type.\n";
        return;
    }

    obj->Read(std::cout, std::cin);
    objects.push_back(obj);
}

void Database::DisplayAll() {
    for (BaseClassName* obj : objects) {
        obj->Write(std::cout);
    }
}

void Database::Display(const std::string& name) {
    for (BaseClassName* obj : objects) {
        if (obj->GetName() == name) {
            obj->Write(std::cout);
        }
    }
}

void Database::Display(BaseClassName::eType type) {
    for (BaseClassName* obj : objects) {
        if (obj->GetType() == type) {
            obj->Write(std::cout);
        }
    }
}