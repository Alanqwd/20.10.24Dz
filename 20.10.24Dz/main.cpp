#include <iostream>
#include <string>


class Plant {
protected:
    std::string name;
    std::string size; 
    float height;

public:
    Plant(const std::string& name, const std::string& size, float height)
        : name(name), size(size), height(height) {}

    virtual ~Plant() {}

    virtual void collectFruits() = 0; 
    virtual void printInfo() const = 0; 
};


class Bush : public Plant {
public:
    Bush(const std::string& name, float height)
        : Plant(name, "���������", height) {}

    void collectFruits() override {
        std::cout << "�������� ����� � �����: " << name << std::endl;
    }

    void printInfo() const override {
        std::cout << "����: " << name << ", ������: " << size << ", ������: " << height << std::endl;
    }
};


class Tree : public Plant {
protected:
    int fruitsAvailable;

public:
    Tree(const std::string& name, float height, int fruitsAvailable)
        : Plant(name, "�������", height), fruitsAvailable(fruitsAvailable) {}

    virtual void collectFruits() = 0;

    void printInfo() const override {
        std::cout << "������: " << name << ", ������: " << size << ", ������: " << height
            << ", �������� ������: " << fruitsAvailable << std::endl;
    }
};


class Fruit {
protected:
    std::string name;
    float weight;

public:
    Fruit(const std::string& name, float weight)
        : name(name), weight(weight) {}

    virtual ~Fruit() {}

    virtual void printInfo() const = 0; 
};


class Berry : public Fruit {
public:
    Berry(const std::string& name, float weight)
        : Fruit(name, weight) {}

    void printInfo() const override {
        std::cout << "�����: " << name << ", ���: " << weight << " �" << std::endl;
    }
};


class FruitClass : public Fruit {
public:
    FruitClass(const std::string& name, float weight)
        : Fruit(name, weight) {}

    void printInfo() const override {
        std::cout << "�����: " << name << ", ���: " << weight << " �" << std::endl;
    }
};


class AppleTree : public Tree {
public:
    AppleTree(float height, int fruitsAvailable)
        : Tree("������", height, fruitsAvailable) {}

    void collectFruits() override {
        std::cout << "�������� ������ � ������." << std::endl;
    }

    void printInfo() const override {
        Tree::printInfo();
    }
};


class PearTree : public Tree {
public:
    PearTree(float height, int fruitsAvailable)
        : Tree("�����", height, fruitsAvailable) {}

    void collectFruits() override {
        std::cout << "�������� �����." << std::endl;
    }

    void printInfo() const override {
        Tree::printInfo();
    }
};


class RaspberryBush : public Bush {
public:
    RaspberryBush(float height)
        : Bush("������", height) {}

    void collectFruits() override {
        std::cout << "�������� ������." << std::endl;
    }

    void printInfo() const override {
        Bush::printInfo();
    }
};


class BlueberryBush : public Bush {
public:
    BlueberryBush(float height)
        : Bush("�������", height) {}

    void collectFruits() override {
        std::cout << "�������� �������." << std::endl;
    }

    void printInfo() const override {
        Bush::printInfo();
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    AppleTree appleTree(3.5, 10);
    PearTree pearTree(4.0, 15);
    RaspberryBush raspberryBush(1.0);
    BlueberryBush blueberryBush(0.8);

    Plant* plants[4] = { &appleTree, &pearTree, &raspberryBush, &blueberryBush };

    for (int i = 0; i < 4; ++i) {
        plants[i]->printInfo();
        plants[i]->collectFruits();
        std::cout << std::endl;
    }

    return 0;
}