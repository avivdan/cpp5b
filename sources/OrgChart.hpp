#include <iostream>
#include <string>
#include <vector>
namespace ariel
{
    class Node{
        public:
            std::string val;
            Node *sub;
            Node *next;

            Node(std::string val){
                this->val = val;
                sub = NULL;
                next = NULL;
            }
            Node(Node& n){
                this->val = n.val;
                this->next = n.next;
                this->sub = n.sub;
            }
    };
    class OrgChart
    {
        public:
            Node* head = new Node("");
            OrgChart();
            ~OrgChart();
            // string &get_val(Node* n){return n->val;};
            OrgChart &add_root(std::string val);
            OrgChart &add_sub(std::string above, std::string value);
            Node *inLine(Node* src, std::string& above);
            void println_src(); 
            void println(Node *src);
            std::vector<std::string>::iterator begin_level_order();
            std::vector<std::string>::iterator end_level_order();
            std::vector<std::string>::iterator begin_reverse_order();
            std::vector<std::string>::iterator reverse_order();
            std::vector<std::string>::iterator begin_preorder();
            std::vector<std::string>::iterator end_preorder();
            std::vector<std::string>::iterator begin();
            std::vector<std::string>::iterator end();
            friend std::ostream & operator << (std::ostream &out, const OrgChart &organization);

    };
}
// namespace ariel
