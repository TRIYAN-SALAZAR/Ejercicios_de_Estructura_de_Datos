#include <iostream>
#include <SinglyLinkedList.h>

using std::cout;
using std::endl;

int main() {
    cout << "\n";
    cout << "=========================================\n";
    cout << "    PRUEBAS SINGLY LINKED LIST\n";
    cout << "=========================================\n";
    
    SinglyLinkedList list;
    
    // TEST 1: Lista vacia
    cout << "\n--- TEST 1: Lista vacia inicial ---\n";
    cout << "Vacia: " << (list.is_empty() ? "SI" : "NO") << " | Tamano: " << list.size() << endl;
    cout << ">> Esperado: Vacia=SI, Tamano=0\n";
    
    // TEST 2: Insertar al inicio
    cout << "\n--- TEST 2: Insertar al inicio: 10, 20, 30 ---\n";
    list.insert_at_the_beggining(10);
    list.insert_at_the_beggining(20);
    list.insert_at_the_beggining(30);
    cout << "Vacia: " << (list.is_empty() ? "SI" : "NO") << endl;
    cout << ">> Esperado: [30->20->10], Tamano: 3" << endl;

    cout << ">> Resultado: [";
    list.show_all();
    cout << "]" << "Tamano: " << list.size() << endl;
    
    // TEST 3: Insertar al final
    cout << "\n--- TEST 3: Insertar al final: 5, 1 ---\n";
    list.insert_at_the_end(5);
    list.insert_at_the_end(1);
    cout << ">> Esperado: [30->20->10->5->1], Tamano=5\n";
    cout << ">> Resultado: [";
    list.show_all();
    cout << "]" << "Tamano: " << list.size() << endl;
    
    // TEST 4: Insertar en posicion
    cout << "\n--- TEST 4: Insertar en posicion ---\n";
    
    cout << "  4.1) Insertar 15 despues de 20\n";
    list.insert_in_a_position(15, 20);
    cout << "  >> Esperado: [30->20->15->10->5->1], Tamano=6\n";
    cout << ">> Resultado: [";
    list.show_all();
    cout << "]" << "Tamano: " << list.size() << endl;

    cout << "\n  4.2) Insertar 25 despues de 10\n";
    list.insert_in_a_position(25, 10);
    cout << "  >> Esperado: [30->20->15->10->25->5->1], Tamano=7\n";
    cout << ">> Resultado: [";
    list.show_all();
    cout << "]" << "Tamano: " << list.size() << endl;
    
    cout << "\n  4.3) Insertar 0 despues de 1 (ultimo nodo)\n";
    list.insert_in_a_position(0, 1);
    cout << "  >> Esperado: [30->20->15->10->25->5->1->0], Tamano=8\n";
    cout << ">> Resultado: [";
    list.show_all();
    cout << "]" << "Tamano: " << list.size() << endl;
    
    cout << "\n  4.4) Insertar despues de valor inexistente (99)\n";
    list.insert_in_a_position(100, 99);
    cout << "  Tamano: " << list.size() << endl;
    cout << "  >> Esperado: Mensaje 'no encontrado', Tamano=8\n";
    
    // TEST 5: Eliminar nodos
    cout << "\n--- TEST 5: Eliminar nodos ---\n";
    
    cout << "  5.1) Eliminar nodo con valor 15\n";
    list.delete_one(15);
    cout << "  >> Esperado: [30->20->10->25->5->1->0], Tamano=7\n";
    cout << ">> Resultado: [";
    list.show_all();
    cout << "]" << "Tamano: " << list.size() << endl;
    
    cout << "\n  5.2) Eliminar primer nodo (30)\n";
    list.delete_one(30);
    cout << "  >> Esperado: [20->10->25->5->1->0], Tamano=6\n";
    cout << ">> Resultado: [";
    list.show_all();
    cout << "]" << "Tamano: " << list.size() << endl;
    
    cout << "\n  5.3) Eliminar ultimo nodo (0)\n";
    list.delete_one(0);
    cout << "  >> Esperado: [20->10->25->5->1], Tamano=5\n";
    cout << ">> Resultado: [";
    list.show_all();
    cout << "]" << "Tamano: " << list.size() << endl;
    
    cout << "\n  5.4) Eliminar valor inexistente (99)\n";
    list.delete_one(99);
    cout << "  Tamano: " << list.size() << endl;
    cout << "  >> Esperado: Mensaje 'no encontrado', Tamano=5\n";
    
    // TEST 6: Lista nueva
    cout << "\n--- TEST 6: Pruebas con lista nueva ---\n";
    SinglyLinkedList list2;
    
    cout << "  6.1) Insertar en lista vacia\n";
    list2.insert_at_the_end(100);
    cout << "  >> Esperado: [100], Tamano=1\n";
    cout << ">> Resultado: [";
    list2.show_all();
    cout << "]" << "Tamano: " << list2.size() << endl;
    
    cout << "\n  6.2) Eliminar unico elemento\n";
    list2.delete_one(100);
    cout << "Vacia: " << (list2.is_empty() ? "SI" : "NO") << endl;
    cout << "  >> Esperado: [], Tamano=0, Vacia=SI\n";
    cout << ">> Resultado: [";
    list2.show_all();
    cout << "]" << "Tamano: " << list2.size() << endl;
    
    cout << "\n  6.3) Eliminar de lista vacia\n";
    list2.delete_one(50);
    cout << "  >> Esperado: Mensaje 'Lista esta vacia'\n";
    
    cout << "\n  6.4) Insertar al inicio en lista vacia\n";
    list2.insert_at_the_beggining(200);
    cout << "  >> Esperado: [200], Tamano=1\n";
    cout << ">> Resultado: [";
    list2.show_all();
    cout << "]" << "Tamano: " << list2.size() << endl;
    
    cout << "\n  6.5) Insertar en posicion (1 elemento)\n";
    list2.insert_in_a_position(250, 200);
    cout << "  >> Esperado: [200->250], Tamano=2\n";
    cout << ">> Resultado: [";
    list2.show_all();
    cout << "]" << "Tamano: " << list2.size() << endl;
    
    // TEST 7: Delete all
    cout << "\n--- TEST 7: Eliminar todos los nodos ---\n";
    cout << "Tamano antes: " << list.size() << endl;
    list.delete_all();
    cout << "Tamano despues: " << list.size() << " | Vacia: " << (list.is_empty() ? "SI" : "NO") << endl;
    cout << ">> Esperado: Tamano=0, Vacia=SI\n";
    
    cout << "\n  7.2) Usar lista despues de delete_all\n";
    list.insert_at_the_beggining(500);
    list.insert_at_the_end(600);
    cout << "  >> Esperado: [500->600], Tamano=2\n";
    cout << ">> Resultado: [";
    list.show_all();
    cout << "]" << "Tamano: " << list.size() << endl;
    
    // TEST 8: Operaciones mixtas
    cout << "\n--- TEST 8: Operaciones consecutivas mixtas ---\n";
    SinglyLinkedList list3;
    
    list3.insert_at_the_end(1);
    list3.insert_at_the_end(2);
    list3.insert_at_the_end(3);
    list3.insert_at_the_beggining(0);
    cout << ">> Esperado: [0->1->2->3], Tamano=4\n";
    cout << ">> Resultado: [";
    list3.show_all();
    cout << "]" << "Tamano: " << list3.size() << endl;
    
    cout << "\nEliminar 2...\n";
    list3.delete_one(2);
    cout << ">> Esperado: [0->1->3], Tamano=3\n";
    cout << ">> Resultado: [";
    list3.show_all();
    cout << "]" << "Tamano: " << list3.size() << endl;
    
    cout << "\nInsertar 2 despues de 1...\n";
    list3.insert_in_a_position(2, 1);
    cout << ">> Esperado: [0->1->2->3], Tamano=4\n";
    cout << ">> Resultado: [";
    list3.show_all();
    cout << "]" << "Tamano: " << list3.size() << endl;
    
    cout << "\nEliminar 0 y 3...\n";
    list3.delete_one(0);
    list3.delete_one(3);
    cout << ">> Esperado: [1->2], Tamano=2\n";
    cout << ">> Resultado: [";
    list3.show_all();
    cout << "]" << "Tamano: " << list3.size() << endl;
    
    // TEST 9: Prueba de estres
    cout << "\n--- TEST 9: Prueba de estres ---\n";
    SinglyLinkedList list4;
    
    cout << "Insertando 100 elementos...\n";
    for(int i = 0; i < 100; i++) {
        list4.insert_at_the_end(i);
    }
    cout << "Tamano: " << list4.size() << endl;
    cout << ">> Esperado: Tamano=100\n";
    
    cout << "\nEliminando 50 elementos...\n";
    for(int i = 0; i < 50; i++) {
        list4.delete_one(i);
    }
    cout << "Tamano: " << list4.size() << endl;
    cout << ">> Esperado: Tamano=50\n";
    
    cout << "\nEliminando todos (delete_all)...\n";
    list4.delete_all();
    cout << "Tamano: " << list4.size() << " | Vacia: " << (list4.is_empty() ? "SI" : "NO") << endl;
    cout << ">> Esperado: Tamano=0, Vacia=SI\n";
    
    // TEST 10: Casos edge
    cout << "\n--- TEST 10: Casos edge ---\n";
    SinglyLinkedList list5;
    
    cout << "  10.1) Insertar en posicion en lista vacia\n";
    list5.insert_in_a_position(50, 10);
    cout << "  >> Esperado: [50], Tamano=1\n";
    cout << ">> Resultado: [";
    list5.show_all();
    cout << "]" << "Tamano: " << list5.size() << endl;
    
    cout << "\n  10.2) Insertar mismo valor varias veces\n";
    list5.insert_at_the_end(50);
    list5.insert_at_the_end(50);
    list5.insert_at_the_end(50);
    cout << "  >> Esperado: [50->50->50->50], Tamano=4\n";
    cout << ">> Resultado: [";
    list5.show_all();
    cout << "]" << "Tamano: " << list5.size() << endl;
    
    cout << "\n  10.3) Eliminar primera ocurrencia de duplicado\n";
    list5.delete_one(50);
    cout << "  >> Esperado: [50->50->50], Tamano=3\n";
    cout << ">> Resultado: [";
    list5.show_all();
    cout << "]" << "Tamano: " << list5.size() << endl;
    
    // RESUMEN
    cout << "\n=========================================\n";
    cout << "       TODAS LAS PRUEBAS COMPLETADAS\n";
    cout << "=========================================\n";
    cout << "\n[OK] Revisa que los resultados coincidan\n";
    cout << "[OK] El destructor limpiara las listas\n\n";
    
    return 0;
}