#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>
#include "OrgChart.hpp"

namespace ariel
{

    OrgChart::OrgChart(){}
    OrgChart::~OrgChart(){}
   //also runs over the existing root
    OrgChart &OrgChart::add_root(std::string value){
        this->head->val = value;
        return *this;
    }

    OrgChart &OrgChart::add_sub(std::string above, std::string value){
        Node *subs = this->head;
        if (this->head->val.compare(above) == 0){
            if(this->head->sub == NULL){
                subs->sub = new Node(value);
                return *this;
            }
            subs = subs->sub;
            while (subs->next != NULL){               
                subs = subs->next;
            }
            subs->next = new Node(value);
            return *this;
        }
        //checked for root and now for sons
        //first we go on horizontal list to check if there is the above value
        //after that we continue to next horizontal level and so on
        Node* inlin = inLine(subs, above);
        // inlin = findIt(subs, above);
        if( inlin != NULL ){
            inlin->sub = new Node(value);
            // std::cout<<inlin->val<<std::endl;
            return *this;
        }
        return *this;
    }

    Node *OrgChart::inLine(Node* src, std::string& above){
        if(src->val.compare(above) == 0){
            return src;
        }
        if(src->sub != NULL){
            Node* n = inLine(src->sub, above);
            if(n != NULL){return n;}
        }
        while (src->next != NULL){
            src = src->next;
            if(src->val.compare(above) == 0){
                return src;
            }
            if(src->sub != NULL){
                Node* n = inLine(src->sub, above);
                if (n != NULL){return n;}
            }
        }
        return NULL;
    }

    void OrgChart::println_src(){
        std::cout<< this->head->val <<std::endl;
        if(this->head->sub != NULL){
            println(this->head->sub);
        }
            
    } 

    void OrgChart::println(Node *src){
        std::cout<< src->val <<std::endl;
        if (src->sub != NULL){
            println(src->sub);
        }
        while(src->next != NULL){
            src = src->next;
            std::cout<< src->val <<std::endl;
            if (src->sub != NULL){
                println(src->sub);
            }
        }
    }
    std::vector<std::string>::iterator OrgChart::begin_level_order(){
        std::vector<std::string>::iterator it;
        return it;
    }
    std::vector<std::string>::iterator OrgChart::end_level_order(){
        std::vector<std::string>::iterator it;
        return it;
    }
    std::vector<std::string>::iterator OrgChart::begin_reverse_order(){
        std::vector<std::string>::iterator it;
        return it;
    }
    std::vector<std::string>::iterator OrgChart::reverse_order(){
        std::vector<std::string>::iterator it;
        return it;
    }

    std::vector<std::string>::iterator OrgChart::begin_preorder(){
        std::vector<std::string>::iterator it;
        return it;
    }
    std::vector<std::string>::iterator OrgChart::end_preorder(){
        std::vector<std::string>::iterator it;
        return it;
    }
    std::vector<std::string>::iterator OrgChart::begin(){
        std::vector<std::string>::iterator it;
        return it;
    }
    std::vector<std::string>::iterator OrgChart::end(){
        std::vector<std::string>::iterator it;
        return it;
    }
}