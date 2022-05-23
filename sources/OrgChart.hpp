#include <iostream>
#include <string>
#include <vector>
#include <stack> 
namespace ariel
{
    class Node{
        public:
            std::string val;
            Node *sub;
            Node *next;
            int depth;
            Node(std::string val, int depth){
                this->val = val;
                sub = NULL;
                next = NULL;
                this->depth = depth;
            }
            Node(Node& n){
                this->val = n.val;
                this->next = n.next;
                this->sub = n.sub;
                this->depth = n.depth;
            }
    };
    class OrgChart
    {
        private:
            std::vector<std::string> level_order;
            std::vector<std::string> reversed_level_order;
            std::vector<std::string> pre_order;
        public:
            Node* head = new Node("", 0);
            OrgChart();
            ~OrgChart();
            // string &get_val(Node* n){return n->val;};
            OrgChart &add_root(std::string val);
            OrgChart &add_sub(std::string above, std::string value);
            Node *inLine(Node* src, std::string& above);
            void println_src(); 
            void println(Node *src);
            void set_all_my_kids_pre();
            std::vector<std::string> all_my_kids_pre(Node* src);
            void set_all_my_kids();
            std::vector<std::string> all_my_kids(Node* src);
            void set_all_my_kids_reversed();
            // std::vector<Node*> level_order(Node* src); 
            std::string* begin_level_order();
            std::string* end_level_order();
            std::string* begin_reverse_order();
            std::string* reverse_order();
            std::string* begin_preorder();
            std::string* end_preorder();
            std::string* begin(){return begin_level_order();}
            std::string* end(){return end_level_order();}
            friend std::ostream & operator << (std::ostream &out, const OrgChart &organization);
            
    };
}
// namespace ariel
