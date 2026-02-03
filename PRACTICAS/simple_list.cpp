#include <iostream>

class StringNode
{
private:
    std::string elem;
    StringNode *next;

    friend class StringLinkedList;
};

class StringLinkedList
{
    private:
        StringNode *head;
    public:
        StringLinkedList() : head(nullptr) {
            std::cout << "Lista de nodos creada"<<std::endl;
            std::cout << std::endl;
        }
        ~StringLinkedList()
        {
            while (!empty())
                remove_front();

            std::cout << std::endl;
            std::cout << "Lista simplemente enlazada de strings eliminada con exito" << std::endl;
            std::cout << std::endl;
        }

        bool empty() const { 
            return head == nullptr;
        }
        
        const std::string &front() const {
            return head->elem;
        }
        
        void add_front(const std::string &e)
        {
            StringNode *v = new StringNode;
            v->elem = e;
            v->next = head;
            head = v;
        }
        
        void remove_front() {
            StringNode* old = head;
            head = old->next;
            std::cout << std::endl;
            std::cout << "Elemento eliminado: " << (old->elem) << std::endl;
            delete old;
        }
};

int main() {
    std::string value;
    StringLinkedList a;
    int i = 0;
    while(i < 4) {
        std::cout << "Introduce un valor para la lista" << std::endl;
        std::cin >> value;
        
        a.add_front(value);
        i++;
    }
}