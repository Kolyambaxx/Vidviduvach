// Мшвмшвгмфср.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

class ConcreteElementA;
class ConcreteElementB;

class Element {
public:
    virtual void accept(class Visitor& visitor) = 0;
    virtual ~Element() = default;
};

class ConcreteElementA : public Element {
public:
    void accept(Visitor& visitor) override;
    void operationA() const {
        std::cout << "ConcreteElementA operationA()" << std::endl;
    }
};

class ConcreteElementB : public Element {
public:
    void accept(Visitor& visitor) override;
    void operationB() const {
        std::cout << "ConcreteElementB operationB()" << std::endl;
    }
};

class Visitor {
public:
    virtual void visitConcreteElementA(ConcreteElementA& elementA) = 0;
    virtual void visitConcreteElementB(ConcreteElementB& elementB) = 0;
    virtual ~Visitor() = default;
};

class ConcreteVisitor : public Visitor {
public:
    void visitConcreteElementA(ConcreteElementA& elementA) override;
    void visitConcreteElementB(ConcreteElementB& elementB) override;
};


class ObjectStructure {
public:
    void addElement(Element* element) {
        elements.push_back(element);
    }

    void accept(Visitor& visitor) {
        for (Element* element : elements) {
            element->accept(visitor);
        }
    }

private:
    std::vector<Element*> elements;
};



void ConcreteElementA::accept(Visitor& visitor) {
    visitor.visitConcreteElementA(*this);
}

void ConcreteElementB::accept(Visitor& visitor) {
    visitor.visitConcreteElementB(*this);
}



void ConcreteVisitor::visitConcreteElementA(ConcreteElementA& elementA) {
    std::cout << "ConcreteVisitor visiting ConcreteElementA" << std::endl;
    elementA.operationA();
}

void ConcreteVisitor::visitConcreteElementB(ConcreteElementB& elementB) {
    std::cout << "ConcreteVisitor visiting ConcreteElementB" << std::endl;
    elementB.operationB();
}

int main() {
    ConcreteElementA elementA;
    ConcreteElementB elementB;

    ObjectStructure objectStructure;
    objectStructure.addElement(&elementA);
    objectStructure.addElement(&elementB);

    ConcreteVisitor visitor;
    objectStructure.accept(visitor);

    return 0;
}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
