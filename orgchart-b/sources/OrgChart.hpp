#include <iostream>
#include <string>
#include <vector>
namespace ariel{
    class Node{
        public:
            std::string val;
            std::vector<Node*> subs;
            Node* next;

            Node(std::string val){
                this->val = std::move(val);
                this->subs = std::vector<Node*>();
                this->next = nullptr;
            }
            // Node(Node& n){
            //     this->val = n.val;                
            //     this->subs = n.subs;
            //     this->next = nullptr;
            // }
    };
    class OrgChart{
        // private:
        public:
            Node* head;
            std::vector<Node*> allNodes;
            std::vector<std::string> sNodes;
    class iterator {

	private:
		Node* pointer_to_current_node;

	public:

		iterator(Node* root){
            pointer_to_current_node = root;
        }

		// Note that the method is const as this operator does not
		// allow changing of the iterator.
		// Note that it returns T& as it allows to change what it points to.
		// A const_iterator class will return const T&
		// and the method will still be const
		std::string& operator*() const {
			//return *pointer_to_current_node;
			return pointer_to_current_node->val;
		}

		std::string* operator->() const {
			return &(pointer_to_current_node->val);
		}

        Node* operator&() const {
            return pointer_to_current_node;
        }
		// ++i;
		iterator& operator++() {
			//++pointer_to_current_node;
			pointer_to_current_node = pointer_to_current_node->next;
			return *this;
		}

		// i++;
		// Usually iterators are passed by value and not by const& as they are small.
		iterator operator++(int) {
			iterator tmp= *this;
			pointer_to_current_node= pointer_to_current_node->next;
			return tmp;
		}

		bool operator==(const iterator& rhs) const {
			return pointer_to_current_node == rhs.pointer_to_current_node;
		}

		bool operator!=(const iterator& rhs) const {
			return pointer_to_current_node != rhs.pointer_to_current_node;
		}
	};  


            OrgChart();
            OrgChart &add_root(const std::string& value);
            OrgChart &add_sub(const std::string& above, const std::string& value);
            iterator begin_level_order();
            iterator end_level_order(){
                if (this->head == nullptr){
                    throw std::runtime_error("never initialize tree");
                }           
                return iterator{allNodes[allNodes.size()]};
            };
            iterator begin_reverse_order();
            iterator reverse_order(){
                if (this->head == nullptr){
                    throw std::runtime_error("never initialize tree");
                }           
                return iterator{allNodes[allNodes.size()]};
            };
            iterator begin_preorder();
            iterator end_preorder(){
                if (this->head == nullptr){
                    throw std::runtime_error("never initialize tree");
                }           
                return iterator{allNodes[allNodes.size()]};
            };
            iterator begin(){return begin_level_order();}
            iterator end(){
                if (this->head == nullptr){
                    throw std::runtime_error("never initialize tree");
                }           
                return end_level_order();
            }
            friend std::ostream &operator<<(std::ostream &out, OrgChart &organization) {
                for (iterator it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
                {
                    out << *it <<" ";
                } 
                return out;
            }

    };


    
}
// namespace ariel
