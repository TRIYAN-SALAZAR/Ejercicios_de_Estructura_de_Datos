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
        
        void insert_at_the_beginning(int, int, float, const std::string&, const std::string&);
        void insert_at_the_end(int , int, float, const std::string&, const std::string&);

        Node* search_by_name(const std::string&, const std::string&);
        Node* search_by_age(int);
        Node* search_by_grade(int);
        Node* search_at_position(int);
        bool contains(const std::string&, const std::string&);

        bool delete_at_position(int);
        bool delete_by_name(const std::string&, const std::string&);
        bool delete_first();
        void delete_all();

        void show_all() const;
        void show_at_position(int) const;
        void show_reverse() const;

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