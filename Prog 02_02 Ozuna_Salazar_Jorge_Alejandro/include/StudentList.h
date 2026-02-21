#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include "Node.h"
#include "Student.h"

class StudentList {
    private:
        Node *head;
        Node *current_position;
        Node *previous;
        int total_nodes;

    public:
        StudentList();
        StudentList(Student*); 
        StudentList(const StudentList& other);
        StudentList& operator=(const StudentList& other);
        virtual ~StudentList();

        void insert_at_the_beginning(Student*);
        void insert_at_the_end(Student*);
        void insert_at_position(Student*, int);
        
        Node* search_by_name(const std::string&, const std::string&);
        Node* search_at_position(int);

        bool delete_at_position(int);
        bool delete_by_name(const std::string&, const std::string&);
        bool delete_first();
        void delete_all();

        void show_all() const;
        void show_at_position(int) const;

        bool is_empty() const;
        int size() const;
        
        Node* first();
        Node* last();
        Node* get_current();
        Node* next_node();
        Node* previous_node();
        void reset_current();

};

#endif // STUDENTLIST_H